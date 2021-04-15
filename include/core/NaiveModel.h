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


public:

    //v~~~~public for testing~~~~v

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


    // The default Laplace Smoothing constant.
    static const int kLaplaceSmoothing = 1;
    //^~~~~public for testing~~~~^

    /**
     * Default constructor.
     */
    NaiveModel();

    /**
     * Creates the model and sets its basic information.
     * SetModel() must be called after this in order to have information to preform calculations.
     * Constructor is not time or memory intensive but SetModel() is.
     *
     * @param set_images
     */
    explicit NaiveModel(vector<Image> set_images);

    /**
     * Sets the information and inizialzes the information needed for the model to
     * do any work. This is time intensive unlike the constructor. Only needs to be done once.
     */
    void SetModel();

    /**
     * Calculates the probabilities needed for image guessing.
     */
    void CalculateProbabilities();

    /**
     * Finds how often each pixel is shaded in each class.
     * @param image The image being added to the shading.
     * @param character The class the image is in.
     */
    static void CalculateShading(string &image, ImageClass &character);

    /**
     * Uses Model information to calculate guess what image is being displayed.
     * @param current_image the image that is to be guessed.
     * @return Image guess.
     */
    char GuessImage(const Image& current_image);

    /**
     * Overload for model class.
     * Loads a file of images in and sets them to a model and sets it.
     */
    friend std::ifstream& operator >> (std::ifstream& in, NaiveModel& model);

    /**
     * Writes model information to a file to be loaded later. Used to avoid having to retrain the model.
     */
    friend std::ofstream& operator << (std::ofstream& out, NaiveModel& model);

};

} // namespace naivebayes

#endif //NAIVE_BAYES_NAIVEMODEL_H
