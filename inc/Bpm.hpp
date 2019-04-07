#ifndef IDCP_BPM_HPP
#define IDCP_BPM_HPP

#include <string>
#include <regex>

namespace idc::parser
{
	class Bpm
	{
		private:
			const std::regex exp = std::regex("^bpm\\s+(((\\d+)[.](\\d+))|(\\d+))$");
			float val;

		public:
			Bpm();
			virtual ~Bpm();

			bool init(std::string line);
			float get_val() const;

			std::string to_string() const;
	};
}

#endif