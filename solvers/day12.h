#ifndef AOC2018_DAY12_H
#define AOC2018_DAY12_H

#include <string>
#include <unordered_set>

namespace day12{

bool nextGen(const std::unordered_set<std::string>& setOK, const std::string& s);
std::string parseFirstLine(std::string s);
void parseline(std::unordered_set<std::string>& setOK, const std::string& s);
std::pair<std::string, std::unordered_set<std::string>> parseInput(std::string filename);
std::tuple<std::string, int, int> updateState(std::string state, const std::unordered_set<std::string>& setOK);
std::tuple<std::string, int, int> updateNGeneration(std::string state, const std::unordered_set<std::string>& setOK, const int numGen);
int getSum(const std::string& state, int neg);

void solve();

} // namespace day12

#endif //AOC2018_DAY12_H
