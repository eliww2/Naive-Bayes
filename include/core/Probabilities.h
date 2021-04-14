#include <string>
#include "NaiveModel.h"

using std::vector;
using std::string;
using std::ifstream;

namespace naivebayes {

    /** This function will return the probability that an Image belongs to any class c.
     *
     * @param num_of_class - Is the # of images that belong to class c in the training set.
     * @param total_images - Is the # of training images given.
     * @param laplace_smoothing the smoothing constant needed for the calculations.
     * @return prior
     */
    float CalculatePrior(int num_of_class, int total_images, int laplace_smoothing);

    /** This function will return the probability of a certain pixel being shaded or unshaded,
     * given that it belongs to class c.
     * (Note- the # of pixels shaded will be the (# images in class c - #pixels unshaded).)
     *
     * @param num_pixels - Is the # of pixels that were shaded or unshaded for position being calculated.
     * @param num_of_class - Is the # of images that belong to class c in the training set.
     * @param laplace_smoothing the smoothing constant needed for the calculations.
     * @return
     */
    float CalculateLikelihoodPixel(int num_pixels, int num_of_class, int laplace_smoothing);

    /**
     * Calculates the probability of a image being in the given class.
     * @param image The image that needs to know its class probability.
     * @param current_class What class is trying to be guessed.
     * @return Probability of the image being in the class.
     */
    float CalculateClassProbability(const string& image, const NaiveModel::ImageClass& current_class);

}  // namespace naivebayes

