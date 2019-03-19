
#include "day6.h"
#include <fstream>
#include <iostream>
#include <numeric>

namespace day6{

Point parseline(std::string line){
    auto pos = line.find(',');
    Point p;
    p.x = std::stoi(line.substr(0,pos));
    p.y = std::stoi(line.substr(pos+2));

    return p;
}

std::set<Point> getGridPointsFromFile(std::string filename){
    std::ifstream file(filename, std::ios::in);
    assert(file.is_open());
    std::string line;

    std::set<Point> gridPoints;

    while (std::getline(file, line)) {
        gridPoints.insert(parseline(line));
    }
    return gridPoints;
}

std::pair<int, std::map<Point, std::vector<Point>>> getGrid(const std::set<Point>& points, int maxDistance){
    std::map<Point, std::vector<Point>> grid;
    int xmin = (*points.begin()).x;
    int xmax = (*--points.end()).x;
    int ymin = 1000;
    int ymax = 0;
    grid[{-1,-1}];
    for (auto p : points){
        grid[p];
        if (p.y > ymax)
            ymax = p.y;
        if (p.y < ymin)
            ymin = p.y;
    }

    int sizeRegion = 0;

    for (int i = xmin; i <= xmax; ++i) {
        for (int j = ymin; j <= ymax; ++j){
            Point current{i,j};
            std::map<int, std::vector<Point>> distances;
            int sum = 0;
            for (auto& p : points){
                auto d = p.distance(current);
                distances[d].push_back(p);
                sum += d;
            }
            if (sum < maxDistance)
                sizeRegion++;

            if ((*distances.begin()).second.size() > 1)
                grid[{-1,-1}].push_back(current);
            else
                grid[(*distances.begin()).second.front()].push_back(current);
        }
    }

    grid.erase({-1, -1});

    for (auto& [key, val] : grid) {
        for (auto& p : val) {
            if (p.x == xmin or p.x == xmax or p.y == ymin or p.y == ymax){
                grid[key].clear();
                break;
            }
        }
    }

    return {sizeRegion, grid};
};

void solve(){
    auto gridPoints = day6::getGridPointsFromFile("../input/input-6.txt");
    auto [regionSize, grid] = day6::getGrid(gridPoints, 10000);

    auto p = (*grid.begin()).first;
    size_t max = 0;
    for (auto& [key, val] : grid){
        if (val.size() > max){
            max = val.size();
            p = key;
        }
    }

    std::cout << "Day6 - Point : [" << p.x << "," << p.y << "]\n";
    std::cout << "Day6 - Puzzle 1 : " << max << '\n';
    std::cout << "Day6 - Puzzle 2 : Region size : " << regionSize << '\n';
}


} // namespace day6