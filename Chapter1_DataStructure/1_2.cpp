#include <iostream>
#include <map>
#include <string>
using namespace std;

#define STR_MAX_SIZE 255

void reverseStr( char *str) {
	// TODO Check if string is empty then react

	char *headPointer = str;
	char *endPointer = str;

	cout << headPointer << endl;
	cout << endPointer << endl;

	while( *endPointer != '\0') {
		// cout << "Checking " << *endPointer;
		// cin.get();

		endPointer++;
	}

	cout << "Starting pointer " << &headPointer << endl;
	cout << "Ending pointer " << &endPointer << endl;
};

int main() {

	char str[STR_MAX_SIZE] = "Justing testing the reverse function\0";

	reverseStr( str);

	return 0;
}
