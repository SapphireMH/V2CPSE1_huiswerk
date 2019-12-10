#ifndef _SET_HPP
#define _SET_HPP

#include <array>
#include <iostream>

template< typename T, T N >
class set {
private:
	std::array< T, N > values;
	
public:

	set():
	values( {} )
	{ values.fill(0); };

	void add(T n){
		if( !contains( n )){
			for( size_t i = 0; i < values.size(); i++ ){
				if( values[i] == 0 ){
					values[i] = n;
					return;
				}
			}
		}
	}
	
	void remove(T n){
		if( contains( n )){
			for( size_t i = 0; i < values.size(); i++ ){
				if( values[i] == n ){
					values[i] = 0;
					return;
				}
			}
		}
	}
	
	bool contains(T n){
		for( size_t i = 0; i < values.size(); i++ ){
			if( values[i] == n ){
				return true;
			}
		}
		return false;
	}
	
	friend std::ostream& operator<<( std::ostream & lhs, const set & st ){
		for( size_t i = 0; i < st.values.size(); i++ ){
			std::cout << st.values[0]; //test print;
			lhs << int(st.values[i]);
		}
		return lhs;
	}
};

#endif //_SET_HPP