#ifndef IDCP_SONG_HPP
#define IDCP_SONG_HPP

#include "Bpm.hpp"
#include "Sud.hpp"
#include "Note.hpp"
#include <map>
#include <string>
#include <vector>
#include <utility>

namespace idc::parser
{
	class Song
	{
		private:
			Bpm bpm;
			Sud sud;
			std::map<int, std::vector<Note>> data; // measure => notes
			bool valid;
			bool finished;
			std::string error;

		public:
			Song();
			virtual ~Song();

			bool load_data(std::string str);

			std::vector<std::pair<float,Note>> seek(float start, float end, float runtime);

			bool is_valid() const;
			bool is_finished() const;
			std::string get_error() const;
			std::string to_string() const;
	};
}

#endif