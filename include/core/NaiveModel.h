//
// Created by eliww on 4/4/2021.
//

#ifndef NAIVE_BAYES_NAIVEMODEL_H
#define NAIVE_BAYES_NAIVEMODEL_H

#include <vector>

using namespace std;

namespace naivebayes {

    class NaiveModel {

        struct class_ {
            char class_name;
            int training_occurrences;
            float prior;
            vector<int> pixels_shaded;
            vector<int> pixels_unshaded;
            vector<float> pixel_shaded_likelihood;
            vector<float> pixel_unshaded_likelihood;
        };

        int total_images;
        vector<class_> *classes = new vector<class_>();


    public:

        NaiveModel();

        NaiveModel(string fileLocation, int image_height);

        void CalculateProbabilities();

        void CalculateShading(string &image, class_ &character);

    };

} // namespace naivebayes

#endif //NAIVE_BAYES_NAIVEMODEL_H
