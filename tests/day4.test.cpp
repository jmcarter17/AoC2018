#include "catch2/catch.hpp"
#include "day4.h"
#include <string>
#include <map>
//#include <utility>
#include <fstream>

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
            CHECK(res[1] == "#2719");
            sortedMap[res[0]] = res[1];

            SECTION("Sort Time") {
                auto it = sortedMap.begin();
                CHECK(it++->first == "1518-05-08 00:02");
                CHECK(it++->first == "1518-09-24 00:59");
                CHECK(it++->first == "1518-11-12 00:30");
            }
        }

        SECTION("Hours Asleep"){
            std::ifstream file("../../input/test-input-4.txt", std::ios::in);
            std::string line;

            while (std::getline(file, line)) {
                auto parsedLine = day4::parseline(line);
                sortedMap[parsedLine[0]] = parsedLine[1];
            }

            auto hoursAsleep = day4::getHoursOfSleep(sortedMap);

            SECTION("Strategy 1") {
                auto goodGuard = day4::findGuardMostAsleep(hoursAsleep);
                auto goodMinute = std::max_element(hoursAsleep[goodGuard].begin(), hoursAsleep[goodGuard].end(),
                                                   [](const std::pair<int, int> &p1, const std::pair<int, int> &p2) {
                                                       return p1.second < p2.second;
                                                   })->first;

                CHECK(goodGuard == "#10");
                CHECK(goodMinute == 24);
            }

            SECTION("Strategy 2") {
                auto goodGuard = day4::findGuardConsistentAsleep(hoursAsleep);

                CHECK(goodGuard.first == "#99");
                CHECK(goodGuard.second == 45);
            }

        }
    }
}