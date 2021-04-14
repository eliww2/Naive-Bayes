#include <iostream>

#include <core/Probabilities.h>
#include <core/parser.h>
#include <core/image.h>
#include <core/NaiveModel.h>
#include <fstream>

// TODO: You may want to change main's signature to take in argc and argv
using namespace naivebayes;

int main() {

  NaiveModel model;
  ifstream file(R"(C:\Users\eliww\Downloads\Cinder\my_projects\naive-bayes\data\trainingimagesandlabels.txt)");
  file >> model;

  auto mine = getTrainingImages(R"(C:\Users\eliww\Downloads\Cinder\my_projects\naive-bayes\data\testimagesandlabels.txt)", 29);
  float correct = 0;
  float amount = 0;
  for (image current_image : mine) {
      amount++;
      char ti = model.GuessImage(current_image);
      if (ti == current_image.imageClass) {
          correct++;
      }
  }
  cout << correct / amount;
  return 0;

}
