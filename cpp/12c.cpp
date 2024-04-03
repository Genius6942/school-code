#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

vector<int> readFile(string filename);
int getChoice();
void displayVector(vector<int> numbers);
int range(vector<int> sorted);
double mean(vector<int> numbers);
double median(vector<int> numbers);
vector<int> mode(vector<int> numbers);
double stddev(vector<int> numbers);

int main() {
  vector<int> numbers = readFile("12c.txt");

  cout << "Original numbers: " << endl;
  displayVector(numbers);

  sort(numbers.begin(), numbers.end());

  cout << "Sorted numbers: " << endl;
  displayVector(numbers);

  int choice;
  do {
    choice = getChoice();
    switch (choice) {
			case 1:
				cout << "Range: " << range(numbers) << endl;
				break;
			case 2:
				cout << "Mean: " << mean(numbers) << endl;
				break;
			case 3:
				cout << "Median: " << median(numbers) << endl;
				break;
			case 4: {
				vector<int> modes = mode(numbers);
				cout << "Mode(s): ";
				for (int i = 0; i < modes.size(); i++) {
					cout << modes[i] << " ";
				}
				cout << endl;
			} break;
			case 5:
				cout << "Standard Deviation: " << stddev(numbers) << endl;
				break;
			default:
				cout << "Invalid choice!" << endl;
				break;
    }
  } while (choice != 0);

  cout << "Thank you for using the stats calculator! See you next time!"
       << endl;
  return 0;
}

vector<int> readFile(string filename) {
  ifstream file(filename);
  vector<int> numbers;
  int number;
  while (file >> number) {
    numbers.push_back(number);
  }
  file.close();
  return numbers;
}

int getChoice() {
  int choice;
  cout << "1. Range" << endl;
  cout << "2. Mean" << endl;
  cout << "3. Median" << endl;
  cout << "4. Mode" << endl;
  cout << "5. Standard Deviation" << endl;
  cout << "0. Exit" << endl;
  do {
    cout << "Enter your choice: ";
    cin >> choice;
  } while (choice < 0 || choice > 5);
  return choice;
}

void displayVector(vector<int> numbers) {
  for (int i = 0; i < numbers.size(); i++) {
    cout << numbers[i] << " ";
    if ((i + 1) % 10 == 0) {
      cout << endl;
    }
  }
  cout << endl;
}

int range(vector<int> sorted) { return sorted[sorted.size() - 1] - sorted[0]; }

double mean(vector<int> numbers) {
  double sum = 0;
  for (int i = 0; i < numbers.size(); i++) {
    sum += numbers[i];
  }
  return sum / numbers.size();
}

double median(vector<int> numbers) {
  if (numbers.size() % 2 == 0) {
    return (numbers[numbers.size() / 2 - 1] + numbers[numbers.size() / 2]) /
           2.0;
  } else {
    return numbers[numbers.size() / 2];
  }
}

vector<int> mode(vector<int> numbers) {
  vector<int> modes;
  int maxCount = 0;
  for (int i = 0; i < numbers.size(); i++) {
    int count = 0;
    for (int j = 0; j < numbers.size(); j++) {
      if (numbers[j] == numbers[i]) {
        count++;
      }
    }
    if (count > maxCount) {
      modes.clear();
      modes.push_back(numbers[i]);
      maxCount = count;
    } else if (count == maxCount) {
      modes.push_back(numbers[i]);
    }
  }

  for (int i = modes.size() - 1; i >= 0; i--) {
    for (int j = 0; j < i; j++) {
      if (modes[i] == modes[j]) {
        modes.erase(modes.begin() + i);
        break;
      }
    }
  }

  return modes;
}

double stddev(vector<int> numbers) {
  double sum = 0;
  double meanValue = mean(numbers);
  for (int i = 0; i < numbers.size(); i++) {
    sum += (numbers[i] - meanValue) * (numbers[i] - meanValue);
  }
  return sqrt(sum / (numbers.size() - 1));
}