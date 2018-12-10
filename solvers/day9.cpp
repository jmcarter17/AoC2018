#include "day9.h"
#include <iostream>
#include <numeric>


namespace day9{


std::map<int, std::vector<int>> scores(int numPlayers, int lastMarbleValue){
    std::map<int, std::vector<int>> scores;
    std::vector<int> game;
    game.reserve(static_cast<unsigned>(lastMarbleValue));
    game.push_back(0);

    int currentPlayer = 1;
    auto currentMarble = game.begin();
    for (auto i = 1; i <= lastMarbleValue; ++i){
        if (i % 23 == 0){
            scores[currentPlayer].push_back(i);
            for (int i = 0; i < 6; ++i) {
                currentMarble--;
                if (currentMarble == game.begin())
                    currentMarble = game.end();
            }
            scores[currentPlayer].push_back(*(--currentMarble));
            currentMarble = game.erase(currentMarble);
        }
        else{
            currentMarble++;
            if (currentMarble == game.end()){
                currentMarble = game.begin();
            }

            game.insert(++currentMarble, i);

        }

        currentPlayer++;
        if (currentPlayer > numPlayers)
            currentPlayer = 1;
    }

    return scores;
}

int getLargestScore(std::map<int, std::vector<int>>& scores) {
    int largestScore = 0;
    for (auto& [key, val] : scores){
        auto currentScore = std::accumulate(val.begin(), val.end(), 0);
        if (currentScore > largestScore)
            largestScore = currentScore;
    }

    return largestScore;
}

void solve(){
    // 463 players; last marble is worth 71787 points

    auto gameScores = scores(463, 71787);
    auto largest = getLargestScore(gameScores);

    std::cout << "Day 9 - Puzzle 1 : " << largest << '\n';

//    gameScores = scores(463, 7178700);
//    largest = getLargestScore(gameScores);
//
//    std::cout << "Day 9 - Puzzle 2 : " << largest << '\n';
}

}