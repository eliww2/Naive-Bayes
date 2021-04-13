#include <iostream>

#include <core/Probabilities.h>
#include <core/parser.h>
#include <core/image.h>
#include <core/NaiveModel.h>

// TODO: You may want to change main's signature to take in argc and argv

int main() {
  vector<naivebayes::image> mine = naivebayes::getTrainingImages("C:\\Users\\eliww\\Downloads\\Cinder\\my_projects\\naive-bayes\\data\\trainingimagesandlabels.txt", 29);
  auto bayes = new naivebayes::NaiveModel(mine);
  bayes->SetModel();
  return 0;
}
