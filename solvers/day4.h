#ifndef AOC2018_DAY4_H
#define AOC2018_DAY4_H

#include <string>
#include <vector>
#include <map>

namespace day4{
    std::vector<std::string> parseline(std::string s);
    int getMinuteFromKey(std::string);
    std::string findGuardMostAsleep(std::map<std::string, std::array<int,60>>& mapGuards);

    void solve();
}

#endif //AOC2018_DAY4_H
