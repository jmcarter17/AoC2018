
#ifndef AOC2018_DAY2_H
#define AOC2018_DAY2_H

#include <string_view>

namespace day2 {

void solve();
std::pair<bool, bool> counts(std::string_view sv);
std::vector<size_t> diffIndices(std::string_view sv1, std::string_view sv2);

} // namespace day2

#endif //AOC2018_DAY2_H
