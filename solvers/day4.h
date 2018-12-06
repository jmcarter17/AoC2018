#ifndef AOC2018_DAY4_H
#define AOC2018_DAY4_H

#include <string>
#include <vector>
#include <map>

namespace day4{
    std::vector<std::string> parseline(std::string s);
    int getMinuteFromKey(std::string);
    std::string findGuardMostAsleep(std::map<std::string, std::map<int, int>>& mapGuards);
    std::pair<std::string, int> findGuardConsistentAsleep(std::map<std::string, std::map<int, int>>& mapGuards);
    std::map<std::string, std::map<int, int>> getHoursOfSleep(std::map<std::string, std::string>& sortedInfo);

    void solve();
}

#endif //AOC2018_DAY4_H
