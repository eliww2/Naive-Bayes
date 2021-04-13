#include <string>
#include "NaiveModel.h"

namespace naivebayes {

    //class that will be used for calculating, storing, and updating probabilities.
class Probabilities {

    //Laplace smoothing constant
    const float kLaplaceSmoothing = 1;

public:

    /** This function will return the probability that an image belongs to any class c.
     *
     * @param num_of_class - Is the # of images that belong to class c in the training set.
     * @param total_images - Is the # of training images given.
     * @return prior
     */
    float CalculatePrior(int num_of_class, int total_images) const;

    /** This function will return the probability of a certain pixel being shaded or unshaded,
     * given that it belongs to class c.
     * (Note- the # of pixels shaded will be the (# images in class c - #pixels unshaded).)
     *
     * @param num_pixels - Is the # of pixels that were shaded or unshaded for position being calculated.
     * @param num_of_class - Is the # of images that belong to class c in the training set.
     * @return
     */
    float CalculateLikelihoodPixel(int num_pixels, int num_of_class) const;

    float CalculateClassProbability(std::string image, naivebayes::NaiveModel::class_ current_class);

};


}  // namespace naivebayes

