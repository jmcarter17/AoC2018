#include "catch2/catch.hpp"
#include "day4.h"
#include <string>
#include <map>

TEST_CASE("Day4") {
    SECTION("Puzzle1") {
        std::map<std::string, std::string> sortedMap;
        SECTION("Parse Line") {
            auto res = day4::parseline("[1518-09-24 00:59] wakes up");
            CHECK(res[0] == "1518-09-24 00:59");
            CHECK(res[1] == "w");
            sortedMap[res[0]] = res[1];

            res = day4::parseline("[1518-11-12 00:30] falls asleep");
            CHECK(res[0] == "1518-11-12 00:30");
            CHECK(res[1] == "f");
            sortedMap[res[0]] = res[1];

            res = day4::parseline("[1518-05-08 00:02] Guard #2719 begins shift");
            CHECK(res[0] == "1518-05-08 00:02");
            CHECK(res[1] == "2719");
            sortedMap[res[0]] = res[1];

            SECTION("Sort Time") {
                auto it = sortedMap.begin();
                CHECK(it++->first == "1518-05-08 00:02");
                CHECK(it++->first == "1518-09-24 00:59");
                CHECK(it++->first == "1518-11-12 00:30");
            }
        }



    }
}