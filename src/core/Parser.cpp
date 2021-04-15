//
// Created by eliww on 4/4/2021.
//

#include <iostream>
#include <fstream>
#include <string>
#include <iostream>
#include <core/Image.h>
#include "core/Parser.h"
#include "core/NaiveModel.h"

namespace naivebayes {

    vector<Image> GetTrainingImages(const string& file_location) {
        ifstream file(file_location);
        vector<string> image_lines;
        string temp_string;
        getline(file, temp_string);
        getline(file, temp_string);
        int image_length = temp_string.length() + 1;
        file.seekg(0);
        temp_string = "";
        
        while (getline(file, temp_string)) {
            image_lines.push_back(temp_string);
            temp_string = "";
        }

        int line_num = 1;
        size_t lines_size = image_lines.size();
        temp_string = "";
        vector<Image> images;
        for (size_t i = 0; i < lines_size; i++, line_num++) {
            if (line_num < image_length) {
                temp_string += image_lines.at(i);
            } else {
                temp_string += image_lines.at(i);
                images.emplace_back(image_length, temp_string.substr(1), temp_string.at(0));
                temp_string = "";
                line_num = 0;
            }
        }
        return images;
    }

    vector<Image> GetTrainingImages(ifstream& file) {
        vector<string> image_lines;
        string temp_string;
        getline(file, temp_string);
        getline(file, temp_string);
        int image_length = temp_string.length() + 1;
        file.seekg(0);
        temp_string = "";
        
        while (getline(file, temp_string)) {
            image_lines.push_back(temp_string);
            temp_string = "";
        }

        int line_num = 1;
        size_t lines_size = image_lines.size();
        temp_string = "";
        vector<Image> images;
        for (size_t i = 0; i < lines_size; i++, line_num++) {
            if (line_num < image_length) {
                temp_string += image_lines.at(i);
            } else {
                temp_string += image_lines.at(i);
                images.emplace_back(image_length, temp_string.substr(1), temp_string.at(0));
                temp_string = "";
                line_num = 0;
            }
        }
        return images;
    }

} // namespace naivebayes