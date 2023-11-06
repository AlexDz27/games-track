#include <vector>
#include <string>
using std::string, std::vector, std::cout, std::endl, 
std::getline, std::cin;

bool vectorContainsString(vector<string> vector, string value) {
  return find(begin(vector), end(vector), value) != end(vector);
}

vector<string> splitString(string _string, string delimeter) {
  int prevPos = 0;
  vector<string> resultVector;
  for (int i = 0; _string.find(delimeter, prevPos) != -1; i++) {
    int currentPos = _string.find(delimeter, prevPos + 1);

    string substred;
    if (i == 0) {
      substred = _string.substr(0, currentPos);
    } else {
      substred = _string.substr(prevPos + delimeter.length(), currentPos - prevPos - delimeter.length());
    }

    prevPos = currentPos;

    resultVector.push_back(substred);
  }

  return resultVector;
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