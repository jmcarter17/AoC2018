#include "catch2/catch.hpp"
#include "day8.h"


#include <fstream>

TEST_CASE("Day8") {
    SECTION("parsefile") {
        auto info = day8::parsefile("../../input/test-input-8.txt");

        CHECK(info->header.numChildren == 2);
        CHECK(info->children.size() == 2);
        CHECK(info->header.numMetaData == 3);
        CHECK(info->metadata == std::vector{1,1,2});
        CHECK(info->children[0].header.numChildren == 0);
        CHECK(info->children[0].header.numMetaData == 3);
        CHECK(info->children[0].metadata == std::vector{10, 11, 12});
        CHECK(info->children[1].header.numChildren == 1);
        CHECK(info->children[1].header.numMetaData == 1);
        CHECK(info->children[1].metadata == std::vector{2});
        CHECK(info->children[1].children[0].header.numChildren == 0);
        CHECK(info->children[1].children[0].header.numMetaData == 1);
        CHECK(info->children[1].children[0].metadata == std::vector{99});

        CHECK(info->sumMetaData() == 138);
    }

    SECTION("Value Of Node"){
        auto root = day8::parsefile("../../input/test-input-8.txt");
        auto A = root.get();
        auto B = &root->children[0];
        auto C = &root->children[1];
        auto D = &C->children[0];

        CHECK(B->value() == 33);
        CHECK(C->value() == 0);
        CHECK(D->value() == 99);
        CHECK(A->value() == 66);
    }
}