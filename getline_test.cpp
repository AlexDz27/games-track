#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include "functions.cpp"
using std::string, std::vector, std::cout, std::endl,
std::atexit, std::ofstream, std::ifstream;
using namespace std::literals;

const string FILE_NAME = "TIMES.txt";

int main() {
  ifstream file;
  file.open(FILE_NAME);

  string line;
  while (getline(file, line)) {
    cout << line << endl;
  }

  file.close();
}