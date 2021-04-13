//
// Created by eliww on 4/4/2021.
//

#ifndef NAIVE_BAYES_PARSER_H
#define NAIVE_BAYES_PARSER_H

#include <vector>
#include <core/image.h>

using namespace std;

namespace naivebayes {

    vector<image> getTrainingImages(const string& fileLocation, int imageLength);

    vector<image> getTrainingImages(ifstream& file, int imageLength);

    vector<string> getOverload(vector<string> image_lines, int imageDimension);

} // namespace naivebayes

#endif //NAIVE_BAYES_PARSER_H
