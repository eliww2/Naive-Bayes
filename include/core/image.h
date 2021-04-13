//
// Created by eliww on 4/13/2021.
//

#ifndef NAIVE_BAYES_IMAGE_H
#define NAIVE_BAYES_IMAGE_H

#include <string>

using namespace std;

namespace naivebayes {

class image {

public:

    image(int height, string unicode, char imageClass);

    int imageHeight;

    string imageUnicode;

    char imageClass;

};

}

#endif //NAIVE_BAYES_IMAGE_H
