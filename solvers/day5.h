#ifndef AOC2018_DAY5_H
#define AOC2018_DAY5_H

#include <string>

namespace day5{

bool checkCompatible(const char c1, const char c2);

std::string foldPolymer(std::string s);
std::string removeAndFold(std::string s, unsigned char toremove);

void solve();

}

#endif //AOC2018_DAY5_H
