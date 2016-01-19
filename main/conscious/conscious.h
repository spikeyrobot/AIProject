#ifndef CONSCIOUS_H
#define CONSCIOUS_H

#include "../output/output.h"
#include <iostream>

#define HISTORY_LENGTH 20

namespace aimain {
class conscious {
private:
  int lastResponseLoc;
  int nextResponseLoc;
  int firstResponseLoc;
protected:
  const char* previousResponces[HISTORY_LENGTH];
public:
  static const char* interpret(const char* input);
  static const char* findSubject(const char* input);
}; // class conscious
} // namespace aimain
#endif
