#include <iostream>
#include <map>
#include <string>
using namespace std;

#define MAX_SIZE 18

void shift2Right( char *, const int );

int main() {
	char str[MAX_SIZE] = "Mr John Smith\0   ";

	cout << "Before: " << str << endl;

	for( int i = 0; str[i] != '\0'; i++) {
		if( str[i] == ' ') {
			shift2Right( str, i);
			*(str+i) = '%';
			*(str+(i+1)) = '2';
			*(str+(i+2)) = '0';
			
			i+=2;
		}
	}

	cout << str << endl;

	return 0;
}

void shift2Right( char *str, const int currentIdx) {
	int lastIdx = MAX_SIZE-1;
	while( lastIdx > currentIdx+2) {
		str[lastIdx] = str[lastIdx-2];
		lastIdx--;
	}
};
