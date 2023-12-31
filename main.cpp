#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <thread>
#include "functions.cpp"
using std::string, std::vector, std::cout, std::endl,
std::ifstream, std::ofstream, std::to_string, std::ios,
std::cin, std::thread;
using namespace std::literals;

bool continueCounting = true;
void observeCancellation() {
  if (cin.get() == '\n') continueCounting = false;
}

void writeTime(string chosenGame, int seconds) {
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
        convertFormattedTimeToSeconds(gameTime) + seconds
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
  thread observeCancellationThread(observeCancellation);
  int i = 1;
  while (continueCounting) {
    _sleep(1000);
    cout << "\r" + convertSecondsToFormattedTime(i);
    i++;
  }

  observeCancellationThread.join();
  writeTime(chosenGame, i);
}