#include "day2.h"
#include <map>
#include <fstream>
#include <iostream>
#include <vector>

namespace day2 {


std::pair<bool, bool> check2And3(const std::map<char, int> &map) {
    bool has2 = false;
    bool has3 = false;
    for (auto&[_, val] : map) {
        if (val == 2) {
            has2 = true;
            if (has3) break;
        } else if (val == 3) {
            has3 = true;
            if (has2) break;
        }
    }
    return {has2, has3};
}

std::map<char, int> getMap(std::string_view sv) {
    std::map<char, int> map;
    for (auto &c : sv) {
        map[c] += 1;
    }

    return map;
}

std::pair<bool, bool> counts(std::string_view sv) {
    auto map = getMap(sv);
    return check2And3(map);
}

std::vector<size_t> diffIndices(std::string_view sv1, std::string_view sv2){
    std::vector<size_t> v;
    for (size_t i = 0; i < sv1.size(); ++i){
        if (sv1[i] != sv2[i])
            v.push_back(i);
    }

    return v;
}

void solve() {
    std::ifstream file("../input/input-2.txt", std::ios::in);
    assert(file.is_open());
    std::string line;
    std::vector<std::string> vecString;

    int twos = 0;
    int threes = 0;
    while (std::getline(file, line)) {
        vecString.push_back(line);
        auto [has2, has3] = counts(line);
        if (has2) ++twos;
        if (has3) ++threes;
    }

    std::cout << "Day2 - CheckSum (twos times threes) : " << twos * threes << '\n';

    std::vector<size_t> indices;
    auto itResult = vecString.end();

    for (auto it = vecString.begin(); it != vecString.end(); ++it){
        for (auto it2 = next(it); it2 != vecString.end(); ++it2){
            indices = diffIndices(*it, *it2);
            if (indices.size() == 1)
            {
                itResult = it;
                it = std::prev(vecString.end());
                it2 = std::prev(vecString.end());
            }
        }
    }

    std::string s = *itResult;
    s.erase(indices.front(),1);
    std::cout << "Day2 - ID is : " << s << '\n';
}

} // namespace day2