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

TEST_CASE("Naive testing") {
    NaiveModel model;
    std::ifstream file("data/testingImages.txt");
    file >> model;

    SECTION("Images and labels are correctly loaded with operator overloading") {
        REQUIRE(model.classes.at(0).training_occurrences == 1);
        REQUIRE(model.classes.at(0).class_name == 0);
        REQUIRE(model.classes.at(0).pixels_shaded.at(0) == 1);
    }

    SECTION("Images of different sizes") {
        NaiveModel new_model;
        std::ifstream new_file("data/trainingimagesandlabelstesting.txt");
        new_file >> new_model;
        REQUIRE(new_model.classes.size() == 10);
    }

    SECTION("Tests all values of model") {
        for (auto i = model.classes.begin(); i < model.classes.end(); i++) {
            REQUIRE(i.trainingOccurances == 2);
            REQUIRE(i.image_heights == 2);
            REQUIRE(i.total_images == 3);
            int b = 0;
            for (auto j = i.pixels_shaded.begin(); j < j.pixels_shaded.end(); j++, b++) {
                REQUIRE(j.at(b));
            }
        }
    }           
}

}