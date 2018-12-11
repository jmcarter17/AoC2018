#include "day1.h"
#include <fstream>
#include <numeric>
#include <string>
#include <iostream>
#include <set>

namespace day1{

void parseInput(std::vector<int> &v) {
    std::ifstream file("../input/input-1.txt", std::ios::in);
    assert(file.is_open());
    std::string line;

    while (std::getline(file, line)) {
        int val = std::stoi(line);

        v.push_back(val);
    }
}

int sum(std::vector<int>& v) {
    return std::accumulate(std::begin(v), std::end(v), 0);
}


void solve() {
    std::vector<int> v;

    parseInput(v);
    std::cout << "Day1 - Puzzle 1: Resulting Frequency : " << sum(v) << '\n';
    std::cout << "Day1 - Puzzle 2: Repeated Frequency : " << repeatedFrequency(v) << '\n';
}

int repeatedFrequency(std::vector<int>& v){
    std::set<int> partialSums;
    int partialSum = 0;
    partialSums.insert(partialSum);
    bool good = true;
    while (good) {
        for(int i = 0; i < v.size(); ++i) {
            partialSum += v[i];
            auto[_, ok] = partialSums.insert(partialSum);
            if (!ok) {
                good = false;
                break;
            }
        }
    }

    return partialSum;
}

} // namespace day1

