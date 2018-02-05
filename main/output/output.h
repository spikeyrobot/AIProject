#ifndef OUTPUT_H
#define OUTPUT_H
#pragma once

#define DEBUG "DEBUG"
#define INFO "INFO "
#define INPUT "INPUT"
#define WARN "WARN "
#define ERROR "ERROR"
#define FATAL "FATAL"

#include <iostream>
#include <string.h>
#include "../output/output.h"
#include "../fileio/fileio.h"

namespace aimain {
class output {
 public:
  static void close(std::string loc);
  static void LOG(const char *clsname, std::string level, std::string message,
                  int recurr = 0);
  static constexpr int BufferSize = 5;

 private:
  static void writeBuffer();
};  // class output
}  // namespace aimain
#endif
