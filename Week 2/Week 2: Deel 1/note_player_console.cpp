#include "hwlib.hpp"
#include "note_player_console.hpp"
  
void play( const char *s ){
	int state = 0;
	for( const char * p = s; state >= 0; p++ ){
		const char c = *p;
		switch( state ){
			
			case 0:
				if( c == ':' ){
					state = 1;
				}
				continue;
			
			case 1:
				if( c == ':' ){
					state = 2;
				}
				continue;
			
			case 2:
			
				if( c == ',' ){
					hwlib::cout << "\n";
				} else {
					hwlib::cout << c;
					if( c == '\0' ){
						hwlib::cout << "\n";
						state = -1;
					}
				}
				continue;
		}	
	}
}