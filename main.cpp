#include <iostream>
#include <string>
using namespace std;

#define GET_VAR_NAME(var) (#var)

string s(char charStr[]) {
  return string(charStr);
}

int main() {
  // 1. Choose the game
  string d2 = "d2";
  string thief2 = "thief2";
  string chosenGame;
  string gamesWithCommas;
  string chooseGameMessage = "Choose "s + GET_VAR_NAME(d2) + " or " + ":";
  cout << chooseGameMessage << endl;
  getline(cin, chosenGame);

  cout << chosenGame << endl;
  cout << (chosenGame == "d2") << endl;
}