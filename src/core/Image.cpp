//
// Created by eliww on 4/13/2021.
//
#include "core/Image.h"

naivebayes::Image::Image(const int set_height, const std::string& set_unicode, const char set_image_class) {
    image_height_ = set_height;
    image_class_ = set_image_class;
    image_unicode_ = set_unicode;
}
