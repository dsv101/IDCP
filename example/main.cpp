#include "Sud.hpp"
#include "Bpm.hpp"
#include "Note.hpp"
#include "Song.hpp"
#include <iostream>

std::string nd = "\
bpm 12.8\n\
sud 3.2\n\
\n\
m\n\
c 1/2\n\
t 5/8\n\
q 7/8\n\
\n\
m\n\
l\n\
r 1/2\n\
q 3/4\n\
\n\
m\n\
m\n\
m\n\
qh\n\
m\n\
qhe 1/2\n\
\n\
\n\
\n\
\n\
\n\
\n\
\n\
\n";

int main()
{
	idc::parser::Song song;

	bool loaded = song.load_data(nd);

	std::cout << loaded << std::endl;
	
	if (!loaded)
		std::cout << song.get_error() << std::endl;
	else
		std::cout << song.to_string() << std::endl;

	return 0;
}