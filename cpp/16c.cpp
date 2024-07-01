#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<string> readFile(string);
vector<string> processLine(string, int &);
string getTime(int);

int main() {
  const vector<string> lines = readFile("16c.txt");
  cout << lines[0] << endl;
  cout << "------------------------------------------------------" << endl;
  int time = 0;
  const int numWidth = floor(log10(lines.size() - 1)) + 1;
  for (int i = 1; i < lines.size(); i++) {
    vector<string> data = processLine(lines[i], time);
    cout << setw(numWidth) << i << ".  " << data[1] << " " << data[0] << " by "
         << data[2] << endl;
  }
  cout << "------------------------------------------------------" << endl;
  cout << "Total Playing Time: " << getTime(time) << endl;

  return 0;
}

vector<string> readFile(string filename) {
  vector<string> lines;
  ifstream file(filename);
  string line;
  while (getline(file, line)) {
    lines.push_back(line);
  }
  file.close();
  return lines;
}

vector<string> processLine(string line, int &time) {
  vector<string> data;

  line.erase(0, 1);

  const int nameIdx = line.find("\"");
  data.push_back(line.substr(0, nameIdx));
  line.erase(0, nameIdx + 2);

  const int timeIdx = line.find(" ");
  const string timeStr = line.substr(0, timeIdx);
  data.push_back(timeStr);
  const int minutes = stoi(timeStr.substr(0, timeStr.find(":")));
  const int seconds = stoi(timeStr.substr(timeStr.find(":") + 1));
  time += minutes * 60 + seconds;
  line.erase(0, timeIdx + 2);

  data.push_back(line);

  return data;
}

string getTime(int time) {
  const int hours = time / 3600;
  const int minutes = (time % 3600) / 60;
  const int seconds = time % 60;
  return to_string(hours) + ":" + to_string(minutes) + ":" + to_string(seconds);
}