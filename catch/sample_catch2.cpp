
#define CATCH_CONFIG_MAIN

#include "single_include/catch2/catch.hpp"
// #include "catch2/catch.hpp" TODO: find why strip prefix is not working

int sum(int a, int b) {
    return a + b;
}

TEST_CASE("Sum of 4 + 9 = 13"){
  REQUIRE( sum(4,9) == 11 );
}

TEST_CASE("zero sums"){
  REQUIRE( sum(0,1) == 1 );
  REQUIRE( sum(0,3) == 3 );
}
