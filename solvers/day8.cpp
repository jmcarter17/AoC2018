#include "day8.h"
#include <fstream>
#include <iostream>

namespace day8{

std::unique_ptr<Node> parsefile(std::string filename){
    auto node = std::make_unique<Node>();
    std::ifstream file(filename, std::ios::in);
    assert(file.is_open());


    bool headerToParse = true;
    Node* currentNode = node.get();
    while (!file.eof() and currentNode){

        if (headerToParse){
            file >> currentNode->header.numChildren >> currentNode->header.numMetaData;
            headerToParse = false;
        }
        else if (currentNode->header.numChildren > currentNode->children.size()){
            currentNode = &currentNode->children.emplace_back(currentNode);
            headerToParse = true;
        }
        else {
            int value;
            while (currentNode->header.numMetaData > currentNode->metadata.size()) {
                file >> value;
                currentNode->metadata.push_back(value);
            }
            currentNode = currentNode->parentNode;
        }
    }

    return node;
}

void solve(){
    auto root = parsefile("../input/input-8.txt");
    auto sum = root->sumMetaData();
    auto value = root->value();

    std::cout << "Day8 - Puzzle1 : " << sum << '\n';
    std::cout << "Day8 - Puzzle2 : " << value << '\n';

}

} //namespace day8