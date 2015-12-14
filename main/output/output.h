#ifndef OUTPUT_H
#define OUTPUT_H
#pragma once

#define DEBUG "DEBUG"
#define INFO  "INFO "
#define INPUT "INPUT"
#define WARN  "WARN "
#define ERROR "ERROR"
#define FATAL "FATAL"
#define BUFFER_SIZE 10

#include <iostream>
#include <string.h>
#include "../output/output.h"
#include "../fileio/fileio.h"

namespace aimain {
class output {
public:
  static void LOG(const char* clsname, std::string level, std::string message);
  static void close(std::string loc);
}; // class output
} // namespace aimain
#endif
