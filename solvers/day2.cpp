#include "day2.h"
#include <map>

namespace day2 {


std::pair<bool, bool> check2And3(const std::map<char, int>& map){
    bool has2 = false;
    bool has3 = false;
    for(auto& [_, val] : map){
        if (val == 2) {
            has2 = true;
            if (has3) break;
        }
        else if (val == 3) {
            has3 = true;
            if (has2) break;
        }
    }
    return {has2, has3};
}

std::map<char, int> getMap(std::string_view sv)
{
    std::map<char, int> map;
    for (auto& c : sv)
    {
        map[c] += 1;
    }

    return map;
};

std::pair<bool, bool> counts(std::string_view sv){
    auto map = getMap(sv);
    return check2And3(map);


};


}