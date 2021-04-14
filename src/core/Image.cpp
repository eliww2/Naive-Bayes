//
// Created by eliww on 4/13/2021.
//
#include "core/Image.h"

naivebayes::Image::Image(const int height, const std::string& unicode, const char setClass) {
    image_height_ = height;
    image_class_ = setClass;
    image_unicode_ = unicode;
}
