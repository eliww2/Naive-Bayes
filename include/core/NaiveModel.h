//
// Created by eliww on 4/4/2021.
//

#ifndef NAIVE_BAYES_NAIVEMODEL_H
#define NAIVE_BAYES_NAIVEMODEL_H

#include <vector>
#include <core/Image.h>

using std::vector;
using std::string;

namespace naivebayes {

class NaiveModel {

    static const int kLaplaceSmoothing = 1;

public:

    //~~~~public for testing~~~~
    struct ImageClass {
            char class_name;
            int training_occurrences;
            float prior;
            vector<int> pixels_shaded;
            vector<int> pixels_unshaded;
            vector<float> pixel_shaded_likelihood;
            vector<float> pixel_unshaded_likelihood;
        };
    vector<ImageClass> classes;

    vector<Image> images;
    int images_heights;
    int total_images;

    //^~~~~public for testing~~~~^

    NaiveModel();

    explicit NaiveModel(vector<Image> set_images);

    void SetModel();

    void CalculateProbabilities();

    static void CalculateShading(string &image, ImageClass &character);

    char GuessImage(const Image& current_image);

    friend std::ifstream& operator >> (std::ifstream& in, NaiveModel& model);

    friend std::ofstream& operator << (std::ofstream& out, NaiveModel& model);

};

} // namespace naivebayes

#endif //NAIVE_BAYES_NAIVEMODEL_H
