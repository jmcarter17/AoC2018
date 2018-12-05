#include "day3.h"
#include <string>
#include <fstream>
#include <iostream>
#include <set>


namespace day3{

//"#123 @ 3,2: 5x4"
std::map<std::pair<int, int>, int> getMapSquares(std::string s) {

    std::map<std::pair<int, int>, int> map;
    auto pos = s.find(' ');
    auto index = std::stoi(s.substr(1,pos-1));
    s.erase(0,pos+1);
    pos = s.find(" ");
    auto pos2 = s.find(',');
    auto col = std::stoi(s.substr(pos+1,pos2 - pos - 1));
    s.erase(0,pos2+1);
    pos = s.find(':');
    auto row = std::stoi(s.substr(0,pos));
    pos2 = s.find(' ');
    s.erase(0,pos2+1);
    pos = s.find('x');
    auto numCols = std::stoi(s.substr(0,pos));
    s.erase(0,pos+1);
    auto numRows = std::stoi(s);

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