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

/*
NaiveModel::NaiveModel(string fileLocation, int image_height) {
    images_heights = image_height;
    auto *parser = new Parser();
    vector<string> images = parser->getTrainingImages(fileLocation, image_height);
    delete parser;
    total_images = images.size();
    size_t image_size = images.at(0).length();
    for (string current_image : images) {

        // Image representation
        char current_class_name = current_image.at(0);

        //2
        //Determining if the this kind of image has been interpreted before and incrementing.
        if (classes->empty()) {
            auto *new_class = new class_();
            new_class->class_name = current_class_name;
            auto *shaded = new vector<int>(image_size - 1, 0);
            auto *unshaded = new vector<int>(image_size - 1, 0);
            auto *shaded_like = new vector<float>(image_size - 1, 0);
            auto *unshaded_like = new vector<float>(image_size - 1, 0);
            new_class->pixels_unshaded = *unshaded;
            new_class->pixels_shaded = *shaded;
            new_class->pixel_unshaded_likelihood = *unshaded_like;
            new_class->pixel_shaded_likelihood = *shaded_like;
            classes->push_back(*new_class);
        }
        bool class_DNE = true;
        for (auto i = classes->begin(); i < classes->end(); i++) {
            if (i->class_name == current_class_name) {
                class_DNE = false;
                i->training_occurrences++;
                break;
            }
        }
        if (class_DNE) {
            auto *new_class = new class_();
            new_class->class_name = current_class_name;
            new_class->training_occurrences++;
            auto *shaded = new vector<int>(image_size - 1, 0);
            auto *unshaded = new vector<int>(image_size - 1, 0);
            auto *shaded_like = new vector<float>(image_size - 1, 0);
            auto *unshaded_like = new vector<float>(image_size - 1, 0);
            new_class->pixels_unshaded = *unshaded;
            new_class->pixels_shaded = *shaded;
            new_class->pixel_unshaded_likelihood = *unshaded_like;
            new_class->pixel_shaded_likelihood = *shaded_like;
            classes->push_back(*new_class);
        }

        //sets class of current image
        class_ *current_class;
        for (size_t i = 0; i < classes->size(); i++) {
            if (current_class_name == classes->at(i).class_name) {
                current_class = &classes->at(i);
            }
        }

        //calculates the shading of each pixel.
        CalculateShading(current_image, *current_class);

    }
}

NaiveModel::NaiveModel(vector<string> images, int image_height) {
        images_heights = image_height;
        total_images = images.size();
        size_t image_size = images.at(0).length();
        for (string current_image : images) {

            // Image representation
            char current_class_name = current_image.at(0);

            //2
            //Determining if the this kind of image has been interpreted before and incrementing.
            if (classes->empty()) {
                auto *new_class = new class_();
                new_class->class_name = current_class_name;
                auto *shaded = new vector<int>(image_size - 1, 0);
                auto *unshaded = new vector<int>(image_size - 1, 0);
                auto *shaded_like = new vector<float>(image_size - 1, 0);
                auto *unshaded_like = new vector<float>(image_size - 1, 0);
                new_class->pixels_unshaded = *unshaded;
                new_class->pixels_shaded = *shaded;
                new_class->pixel_unshaded_likelihood = *unshaded_like;
                new_class->pixel_shaded_likelihood = *shaded_like;
                classes->push_back(*new_class);
            }
            bool class_DNE = true;
            for (auto i = classes->begin(); i < classes->end(); i++) {
                if (i->class_name == current_class_name) {
                    class_DNE = false;
                    i->training_occurrences++;
                    break;
                }
            }
            if (class_DNE) {
                auto *new_class = new class_();
                new_class->class_name = current_class_name;
                new_class->training_occurrences++;
                auto *shaded = new vector<int>(image_size - 1, 0);
                auto *unshaded = new vector<int>(image_size - 1, 0);
                auto *shaded_like = new vector<float>(image_size - 1, 0);
                auto *unshaded_like = new vector<float>(image_size - 1, 0);
                new_class->pixels_unshaded = *unshaded;
                new_class->pixels_shaded = *shaded;
                new_class->pixel_unshaded_likelihood = *unshaded_like;
                new_class->pixel_shaded_likelihood = *shaded_like;
                classes->push_back(*new_class);
            }

            class_ *current_class;
            for (size_t i = 0; i < classes->size(); i++) {
                if (current_class_name == classes->at(i).class_name) {
                    current_class = &classes->at(i);
                }
            }

            CalculateShading(current_image, *current_class);

        }
    }
*/

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

    Probabilities *calculator = new Probabilities();
    for (class_ &current_class : classes) {
        current_class.prior = calculator->calculatePrior(current_class.training_occurrences, total_images);
        for (size_t i = 0; i < current_class.pixels_shaded.size(); i++) {
            current_class.pixel_shaded_likelihood.at(i) = calculator->calculateLikelihoodPixel(current_class.pixels_shaded.at(i), current_class.training_occurrences);
            current_class.pixel_unshaded_likelihood.at(i) =
                    calculator->
                            calculateLikelihoodPixel(current_class.pixels_unshaded.at(i),
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

/*std::istream& operator >> (std::istream& is, NaiveModel& model) {
    vector<string> image_lines;
    string temp_string;
    int image_height = 0;
    string fixer = "                            ";
    while (getline(is, temp_string)) {
        if (image_height == 0) {
            image_height = stoi(temp_string);
            continue;
        } else if (temp_string.length() == 0) {
            temp_string = fixer;
        }
        image_lines.push_back(temp_string);
        temp_string = "";
    }

    NaiveModel *new_model = new NaiveModel(getOverload(image_lines, image_height), image_height);
    model.classes = new_model->classes;
    model.images_heights = new_model->images_heights;
    model.total_images = new_model->total_images;
    return is;
} */

std::ostream& operator << (std::ostream& os, NaiveModel& model) {
    os << model.images_heights;
    string json = "";
    return os;
}



} // namespace naivebayes