#include <string>

namespace naivebayes {

    //class that will be used for calculating, storing, and updating probabilities.
class Probabilities {

    const float kLaplaceSmoothing = 1;

public:

    float calculatePrior(int num_of_class, int total_images) const;

    float calculateLikelihoodPixel(int num_pixels, int num_of_class) const;

};


}  // namespace naivebayes

/*
Make sure to add any files that you create to CMakeLists.txt.

TODO Delete this comment before submitting your code.
*/
