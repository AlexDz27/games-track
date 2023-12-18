#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <thread>
#include "functions.cpp"
using std::string, std::vector, std::cout, std::endl,
std::ifstream, std::ofstream, std::to_string, std::ios;
using namespace std::literals;

bool weCount = true;
void someT() {
  if (std::cin.get() == '\n') weCount = false;
}

// TODO: DAYS
void writeTime(string chosenGame) {
  const string FILE_NAME = "TIMES.txt";
  ifstream fileStreamRead(FILE_NAME);
  vector<string> gamesWithTimes;

  string line;
  while (getline(fileStreamRead, line)) {
    vector<string> lineSplit = splitString(line, ": ");
    string game = lineSplit[0];
    string gameTime = lineSplit[1];
    if (game == chosenGame) {
      gameTime = convertSecondsToFormattedTime(
        convertFormattedTimeToSeconds(gameTime) + 1
      );
      gamesWithTimes.push_back(game + ": " + gameTime + "\n");
    } else {
      gamesWithTimes.push_back(line + "\n");
    }
  }
  fileStreamRead.close();

  ofstream fileStreamWrite(FILE_NAME, ios::trunc);
  for (auto it : gamesWithTimes) {
    fileStreamWrite << it;
  }
  fileStreamWrite.close();
}

int main() {
  const string D2 = "d2";
  const string THIEF2 = "thief2";
  const string DM2 = "dm2";
  vector<string> games = {D2, THIEF2, DM2};
  string gamesThroughComma = games[0];
  for (int i = 1; i < games.size(); i++) {
    gamesThroughComma += ", or " + games[i];
  }

  string chosenGame;
  string chooseGameMessage = "Choose "s + gamesThroughComma + ":";
  displayMessageUntilGameChosen(chooseGameMessage, games, chosenGame);

  cout << "\n";
  std::thread worker(someT);
  for (int i = 1; ; i++) {
    if (!weCount) {
      // worker.join();
      return 0;
    }

    _sleep(1000);
    writeTime(chosenGame);
    cout << "\r" + convertSecondsToFormattedTime(i);
  }
}