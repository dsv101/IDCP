#ifndef IDCP_SONG_HPP
#define IDCP_SONG_HPP

#include "Bpm.hpp"
#include "Sud.hpp"
#include "Note.hpp"
#include <map>
#include <string>
#include <vector>
#include <sstream>

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
			struct SeekResult
			{
				Note note;
				float dist_norm;

				SeekResult(const Note &note, float dist_norm) :
					note(note),
					dist_norm(dist_norm)
				{

				}

				std::string to_string() const
				{
					std::stringstream ss;
					ss << "SeekResult: dist_norm(" << this->dist_norm << ")";
					ss << " with " << this->note.to_string();

					return ss.str();
				}
			};

			Song();
			virtual ~Song();

			bool load_data(std::string str);

			std::vector<SeekResult> seek(float start, float end, float runtime); // all in seconds

			bool is_valid() const;
			bool is_finished() const;
			std::string get_error() const;
			std::string to_string() const;
	};
}

#endif