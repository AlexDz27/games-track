#include <iostream>
#include <string>
using namespace std;

int main() {
  // 1. Choose the game
  const string D2 = "d2";
  const string THIEF2 = "thief2";

  string gamesThroughComma = D2;
  string otherGames[] = {THIEF2};
  for (string game: otherGames) {
    gamesThroughComma += ", or " + game;
  }

  string chosenGame;
  string chooseGameMessage = "Choose "s + gamesThroughComma + ":";
  cout << chooseGameMessage << endl;
  getline(cin, chosenGame);
  cout << chosenGame << endl;
  // if (cho)
}