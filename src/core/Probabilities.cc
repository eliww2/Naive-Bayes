#include <core/Probabilities.h>
#include <core/Image.h>

namespace naivebayes {

    float CalculatePrior(int num_of_class, int total_images, int laplace_smoothing) {
        float prior_top = (float)laplace_smoothing + (float)num_of_class;
        float prior_bottom = (10 * (float)laplace_smoothing) + (float)total_images;
        float prior = prior_top / prior_bottom;
        return prior;
    }

    float CalculateLikelihoodPixel(int num_pixels, int num_of_class, int laplace_smoothing) {
        float likelihood_top = (float)laplace_smoothing + (float)num_pixels;
        float likelihood_bottom = (2 * (float)laplace_smoothing) + (float)num_of_class;
        float likelihood = likelihood_top / likelihood_bottom;
        return likelihood;
    }

    float CalculateClassProbability(const string& image, const NaiveModel::ImageClass& current_class) {
        size_t pixels_amount = image.length();
        float class_probability = log(current_class.prior);
        for (size_t i = 0; i < pixels_amount; i++) {
            if (isspace(image[i])) {
                class_probability += log(current_class.pixel_unshaded_likelihood.at(i));
            } else {
                class_probability += log(current_class.pixel_shaded_likelihood.at(i));
            }
        }
        return class_probability;
    }

}  // namespace naivebayes