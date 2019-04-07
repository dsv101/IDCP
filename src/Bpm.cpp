#include "Bpm.hpp"
#include <sstream>

namespace idc
{
namespace parser
{
	Bpm::Bpm() :
		val(-1.0f)
	{

	}

	Bpm::~Bpm()
	{

	}

	bool Bpm::init(std::string line)
	{
		std::smatch m;

		if (std::regex_search(line, m, this->exp))
		{
			//std::cerr << m[0] << " '" << m[1] << "' '" << m[2] << "' '" << m[3] << "' '"<< m[4] << "' '" << m[5] << "'" << std::endl;

			try
			{
				this->val =
					(m[5] != "")
						? std::stof(m[5])
						: (m[2] != "")
							? std::stof(m[2])
							: std::stof(m[1]);
				return true;
			}
			catch (...)
			{
				return false;
			}
		}

		return false;
	}

	float Bpm::get_val() const
	{
		return this->val;
	}

	std::string Bpm::to_string() const
	{
		std::stringstream ss;

		ss << "Bpm: val(" << this->val << ")";

		return ss.str();
	}
}
}