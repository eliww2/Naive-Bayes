//
// Created by eliww on 4/4/2021.
//

#include <fstream>
#include <core/parser.h>
#include <core/Probabilities.h>
#include "core/NaiveModel.h"
#include <core/image.h>

namespace naivebayes {

NaiveModel::NaiveModel() {};

NaiveModel::NaiveModel(vector<image> setImages) {
    images = setImages;
    total_images = images.size();
    images_heights = images.at(0).imageHeight;
}

void NaiveModel::SetModel() {
    for (image current_image : images) {

        // Determines if this image is of a new or existing class, adding it if it's new
        bool new_class = true;
        if (!(this->classes.empty())) {
            for (class_ current_class : classes) {
                if (current_class.class_name == current_image.imageClass) {
                    new_class = false;
                    break;
                }
            }
        }
        if (new_class) {
            class_ current_class;
            current_class.training_occurrences = 0;
            current_class.class_name = current_image.imageClass;
            current_class.pixels_unshaded = vector<int>(current_image.imageUnicode.length(), 0);
            current_class.pixels_shaded = vector<int>(current_image.imageUnicode.length(), 0);
            current_class.pixel_shaded_likelihood = vector<float>(current_image.imageUnicode.length(), 0);
            current_class.pixel_unshaded_likelihood = vector<float>(current_image.imageUnicode.length(), 0);
            classes.push_back(current_class);
        }

        class_ *current_class;
        for (size_t i = 0; i < classes.size(); i++) {
            if (current_image.imageClass == classes.at(i).class_name) {
                current_class = &classes.at(i);
            }
        }

        CalculateShading(current_image.imageUnicode, *current_class);
        this->CalculateProbabilities();
    }
}

void NaiveModel::CalculateProbabilities() {

    Probabilities calculator;
    for (class_ &current_class : classes) {
        current_class.prior = calculator.CalculatePrior(current_class.training_occurrences, total_images);
        for (size_t i = 0; i < current_class.pixels_shaded.size(); i++) {
            current_class.pixel_shaded_likelihood.at(i) = calculator.CalculateLikelihoodPixel(
                    current_class.pixels_shaded.at(i), current_class.training_occurrences);
            current_class.pixel_unshaded_likelihood.at(i) =
                    calculator.
                            CalculateLikelihoodPixel(current_class.pixels_unshaded.at(i),
                                                     current_class.training_occurrences
                    );
        }
    }
}

void NaiveModel::CalculateShading(string &image, class_ &character) {
    character.training_occurrences++;
    for (size_t i = 1; i < character.pixels_unshaded.size(); i++) {

        if (image.at(i) == *" ") {
            character.pixels_unshaded.at(i - 1)++;
        } else {
            character.pixels_shaded.at(i - 1)++;
        }
    }
}

char NaiveModel::GuessImage(const image& current_image) {
    char image_guess = classes.at(0).class_name;
    Probabilities calculator;
    float highest_prob = calculator.CalculateClassProbability(current_image.imageUnicode, classes.at(0));
    for (const class_& current_class : classes) {
        float current_prob = calculator.CalculateClassProbability(current_image.imageUnicode, current_class);
        if (current_prob >= highest_prob) {
            highest_prob = current_prob;
            image_guess = current_class.class_name;
        }
    }
    return image_guess;
}

std::ifstream& operator >> (std::ifstream& in, NaiveModel& model) {
    auto images = getTrainingImages(in, 29);
    auto new_model = NaiveModel(images);
    model = new_model;
    model.SetModel();
    return in;
}

std::ofstream& operator << (std::ofstream& out, NaiveModel& model) {
    out.write((char*)&model, sizeof(model));
    out.close();
    return out;
}

} // namespace naivebayes