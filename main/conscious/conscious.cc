#include "conscious.h"

using namespace aimain;

// Eventually should find all the different parts of the sentence,
//  (ei: verbs, nouns, etc...) and return something relevant
const char* conscious::interpret(const char* input) {
  const char* output = "N/A"; 
  return output;
}

// Supposed to return who the inputed sentence is talking about
//  gramatically.
const char* conscious::findSubject(const char* input) {
  const char* output = "N/A";

  output::LOG(__FILE__, INFO, "Subject: " + std::string(output));
  return output;
}
