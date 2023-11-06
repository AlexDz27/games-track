#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include "functions.cpp"
using std::string, std::vector, std::cout, std::endl,
std::atexit, std::ifstream;
using namespace std::literals;

const string FILE_NAME = "TIMES.txt";
string chosenGame;

void writeTime() {
  ifstream file;
  file.open(FILE_NAME);

  string line;
  while (getline(file, line)) {
    vector<string> lineSplit = splitString(line, ":");
    if (lineSplit[0] == chosenGame) {
      cout << lineSplit[0] << endl;
    }
  }

  file.close();
}

int main() {
  const string D2 = "d2";
  const string THIEF2 = "thief2";
  vector<string> games = {D2, THIEF2};
  string gamesThroughComma = games[0];
  for (int i = 1; i < games.size(); i++) {
    gamesThroughComma += ", or " + games[i];
  }

  string chooseGameMessage = "Choose "s + gamesThroughComma + ":";
  displayMessageUntilGameChosen(chooseGameMessage, games, chosenGame);

  time_t start = time(nullptr);

  atexit(writeTime);
}