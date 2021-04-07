//
// Created by eliww on 4/4/2021.
//

#include <iostream>
#include <fstream>
#include <string>
#include <iostream>
#include "core/parser.h"

namespace naivebayes {

    vector<string> Parser::getTrainingImages(string fileLocation, int imageDimension) {
        ifstream file(fileLocation);
        vector<string> image_lines;
        string temp_string;
        string fixer = "                            ";
        while (getline(file, temp_string)) {
            if (temp_string.length() == 0) {
                temp_string = fixer;
            }
            image_lines.push_back(temp_string);
            temp_string = "";
        }

        int line_num = 1;
        size_t lines_size = image_lines.size();
        string tmp_image = "";
        vector<string> images;
        for (size_t i = 0; i < lines_size; i++, line_num++) {
            if (line_num < imageDimension) {
                tmp_image = tmp_image + image_lines.at(i);
            } else {
                tmp_image = tmp_image + image_lines.at(i);
                images.push_back(tmp_image);
                tmp_image = "";
                line_num = 0;
            }
        }

        return images;
    }

} // namespace naivebayes