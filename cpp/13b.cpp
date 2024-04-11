#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ifstream file("13b.txt");

  vector<vector<int>> data;
  for (int i = 0; i < 10; i++) {
    data.push_back({});
    for (int j = 0; j < 15; j++) {
      int n;
      file >> n;
      data[i].push_back(n);
    }
  }

  cout << "Lab Averages:\n";
  for (int i = 0; i < 10; i++) {
    double sum = 0;
    for (int j = 0; j < 15; j++)
      sum += data[i][j];
    sum = sum / 15;
    cout << "Lab " << i + 1 << ": " << sum << endl;
  }

  cout << "\nGrade Averages:\n";
  for (int j = 0; j < 15; j++) {
    double sum = 0;
    for (int i = 0; i < 10; i++)
      sum += data[i][j];
    sum = sum / 10;
    cout << "Student " << j + 1 << ": " << sum << endl;
  }
}