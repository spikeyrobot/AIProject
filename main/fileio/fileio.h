#ifndef FILEIO_H
#define FILEIO_H
#pragma once

#include <cstdint>
#include <iostream>
#include <fstream>

class fileio {
  private:
    static void open(std::string loc, bool append = false);
  public:
    static void close(std::string loc);
    static bool isOpen(std::string loc);
    static void write(std::string loc, std::string msg);
    static void write(std::string loc, const char* msg);
    static const char* readLine(std::string loc, uint32_t linenum);
};

#endif
