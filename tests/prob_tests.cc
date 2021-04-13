#include <catch2/catch.hpp>

#include <core/Probabilities.h>
#include <core/parser.h>
#include <core/NaiveModel.h>
#include <iostream>
#include <fstream>

namespace naivebayes {
TEST_CASE("Probabilities") {
    NaiveModel *model = new NaiveModel("C:\\Users\\eliww\\Downloads\\Cinder\\my_projects\\naive-bayes\\data\\Test", 4);
    Probabilities *calc = new Probabilities();

    SECTION("Prior probability") {
        float my_prior = calc->CalculatePrior(model->classes->at(0).training_occurrences, model->total_images);
        REQUIRE(my_prior == .25f);
    }
    SECTION("Check all likelihoods") {
         REQUIRE(calc->CalculateLikelihoodPixel
                 (model->classes->at(0).pixels_unshaded.at(0),
                  model->classes->at(0).training_occurrences)
                                == .5f
         );
         REQUIRE(calc->CalculateLikelihoodPixel
                 (model->classes->at(1).pixels_unshaded.at(0),
                  model->classes->at(0).training_occurrences)
         == .5f
         );
         REQUIRE(calc->CalculateLikelihoodPixel
                 (model->classes->at(1).pixels_unshaded.at(1),
                  model->classes->at(0).training_occurrences)
          == .33f
          );
    }

}
}
