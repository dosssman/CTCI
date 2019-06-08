#include <iostream>
using namespace std;

void reverseStr( char *);

int main() {
	char str[255]="Just testing the reverse function string\0";

	//cout << *(str+1) << endl;
	reverseStr( str);
	cout << str << endl;
	return 0;
}

void reverseStr(  char *str) {
	int tailIdx = 0;

	do {
		tailIdx++;
	}while( str[tailIdx] != '\0');

//	while( str[tailIdx] != '\0') {
//		tailIdx++;
//	}
	tailIdx--;

	cout << str[tailIdx] << endl;

	//cin.get();
	int headIdx =0;

	while(headIdx < tailIdx) {
		char tmp = str[headIdx];
		str[headIdx++] = str[tailIdx];
		str[tailIdx--] = tmp;
	}
}
