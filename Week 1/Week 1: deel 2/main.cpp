//Assembly homework Week 1, Part 2
//Written by: Mike Hoogendoorn
//Date of last edit: 17-09-2019

#include "hwlib.hpp"

extern "C" {
	void application();
	void print_asciz( const char * s );
	void uart_put_char( char c );
}

void uart_put_char( char c ){
   hwlib::cout << c;
}

int main( void ){	
   
   namespace target = hwlib::target;   
    
      // wait for the PC console to start
   hwlib::wait_ms( 2000 );

   application();
}