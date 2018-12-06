#include "day4.h"
#include <boost/algorithm/string.hpp>
#include <fstream>
#include <numeric>
#include <algorithm>
#include <iostream>


namespace day4 {

std::vector<std::string> parseline(std::string s){
    namespace algo = boost::algorithm;

    s.erase(0,1); // remove first '[' character
    std::vector<std::string> tokens;
    algo::split(tokens, s, algo::is_any_of("]"), algo::token_compress_on);

    algo::trim(tokens[1]);
    char c = tokens[1][0];
    if (c == 'w')
        tokens[1] = "w";
    else if (c == 'f')
        tokens[1] = "f";
    else if (c == 'G')
    {
        auto pos = tokens[1].find('#');
        tokens[1].erase(0,pos);
        pos = tokens[1].find(' ');
        tokens[1].erase(pos);
    }

    return tokens;
}

std::string findGuardMostAsleep(std::map<std::string, std::map<int, int>>& mapGuards){
    auto sum = 0;
    std::string result;
    for(auto& [key, array] : mapGuards){
        auto currentSum = std::accumulate(array.begin(), array.end(), 0,
            [] (int value, const std::map<int, int>::value_type& p)
               { return value + p.second; });
        if (currentSum > sum)
            result = key;
    }

    return result;
}

//"1518-05-08 00:02"
int getMinuteFromKey(std::string s){
    auto pos = s.find(':');
    s.erase(0,pos+1);
    return std::stoi(s);
}

void solve(){
    std::ifstream file("../input/input-4.txt", std::ios::in);
    assert(file.is_open());
    std::string line;

    std::map<std::string, std::string> sortedInfo;

    while (std::getline(file, line)) {
        auto parsedLine = parseline(line);
        sortedInfo[parsedLine[0]] = parsedLine[1];
    }

    std::map<std::string, std::map<int, int>> hoursAsleep;

    std::string guard;
    int minFall{};
    int minWakes{};
    for (auto& [key, value] : sortedInfo)
    {
        if (value[0] == '#') {
            guard = value;
        }
        else if (value == "f"){
            minFall = getMinuteFromKey(key);
        }
        else if (value == "w"){
            minWakes = getMinuteFromKey(key);
            for (int i = minFall; i != minWakes; i = (i+1)%60){
                hoursAsleep[guard][i]++;
            }
        }
    }

    auto goodGuard = findGuardMostAsleep(hoursAsleep);
    auto goodMinuteIt = std::max_element(hoursAsleep[goodGuard].begin(), hoursAsleep[goodGuard].end());
    auto goodMinute = std::distance(hoursAsleep[goodGuard].begin(), goodMinuteIt);
    auto goodGuardInt = std::stoi(goodGuard.erase(0,1));

    std::cout << "Day4 - Good Guard : " << goodGuard << '\n';
    std::cout << "Day4 - Best Minute : " << goodMinute << '\n';
    std::cout << "Day4 - Puzzle1 : " << goodMinute * goodGuardInt << '\n';


}


} // namespace day4