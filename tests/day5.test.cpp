#include "catch2/catch.hpp"
#include "day5.h"


#include <fstream>

TEST_CASE("Day5") {
    SECTION("Puzzle1") {
        CHECK(day5::checkCompatible('a', 'A'));
        CHECK(!day5::checkCompatible('a', 'a'));
        CHECK(!day5::checkCompatible('A', 'A'));
        CHECK(!day5::checkCompatible('a', 'B'));

        CHECK(day5::foldPolymer("dabAcCaCBAcCcaDA") == "dabCBAcaDA");
        CHECK(day5::foldPolymer("dabAcCaCBAcCcaDA").size() == 10);
    }

    SECTION("Puzzle2") {
        CHECK(day5::removeAndFold("dabAcCaCBAcCcaDA", 'a').size() == 6);
        CHECK(day5::removeAndFold("dabAcCaCBAcCcaDA", 'b').size() == 8);
        CHECK(day5::removeAndFold("dabAcCaCBAcCcaDA", 'c').size() == 4);
        CHECK(day5::removeAndFold("dabAcCaCBAcCcaDA", 'd').size() == 6);
    }
}