#include "Sud.hpp"
#include "Bpm.hpp"
#include "Note.hpp"
#include "Song.hpp"
#include <iostream>

std::string nd = "\
bpm 60\n\
sud 4\n\
\n\
m\n\
l 0\n\
l 1/4\n\
l 2/4\n\
l 3/4\n\
m\n\
r 0\n\
r 1/4\n\
r 2/4\n\
r 3/4\n\
m\n\
q 0\n\
q 1/4\n\
q 2/4\n\
q 3/4\n\
m\n\
c 0\n\
c 1/4\n\
c 2/4\n\
c 3/4\n\
";

int main()
{
	idc::parser::Song song;

	bool loaded = song.load_data(nd);

	std::cout << loaded << std::endl;
	
	if (!loaded)
		std::cout << song.get_error() << std::endl;
	else
	{
		std::cout << song.to_string() << std::endl << std::endl;

		std::vector<idc::parser::Song::SeekResult> results = song.seek(8.f,12.f,60.f);

		std::cout << "found " << results.size() << std::endl;

		for (std::vector<idc::parser::Song::SeekResult>::iterator it = results.begin(); it != results.end(); ++it)
			std::cout << (*it).to_string() << std::endl;
	}

	return 0;
}