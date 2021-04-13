#include <core/Probabilities.h>
#include <core/image.h>

namespace naivebayes {

    float Probabilities::CalculatePrior(int num_of_class, int total_images) const {
        float prior_top = kLaplaceSmoothing + (float)num_of_class;
        float prior_bottom = (10 * kLaplaceSmoothing) + (float)total_images;
        float prior = prior_top / prior_bottom;
        return prior;
    }

    float Probabilities::CalculateLikelihoodPixel(int num_pixels, int num_of_class) const {
        float likelihood_top = kLaplaceSmoothing + (float)num_pixels;
        float likelihood_bottom = (2 * kLaplaceSmoothing) + (float)num_of_class;
        float likelihood = likelihood_top / likelihood_bottom;
        return likelihood;
    }

    float Probabilities::CalculateClassProbability(std::string image, naivebayes::NaiveModel::class_ current_class) {
        size_t pixels_amount = image.length();
        float classProbability = log(current_class.prior);
        for (size_t i = 0; i < pixels_amount; i++) {
            if (&image.at(i) == " ") {
                classProbability = classProbability + log(current_class.pixel_unshaded_likelihood.at(i));
            } else {
                classProbability = classProbability + log(current_class.pixel_shaded_likelihood.at(i));
            }
        }
        return classProbability;
    }

}  // namespace naivebayes