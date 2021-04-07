//
// Created by eliww on 4/4/2021.
//

#ifndef NAIVE_BAYES_PARSER_H
#define NAIVE_BAYES_PARSER_H

#include <vector>

using namespace std;

namespace naivebayes {

class Parser {

public:

    /**
     * Grabs a file and parses it taking the images and converting it to an array of the images.
     * @param fileLocation Where the file is stored in memory.
     * @param imageLength The height of the image including the label.
     * @return vector containing the training images.
     */
    static vector<string> getTrainingImages(string fileLocation, int imageLength);

};

} // namespace naivebayes
#endif //NAIVE_BAYES_PARSER_H
