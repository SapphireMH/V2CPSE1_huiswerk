#include "set.hpp"
#define CATCH_CONFIG_MAIN
#include "/home/thisismike97/Catch2/single_include/catch2/catch.hpp"

TEST_CASE( "checking for existence, with 20 ints" ){
	set<int, 20> numbers;
	numbers.add(5);
	REQUIRE( numbers.contains(5) );
}

TEST_CASE( "Adding a number, with 20 ints" ){
	set<int, 20> numbers;
	numbers.add(5);
	REQUIRE( numbers.contains(5) );
}

TEST_CASE( "Removing a number, with 20 ints" ){
	set<int, 20> numbers;
	REQUIRE( !numbers.contains(5) );
	numbers.add(5);
	numbers.add(6);
	numbers.remove(5);
	REQUIRE( numbers.contains(6) );
	REQUIRE( !numbers.contains(5) );
}

TEST_CASE( "checking for existence, with 10 chars" ){
	set<char, 10> numbers;
	numbers.add('a');
	REQUIRE( numbers.contains('a') );
}

TEST_CASE( "Adding a number, with 10 chars" ){
	set<char, 10> numbers;
	numbers.add('a');
	REQUIRE( numbers.contains('a') );
}

TEST_CASE( "Removing a number, with 10 chars" ){
	set<char, 10> numbers;
	REQUIRE( !numbers.contains('a') );
	numbers.add('a');
	numbers.add('b');
	numbers.remove('a');
	REQUIRE( numbers.contains('b') );
	REQUIRE( !numbers.contains('a') );
}