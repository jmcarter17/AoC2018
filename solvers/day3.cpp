#include "day3.h"
#include <string>
#include <fstream>
#include <iostream>
#include <set>
#include <boost/algorithm/string.hpp>


namespace day3{

//"#123 @ 3,2: 5x4"
std::map<std::pair<int, int>, int> getMapSquares(std::string s) {

    namespace algo = boost::algorithm;

    s.erase(0,1); // remove begining #
    std::vector<std::string> tokens;
    algo::split(tokens, s, algo::is_any_of("@,:x "), algo::token_compress_on);

    auto index = std::stoi(tokens[0]);
    auto col = std::stoi(tokens[1]);
    auto row = std::stoi(tokens[2]);
    auto numCols = std::stoi(tokens[3]);
    auto numRows = std::stoi(tokens[4]);

    std::map<std::pair<int, int>, int> map;

    for (int i = col; i < numCols + col; i++) {
        for (int j = row; j < numRows + row; j++)
            map[{i,j}] = index;
    }
    return map;
}

void combineMaps(std::map<std::pair<int, int>, std::vector<int>>& combined, const std::map<std::pair<int,int>, int>& input){
    for(auto& [key, val] : input){
        combined[key].push_back(val);
    }
}

size_t countOverusedSquares(std::map<std::pair<int, int>, std::vector<int>>& fabricMap){
    size_t count = 0;
    for (const auto& [key, val] : fabricMap) {
        if (val.size() > 1)
            count++;
    }

    return count;
}

int findGoodClaim(const std::map<std::pair<int, int>, std::vector<int>>& fabricMap, int numClaims){
    std::set<int> claims;
    for (int i = 1; i <= numClaims; ++i){
        claims.insert(i);
    }

    for (auto& [key, val] : fabricMap){
        if (val.size() > 1) {
            for (auto &e : val) {
                claims.erase(e);
            }
        }
    }

    return *claims.begin();

}

void solve(){
    std::ifstream file("../input/input-3.txt", std::ios::in);
    assert(file.is_open());
    std::string line;

    std::map<std::pair<int, int>, std::vector<int>> fabricMap;

    while (std::getline(file, line)) {
        auto claim = getMapSquares(line);
        combineMaps(fabricMap, claim);
    }

    std::cout << "Day3 - Number of Overused Square Inch of Fabric : " << countOverusedSquares(fabricMap) << '\n';
    std::cout << "Day3 - Good Claim : " << findGoodClaim(fabricMap, 1381) << '\n';
}

} // namespace day3