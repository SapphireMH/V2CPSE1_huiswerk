#ifndef _NOTE_PLAYER_FILE_HPP
#define _NOTE_PLAYER_FILE_HPP

#include "note_player.hpp"
#include <iostream>
#include <fstream> 

class note_player_file : public note_player {

public:
	std::ofstream outfile;
	
	note_player_file()
	{std::ofstream outfile("zelda.hpp");
	outfile <<	"#ifndef _ZELDA_HPP\n"
			<<	"#define _ZELDA_HPP\n\n"
			<<	"#include \"melody.hpp\"\n\n"
			<<	"class zelda : public melody {\n"
			<<	"public:\n"
			<<	"void play( note_player & p ){\n";
	outfile.close();
	}
				
	~note_player_file()
	{std::ofstream outfile("zelda.hpp", std::ios::app);
	outfile <<	"\t}\n"
			<<	"};\n\n"
			<<	"#endif";
	outfile.close();
	}
	void play( const note & n ) override;
};

#endif