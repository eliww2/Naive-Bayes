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

    vector<Image> GetTrainingImages(const string& file_location, int image_length);

    vector<Image> GetTrainingImages(ifstream& file, int image_length);

} // namespace naivebayes

#endif //NAIVE_BAYES_PARSER_H
