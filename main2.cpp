#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  // 1. Choose the game
  const string D2 = "d2";
  const string THIEF2 = "thief2";

  vector<string> games = {D2, THIEF2};
  string gamesThroughComma = games[0];
  for (int i = 1; i < games.size(); i++) {
    gamesThroughComma += ", or " + games[i];
  }

  string chosenGame;
  string chooseGameMessage = "Choose "s + gamesThroughComma + ":";
  cout << chooseGameMessage << endl;
  getline(cin, chosenGame);
  while (!(find(begin(games), end(games), chosenGame) != end(games))) {
    cout << "Error: unknown game" << endl;

    cout << chooseGameMessage << endl;
    getline(cin, chosenGame);
  }
}