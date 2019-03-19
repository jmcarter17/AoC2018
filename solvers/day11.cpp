#include "day11.h"
#include <iostream>


namespace day11 {

int powercell(Point p, int serialNumber){
    int rackID = p.x + 10;
    int powerLevel = (rackID * p.y + serialNumber) * rackID;

    int hundredDigit = 0;
    std::string pl = std::to_string(powerLevel);
    if (pl.size() > 2)
        hundredDigit = std::stoi(pl.substr(pl.size() - 3,1));

    return hundredDigit - 5;
}

std::array<int, 300*300> gridPowercell(int serialNumber){
    std::array<int, 300*300> array{};
    for (int i = 0; i < 300; ++i){
        for (int j = 0; j < 300; ++j){
            array[j + 300*i] = powercell({i+1, j+1}, serialNumber);
        }
    }
    return array;
}

std::pair<Point, int> findBest3x3(std::array<int, 300*300>& array){
    int sum = 0;
    Point p{0, 0};
    for (int i = 0; i < 300 - 3; ++i){
        for (int j = 0; j < 300 - 3; ++j){
            auto currentSum = array[j+300*i] + array[j+1 + 300*i] + array[j+2 + 300*i] +
                              array[j + 300*(i+1)] + array[j+1 + 300*(i+1)] + array[j+2 + 300*(i+1)] +
                              array[j + 300*(i+2)] + array[j+1 + 300*(i+2)] + array[j+2 + 300*(i+2)];
            if (currentSum > sum){
                sum = currentSum;
                p = {i+1,j+1};
            }
        }
    }

    return {p, sum};
}

std::tuple<Point, int, int> findBestN(std::array<int, 300*300>& array){
    int sum = 0;
    Point p{0, 0};
    int size = 0;
    for (int k = 10; k < 17; ++k) {
        for (int i = 0; i < 300 - k; ++i) {
            for (int j = 0; j < 300 - k; ++j) {
                int currentSum = 0;
                for (int l = 0; l < k; ++l){
                    for (int m = 0; m < k; ++m){
                        currentSum += array[j + l + 300 * (i + m)];
                    }
                }
                if (currentSum > sum) {
                    sum = currentSum;
                    p = {i + 1, j + 1};
                    size = k;
                }
            }
        }
    }

    return {p, sum, size};
}

void solve(){
    auto grid = gridPowercell(8772);
    auto [p, sum] = findBest3x3(grid);
    auto [p2, sum2, size] = findBestN(grid);

    std::cout << "Day11 - Puzzle1, Point: {" << p.x << ',' << p.y << "}\n";
    std::cout << "Day11 - Puzzle1, Sum: " << sum << "\n";
    std::cout << "Day11 - Puzzle2, Point: {" << p2.x << ',' << p2.y << "}\n";
    std::cout << "Day11 - Puzzle2, Sum: " << sum2 << "\n";
    std::cout << "Day11 - Puzzle2, Size: " << size << "\n";
}

} // namespace day11

