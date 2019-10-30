#include "note_player_file.hpp"

void note_player_file::play( const note & n ){
	
std::ofstream outfile("zelda.hpp", std::ios::app);
outfile << "\tp.play( note{ " << n.frequency << "," << n.duration << "} );\n";
outfile.close();
	
};