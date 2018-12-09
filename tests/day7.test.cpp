#include "catch2/catch.hpp"
#include "day7.h"


#include <fstream>

TEST_CASE("Day7") {
    SECTION("parseline") {
        auto info = day7::parseline("Step C must be finished before step A can begin.");
        CHECK(info == std::pair<char, char>{'C', 'A'});
    }

    SECTION("parsefile") {
        auto info = day7::parsefile("../../input/test-input-7.txt");
        auto it = info.begin();
        CHECK(*(it++) == std::pair<char, char>{'C', 'A'});
        CHECK(*(it++) == std::pair<char, char>{'C', 'F'});
        CHECK(*(it++) == std::pair<char, char>{'A', 'B'});
        CHECK(*(it++) == std::pair<char, char>{'A', 'D'});
        CHECK(*(it++) == std::pair<char, char>{'B', 'E'});
        CHECK(*(it++) == std::pair<char, char>{'D', 'E'});
        CHECK(*(it++) == std::pair<char, char>{'F', 'E'});

        SECTION("organize information"){
            auto map = day7::organizeInfo(info);

            CHECK(map['C'].size() == 0);
            CHECK(map['A'].size() == 1);
            CHECK(map['F'].size() == 1);
            CHECK(map['B'].size() == 1);
            CHECK(map['D'].size() == 1);
            CHECK(map['E'].size() == 3);

            CHECK(map['A'].front() == 'C');
            CHECK(day7::findNextChar(map) == 'C');

            SECTION("Step Order") {
                std::string result = day7::getStepOrder(map);

                CHECK(result == "CABDFE");
            }

            SECTION("Time") {
                CHECK(day7::timeForChar('A') == 61);
                CHECK(day7::timeForChar('Z') == 86);
                CHECK(day7::getStepOrderAndTime(map, 1).second == 381);
                CHECK(day7::getStepOrderAndTime(map, 2).second == 258);
            }
        }
    }
}
//Step C must be finished before step A can begin.
//Step C must be finished before step F can begin.
//Step A must be finished before step B can begin.
//Step A must be finished before step D can begin.
//Step B must be finished before step E can begin.
//Step D must be finished before step E can begin.
//Step F must be finished before step E can begin.