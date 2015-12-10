import os

print os.getcwd()
print os.path.dirname(os.path.realpath(__file__))

os.chdir(os.path.dirname(os.path.realpath(__file__)))
os.chdir('../output/')
os.system("g++ ../main/main.cc -o main && ./main")
