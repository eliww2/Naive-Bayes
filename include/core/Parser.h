//
// Created by eliww on 4/4/2021.
//

#ifndef NAIVE_BAYES_PARSER_H
#define NAIVE_BAYES_PARSER_H

#include <vector>
#include <core/Image.h>

using std::vector;
using std::string;
using std::ifstream;

namespace naivebayes {

    /**
     * Takes location of training images and parses them, then returns image length.
     * @param file_location where the file is located.
     * @param image_length height of image. Used for parsing.
     * @return vector of images for the model.
     */
    vector<Image> GetTrainingImages(const string& file_location, int image_length);

    /**
     * Takes file of images and parses it.
     * @param file File of images
     * @param image_length height of image. Used for parsing.
     * @return vector of images for the model.
     */
    vector<Image> GetTrainingImages(ifstream& file, int image_length);

} // namespace naivebayes

#endif //NAIVE_BAYES_PARSER_H
