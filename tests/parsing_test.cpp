//
// Created by eliww on 4/6/2021.
//
#include <catch2/catch.hpp>

#include <core/Probabilities.h>
#include <core/Parser.h>
#include <core/NaiveModel.h>
#include <iostream>
#include <fstream>

namespace naivebayes {

TEST_CASE("parsing tests") {
     NaiveModel model(GetTrainingImages("data/testingImages.txt"));
     
    //Operator overloading
    SECTION("Storing into a file") {
        std::ofstream out("data/test_storing_file.txt");
        out << model;
    }
    
    //operator overloading
    SECTION("Taking from a file") {
        std::ifstream in("data/test_storing_file.txt");
        NaiveModel new_model;
        in >> new_model;
        REQUIRE(new_model.classes.at(0).training_occurrences == 1);  
        REQUIRE(model.classes.at(0).training_occurrences == new_model.classes.at(0).training_occurrences);
    }

    SECTION("GettingFilesFromFile") {
        ifstream file("data/testingImages.txt");
        REQUIRE(GetTrainingImages(file).at(0) == "0#### ####");
        REQUIRE(GetTrainingImages(file).at(0) == "0#### ####");
    }
}

}