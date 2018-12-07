#include "iostream"
#include "solvers/day1.h"
#include "solvers/day2.h"
#include "solvers/day3.h"
#include "solvers/day4.h"
#include "solvers/day5.h"
#include <chrono>

using namespace std::chrono;

template<typename F, typename ...Args>
auto timeCallVoid(F f, Args ... args){

    auto pre = high_resolution_clock::now();
    f(std::forward<Args>(args)...);
    auto post = high_resolution_clock::now();

    return post - pre;
};


template<typename T>
void outputDuration(T d) {
    std::cout << "Duration : " << duration_cast<milliseconds>(d).count() << "ms\n";
}

int main(){
    outputDuration(timeCallVoid(day1::solve));
    outputDuration(timeCallVoid(day2::solve));
    outputDuration(timeCallVoid(day3::solve));
    outputDuration(timeCallVoid(day4::solve));
    outputDuration(timeCallVoid(day5::solve));

}