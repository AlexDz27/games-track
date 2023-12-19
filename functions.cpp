#include <vector>
#include <string>
using std::string, std::vector, std::cout, std::endl, 
std::getline, std::cin, std::to_string;

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

int convertFormattedTimeToSeconds(string formattedTime) {
  vector<string> splitFormattedTime = splitString(formattedTime, ":");
  string takenSecondsString = splitFormattedTime[2];
  int takenSeconds = stoi(takenSecondsString);

  string takenMinutesString = splitFormattedTime[1];
  int takenMinutes = stoi(takenMinutesString);

  string takenHoursString = splitFormattedTime[0];
  int takenHours = stoi(takenHoursString);


  int totalSeconds = takenSeconds;

  int takenMinutesToSeconds = takenMinutes * 60;
  totalSeconds += takenMinutesToSeconds;

  int takenHoursToSeconds = takenHours * 60 * 60;
  totalSeconds += takenHoursToSeconds;

  vector<string> splitFormattedTimeWithDays = splitString(formattedTime, " ");
  if (!splitFormattedTimeWithDays.empty()) {
    vector<string> splitDays = splitString(splitFormattedTimeWithDays[0], "d");
    int takenDays = stoi(splitDays[0]);
    int takenDaysToSeconds = takenDays * 86400;
    totalSeconds += takenDaysToSeconds;
  }

  return totalSeconds;
}

string convertSecondsToFormattedTime(int seconds) {
  int days = seconds / 60 / 60 / 24;
  string daysString;
  if (days > 0) daysString = to_string(days) + "d ";

  int hours = seconds / 60 / 60 - days * 24;
  string hoursString = to_string(hours);
  if (hours < 10) hoursString = "0" + hoursString;
  int secondsToConvertLeft = seconds - (hours + days * 24) * 3600;

  int minutes = secondsToConvertLeft / 60;
  string minutesString = to_string(minutes);
  if (minutes < 10) minutesString = "0" + minutesString;
  secondsToConvertLeft = secondsToConvertLeft - minutes * 60;

  string secondsString = to_string(secondsToConvertLeft);
  if (secondsToConvertLeft < 10) secondsString = "0" + secondsString;

  return daysString + hoursString + ":" + minutesString + ":" + secondsString;
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