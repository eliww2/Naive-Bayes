#include <iostream>

#include <core/Probabilities.h>
#include <core/parser.h>
#include <core/image.h>
#include <core/NaiveModel.h>
#include <fstream>

// TODO: You may want to change main's signature to take in argc and argv
using namespace naivebayes;

int main(int argc, char* argv[]) {

  // Loads in the file and creates the model
  NaiveModel model;
  ifstream input(argv[1]);
  input >> model;

  //Writes model to file
  ofstream output(argv[2]);
  output << model;

  // Creates array of images and guesses their value, then prints success rate
  auto mine = getTrainingImages(argv[3], 29);
  float correct = 0;
  float amount = 0;
  for (const image& current_image : mine) {
      amount++;
      char ti = model.GuessImage(current_image);
      if (ti == current_image.imageClass) {
          correct++;
      }
  }
  cout << "Success Rate: " << (100 * correct) / amount << "%";
  return 0;
}
