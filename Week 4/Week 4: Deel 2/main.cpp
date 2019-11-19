#include <iostream>
#include <fstream>

#include "compressor.hpp" 
#include "decompressor.hpp" 

int main( void ){	
	lz_compressor< 4096 > compressor;
 
	std::ifstream f1;
	f1.open( "wilhelmus.txt" );
	if( ! f1.is_open()){
		std::cerr << "input file not opened";
		return -1;      
	}
   
	std::ofstream f2;
	f2.open( "compressed.asm" );
	if( ! f2.is_open()){
		std::cerr << "output file not opened";
		return -1;      
	}
   
	f2 << "//Assembly homework Week 4, Part 2\n//Written by: Mike Hoogendoorn\n//Date of last edit: 31-10-2019\n\n.data\nvar1: .asciz \""; 
   
	compressor.compress( 
		[ &f1 ]()-> int { auto c = f1.get(); return f1.eof() ? '\0' : c; },
		[ &f2 ]( char c ){ if(c == '\n'){f2.put( '*' );} else{f2.put( c );}; }
	);
  
	f2 << "\" //Store the text into memory.\n\n.text\n.align 2\n.global compressed\n\ncompressed:\nLDR r0, adr_var1 //Put the memory address of adr_var1 into r0.\nB decode //Branch to decode.asm.\n\nadr_var1: .word var1 //Put the memory address of var1 into adr_var1.";
   
	f1.close();
	f2.close();
   
	f1.open( "compressed.asm" );
	if( ! f1.is_open()){
		std::cerr << "compressed file not opened";
		return -1;      
	}
   
	lz_decompressor decompressor;
	decompressor.decompress( 
		[ &f1 ]()-> int { auto c = f1.get(); return f1.eof() ? '\0' : c; },
		[ &f2 ]( char c ){ std::cout << c; }
   );
}