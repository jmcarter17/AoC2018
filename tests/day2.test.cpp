#include "catch2/catch.hpp"
#include "day2.h"
#include <string_view>

TEST_CASE("Day2"){
    SECTION("Puzzle1"){
        std::string s = "abcdef";
        REQUIRE(day2::counts(s) == std::pair{false, false});
        REQUIRE(day2::counts("bababc") == std::pair{true, true});
        REQUIRE(day2::counts("abbcde") == std::pair{true, false});
        REQUIRE(day2::counts("abcccd") == std::pair{false, true});
        REQUIRE(day2::counts("aabcdd") == std::pair{true, false});
        REQUIRE(day2::counts("abcdee") == std::pair{true, false});
        REQUIRE(day2::counts("ababab") == std::pair{false, true});
    }

}