#include <iostream>

#include <core/Probabilities.h>
#include <core/Parser.h>
#include <core/Image.h>
#include <core/NaiveModel.h>
#include <fstream>

using namespace naivebayes;

int main(int argc, char* argv[]) {

  // Loads in the file and creates the model
  NaiveModel model;
  std::ifstream input(argv[1]);
  input >> model;

  //Writes model to file
  std::ofstream output(argv[2]);
  output << model;

  // Creates array of training_images and guesses their value, then prints success rate
  auto training_images = GetTrainingImages(argv[3], 29);
  float correct = 0;
  float amount = 0;
  for (const Image& current_image : training_images) {
      amount++;
      char ti = model.GuessImage(current_image);
      if (ti == current_image.image_class_) {
          correct++;
      }
  }
  std::cout << "Success Rate: " << (100 * correct) / amount << "%";
  return 0;
}
