//
// Created by eliww on 4/4/2021.
//

#include <fstream>
#include <core/parser.h>
#include "core/NaiveModel.h"

NaiveModel::NaiveModel() {};

NaiveModel::NaiveModel(string fileLocation, int image_length) {
    //1
    Parser *parser = new Parser();
    vector<string> images = parser->getTrainingImages(fileLocation, image_length);
    //2, 3, 4
    for (string current_image : images) {

        // Image representation
        char current_class_name = current_image.at(0);

        //2
        //Determining if the this kind of image has been interpreted before and incrementing.
        if (classes.empty()) {
            auto *new_class = new class_();
            new_class->class_name = current_class_name;
            classes.push_back(*new_class);
        }
        bool class_DNE = true;
        for (auto i = classes.begin(); i < classes.end(); i++) {
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
            classes.push_back(*new_class);
        }

        //3
        class_ *current_class;
        for (int i = 0; i < classes.size(); i++) {
            if (current_class_name == classes[i].class_name) {
                current_class = &classes[i];
            }
        }
        for (int i = 1; i < current_image.size(); i++) {
            if (&current_image.at(i) == " ") {
                current_class->pixels_unshaded[i]++;
            } else {
                current_class->pixels_shaded[i]++;
            }
        }




    }



    /*
     * 1. go through training data and divide into images
     * 2a. For any image that does not have a class, create a new one and increment occurrences.
     * 2b. If an image does have a class increment occurrences.
     * 3. Go through each pixel of the image and find if it is shaded or not,
     * incrementing counts accordingly
     * 4.Do this for all images
     *
     */
}
