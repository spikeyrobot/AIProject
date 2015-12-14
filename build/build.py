import os

print os.path.dirname(os.path.realpath(__file__))

os.chdir(os.path.dirname(os.path.realpath(__file__)))
os.chdir('../output/')

print os.getcwd()


print '\n====================================\nBuilding main/main.cc\n====================================\n\n'
os.system("g++ ../main/main.cc -std=c++0x -pthread ../main/output/output.cc ../main/input/input.cc ../main/fileio/fileio.cc -o main && echo '\n====================================\nBuild Successful. Executing\n====================================\n\n' && ./main && echo '\n====================================\nDone.\n====================================\n'")
