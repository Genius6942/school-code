#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

vector<int> getNumber();
vector<int> add(vector<int>, vector<int>);

int main() {
  const vector<int> num1 = getNumber();
  const vector<int> num2 = getNumber();

  vector<int> sum = add(num1, num2);

  cout << "\nThe sum is: ";
  for (int i = 0; i < sum.size(); i++) {
    cout << sum[i];
  }
  cout << endl;
}

vector<int> getNumber() {
  string numStr;
  cout << "Enter number: ";
  cin >> numStr;

  vector<int> num;
  for (int i = 0; i < numStr.size(); i++) {
    num.push_back(numStr[i] - '0');
  }

  return num;
}

vector<int> add(vector<int> num1, vector<int> num2) {
  vector<int> sum;
  
  int carry = 0;
  int idx = 0;
  while (idx < num1.size() || idx < num2.size()) {
    int dig1 = idx < num1.size() ? num1[num1.size() - 1 - idx] : 0;
    int dig2 = idx < num2.size() ? num2[num2.size() - 1 - idx] : 0;
    int sumDigit = dig1 + dig2 + carry;
    sum.push_back(sumDigit % 10);
    carry = sumDigit / 10;
    idx++;
  }

  if (carry > 0) {
    sum.push_back(carry);
  }

  // reverse
  reverse(sum.begin(), sum.end());
  return sum;
}

