#ifndef AOC2018_DAY9_H
#define AOC2018_DAY9_H

#include <map>
#include <vector>

namespace day9{

std::map<int, std::vector<int>> scores(int numPlayers, int lastMarbleValue);

int getLargestScore(std::map<int, std::vector<int>>& scores);

void solve();

} // namespace day9

#endif //AOC2018_DAY9_H
