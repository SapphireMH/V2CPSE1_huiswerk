#############################################################################
#
# Project Makefile
#
# (c) Wouter van Ooijen (www.voti.nl) 2016
#
# This file is in the public domain.
# 
#############################################################################

# source files in this project (main.cpp is automatically assumed)
SOURCES := decode.asm compressed.asm

# header files in this project
HEADERS := match.hpp compressor.hpp

# other places to look for files for this project
SEARCH  :=

# set REATIVE to the next higher directory 
# and defer to the Makefile.due there
RELATIVE := $(RELATIVE)../

.PHONY: clean

clean2: clean
	rm compressed.asm generate

generate:
	g++ -std=c++17 generator.cpp match.hpp compressor.hpp -o generate

compressed.asm: generate
	./generate
include $(RELATIVE)Makefile.due


