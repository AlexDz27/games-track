#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include "functions.cpp"
using std::string, std::vector, std::cout, std::endl,
std::atexit, std::ifstream, std::ofstream, std::fstream;
using namespace std::literals;

const string FILE_NAME = "TIMES.txt";
string chosenGame;

void writeTime() {
  // ifstream file(FILE_NAME);
  // ofstream fileWriteStream(FILE_NAME);
  fstream fileStream(FILE_NAME);
  // file.open(FILE_NAME);

  string line;
  while (getline(fileStream, line)) {
    vector<string> lineSplit = splitString(line, ":");
    string game = lineSplit[0];
    fileStream.clear();
    if (game == chosenGame) {
      // cout << -std::ios::off_type(line.size()) - 1 << endl;
      // cout << file.cur << endl;
      // cout << line.size() << endl;

      // file.seekp(-std::ios::off_type(line.size()) - 1, file.cur);
      // file << "d2: 1";
      // file << "d2: 12\n";
      // cout << file.tellg() << endl;
      fileStream.seekp(-9, std::ios_base::cur);
      fileStream << "00:00:01";
      break;  // TODO: maybe не нужен, тк уже есть file.clear()
    }
  }

  fileStream.close();
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