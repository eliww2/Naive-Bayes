//
// Created by eliww on 4/4/2021.
//

#ifndef NAIVE_BAYES_PARSER_H
#define NAIVE_BAYES_PARSER_H

#include <vector>

using namespace std;

class Parser {

    int images_total = 0;
    const int kImageDimension = 28;

public:

    static vector<string> getTrainingImages(string fileLocation, int imageLength);

};
#endif //NAIVE_BAYES_PARSER_H
