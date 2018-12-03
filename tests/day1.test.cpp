#include "catch2/catch.hpp"
#include "day1.h"

TEST_CASE("Day1"){
//    std::vector v{1, -2, 3, 1};
    std::vector<int> v;

    SECTION("Puzzle1"){
        std::vector v{1, -2, 3, 1};
        REQUIRE(day1::sum(v) == 3);

        v = {1, 1, 1};
        REQUIRE(day1::sum(v) == 3);

        v = {1, 1, -2};
        REQUIRE(day1::sum(v) == 0);

        v = {-1, -2, -3};
        REQUIRE(day1::sum(v) == -6);
    }

    SECTION("Puzzle2"){
        std::vector v{1, -2, 3, 1};
        REQUIRE(day1::repeatedFrequency(v) == 2);

        v = {1, -1};
        REQUIRE(day1::repeatedFrequency(v) == 0);

        v = {3, 3, 4, -2, -4};
        REQUIRE(day1::repeatedFrequency(v) == 10);

        v = {-6, 3, 8, 5, -6};
        REQUIRE(day1::repeatedFrequency(v) == 5);

        v = {7, 7, -2, -7, -4};
        REQUIRE(day1::repeatedFrequency(v) == 14);

    }
}
