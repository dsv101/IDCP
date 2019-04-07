#include "Note.hpp"
#include <sstream>
#include <iostream>

namespace idc
{
namespace parser
{
	unsigned int Note::numNotes = 0;

	Note::Note() :
		type(Note::Type::UNKNOWN),
		place(0.0f),
		uid(numNotes++)
	{
	
	}

	Note::Note(const Note &note)
	{
		this->type = note.type;
		this->place = note.place;
		this->uid = note.uid;
	}

	Note::~Note()
	{

	}

	bool Note::init(std::string line)
	{
		this->type = Type::UNKNOWN;
		this->place = -1.0f;

		std::smatch m;

		if (std::regex_search(line, m, this->exp))
		{
			std::string t = m[1];

			// std::cerr << m[0] << " ~'" << m[1] << "' '" << m[2] << "' '" << m[3] << "' '"<< m[4] << "' '" << m[5] << "' '" << m[6] << "' '" << m[7] << "'~" << std::endl;

			if (t == "q")
				this->type = Type::Q;
			else if (t == "t")
				this->type = Type::T;
			else if (t == "c")
				this->type = Type::C;
			else if (t == "l")
				this->type = Type::L;
			else if (t == "r")
				this->type = Type::R;
			else if (t == "qh")
				this->type = Type::QH;
			else if (t == "th")
				this->type = Type::TH;
			else if (t == "ch")
				this->type = Type::CH;
			else if (t == "lh")
				this->type = Type::LH;
			else if (t == "rh")
				this->type = Type::RH;
			else if (t == "qhe")
				this->type = Type::QHE;
			else if (t == "the")
				this->type = Type::THE;
			else if (t == "che")
				this->type = Type::CHE;
			else if (t == "lhe")
				this->type = Type::LHE;
			else if (t == "rhe")
				this->type = Type::RHE;
			else
				return false;

			if (m[4] == "0" || m[6] == "0" || (m[4] == "" && m[6] == ""))
				this->place = 0.0f;
			else if (this->place != 0.0f)
			{
				try
				{
					this->place = std::stof(m[6]);

					if (m[7] != "")
						this->place /= std::stof(m[7]);
				}
				catch(...)
				{
					return false;
				}
			}

			return true;
		}

		return false;
	}

	Note::Type Note::get_type() const
	{
		return this->type;
	}

	float Note::get_place() const
	{
		return this->place;
	}

	unsigned int Note::get_uid() const
	{
		return this->uid;
	}

	std::string Note::to_string() const
	{
		std::stringstream ss;

		ss << "Note: type(" << this->type << ") place(" << this->place << ") uid(" << this->uid << ")";

		return ss.str();
	};
}
}