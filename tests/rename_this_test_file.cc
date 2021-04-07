#include <catch2/catch.hpp>

#include <core/Probabilities.h>
#include <core/parser.h>
#include <core/NaiveModel.h>
#include <iostream>

namespace naivebayes {
TEST_CASE("Check that 126 is the best class") {
    NaiveModel model("C:\\Users\\eliww\\Downloads\\Cinder\\my_projects\\naive-bayes\\data\\trainingimagesandlabels.txt",29);
    model.CalculateProbabilities();
    cout << "hello";
}
}
/*
TODO: Rename this test file. You'll also need to modify CMakeLists.txt.

You can (and should) create more test files; this project is too big
for all tests to be in the same file. Remember that, for each file (foo.cc)
containing non-trivial code, you should have a corresponding test file
(foo_test.cc)

Make sure to add any files that you create to CMakeLists.txt.

TODO Delete this comment and the placeholder test before submitting your code.
*/
