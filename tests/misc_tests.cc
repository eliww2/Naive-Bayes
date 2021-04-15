#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <catch2/catch.hpp>

#include <core/Probabilities.h>
#include <core/Parser.h>
#include <core/NaiveModel.h>
#include <iostream>
#include <fstream>

namespace naivebayes {

TEST_CASE("Misc testing") {
    NaiveModel model;
    std::ifstream file("data/testingImages.txt");
    file >> model;
}
}