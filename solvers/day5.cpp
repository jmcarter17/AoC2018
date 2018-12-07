#include <cctype>
#include <string>
#include "day5.h"
#include <fstream>
#include <iostream>


namespace day5{

bool checkCompatible(const char c1, const char c2){
    return c1 != c2 and (toupper(c1) == c2 or toupper(c2) == c1);
}

std::string foldPolymer(std::string s){
    for(auto it = s.begin(); it != s.end(); it++){
        while (it != s.end() and checkCompatible(*it, *next(it))){
            it = s.erase(it);
            it = s.erase(it);
            if (it != s.begin())
                it = prev(it);
        }
    }
    return s;
}

std::string removeAndFold(std::string s, unsigned char toremove){
    unsigned char test = std::tolower(toremove);
    s.erase(std::remove_if(s.begin(), s.end(), [test](unsigned char c){
        return test == tolower(c);
    }), s.end());

    return foldPolymer(s);
}

void solve(){
    std::ifstream file("../input/input-5.txt", std::ios::in);
    assert(file.is_open());
    std::string line;
    std::getline(file, line);

    auto polymer = foldPolymer(line);

    std::cout << "Day5 - Puzzle1 : Size of Polymer = " << polymer.size() << '\n';

    std::string_view sv{"abcdefghijklmnopqrstuvwxyz"};

    size_t smallest = polymer.size();

    for (auto c : sv){
        auto str = removeAndFold(line, c);
        if (str.size() < smallest)
        {
            smallest = str.size();
        }
    }

    std::cout << "Day5 - Puzzle2 : Size of Smallest Polymer = " << smallest << '\n';

}

}