import os
import subprocess

# Print current CWD
print os.path.dirname(os.path.realpath(__file__))

# Change CWD to the output folder
os.chdir(os.path.dirname(os.path.realpath(__file__)))
os.chdir('../output/')

# Print CWD to ensure the change was successful
print "CWD: "
print os.getcwd()

# Check to see if there is a dictionary installed
# Currently not necessary to run the script so this will not cause the program to terminate
isdict =  subprocess.call(["sdcv", "-v"], stdout=open(os.devnull, "w"), stderr=subprocess.STDOUT)

if isdict != 0:
  print "Please install sdcv and the Longman Dictionary of Contemporary English\nhttp://askubuntu.com/questions/191125/is-there-an-offline-command-line-dictionary"


print '\n====================================\nBuilding\n====================================\n\n'




# Array of files to build relative to ../main/ (NOT CWD)
buildList = [
  "output/output.cc",
  "input/input.cc",
  "fileio/fileio.cc",
  "conscious/conscious.cc"
]




# Change the build list into one string instead of an array
buildListConcat = ""
for next in buildList:
  print "../main/%s" % next
  buildListConcat += "../main/%s " % next

# Actually compile the files and print any outputs
print "\nBegin:"
buildSuccess = os.system("g++ ../main/main.cc -std=c++0x -pthread %s-o main" % buildListConcat)
print "End."

# If the build exited successfuly, run the output file.
# Will print "Done" if the program exits successfully
if buildSuccess == 0:
  os.system("echo '\n====================================\nBuild Successful. Executing\n====================================\n\n' && ./main && echo '\n====================================\nDone.\n====================================\n'")
else:
  print "\n====================================\nBuild FAILED. Exiting\n====================================\n"
