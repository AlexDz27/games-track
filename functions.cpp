#include <vector>
#include <string>
using std::string, std::vector, std::cout, std::endl, 
std::getline, std::cin;

bool vectorContainsString(vector<string> vector, string value) {
  return find(begin(vector), end(vector), value) != end(vector);
}

void displayMessageUntilGameChosen(string &message, vector<string> &games, string &chosenGame) {
  cout << message << endl;
  getline(cin, chosenGame);

  while (!vectorContainsString(games, chosenGame)) {
    cout << "\nError: unknown game" << endl;

    cout << message << endl;
    getline(cin, chosenGame);
  }
}