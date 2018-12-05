#include <set>
#include "catch2/catch.hpp"
#include "day3.h"

TEST_CASE("Day3"){
    SECTION("Maps Square Inch from Claims") {
        auto mapSquares = day3::getMapSquares("#123 @ 3,2: 5x4");
        REQUIRE(mapSquares.size() == 20);
        REQUIRE(mapSquares[{3, 2}] == 123);

        mapSquares = day3::getMapSquares("#9 @ 12,645: 22x4");
        REQUIRE(mapSquares.size() == 88);
        REQUIRE(mapSquares[{16, 648}] == 9);
    }

    SECTION("Combine Maps") {
        std::map<std::pair<int, int>, std::vector<int>> combinedMap;
        auto mapSquares = day3::getMapSquares("#1 @ 1,3: 4x4");
        day3::combineMaps(combinedMap, mapSquares);
        mapSquares = day3::getMapSquares("#2 @ 3,1: 4x4");
        day3::combineMaps(combinedMap, mapSquares);
        mapSquares = day3::getMapSquares("#3 @ 5,5: 2x2");
        day3::combineMaps(combinedMap, mapSquares);

        REQUIRE(combinedMap[{3,3}].size() == 2);
        REQUIRE(combinedMap[{3,4}].size() == 2);
        REQUIRE(combinedMap[{4,3}].size() == 2);
        REQUIRE(combinedMap[{4,4}].size() == 2);
        REQUIRE(combinedMap[{3,5}].size() == 1);

        REQUIRE(day3::countOverusedSquares(combinedMap) == 4);
        REQUIRE(day3::findGoodClaim(combinedMap, 3) == 3);

    }
}