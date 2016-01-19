#ifndef INPUT_H
#define INPUT_H
#pragma once

#define MAX_INPUT_SIZE 128
// maximum number of characters that will be recognized from the user input

#include <iostream>
#include <cctype>
#include <algorithm>
#include <sstream>
#include <string>
#include <thread>
#include "../output/output.h"

namespace aimain {
class input {
public:
  static void setInputArray(std::string newin);
  static const char* getInputArray();
  static void setAvailable(bool availnew);
  static void* waitForInput();
  static bool isAvailable();
  static const char* getNext();
  static bool keepAlive();
  static void killProcess();
  static bool invalidChar(char c);
  static void stripUnicode(std::string & str);

}; // class input
} // namespace aimain

#endif
