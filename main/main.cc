#include "main.h"

using namespace aimain;
using namespace std;

int main(void) {
  output::LOG(__FILE__, INFO, "\n\nAIMAIN INIT");
  output::LOG(__FILE__, INFO, "Starting threads");
  
  // Start input_thread as detached thread
  std::thread input_thread(&input::waitForInput);
  input_thread.detach();
  
  output::LOG(__FILE__, INFO, "All threads started");

  while(true) {
    // If there is an input that has not yet been read
    if(input::isAvailable()) {
      std::string recieved = input::getNext();
      // Exit the entire program if the user types "exit"
      if(strcmp(recieved.c_str(), "exit") == 0){
        output::LOG(__FILE__, INFO, "SHUTDOWN");
        // Tell the input thread to exit
        input::killProcess();
        break;
      } else {
        // Finds the inputted sentence's subject (Who the sentence
        //  is referring to gramatically)
        // conscious::findSubject(recieved.c_str());
      }
    }
  }

  // Join threads that are not detached in order to terminate them
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
  // Close/Save the log file
  output::close("output.log");
  return 0;
}
