#ifndef AOC2018_DAY8_H
#define AOC2018_DAY8_H

#include <vector>
#include <string>
#include <memory>
#include <numeric>

namespace day8{

struct Header{
    int numChildren;
    int numMetaData;
};

struct Node{
    Header header;
    std::vector<Node> children;
    std::vector<int> metadata;
    Node* parentNode = nullptr;

    Node() = default;
    Node(Node* parent) {
        parentNode = parent;
    }

    int sumMetaData(){
        auto sum = std::accumulate(metadata.begin(), metadata.end(), 0);
        for (auto& n : children){
            sum += n.sumMetaData();
        }

        return sum;
    }

    int value(){
        if (children.empty())
            return std::accumulate(metadata.begin(), metadata.end(), 0);
        else {
            int sum = 0;
            for (auto data : metadata){
                if (data <= children.size()){
                    sum += children[data - 1].value();
                }
            }
            return sum;
        }
    }
};

std::unique_ptr<Node> parsefile(std::string filename);
void solve();

} //namespace day8

#endif //AOC2018_DAY8_H
