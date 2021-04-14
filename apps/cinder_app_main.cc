#include <visualizer/naive_bayes_app.h>
#include <core/NaiveModel.h>

using naivebayes::visualizer::NaiveBayesApp;
using namespace naivebayes;

void prepareSettings(NaiveBayesApp::Settings* settings) {
  settings->setResizable(false);
}

// This line is a macro that expands into an "int main()" function.
CINDER_APP(NaiveBayesApp, ci::app::RendererGl, prepareSettings);
