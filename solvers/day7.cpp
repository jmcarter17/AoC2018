#include <string>
#include "day7.h"
#include <vector>
#include <fstream>
#include <set>
#include <iostream>

namespace day7{

std::pair<char, char> parseline(std::string s) {
    return {s[5], s[36]};
};

std::vector<std::pair<char, char>> parsefile(std::string s){
    std::ifstream file(s, std::ios::in);
    assert(file.is_open());
    std::string line;

    std::vector<std::pair<char, char>> parsedInfo;

    while (std::getline(file, line)) {
        parsedInfo.emplace_back(parseline(line));
    }
    return parsedInfo;
};

std::map<char, std::vector<char>> organizeInfo (std::vector<std::pair<char, char>>& vec){
    std::map<char, std::vector<char>> map;
    for(std::pair<char, char> chars : vec){
        map[chars.first];
        map[chars.second].push_back(chars.first);
    }

    return map;
};

char findNextChar(std::map<char, std::vector<char>>& info) {
    for (auto& [key, val] : info){
        if (val.size() == 0)
            return key;
    }
    return '-';
}

void removeChar(std::map<char, std::vector<char>>& info, char toremove){
    for (auto&[key, val] : info) {
        val.erase(std::remove_if(val.begin(), val.end(), [toremove](char c) { return toremove == c; }), val.end());
    }
}

std::string getStepOrder(std::map<char, std::vector<char>> info) {
    std::string s;

    while (info.size()) {
        auto nextChar = findNextChar(info);
        info.erase(nextChar);
        removeChar(info, nextChar);
        s.push_back(nextChar);
    }

    return s;
}

int timeForChar(char c){
    return 61 + c - 'A';
}

std::pair<std::string, int> getStepOrderAndTime(std::map<char, std::vector<char>> info, const int numberHelpers){
    int remainingHelpers = numberHelpers;
    std::map<char, int> processing;
    std::string s;
    int totalTime = 0;

    while (!info.empty()){
        auto nextChar = findNextChar(info);
        while (remainingHelpers > 0 and nextChar != '-') {
            info.erase(nextChar);
            processing[nextChar] = timeForChar(nextChar);
            s.push_back(nextChar);
            --remainingHelpers;
            nextChar = findNextChar(info);
        }

        auto it = std::min_element(processing.begin(), processing.end(),
                                   [](const std::pair<char, int> &p1, const std::pair<char, int> &p2) {
                                       return p1.second < p2.second;
                                   });

        removeChar(info, (*it).first);
        auto timeToRemove = (*it).second;
        totalTime += timeToRemove;
        processing.erase(it);
        for (auto& pair : processing){
            pair.second -=  timeToRemove;
        }
        ++remainingHelpers;

    }

    return {s, totalTime};
}

void solve() {
    auto parsedInfo = parsefile("../input/input-7.txt");
    auto info = organizeInfo(parsedInfo);

    auto stepOrder = getStepOrder(info);
    auto time = getStepOrderAndTime(info, 5);

    std::cout << "Day7 - Puzzle1: " << stepOrder << '\n';
    std::cout << "Day7 - Puzzle2 Order: " << time.first << '\n';
    std::cout << "Day7 - Puzzle2 Time: " << time.second << '\n';
}

} //namespace day7