//
// Created by eliww on 4/13/2021.
//

#ifndef NAIVE_BAYES_IMAGE_H
#define NAIVE_BAYES_IMAGE_H

#include <string>

namespace naivebayes {

class Image {

public:

    Image(int height, const std::string& unicode, char imageClass);

    int image_height_;

    std::string image_unicode_;

    char image_class_;

};

}

#endif //NAIVE_BAYES_IMAGE_H
