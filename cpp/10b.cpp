#include <iostream>

using namespace std;

void add(int n1, int d1, int n2, int d2, int &n3, int &d3);
void subtract(int n1, int d1, int n2, int d2, int &n3, int &d3);
void multiply(int n1, int d1, int n2, int d2, int &n3, int &d3);
void divide(int n1, int d1, int n2, int d2, int &n3, int &d3);
int findGcd(int n, int d);
void simplify(int n1, int d1, int &n2, int &d2);

int main() {
  char looping;

  do {
    int n1, d1, n2, d2;

    cout << "Enter the numerator and denominator of the first fraction: ";
    cin >> n1 >> d1;

    cout << "Enter the numerator and denominator of the second fraction: ";
    cin >> n2 >> d2;

    cout << endl
         << "Menu of Operations\nAdd...................1\nSubtract..............2\nMultiply..............3\nDivide................4\n\n";

    int operation;
    do {
      cout << "Which operation? ";
      cin >> operation;
    } while (operation != 1 && operation != 2 && operation != 3 &&
             operation != 4);

    if (d1 == 0 || d2 == 0 || (operation == 4 && n2 == 0)) {
      cout << "This results in division by 0, not allowed.\n\n";
      looping = 'y';
      continue;
    }

    int resN, resD;

    switch (operation) {
    case 1:
      add(n1, d1, n2, d2, resN, resD);
      break;
    case 2:
      subtract(n1, d1, n2, d2, resN, resD);
      break;
    case 3:
      multiply(n1, d1, n2, d2, resN, resD);
      break;
    case 4:
      divide(n1, d1, n2, d2, resN, resD);
      break;
    }

    int simN, simD;
    simplify(resN, resD, simN, simD);

    char op;
    switch (operation) {
      case 1:
        op = '+';
        break;
      case 2:
        op = '-';
        break;
      case 3:
        op = '*';
        break;
      case 4:
        op = '/';
        break;
    }

    cout << endl;
    if (simD != 1) {
      cout << " " << n1 << "       " << n2 << "       " << resN << "       " << simN << endl;
      cout << "---  " << op <<"  ---  =  ---  =  ---\n";
      cout << " " << d1 << "       " << d2 << "       " << resD << "       " << simD;
    } else {
      cout << " " << n1 << "       " << n2 << "       " << resN << endl;
      cout << "---  " << op << "  ---  =  ---  =  " << simN << endl;
      cout << " " << d1 << "       " << d2 << "       " << resD;
    }

    cout << endl << endl;

    do {
      cout << "Another problem (y for yes, n for no)? ";
      cin >> looping;
    } while (looping != 'y' && looping != 'n');

     cout << endl;
  } while (looping == 'y');

  return 0;
}

void add(int n1, int d1, int n2, int d2, int &n3, int &d3) {
  n3 = n1 * d2 + n2 * d1;
  d3 = d1 * d2;
}

void subtract(int n1, int d1, int n2, int d2, int &n3, int &d3) {
  n3 = n1 * d2 - n2 * d1;
  d3 = d1 * d2;
}

void multiply(int n1, int d1, int n2, int d2, int &n3, int &d3) {
  n3 = n1 * n2;
  d3 = d1 * d2;
}

void divide(int n1, int d1, int n2, int d2, int &n3, int &d3) {
  n3 = n1 * d2;
  d3 = n2 * d1;
}

int findGcd(int n, int d) {
  if (d == 0) {
    return n;
  } else {
    return findGcd(d, n % d);
  }
}

void simplify(int n1, int d1, int &n2, int &d2) {
  int gcd = findGcd(n1, d1);
  n2 = n1 / gcd;
  d2 = d1 / gcd;
}
