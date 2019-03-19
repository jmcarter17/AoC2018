#include "iostream"
#include "solvers/day1.h"
#include "solvers/day2.h"
#include "solvers/day3.h"
#include "solvers/day4.h"
#include "solvers/day5.h"
#include "solvers/day6.h"
#include "solvers/day7.h"
#include "solvers/day8.h"
#include "solvers/day9.h"
#include "solvers/day11.h"
#include "solvers/day12.h"
#include <chrono>

using namespace std::chrono;

template<typename F, typename ...Args>
auto timeCallVoid(F f, Args ... args){

    auto pre = high_resolution_clock::now();
    f(std::forward<Args>(args)...);
    auto post = high_resolution_clock::now();

    return post - pre;
};

int main(){
    std::vector<std::pair<int, decltype(high_resolution_clock::now() - high_resolution_clock::now())>> v;

    v.emplace_back(1, timeCallVoid(day1::solve));
    v.emplace_back(2, timeCallVoid(day2::solve));
    v.emplace_back(3, timeCallVoid(day3::solve));
    v.emplace_back(4, timeCallVoid(day4::solve));
    v.emplace_back(5, timeCallVoid(day5::solve));
    v.emplace_back(6, timeCallVoid(day6::solve));
    v.emplace_back(7, timeCallVoid(day7::solve));
    v.emplace_back(8, timeCallVoid(day8::solve));
    v.emplace_back(9, timeCallVoid(day9::solve));
    v.emplace_back(11, timeCallVoid(day11::solve));
    v.emplace_back(12, timeCallVoid(day12::solve));

    std::cout << "DURATIONS (ms)\n";
    for (auto &i : v) {
        std::cout << "Day " << i.first << ": " << duration_cast<milliseconds>(i.second).count() << '\n';
    }

}