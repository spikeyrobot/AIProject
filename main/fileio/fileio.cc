#include "fileio.h"

std::ofstream file;
void fileio::open(std::string loc, bool append) {
  if (append)
    file.open(loc, std::ios::out | std::ios::app);
  else {
    if(std::remove(loc.c_str()) !=0) {
      std::cout << "Error deleting log file, Appending" << std::endl;
    }
    file.open(loc, std::ios::out | std::ios::app);
  }
}
void fileio::close(std::string loc) {
  file.close();
}
bool fileio::isOpen(std::string loc) {
  return file.is_open();
}


void fileio::write(std::string loc, std::string msg) {
  if(!fileio::isOpen(loc))
    fileio::open(loc);
  file.seekp(std::ios::end);
  file << msg;
}
void fileio::write(std::string loc, const char* msg) {
  if(!fileio::isOpen(loc))
    fileio::open(loc);
  file.seekp(std::ios::end);
  file << file << msg;
}

const char* fileio::readLine(std::string loc, uint32_t linenum) {
  std::ifstream file(loc);

  std::string out = std::string("");
  file.close();
  return NULL;
}
