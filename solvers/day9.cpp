#include "day9.h"
#include <iostream>
#include <numeric>
#include <list>


namespace day9{


std::map<integer, integer> scores(integer numPlayers, integer lastMarbleValue){
    std::map<integer, integer> scores;
    std::list<integer> game;
    game.push_back(0);

    integer currentPlayer = 1;
    auto currentMarble = game.begin();
    for (integer i = 1; i <= lastMarbleValue; ++i){
        if (i % 23 == 0){
            scores[currentPlayer] += i;
            for (int j = 0; j < 6; ++j) {
                currentMarble--;
                if (currentMarble == game.begin())
                    currentMarble = game.end();
            }
            scores[currentPlayer] += (*(--currentMarble));
            currentMarble = game.erase(currentMarble);
        }
        else{
            currentMarble++;
            if (currentMarble == game.end()){
                currentMarble = game.begin();
            }

            currentMarble = game.insert(++currentMarble, i);

        }

        currentPlayer++;
        if (currentPlayer > numPlayers)
            currentPlayer = 1;
    }

    return scores;
}

integer getLargestScore(std::map<integer, integer>& scores) {
    integer largestScore = 0;
    for (auto& [key, val] : scores){
        if (val > largestScore)
            largestScore = val;
    }

    return largestScore;
}

void solve(){
    // 463 players; last marble is worth 71787 points

    auto gameScores = scores(463, 71787);
    auto largest = getLargestScore(gameScores);

    std::cout << "Day 9 - Puzzle 1 : " << largest << '\n';

    gameScores = scores(463, 7178700);
    largest = getLargestScore(gameScores);

    std::cout << "Day 9 - Puzzle 2 : " << largest << '\n';
}

}