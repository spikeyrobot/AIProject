#include "input.h"

static bool newAvailable;
static std::string inputarray;
bool keepAlive_ = true;

void aimain::input::setInputArray(std::string newin) {
  inputarray = newin;
}

const char* aimain::input::getInputArray() {
  return inputarray.c_str();
}

void aimain::input::setAvailable(bool availnew) {
  newAvailable = availnew;
}

bool aimain::input::isAvailable() {
  return newAvailable;
}

void* aimain::input::waitForInput() {
  output::LOG(__FILE__, INFO, "Begin");
  aimain::input::setAvailable(false);
  std::string inputarray;
  while (aimain::input::keepAlive()) {
    std::cout << std::flush;
    char inputchararray[MAX_INPUT_SIZE];
    std::cin.getline(inputchararray,MAX_INPUT_SIZE);
    inputarray = inputchararray;
    if(inputarray != ""  && inputarray != "\n") {
      aimain::input::stripUnicode(inputarray);
      aimain::input::setAvailable(true);
      aimain::input::setInputArray(inputarray);
      output::LOG(__FILE__, INPUT, "\"" + inputarray + "\"");
    }
    inputarray = "";
  }
  output::LOG(__FILE__, INFO, "End");
}

const char* aimain::input::getNext() {
  aimain::input::setAvailable(false);
  return aimain::input::getInputArray();
}

bool aimain::input::keepAlive() {
  return keepAlive_;
}
void aimain::input::killProcess() {
  output::LOG(__FILE__, INFO, "Killing");
  keepAlive_ = false;
}

bool aimain::input::invalidChar(char c) {
  bool invalid = !(c>=0 && c<128); 
  if(invalid) {
    output::LOG(__FILE__, WARN, "Invalid character: " + c);
  }
  return invalid;
}
void aimain::input::stripUnicode(std::string & str) 
{ 
  str.erase(std::remove_if(str.begin(),str.end(), aimain::input::invalidChar), str.end());  
}
