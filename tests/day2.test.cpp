#include "catch2/catch.hpp"
#include "day2.h"
#include <string_view>

TEST_CASE("Day2"){
    SECTION("Puzzle1"){
        REQUIRE(day2::counts("abcdef") == std::pair{false, false});
        REQUIRE(day2::counts("bababc") == std::pair{true, true});
        REQUIRE(day2::counts("abbcde") == std::pair{true, false});
        REQUIRE(day2::counts("abcccd") == std::pair{false, true});
        REQUIRE(day2::counts("aabcdd") == std::pair{true, false});
        REQUIRE(day2::counts("abcdee") == std::pair{true, false});
        REQUIRE(day2::counts("ababab") == std::pair{false, true});
    }

    SECTION("Puzzle2"){
        REQUIRE(day2::diffIndices("abcde", "axcye") == std::vector<size_t>{1,3});
        REQUIRE(day2::diffIndices("fghij", "fguij") == std::vector<size_t>{2});
    }
}