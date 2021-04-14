//
// Created by eliww on 4/4/2021.
//

#include <fstream>
#include <utility>
#include <core/Parser.h>
#include <core/Probabilities.h>
#include "core/NaiveModel.h"
#include <core/Image.h>

namespace naivebayes {

NaiveModel::NaiveModel() {};

NaiveModel::NaiveModel(vector<Image> set_images) {
    images = std::move(set_images);
    total_images = images.size();
    images_heights = images.at(0).image_height_;
}

void NaiveModel::SetModel() {
    for (Image current_image : images) {

        // Determines if this Image is of a new or existing class, adding it if it's new
        bool new_class = true;
        if (!(this->classes.empty())) {
            for (const ImageClass& current_class : classes) {
                if (current_class.class_name == current_image.image_class_) {
                    new_class = false;
                    break;
                }
            }
        }
        if (new_class) {
            ImageClass current_class;
            current_class.training_occurrences = 0;
            current_class.class_name = current_image.image_class_;
            current_class.pixels_unshaded = vector<int>(current_image.image_unicode_.length(), 0);
            current_class.pixels_shaded = vector<int>(current_image.image_unicode_.length(), 0);
            current_class.pixel_shaded_likelihood = vector<float>(current_image.image_unicode_.length(), 0);
            current_class.pixel_unshaded_likelihood = vector<float>(current_image.image_unicode_.length(), 0);
            classes.push_back(current_class);
        }

        // Creates pointer to the class this image belongs to.
        ImageClass *current_class;
        for (auto & this_class : classes) {
            if (current_image.image_class_ == this_class.class_name) {
                current_class = &this_class;
            }
        }

        // Uses the pointer to pass the class that needs to be updated.
        CalculateShading(current_image.image_unicode_, *current_class);
        this->CalculateProbabilities();
    }
}

void NaiveModel::CalculateProbabilities() {
    for (ImageClass &current_class : classes) {
        current_class.prior = CalculatePrior(current_class.training_occurrences, total_images, kLaplaceSmoothing);
        for (size_t i = 0; i < current_class.pixels_shaded.size(); i++) {
            current_class.pixel_shaded_likelihood.at(i) = CalculateLikelihoodPixel(
                    current_class.pixels_shaded.at(i), current_class.training_occurrences, kLaplaceSmoothing);
            current_class.pixel_unshaded_likelihood.at(i) =
                    CalculateLikelihoodPixel(current_class.pixels_unshaded.at(i),
                                                     current_class.training_occurrences, kLaplaceSmoothing
                    );
        }
    }
}

void NaiveModel::CalculateShading(string &image, ImageClass &character) {
    character.training_occurrences++;
    for (size_t i = 1; i < character.pixels_unshaded.size(); i++) {
        if (image.at(i) == *" ") {
            character.pixels_unshaded.at(i - 1)++;
        } else {
            character.pixels_shaded.at(i - 1)++;
        }
    }
}

char NaiveModel::GuessImage(const Image& current_image) {
    char image_guess = classes.at(0).class_name;
    float highest_prob = CalculateClassProbability(current_image.image_unicode_, classes.at(0));
    for (const ImageClass& current_class : classes) {
        float current_prob = CalculateClassProbability(current_image.image_unicode_, current_class);
        if (current_prob >= highest_prob) {
            highest_prob = current_prob;
            image_guess = current_class.class_name;
        }
    }
    return image_guess;
}

std::ifstream& operator >> (std::ifstream& in, NaiveModel& model) {
    auto images = GetTrainingImages(in, 29);
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