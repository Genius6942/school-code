#include <iostream>

using namespace std;

int main() {
	srand(time(0));
  int n1, n2, n3, n4;

  bool prompting = false;
  string prompt;

  cout << "Welcome to the Hallmark Movie Plot Generator!\n\n";

  do {
    cout << "Would you like to generate a possible plot? (Yes / No) ";
    cin >> prompt;
  } while (prompt != "Yes" && prompt != "No");

  while (prompt == "Yes") {
    cout << "\nEnter the first name of the your main character: ";

    string name;
    cin >> name;

		n1 = rand() % 5 + 1;
		n2 = rand() % 5 + 1;
		n3 = rand() % 5 + 1;
		n4 = rand() % 5 + 1;

    string s1, s2, s3, s4;

    switch (n1) {
    case 1:
      s1 = "big city";
      break;
    case 2:
      s1 = "career-oriented";
      break;
    case 3:
      s1 = "recently single";
      break;
    case 4:
      s1 = "world-weary";
      break;
    case 5:
      s1 = "with the wrong guy";
      break;
    }

    switch (n2) {
    case 1:
      s2 = "lawyer";
      break;
    case 2:
      s2 = "writer";
      break;
    case 3:
      s2 = "baker";
      break;
    case 4:
      s2 = "interior designer";
      break;
    case 5:
      s2 = "early 2000's actor you forgot about";
      break;
    }

    switch (n3) {
    case 1:
      s3 = "to inherit something";
      break;
    case 2:
      s3 = "to enter a folksy contest";
      break;
    case 3:
      s3 = "to stop some corporate closure";
      break;
    case 4:
      s3 = "to save the family business";
      break;
    case 5:
      s3 = "to appease their sassy friend or widowed parent";
      break;
    }

    switch (n4) {
    case 1:
      s4 = "with a sensitive guy in plaid";
      break;
    case 2:
      s4 = "with an old flame";
      break;
    case 3:
      s4 = "with some guy and his dog";
      break;
    case 4:
      s4 = "with a single dad and his precious child";
      break;
    case 5:
      s4 = "with Christmas, the town, and some guy";
      break;
    }

    cout << "\n"
         << name << ", a " << s1 << " " << s2 << ",\n  returns to her small town at christmas time\n  " << s3
         << "\n  and magically falls in love\n  " << s4
         << "...\nand also the only man in town might actually be the real Santa Claus\n\n";

    do {
      cout << "Would you like to hear another plot (Yes / No) ";
      cin >> prompt;
    } while (prompt != "Yes" && prompt != "No");
  }

  cout << "\nThanks for using the Hallmark Movie Plot Generator!\nHave a "
          "great rest of your day !\n";

  return 0;
}
