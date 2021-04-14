//
// Created by eliww on 4/13/2021.
//

#ifndef NAIVE_BAYES_IMAGE_H
#define NAIVE_BAYES_IMAGE_H

#include <string>

namespace naivebayes {


/**
 * Class that contains the size of an image, what it is representing, and the image itself.
 */
class Image {

public:

    /**
     * Constructor. Sets each of the below variables.
     * @param set_height sets height.
     * @param set_unicode sets unicode.
     * @param set_image_class sets class of the image.
     */
    Image(int set_height, const std::string& set_unicode, char set_image_class);

    int image_height_;

    std::string image_unicode_;

    char image_class_;

};

}

#endif //NAIVE_BAYES_IMAGE_H
