#include "output.h"

std::string buffer[BUFFER_SIZE];
int last = -1;
int first = -1;
namespace aimain {
  void output::LOG(const char* name, std::string level, std::string message) {
    // std::cout << "["<< level << "](" << name << "): " << message << std::endl;
    int next = last+1;
    if(next>=BUFFER_SIZE && next!=first && first!=0) {
      next=0;
    } else if((next==first && last!=-1) || (first==0 && next>=BUFFER_SIZE)) {
      // TODO: throw/write error
      std::cout << "ERR" << first << next << last << std::endl;
      return;
    }
    buffer[next] = "[" + level + "](" + name + "): " + message + "\n";
    last=next;
    first++;
    fileio::write("output.log", buffer[first]);
    buffer[first] = "";
    if(first>=BUFFER_SIZE)
      first=0;
  }
  void output::close(std::string loc) {
    fileio::close(loc);
  }
} // namespace aimain
