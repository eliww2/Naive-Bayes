#include <catch2/catch.hpp>

#include <core/Probabilities.h>
#include <core/Parser.h>
#include <core/NaiveModel.h>
#include <iostream>
#include <fstream>

namespace naivebayes {
TEST_CASE("Probabilities") {
    NaiveModel model;
    std::ifstream file("data/testingImages.txt");
    file >> model;
    
    SECTION("Prior probability") {
        float my_prior = CalculatePrior(model.classes.at(0).training_occurrences, model.total_images, model.kLaplaceSmoothing);
        REQUIRE(my_prior == .25f);
    }
    
    SECTION("Check all likelihoods") {
         REQUIRE(CalculateLikelihoodPixel
                 (model.classes.at(0).pixels_unshaded.at(0),
                  model.classes.at(0).training_occurrences, model.kLaplaceSmoothing)
                                == .5f
         );
         REQUIRE(CalculateLikelihoodPixel
                 (model.classes.at(1).pixels_unshaded.at(0),
                  model.classes.at(0).training_occurrences, model.kLaplaceSmoothing)
         == .5f
         );
         REQUIRE(CalculateLikelihoodPixel
                 (model.classes.at(1).pixels_unshaded.at(1),
                  model.classes.at(0).training_occurrences, model.kLaplaceSmoothing)
          == .33f
          );
    }
    
    SECTION("Check Class probability") {
        Image image = model.images.at(0);
        REQUIRE(CalculateClassProbability(image.image_unicode_, model.classes.at(0)) == -1450);
        REQUIRE(CalculateClassProbability(image.image_unicode_, model.classes.at(1)) == -1563);
        REQUIRE(CalculateClassProbability(image.image_unicode_, model.classes.at(2)) == -2120);
        REQUIRE(CalculateClassProbability(image.image_unicode_, model.classes.at(4)) == -1321);
    }
                       
}                        
}
