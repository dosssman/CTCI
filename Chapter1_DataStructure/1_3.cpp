#include <iostream>
#include <map>
#include <string>
using namespace std;

#define STR_MAX_SIZE 255

bool isPermutation( const string *, const string *);
void displayCharIntMap( const map<char,int> *);

int main() {
	string str1 = "Permutation";
	string str2 = "Pertumation";

	cout << (isPermutation( &str1, &str2) ? "Permutation" : "Not permutation") << endl;

	return 0;
}

void displayCharIntMap( const map<char,int> *map) {
	for( auto &x: *map) {
		cout << x.first << " -> " << x.second << endl;
	}
}

bool isPermutation( const string *str1, const string *str2) {
	if( str1->size() != str2->size()) return false;

	bool isSame = true;

	map<char, int> str1Counter, str2Counter;

	for( int idx=0; idx < str1->size()-1; idx++) {
		if( str1->at(idx) != str2->at(idx)) {
			isSame = false;
		}

		// Counting the occurences
		if( str1Counter.find( str1->at( idx)) == str1Counter.end()) {
			str1Counter.insert( pair<char, int>( str1->at( idx), 1));
		} else {
			str1Counter.at( str1->at( idx))++;
		}

		if( str2Counter.find( str2->at( idx)) == str2Counter.end()) {
			str2Counter.insert( pair<char, int>( str2->at( idx), 1));
		} else {
			str2Counter.at( str2->at( idx))++;
		}
	}


	cout << "checking str1" << endl;
	displayCharIntMap( &str1Counter);

	cout << "checking str2" << endl;
	displayCharIntMap( &str2Counter);

	cin.get();

	for( auto &x: str1Counter) {
		if( str2Counter.find( x.first) == str2Counter.end()) {
			return false;
		}

		if( str2Counter.at( x.first) != x.second) {
			return false;
		}
	}

	if( isSame) {
		cout << "Same string" << endl;
		 return false;
	}

	return true;
}
