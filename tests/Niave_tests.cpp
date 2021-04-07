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

TEST_CASE("Naive testing") {
    ifstream file("C:\\Users\\eliww\\Downloads\\Cinder\\my_projects\\naive-bayes\\data\\Test", 4);
    NaiveModel model();
    file >> model;

    SECTION("Images and labels are correctly loaded with operator overloading") {
        REQUIRE(model.classes->at(0).training_occurrences == 1);
        REQUIRE(model.classes->at(0).class_name == 0);
        REQUIRE(model.classes->at(0).pixels_shaded.at(0) == 1);
    }

    SECTION("Images of different sizes") {
        ifstream new_file("C:\\Users\\eliww\\Downloads\\Cinder\\my_projects\\naive-bayes\\data\\trainingimagesandlabels.txt", 4);
        NaiveModel new_model();
        new_file >> new_model;
        REQUIRE(new_model.classes->size() == 10);
    }

    SECTION("Tests all values of model") {
        for (auto i = new_model.classes.begin(); i < new_model.classes.end(); i++) {
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