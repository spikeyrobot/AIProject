#include "fileio.h"

std::ofstream file;
void fileio::open(std::string loc, bool append) {
  if (append)
    file.open(loc, std::ios::out | std::ios::app);
  else {
    try {
      file.open(loc, std::ios::out);
    } catch (int e) {
      if(std::remove(loc.c_str())!=0) {
        std::cout << "Error clearing log file. Appending" << std::endl;
      }
    }
    if(fileio::isOpen(loc))
      fileio::close(loc);
    file.open(loc, std::ios::out | std::ios::app);
  }
}
void fileio::close(std::string loc) {
  file.close();
}
bool fileio::isOpen(std::string loc) {
  return file.is_open();
}


void fileio::write(std::string loc, std::string msg, bool append) {
  if(!fileio::isOpen(loc))
    fileio::open(loc, append);
  file.seekp(std::ios::end);
  file << msg;
  fileio::close(loc);
}
void fileio::write(std::string loc, const char* msg, bool append) {
  if(!fileio::isOpen(loc))
    fileio::open(loc, append);
  file.seekp(std::ios::end);
  file << msg;
  fileio::close(loc);
}

const char* fileio::readLine(std::string loc, uint32_t linenum) {
  std::ifstream file(loc);

  std::string out = std::string("");
  file.close();
  return NULL;
}
