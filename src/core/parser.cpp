//
// Created by eliww on 4/4/2021.
//

#include <fstream>
#include <string>
#include <iostream>
#include "core/parser.h"

vector<string> Parser::getTrainingImages(string fileLocation, int imageDimension) {
    ifstream file(fileLocation);
    vector<string> image_lines;
    string temp_string;
    while(getline(file, temp_string)) {
            image_lines.push_back(temp_string);
            temp_string = "";
    }
    int line_num = 0;
    auto *lines_in_image = new vector<string>;
    vector<vector<string>> images;
    for (auto i = image_lines.begin(); i < image_lines.end(); i++, line_num++) {
        if (line_num < imageDimension) {
            lines_in_image->push_back(*i);
        } else {
            images.push_back(*lines_in_image);
            lines_in_image = new vector<string>;
            line_num = 0;
        }
    }
    cout << images.at(0).at(28);
    return image_lines;
}

