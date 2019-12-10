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

TEST_CASE( "Getting the max with 20 ints" ){
	set<int, 20> numbers;
	numbers.add(3);
	numbers.add(5);
	numbers.add(4);
	numbers.add(9);
	REQUIRE( numbers.max() == 9 );
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

TEST_CASE( "Getting the max with 10 chars" ){
	set<char, 10> numbers;
	numbers.add('a');
	numbers.add('c');
	numbers.add('f');
	numbers.add('z');
	REQUIRE( numbers.max() == 'z' );
}

TEST_CASE( "strings" ){
	set<std::array<char, 3>, 10> strings;
	strings.add( {'a', 'a', 'a'} );
	REQUIRE( strings.contains({'a', 'a', 'a'}) );
	strings.remove( {'a', 'a', 'a'} );
	REQUIRE( !strings.contains({'a', 'a', 'a'}) );
}

TEST_CASE( "max with strings." ){
	set<std::array<char, 3>, 10> strings;
	strings.add( {'a', 'b', 'c'} );
	strings.add( {'g', 'h', 'i'} );
	strings.add( {'d', 'e', 'f'} );
	std::array<char, 3> A = {'g', 'h', 'i'};
	std::array<char, 3> B = strings.max();
	REQUIRE( A == B );
}