#ifndef AOC2018_DAY7_H
#define AOC2018_DAY7_H

#include <map>
#include <set>

namespace day7{

std::pair<char, char> parseline(std::string s);
std::vector<std::pair<char, char>> parsefile(std::string s);
std::map<char, std::vector<char>> organizeInfo (std::vector<std::pair<char, char>>& vec);
char findNextChar(std::map<char, std::vector<char>>& info);
void removeChar(std::map<char, std::vector<char>>& info, char toremove);
std::string getStepOrder(std::map<char, std::vector<char>> info);
int timeForChar(char c);
std::pair<std::string, int> getStepOrderAndTime(std::map<char, std::vector<char>> info, const int numberHelpers);

void solve();

} //namespace day7

#endif //AOC2018_DAY7_H
