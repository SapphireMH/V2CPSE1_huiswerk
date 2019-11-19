#include "hwlib.hpp"

extern "C" {
	void compressed();
	void decode();
	void print_char( char c );
}

void print_char( char c ){
   hwlib::cout << c;
}

int main( void ){
	
	hwlib::wait_ms(500);
	compressed();
	
}