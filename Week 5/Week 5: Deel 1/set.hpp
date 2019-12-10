#ifndef _SET_HPP
#define _SET_HPP

#include <array>
#include <iostream>

class set {
private:
	std::array<uint8_t, 10> values;
	
public:

	set();

	void add(int n);
	void remove(int n);
	bool contains(int n);
	friend std::ostream& operator<<( std::ostream & lhs, const set & st );
};

#endif //_SET_HPP