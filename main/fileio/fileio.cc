#include "fileio.h"

std::ofstream file;

// Open a file at location loc and whether to wipe the file or append the file
//  if the file already exists. It will only clear the file if append is false
//  and there is no problem deleting the file. Otherwise it will attempt to
//  append the file if it exists or create a new file if it doesn't and open it.
// When saying the file is appended, I mean the next place to write to the file
//  is the end of the file. The other option is clearing the file and starting fresh
void fileio::open(std::string loc, bool append) {
  if (append)
    file.open(loc, std::ios::out | std::ios::app);
  else {
    try {
      file.open(loc, std::ios::out);
    } catch (int e) {
      if(std::remove(loc.c_str())!=0) {
        std::cout << "Error clearing log file. Appending" << std::endl;
        if(fileio::isOpen(loc))
          fileio::close(loc);
        file.open(loc, std::ios::out | std::ios::app);
      }
    }
  }
}

void fileio::close(std::string loc) {
  file.close();
}
bool fileio::isOpen(std::string loc) {
  return file.is_open();
}

// Writes to a specifinc file based on the given location.
// NOTE: The files are not stored based on their location, they are stored
//  based on the order they were opened. 
// Append is only used if the file is not open.
void fileio::write(std::string loc, std::string msg, bool append) {
  // File is opened if not already
  if(!fileio::isOpen(loc))
    fileio::open(loc, append);
  // Jumps to the end of the file
  file.seekp(std::ios::end);
  // Writes to file
  file << msg;
  // Closes the file to ensure it is saved properly
  fileio::close(loc);
}

void fileio::write(std::string loc, const char* msg, bool append) {
  fileio::write(loc, std::string(msg), append);
}

// Intended to read a specific line in a specific file. Currently does
//  nothing except return NULL
// TODO: Finish this function
const char* fileio::readLine(std::string loc, uint32_t linenum) {
  std::ifstream file(loc);

  std::string out = std::string("");
  file.close();
  return NULL;
}
