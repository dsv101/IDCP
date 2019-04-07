#include "Sud.hpp"
#include <sstream>

namespace idc
{
namespace parser
{
	Sud::Sud() :
		val(-1.0f)
	{

	}

	Sud::~Sud()
	{

	}

	bool Sud::init(std::string line)
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

	float Sud::get_val() const
	{
		return this->val;
	}

	std::string Sud::to_string() const
	{
		std::stringstream ss;

		ss << "Sud: val(" << this->val << ")";

		return ss.str();
	}
}
}
