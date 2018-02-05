#include "output.h"

namespace aimain {
static std::string buffer[output::BufferSize];

int first = -1;
int next = 0;
int last = -1;

// Formats the log messages and will eventually be structured to use a
//  buffer but I've been having issues with that so idk if that will
//  happen. For now it writes the formated log messages to the log file.
// All cout messages are for debugging. Obviously can't write these
//  errors to a file because the error would occur while trying to write
//  the same error to the same file.
void output::LOG(const char *name, std::string level, std::string message,
                 int recurr) {
  /* std::cout
       << "["
       << level
       << "]("
       << name
       << "): "
       << message
       << std::endl;*/

  if (next >= BufferSize && first != 0) {
    // If next is out of bounds and the beginning of the array is free
    next = 0;
  } else if ((next == first && last != -1) ||
             (first == 0 && next >= BufferSize)) {
    // If next is within bounds and not the first string being printed
    // or if next is out of bounds and the array is full
    if (first != 0 && next < BufferSize - 1) {
      // If next equals first, meaning the array is full
      // Attempt to empty the array by waiting for the buffer to empty
      writeBuffer();
      if (recurr > 5) {
        std::cout << "ERR1 " << first << next << last << " arrfull"
                  << std::endl;
        return;
      } else {
        LOG(name, level, message, recurr++);
        return;
      }
    } else if (first != 0 && next >= BufferSize - 1) {
      // If next is out of bounds and the array is not full
      //  (theoretically should never happen because it would be
      //  caught in first if statement)
      std::cout << "ERR1 " << first << next << last << " none" << std::endl;
      next = 0;
    } else {
      std::cout << "ERR1 " << first << next << last << " unk" << std::endl;
      return;
    }
  } else if (next < BufferSize && next != first) {
    // If next is within bounds and is not the start of the array
  } else if (next >= BufferSize) {
    // If next is still out of bounds for some unknown reason
    //  (to prevent segmentation fault)
    std::cout << "ERR2 " << first << next << last << "next>buf" << std::endl;
    return;
  } else {
    // Anything else goes wrong
    std::cout << "ERR3 " << first << last << std::endl;
    return;
  }

  // Add the message to the buffer
  buffer[next] = "[" + level + "](" + name + "): " + message + "\n";
  last = next;

  writeBuffer();
}

// Write the next message in the buffer to the file then clear this
//  location in the buffer
void output::writeBuffer() {
  fileio::write("output.log", buffer[first], true);
  buffer[first] = "";
  first++;
  if (first >= BufferSize) first = 0;
}

// Allows main to close the file without instantiating fileio
void output::close(std::string loc) {
  LOG(__FILE__, INFO, "Closing log file");
  fileio::close(loc);
}
}  // namespace aimain
