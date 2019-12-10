#include "set.hpp"
#define CATCH_CONFIG_MAIN
#include "/home/thisismike97/Catch2/single_include/catch2/catch.hpp"

TEST_CASE( "checking for existence" ){
	set numbers;
	numbers.add(5);
	REQUIRE( numbers.contains(5) );
}

TEST_CASE( "Adding a number" ){
	set numbers;
	numbers.add(5);
	REQUIRE( numbers.contains(5) );
}

TEST_CASE( "Removing a number" ){
	set numbers;
	REQUIRE( !numbers.contains(5) );
	numbers.add(5);
	numbers.add(6);
	numbers.remove(5);
	REQUIRE( numbers.contains(6) );
	REQUIRE( !numbers.contains(5) );
}