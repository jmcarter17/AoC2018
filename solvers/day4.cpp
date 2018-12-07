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
    for(auto& [key, val] : mapGuards) {
        auto currentSum = std::accumulate(val.begin(), val.end(), 0,
                [] (int value, const std::map<int, int>::value_type& p)
                    { return value + p.second; });
        if (currentSum > sum){
            sum = currentSum;
            result = key;
        }
    }
    return result;
}

std::pair<std::string, int> findGuardConsistentAsleep(std::map<std::string, std::map<int, int>>& mapGuards){
    auto most = 0;
    auto minute = 0;
    std::string result;
    for(auto& [key, val] : mapGuards) {
        auto current = std::max_element(val.begin(), val.end(),
                                           [](const std::pair<int, int>& p1, const std::pair<int, int>& p2) { return p1.second < p2.second;}
        );
        if (current->second > most){
            most = current->second;
            minute = current->first;
            result = key;
        }
    }
    return {result, minute};
};

//"1518-05-08 00:02"
int getMinuteFromKey(std::string s){
    auto pos = s.find(':');
    s.erase(0,pos+1);
    return std::stoi(s);
}

std::map<std::string, std::map<int, int>> getHoursOfSleep(std::map<std::string, std::string>& sortedInfo){
    std::map<std::string, std::map<int, int>> hoursAsleep;

    std::string guard;
    int minFall{};
    int minWakes{};
    bool isAsleep = false;
    for (auto& [key, value] : sortedInfo)
    {
        if (value[0] == '#') {
            if (isAsleep){
                auto end = getMinuteFromKey(key);
                for (int i = minFall; i < end; i++){
                    hoursAsleep[guard][i]++;
                }
            }
            guard = value;
            isAsleep = false;
        }
        else if (value == "f"){
            minFall = getMinuteFromKey(key);
            isAsleep = true;
        }
        else if (value == "w"){
            isAsleep = false;
            minWakes = getMinuteFromKey(key);
            for (int i = minFall; i < minWakes; i++){
                hoursAsleep[guard][i]++;
            }
        }
    }

    return hoursAsleep;
};

void solve(){
    std::ifstream file("../input/input-4.txt", std::ios::in);
    assert(file.is_open());
    std::string line;

    std::map<std::string, std::string> sortedInfo;

    while (std::getline(file, line)) {
        auto parsedLine = parseline(line);
        sortedInfo[parsedLine[0]] = parsedLine[1];
    }

    auto hoursAsleep = getHoursOfSleep(sortedInfo);

    auto goodGuard = findGuardMostAsleep(hoursAsleep);
    auto goodGuardMap = hoursAsleep[goodGuard];
    auto goodMinute = std::max_element(goodGuardMap.begin(), goodGuardMap.end(),
           [](const std::pair<int, int>& p1, const std::pair<int, int>& p2) { return p1.second < p2.second;}
       )->first;
    auto goodGuardInt = std::stoi(goodGuard.substr(1,goodGuard.size()));

    std::cout << "Day4 - Good Guard : " << goodGuard << '\n';
    std::cout << "Day4 - Best Minute : " << goodMinute << '\n';
    std::cout << "Day4 - Puzzle1 : " << goodMinute * goodGuardInt << '\n';

    auto consistentGuard = findGuardConsistentAsleep(hoursAsleep);
    std::cout << "Day4 - Consistent Guard : " << consistentGuard.first << '\n';
    std::cout << "Day4 - Consistent Minute : " << consistentGuard.second << '\n';
    auto guardInt = std::stoi(consistentGuard.first.substr(1,consistentGuard.first.size()));
    std::cout << "Day4 - Puzzle2 : " << guardInt * consistentGuard.second << '\n';
}


} // namespace day4