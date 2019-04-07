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

std::string nd2 = "\
bpm 169\n\
sud 2\n\
\n\
m\n\
\n\
m\n\
\n\
t 4/8\n\
c 5/8\n\
t 6/8\n\
c 7/8\n\
\n\
m\n\
qh\n\
qhe 1/2\n\
ch 1/2\n\
\n\
m\n\
che\n\
t\n\
q 1/4\n\
c 2/4\n\
t 3/4\n\
\n\
m\n\
ch\n\
che 1/2\n\
q 1/2\n\
l 7/8\n\
\n\
m\n\
r 1/8\n\
l 3/8\n\
r 5/8\n\
l 7/8\n\
\n\
m\n\
q 1/4\n\
c 1/4\n\
t 2/4\n\
c 2/4\n\
q 3/4\n\
t 3/4\n\
\n\
m\n\
ch\n\
t 1/4\n\
q 2/4\n\
che 3/4\n\
q 3/4\n\
\n\
m\n\
qh\n\
qhe 1/2\n\
r 7/8\n\
\n\
m\n\
l 1/8\n\
r 3/8\n\
l 5/8\n\
\n\
m\n\
q\n\
c\n\
q 1/4\n\
c 1/4\n\
q 2/4\n\
c 2/4\n\
q 3/4\n\
c 3/4\n\
\n\
m\n\
t\n\
c\n\
t 2/8\n\
c 2/8\n\
c 3/8\n\
q 4/8\n\
q 5/8\n\
t 6/8\n\
t 7/8\n\
\n\
m\n\
q\n\
t\n\
q 1/4\n\
t 1/4\n\
q 2/4\n\
t 2/4\n\
q 3/4\n\
t 3/4\n\
\n\
m\n\
c\n\
c 1/8\n\
t 1/8\n\
c 3/8\n\
q 3/8\n\
c 5/8\n\
t 7/8\n\
\n\
m\n\
qh\n\
l 2/4\n\
r 3/4\n\
\n\
m\n\
qhe\n\
ch\n\
r 2/4\n\
l 3/4\n\
\n\
m\n\
che\n\
th\n\
l 2/4\n\
r 3/4\n\
\n\
m\n\
the\n\
q 1/8\n\
c 1/8\n\
q 2/8\n\
c 2/8\n\
q 3/8\n\
c 3/8\n\
q 4/8\n\
c 4/8\n\
q 5/8\n\
c 5/8\n\
q 6/8\n\
c 7/8\n\
q 7/8\n\
\n\
m\n\
t\n\
t 1/4\n\
t 2/4\n\
t 3/4\n\
c 7/8\n\
\n\
m\n\
qh\n\
c 1/4\n\
t 2/4\n\
q 3/4\n\
\n\
m\n\
t\n\
c 1/4\n\
t 2/4\n\
c 3/4\n\
qhe 3/4\n\
\n\
m\n\
ch\n\
t 1/4\n\
q 2/4\n\
c 3/4\n\
\n\
m\n\
q\n\
t 1/4\n\
q 2/4\n\
t 3/4\n\
che 3/4\n\
\n\
m\n\
th\n\
q 1/4\n\
c 2/4\n\
t 3/4\n\
\n\
m\n\
c\n\
q 1/4\n\
c 2/4\n\
q 3/4\n\
the 3/4\n\
\n\
m\n\
qh\n\
c 1/4\n\
q 2/4\n\
t 3/4\n\
\n\
m\n\
qhe\n\
t\n\
c 2/8\n\
t 3/8\n\
q 4/8\n\
t 5/8\n\
c 6/8\n\
r 7/8\n\
\n\
m\n\
q 1/4\n\
c 2/4\n\
t 3/4\n\
l 7/8\n\
\n\
m\n\
t 1/4\n\
t 2/4\n\
t 3/4\n\
\n\
m\n\
q\n\
q 1/4\n\
c 4/8\n\
t 5/8\n\
c 6/8\n\
t 7/8\n\
q 7/8\n\
\n\
m\n\
l 3/8\n\
r 5/8\n\
l 7/8\n\
\n\
m\n\
q 4/8\n\
c 5/8\n\
th 7/8\n\
\n\
m\n\
the 3/8\n\
q 3/8\n\
c 7/8\n\
\n\
m\n\
t 4/8\n\
t 5/8\n\
q 7/8\n\
\n\
m\n\
q 3/8\n\
c 3/8\n\
\n\
m\n\
q\n\
t 1/8\n\
q 2/8\n\
t 3/8\n\
q 4/8\n\
t 5/8\n\
q 6/8\n\
t 7/8\n\
\n\
m\n\
c 5/16\n\
t 7/8\n\
\n\
m\n\
t 1/4\n\
c 9/16\n\
q 7/8\n\
\n\
m\n\
q 5/16\n\
\n\
m\n\
qh\n\
ch\n\
qhe 1/4\n\
che 1/4\n\
\
";

int main()
{
	idc::parser::Song song;
	idc::parser::Song song2;

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

	if (!song2.load_data(nd2))
		std::cout << song2.get_error() <<std::endl;
	else
	{
		std::cout << song2.to_string() << std::endl << std::endl;
	}

	return 0;
}