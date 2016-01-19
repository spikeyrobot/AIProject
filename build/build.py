import os
import subprocess

print os.path.dirname(os.path.realpath(__file__))

os.chdir(os.path.dirname(os.path.realpath(__file__)))
os.chdir('../output/')

print "CWD: "
print os.getcwd()

isdict =  subprocess.call(["sdcv", "-v"], stdout=open(os.devnull, "w"), stderr=subprocess.STDOUT)

if isdict != 0:
  print "Please install sdcv and the Longman Dictionary of Contemporary English\nhttp://askubuntu.com/questions/191125/is-there-an-offline-command-line-dictionary"

print '\n====================================\nBuilding\n====================================\n\n'

# Array of files to build relative to ../main/ NOT CWD
buildList = [
  "output/output.cc",
  "input/input.cc",
  "fileio/fileio.cc",
  "conscious/conscious.cc"
]

buildListConcat = ""
for next in buildList:
  print "../main/%s" % next
  buildListConcat += "../main/%s " % next

print "\nBegin:"
buildSuccess = os.system("g++ ../main/main.cc -std=c++0x -pthread %s-o main" % buildListConcat)
print "End."

if buildSuccess == 0:
  os.system("echo '\n====================================\nBuild Successful. Executing\n====================================\n\n' && ./main && echo '\n====================================\nDone.\n====================================\n'")
print buildSuccess
