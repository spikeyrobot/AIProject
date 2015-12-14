#ifndef INPUT_H
#define INPUT_H
#pragma once

#include <iostream>
#include <sstream>
#include <string>
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


}; // class input
} // namespace aimain

#endif
