#include "catch2/catch.hpp"
#include "day6.h"

TEST_CASE("Day6"){
    SECTION("Parse Line"){
        auto point = day6::parseline("8, 3");
        CHECK(point.x == 8);
        CHECK(point.y == 3);
        CHECK(point == day6::Point{8,3});
    }

    SECTION("distance"){
        day6::Point p1{2,3};
        day6::Point p2{6,0};
        CHECK(p1.distance(p1) == 0);
        CHECK(p1.distance(p2) == 7);
        CHECK(p2.distance(p1) == 7);
        CHECK(p2.distance(p2) == 0);
    }

    SECTION("Parse File"){
        auto gridPoints = day6::getGridPointsFromFile("../../input/test-input-6.txt");

        CHECK(gridPoints.size() == 6);
        CHECK(*gridPoints.begin() == day6::Point{1,1});
        CHECK(*--gridPoints.end() == day6::Point{8,9});

        auto grid = day6::getGrid(gridPoints);

        auto p = (*grid.begin()).first;
        size_t max = 0;
        for (auto& [key, val] : grid){
            if (val.size() > max){
                max = val.size();
                p = key;
            }
        }

        CHECK(p == day6::Point{5,5});
        CHECK(grid[p].size() == 17);
    }
}
