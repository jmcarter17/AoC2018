#ifndef AOC2018_DAY3_H
#define AOC2018_DAY3_H

#include <utility>
#include <map>
#include <vector>
#include <string>

namespace day3 {

std::map<std::pair<int, int>, int> getMapSquares(std::string s);
void combineMaps(std::map<std::pair<int, int>, std::vector<int>>& combined, const std::map<std::pair<int,int>, int>& input);
size_t countOverusedSquares(std::map<std::pair<int, int>, std::vector<int>>& fabricMap);
int findGoodClaim(const std::map<std::pair<int, int>, std::vector<int>>& fabricMap, int numClaims);
void solve();

} // namespace day3

#endif //AOC2018_DAY3_H
