#include "catch2/catch.hpp"
#include "day12.h"
#include <unordered_set>
#include <string>
#include <iostream>

TEST_CASE("Day12") {
    SECTION("Puzzle1") {
        SECTION("Next Gen From input") {
            std::unordered_set<std::string> setOK;
            setOK.insert("....#");
            CHECK(day12::nextGen(setOK, "....#"));
            CHECK(!day12::nextGen(setOK, "##..."));
        }

        SECTION("ParseInput") {
            SECTION("HelpFunctions") {
                std::string s = day12::parseFirstLine("initial state: #..#.#..##......###...###");
                CHECK(s == "#..#.#..##......###...###");

                std::unordered_set<std::string> setOK;
                day12::parseline(setOK, "...## => #");
                day12::parseline(setOK, "#..## => .");

                CHECK(setOK.find("...##") != setOK.end());
                CHECK(setOK.find("#..##") == setOK.end());
            }

            SECTION("Parse File") {
                auto [initState, setOK] = day12::parseInput("../../input/test-input-12.txt");

                CHECK(initState == "#..#.#..##......###...###");
                CHECK(setOK.find("...##") != setOK.end());
                CHECK(setOK.find("####.") != setOK.end());
                CHECK(setOK.find(".#..#") == setOK.end());

                SECTION("Update 1 Generation") {
                    auto [state, neg, pos] = day12::updateState(initState, setOK);

                    CHECK(state == "#...#....#.....#..#..#..#");
                    CHECK(neg == 0);
                    CHECK(pos == 0);
                }

                SECTION("Update 20 Generation") {
                    auto [state, neg, pos] = day12::updateNGeneration(initState, setOK, 20);

                    CHECK(state == "#....##....#####...#######....#.#..##");
                    CHECK(neg == 2);
                    CHECK(pos == 10);

                    auto sum = day12::getSum(state, neg);

                    CHECK(sum == 325);
                }
            }

            SECTION("Find Patterns") {
                auto [initState, setOK] = day12::parseInput("../../input/input-12.txt");

                int sum = 0;
                int delta = 0;
                int totalNeg = 0;
                auto state = initState;
                for (int i = 0; i < 200; ++i) {
                    auto[newState, neg, pos] = day12::updateState(state, setOK);
                    totalNeg += neg;
                    state = newState;
                    auto newSum = day12::getSum(state, totalNeg);
                    auto delta = newSum - sum;
                    sum = newSum;

                    std::cout << i + 1 << ": " << sum << ", " << delta << '\n';
                }
            }
        }
    }
}