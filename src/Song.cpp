#include "Song.hpp"
#include <sstream>
#include <cmath>
#include <iostream>

namespace idc::parser
{
	Song::Song() :
		bpm(),
		sud(),
		data(),
		valid(false),
		finished(false),
		error("")
	{

	}

	Song::~Song()
	{

	}

	bool Song::load_data(std::string str)
	{
		this->bpm.init("");
		this->sud.init("");
		this->data.clear();
		valid = false;
		finished = false;
		error = "";

		std::istringstream iss(str);
		bool hasHeader = false;
		int numMeasures = 0;
		int lineNum = -1;
		for(std::string line; std::getline(iss, line); )
		{
			lineNum++;
			if (line == "")
				continue;

			if (hasHeader == false)
			{
				if (this->bpm.get_val() < 0)
				{
					if (!this->bpm.init(line))
					{
						this->error = "line #" + std::to_string(lineNum) + ": \"" + line + "\" cpp_line:" + std::to_string(__LINE__);
						return false;
					}
				}
				else if (this->sud.get_val() < 0)
				{
					if (!this->sud.init(line))
					{
						this->error = "line #" + std::to_string(lineNum) + ": \"" + line + "\" cpp_line:" + std::to_string(__LINE__);
						return false;
					}
				}

				if (this->bpm.get_val() >= 0 && this->sud.get_val() >= 0)
					hasHeader = true;
			}
			else if (line == "m")
				this->data[numMeasures++] = std::vector<Note>();
			else if (numMeasures > 0)
			{
				Note n;
				if (n.init(line))
					this->data[numMeasures-1].push_back(n);
				else
				{
					this->error = "line #" + std::to_string(lineNum) + ": \"" + line + "\" cpp_line:" + std::to_string(__LINE__);
					return false;
				}
			}
		}

		if (!hasHeader)
		{
			this->error = "No Header Loaded. cpp_line:" + std::to_string(__LINE__);
			return false;
		}

		return this->valid = true;
	}

	std::vector<Song::SeekResult> Song::seek(float start, float end, float runtime)
	{
		std::vector<SeekResult> results;

		float bps = this->bpm.get_val() / 60;
		float spb = 1 / bps;

		int m0 = (int)std::floor(((start-this->sud.get_val()) / spb) / 4);
		int m1= (int)std::floor(((end-this->sud.get_val()) / spb) / 4);

		for (int m = m0; m < m1; ++m)
		{
			if (this->data.count(m) <= 0)
				break;

			for (Note n : this->data[m])
			{
				float nt = this->sud.get_val() + (((m*4) + (n.get_place()*4)) * spb);
				float nd = (nt / runtime);

				SeekResult sr(n, nd);
				results.push_back(sr);
			}
		}

		return results;
	}

	bool Song::is_valid() const
	{
		return this->valid;
	}

	bool Song::is_finished() const
	{
		return this->finished;
	}

	std::string Song::get_error() const
	{
		return this->error;
	}

	std::string Song::to_string() const
	{
		std::stringstream ss;

		ss
			<< this->bpm.to_string() << std::endl
			<< this->sud.to_string() << std::endl;

		for (std::map<int, std::vector<Note>>::const_iterator it = this->data.begin(); it != this->data.end(); ++it)
		{
			ss << "measure #:" << it->first << std::endl;

			for (std::vector<Note>::const_iterator itt = it->second.begin(); itt != it->second.end(); ++itt)
			{
				ss << (*itt).to_string() << std::endl;
			}
		}

		return ss.str();
	}

	
}