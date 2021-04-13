//
// Created by eliww on 4/4/2021.
//

#ifndef NAIVE_BAYES_NAIVEMODEL_H
#define NAIVE_BAYES_NAIVEMODEL_H

#include <vector>

using namespace std;

namespace naivebayes {

    class NaiveModel {

    public:

        //~~~~public for testing~~~~
        struct class_ {
            char class_name;
            int training_occurrences;
            float prior;
            vector<int> pixels_shaded;
            vector<int> pixels_unshaded;
            vector<float> pixel_shaded_likelihood;
            vector<float> pixel_unshaded_likelihood;
        };
        vector<class_> classes;

        vector<image> images;
        int images_heights;
        int total_images;
        //^~~~~public for testing~~~~^

        NaiveModel();

        NaiveModel(vector<image> setImages);

        void SetModel();

        /*
        NaiveModel(string fileLocation, int image_height);

        NaiveModel::NaiveModel(vector<string> images, int image_height);*/

        void CalculateProbabilities();

        void CalculateShading(string &image, class_ &character);

        friend std::istream& operator >> (std::istream& is, NaiveModel& model);

        friend std::ostream& operator << (std::ostream& os, NaiveModel& model);


    };

} // namespace naivebayes

#endif //NAIVE_BAYES_NAIVEMODEL_H
