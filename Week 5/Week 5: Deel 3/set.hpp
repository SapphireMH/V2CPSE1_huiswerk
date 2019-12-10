#ifndef _SET_HPP
#define _SET_HPP

#include <array>
#include <iostream>

template< typename T, int N >
class set {
private:
	std::array< T, N > values;
	int index;
	
public:

	set():
	values( {} ),
	index( 0 )
	{};

	void add(T n){
		if( !contains( n )){
			values[index] = n;
			index++;
		}
	}
	
	void remove(T n){
		if( contains( n )){
			for( size_t i = 0; i < values.size(); i++ ){
				if( values[i] == n ){
					values[i] = values[index];
					index--;
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
	
	T max(){
		T max = values[0];
		for( size_t i = 0; i < values.size(); i++ ){
			if( T( values[i] ) > max ){
				max = values[i];
			}
		}
		return max;
	}
	
	friend std::ostream& operator<<( std::ostream & lhs, const set & st ){
		for( size_t i = 0; i < st.values.size(); i++ ){
			lhs << int(st.values[i]);
		}
		return lhs;
	}
};

#endif //_SET_HPP