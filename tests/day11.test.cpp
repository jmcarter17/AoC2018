#include "catch2/catch.hpp"
#include "day11.h"
#include "day6.h"

TEST_CASE("Day11"){
    SECTION("Puzzle1"){
        SECTION("PowerCell") {
            CHECK(day11::powercell(day6::Point{3, 5}, 8) == 4);
            CHECK(day11::powercell(day6::Point{122, 79}, 57) == -5);
            CHECK(day11::powercell(day6::Point{217, 196}, 39) == 0);
            CHECK(day11::powercell(day6::Point{101, 153}, 71) == 4);
        }

        SECTION("Find Best 3x3 Grid"){
            auto grid = day11::gridPowercell(42);
            auto [p, sum] = day11::findBest3x3(grid);

            CHECK(p == day6::Point{21, 61});
            CHECK(sum == 30);
        }

        SECTION("Find Best Grid of Any Size", "[!hide][.]"){
            auto grid = day11::gridPowercell(18);
            auto [p, sum, n] = day11::findBestN(grid);
            CHECK(p == day6::Point{90, 269});
            CHECK(sum == 113);
            CHECK(n == 16);
        }
    }



//    Fuel cell at  122,79, grid serial number 57: power level -5.
//    Fuel cell at 217,196, grid serial number 39: power level  0.
//    Fuel cell at 101,153, grid serial number 71: power level  4.

}

