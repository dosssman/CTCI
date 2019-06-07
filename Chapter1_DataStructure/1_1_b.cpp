#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
	string str = "no dupess";
	map<char, int> countermap;

	// If empty string return "Empty String"
	bool duplicateFound = false;

	// With while loops

	string::iterator it = str.begin();
	do {
		string::iterator itj = it+1;
		do {
			if( *it == *itj) {
				duplicateFound = true;
			}
			itj++;
		} while( itj != str.end() && !duplicateFound);
		it++;
	} while( it != str.end()-1 && !duplicateFound);


	// With For loops
	// for( string::iterator it=str.begin(); it!=str.end()-1; ++it) {
	// 	for( string::iterator itj = it+1; itj != str.end(); itj++) {
	// 		if ( *it == *itj) {
	// 			duplicateFound = true;
	// 			break;
	// 		}
	// 	}
	// 	if( duplicateFound)
	// 		break;
	// }

	// In the end. ..
	if( duplicateFound)
		cout << "Duplicate found" << endl;
	else
		cout << "Duplicate not found" << endl;

	return 0;
}
