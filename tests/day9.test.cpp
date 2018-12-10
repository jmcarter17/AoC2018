#include "catch2/catch.hpp"
#include "day9.h"


TEST_CASE("Day9"){
    SECTION("Puzzle1"){
        auto scores = day9::scores(9, 25);

        CHECK(scores[5] == std::vector{23, 9});
        CHECK(day9::getLargestScore(scores) == 32);

        scores = day9::scores(10, 1618);
        CHECK(day9::getLargestScore(scores) == 8317);

        scores = day9::scores(13, 7999);
        CHECK(day9::getLargestScore(scores) == 146373);

        scores = day9::scores(17, 1104);
        CHECK(day9::getLargestScore(scores) == 2764);

        scores = day9::scores(21, 6111);
        CHECK(day9::getLargestScore(scores) == 54718);

        scores = day9::scores(30, 5807);
        CHECK(day9::getLargestScore(scores) == 37305);

    }
}


//10 players; last marble is worth 1618 points: high score is 8317
//13 players; last marble is worth 7999 points: high score is 146373
//17 players; last marble is worth 1104 points: high score is 2764
//21 players; last marble is worth 6111 points: high score is 54718
//30 players; last marble is worth 5807 points: high score is 37305
