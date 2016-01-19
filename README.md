# AIProject
My feeble attempt at a program that can interpret the meaning of sentences and respond to them.

This is a personal project I'm working on in my free time for fun.
Any suggestions on how to improve the program are appreciated.

# Building and Running
Running the below python script will automatically rebuild all necessary files and run them if the build is successful
"python build/build.py"

# UI
Once the script is runnning the user may type sentences into the terminal and press enter to send them.
Typing "exit" will shutdown the program

# Logging
output/output.log stores all debugging information about the runtime. This includes [INPUT], [DEBUG], [INFO ], [WARN ], [ERROR], and [FATAL].

[INFO ]: Generic information that is expected and part of normal runtime
[INPUT]: Everything the user typed into the program
[DEBUG]: Information only useful for debugging the program
[WARN ]: Something went wrong but is either recoverable or non-urgent and ignoreable
[ERROR]: Something went wrong and was not recoverable causing some part of the program to crash but does not cause the entire program to terminate
[FATAL]: An error occurred that caused the entire program to terminate

All logging messages are succeeded by the file that the error occurred in.
