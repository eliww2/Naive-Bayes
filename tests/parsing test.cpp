//
// Created by eliww on 4/6/2021.
//
#include <catch2/catch.hpp>

#include <core/Probabilities.h>
#include <core/parser.h>
#include <core/NaiveModel.h>
#include <iostream>
#include <fstream>

namespace naivebayes {

TEST_CASE("parsing tests") {
    //Operator overloading
    SECTION("Storing into a file") {
        NaiveModel *model = new NaiveModel("C:\\Users\\eliww\\Downloads\\Cinder\\my_projects\\naive-bayes\\data\\Test", 4);
        ofstream file(model);
        cout << model;
    }
    //operator overloading
    SECTION("Taking from a file") {
        NaiveModel model();
        ifstream file("C:\\Users\\eliww\\Downloads\\Cinder\\my_projects\\naive-bayes\\data\\Test", 4);
        file >> model;
        REQUIRE(model.classes->at(0).training_occurrences == 1);
    }

    SECTION("GettingFilesFromFile") {
        ifstream file("C:\\Users\\eliww\\Downloads\\Cinder\\my_projects\\naive-bayes\\data\\Test", 4);
        Parser parser = new Parser();
        REQUIRE(parser.getTrainingImages(file, 4).at(0) == "0#### ####");
    }
}

}