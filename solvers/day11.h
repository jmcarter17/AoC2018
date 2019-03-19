
#ifndef AOC2018_DAY11_H
#define AOC2018_DAY11_H

#include "day6.h"
#include <string>
#include <array>

using Point = day6::Point;

namespace day11{

int powercell(Point p, int serialNumber);

std::array<int, 300*300> gridPowercell(int serialNumber);

std::pair<Point, int> findBest3x3(std::array<int, 300*300>& array);
std::tuple<Point, int, int> findBestN(std::array<int, 300*300>& array);

void solve();

} //namespace day11


#endif //AOC2018_DAY11_H
