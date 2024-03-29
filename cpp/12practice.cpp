#include <iostream>

using namespace std;

string getFirstName(string first, string last);
string getLastName(string grandparent, string town);

int main() {
	cout << "Hello, welcome to the Star Wars Name Generator\n\n";

	string first, last, grandparent, town;
	cout << "Enter your first name: ";
	cin >> first;
	cout << "Enter your last name: ";
	cin >> last;
	cout << "Enter your grandparents' last name: ";
	cin >> grandparent;
	cout << "Enter the name of the town you were born in: ";
	cin >> town;

	cout << "\nYour Star Wars Name is: " << getFirstName(first, last) << " " << getLastName(grandparent, town) << endl;
}

string getFirstName(string first, string last) {
	return last.substr(0, 3) + (char)(first[0] + 32) + first[1];
}

string getLastName(string grandparent, string town) {
	return grandparent.substr(0, 2) + (char)(town[0] + 32) + town[1] + town[2];
}