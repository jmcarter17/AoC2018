#ifndef AOC2018_DAY9_H
#define AOC2018_DAY9_H

#include <map>
#include <vector>

namespace day9{

using integer = unsigned int;

std::map<integer, integer> scores(integer numPlayers, integer lastMarbleValue);

integer getLargestScore(std::map<integer, integer>& scores);

void solve();

} // namespace day9

#endif //AOC2018_DAY9_H
