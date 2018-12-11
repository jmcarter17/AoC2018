#ifndef AOC2018_DAY6_H
#define AOC2018_DAY6_H

#include <set>
#include <string>
#include <map>
#include <vector>

namespace day6{

    struct Point{
        int x;
        int y;

        bool operator==(const Point& other) const noexcept {
            return x == other.x and y == other.y;
        }

        bool operator<(const Point& other) const noexcept {
            if ( x < other.x )
                return true;
            if ( other.x < x )
                return false;
            if (y < other.y)
                return true;
            return false;

        }

        int distance(const Point& other) const noexcept {
            return abs(x - other.x) + abs(y - other.y);
        }
    };

    std::set<Point> getGridPointsFromFile(std::string filename);
    Point parseline(std::string line);
    std::map<Point, std::vector<Point>> getGrid(const std::set<Point>& points);

    void solve();

} // namespace day6

#endif //AOC2018_DAY6_H
