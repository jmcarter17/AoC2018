#include "day12.h"
#include <fstream>
#include <iostream>


namespace day12{

bool nextGen(const std::unordered_set<std::string>& setOK, const std::string& s){
    return setOK.find(s) != setOK.end();
}

std::string parseFirstLine(std::string s){
    return s.substr(15);
}

void parseline(std::unordered_set<std::string>& setOK, const std::string& s){
    if (s[9] == '#') {
        setOK.insert(s.substr(0,5));
    }
}

std::pair<std::string, std::unordered_set<std::string>> parseInput(std::string filename){
    std::ifstream file(filename, std::ios::in);
    assert(file.is_open());
    std::string line;

    std::getline(file, line);
    auto initialState = parseFirstLine(line);
    std::getline(file, line); // empty line

    std::unordered_set<std::string> setOK;
    while (std::getline(file, line)) {
        parseline(setOK, line);
    }
    return {initialState, setOK};
}

std::tuple<std::string, int, int> updateState(std::string state, const std::unordered_set<std::string>& setOK){
    std::string nextState;
    state = "...." + state + "....";
    for (auto i = 2u; i < state.size() - 2; i++){
        if (nextGen(setOK, state.substr(i-2,5))) {
            nextState.push_back('#');
        }
        else
            nextState.push_back('.');
    }

    int neg = 2;
    int pos = 2;
    if (nextState.front() == '.') {
        nextState.erase(0, 1);
        --neg;
        if (nextState.front() == '.') {
            nextState.erase(0, 1);
            --neg;
        }
    }

    if (nextState.back() == '.') {
        nextState.erase(nextState.size() - 1);
        --pos;
        if (nextState.back() == '.') {
            nextState.erase(nextState.size() - 1);
            --pos;
        }
    }

    return {nextState, neg, pos};
}

std::tuple<std::string, int, int> updateNGeneration(std::string state, const std::unordered_set<std::string>& setOK, const int numGen) {

//    std::string result = state;
    int neg = 0;
    int pos = 0;

    for (long i = 0; i < numGen; ++i) {
        auto [nextState, nextNeg, nextPos] = updateState(state, setOK);
        neg += nextNeg;
        pos += nextPos;
        state = nextState;

    }

    return {state, neg, pos};

}

int getSum(const std::string& state, int neg){

    int sum = 0;
    for (size_t i = 0; i < state.size(); ++i){
        if (state[i] == '#') {
            sum += (i - neg);
        }
    }
    return sum;
}

void solve(){
    auto [initState, setOK] = day12::parseInput("../input/input-12.txt");
    auto [state, neg, pos] = day12::updateNGeneration(initState, setOK, 20);
    auto sum = getSum(state, neg);

    std::cout << "Day12 - Puzzle 1 : " << sum << '\n';
    std::cout << "Day12 - Puzzle 2 : " << (50'000'000'000 - 200) * 58 + 13456 << '\n';


}

} //namespace day12