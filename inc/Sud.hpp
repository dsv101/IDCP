#ifndef IDCP_SUD_HPP
#define IDCP_SUD_HPP

#include <string>
#include <regex>

namespace idc
{
namespace parser
{
	class Sud
	{
		private:
			const std::regex exp = std::regex("^sud\\s+(((\\d+)[.](\\d+))|(\\d+))$");
			float val;

		public:
			Sud();
			virtual ~Sud();

			bool init(std::string line);
			float get_val() const;

			std::string to_string() const;
	};
}
}

#endif