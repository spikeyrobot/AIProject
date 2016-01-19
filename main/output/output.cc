#include "output.h"

std::string buffer[BUFFER_SIZE];
int last = -1;
int first = -1;
namespace aimain {
  void output::LOG(const char* name, std::string level, std::string message) {
    // std::cout << "["<< level << "](" << name << "): " << message << std::endl;
    int next = last+1;
    if(next>=BUFFER_SIZE && first!=0) {
      // If next is out of bounds and the beginning of the array is free
      next=0;
    } else if((next==first && last!=-1) || (first==0 && next>=BUFFER_SIZE)) {
      // If next is within bounds and not the first string being printed
      // or if next is out of bounds and the array is full
      if(first!=0 && next<BUFFER_SIZE-1) {
        // If next equals first, meaning the array is full
        std::cout << "ERR1 " << first << next << last << " arrfull" << std::endl;
        return;
      } else if (first!=0 && next<BUFFER_SIZE) {
        // If next is out of bounds and the array is not full
        //  (theoretically should never happen because it would be caught in first
        //  if statement)
        std::cout << "ERR1 " << first << next << last << " none" << std::endl;
        next=0;
      } else {
        std::cout << "ERR1 " << first << next << last << " unk" << std::endl;
        return;
      }
    } else if(next<BUFFER_SIZE && next!=first) {
      // If next is within bounds and is not the start of the array
    } else if (next>=BUFFER_SIZE) {
      // If next is still out of bounds for some unknown reason
      //  (to prevent segmentation fault)
      std::cout << "ERR2 " << first << next << last << "next>buf" << std::endl;
      return;
    } else {
      // Anything else goes wrong
      std::cout << "ERR3 "<< first << next<< last << std::endl;
      return;
    }
    buffer[next] = "[" + level + "](" + name + "): " + message + "\n";
    last=next;
    first++;
    if(first>=BUFFER_SIZE)
      first=0;
    fileio::write("output.log", buffer[first], true);
    buffer[first] = "";
  }
  void output::close(std::string loc) {
    output::LOG(__FILE__, INFO, "Closing log file");
    fileio::close(loc);
  }
} // namespace aimain
