#include "set.hpp"

set::set():
	values( {} )

{ values.fill(0); }

void set::add( int n ){
	if( !contains( n )){
		for( size_t i = 0; i < values.size(); i++ ){
			if( values[i] == 0 ){
				values[i] = n;
				return;
			}
		}
	}
}

void set::remove( int n ){
	if( contains( n )){
		for( size_t i = 0; i < values.size(); i++ ){
			if( values[i] == n ){
				values[i] = 0;
				return;
			}
		}
	}
}

bool set::contains(int n){
	for( size_t i = 0; i < values.size(); i++ ){
		if( values[i] == n ){
			return true;
		}
	}
	return false;
}

std::ostream & operator<< ( std::ostream & lhs, const set & st ){
	for( size_t i = 0; i < st.values.size(); i++ ){
		std::cout << st.values[0]; //test print;
		lhs << int(st.values[i]);
	}
	return lhs;
}