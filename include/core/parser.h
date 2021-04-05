//
// Created by eliww on 4/4/2021.
//

#ifndef NAIVE_BAYES_PARSER_H
#define NAIVE_BAYES_PARSER_H

#include <vector>

using namespace std;

class Parser {

public:

    vector<vector<string>> getTrainingData(string fileLocation);

    size_t getTrainingValue(string file);

    vector<char> getValuesOfTiles(string);


};
#endif //NAIVE_BAYES_PARSER_H
