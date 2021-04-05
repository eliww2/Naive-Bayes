#include <core/probabilities.h>

namespace naivebayes {

    float Probabilities::calculatePrior(int num_of_class, int total_images) const {
        float prior_top = kLaplaceSmoothing + (float)num_of_class;
        float prior_bottom = (10 * kLaplaceSmoothing) + (float)total_images;
        float prior = prior_top / prior_bottom;
        return prior;
    }

    float Probabilities::calculateLikelihoodPixel(int num_pixels, int num_of_class) const {
        float likelihood_top = kLaplaceSmoothing + (float)num_pixels;
        float likelihood_bottom = (2 * kLaplaceSmoothing) + (float)num_of_class;
        float likelihood = likelihood_top / likelihood_bottom;
        return likelihood;
    }

    
}  // namespace naivebayes