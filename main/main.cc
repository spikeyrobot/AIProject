#include "main.h"

using namespace aimain;
using namespace std;

int main(void) {
  output::LOG(__FILE__, INFO, "\n\nAIMAIN INIT");
  output::LOG(__FILE__, INFO, "Starting threads");
    
  std::thread input_thread(&input::waitForInput);
  input_thread.detach();
  
  output::LOG(__FILE__, INFO, "All threads started");

  while(true) {
    if(input::isAvailable()) {
      std::string recieved = input::getNext();
      if(strcmp(recieved.c_str(), "exit") == 0){
        output::LOG(__FILE__, INFO, "SHUTDOWN");
        input::killProcess();
        break;
      } else {
        // conscious::findSubject(recieved.c_str());
      }
    }
  }
  /*output::LOG(__func__, INFO, "Joining threads");

  const long double t = time(0);
  do {
    if(input_thread.joinable()) {
      input_thread.join();
      break;
    } else if (time(0) - t > 1) {
      output::LOG(__func__, WARN, "input_thread is not joinable");
      break;
    }
  } while(true);

  output::LOG(__func__, INFO, "All threads joined");*/
  output::LOG(__FILE__, INFO, "DONE");
  output::close("output.log");
  return 0;
}
