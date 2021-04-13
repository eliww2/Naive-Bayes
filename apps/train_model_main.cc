#include <iostream>

#include <core/Probabilities.h>
#include <core/parser.h>
#include <core/image.h>
#include <core/NaiveModel.h>
#include <fstream>

// TODO: You may want to change main's signature to take in argc and argv

int main() {

  naivebayes::NaiveModel model;
  ifstream file(R"(C:\Users\eliww\Downloads\Cinder\my_projects\naive-bayes\data\trainingimagesandlabels.txt)");
  file >> model;
  cout << model.GuessImage(model.images.at(0));
  return 0;

}
