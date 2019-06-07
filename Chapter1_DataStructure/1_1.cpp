#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
	string str = "Just testing now";
	map<char, int> countermap;

	for( string::iterator it=str.begin(); it!=str.end(); ++it) {
		// cout << "Processing " << *it;
		if( countermap.find( (char) *it) == countermap.end()) {
			// cout << " not found" << endl;
			countermap.insert( pair< char, int>( (char) *it, 1));
		} else {
			// cout << " found" << endl;
			// When found a character which occurs twice, return false and break;
			// countermap.at( (char) *it)++;
			cout << "Contains duplicate" << endl;
			break;
		}
	}

	// for( auto &x: countermap) {
	// 	cout << x.first << ": " << x.second << endl;
	// }

	return 0;
}
