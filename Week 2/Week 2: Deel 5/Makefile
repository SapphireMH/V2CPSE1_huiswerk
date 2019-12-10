#############################################################################
#
# Project Makefile
#
# (c) Wouter van Ooijen (www.voti.nl) 2016
#
# This file is in the public domain.
# 
#############################################################################

# source & header files in this project (main.cpp is automatically assumed)

SOURCES := note_player_gpio.cpp note_player_console.cpp rtttl_player.cpp

HEADERS := note.hpp melody.hpp note_player.hpp fur_elise.hpp zelda.hpp note_player_gpio.hpp note_player_console.hpp rtttl_player.hpp

# other places to look for files for this project
SEARCH  := 

# set REATIVE to the next higher directory 
# and defer to the Makefile.due there
RELATIVE := $(RELATIVE)../

.PHONY: clean

clean2: clean
	rm -f generate zelda.hpp

generate:
	g++ -std=c++17 generator.cpp rtttl_player.cpp note_player_file.cpp -o generate

zelda.hpp: generate
	./generate
include $(RELATIVE)Makefile.due
