#include <iostream>
#include <map>
#include <string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

char *compStr( char *) ;

#define MAX_SIZE 255

int main() {
  char str[MAX_SIZE] = "aabcaaacccabbba";

  char *compedStr = compStr( str);

  cout << compedStr << endl;

  return 0;
}

char *compStr( char *str) {
  char lastChar = '\0';
  int counter = 0;
  bool foundBigger = false;
  int strIdx = 0, compIdx = 0;
  char *compedStr = (char*) malloc( sizeof( char) *MAX_SIZE);

  while( str[strIdx] != '\0') {
    if( lastChar == '\0') {
      lastChar = str[strIdx];
      compedStr[compIdx++] = str[strIdx++];
      counter = 1;
    } else {
      if( lastChar == str[strIdx]) {
        counter++;
        if( counter >1 && !foundBigger)
          foundBigger = true;

        strIdx++;
      } else {
        lastChar ='\0';
        sprintf( (compedStr+compIdx), "%d", counter);
        int counterLength = 1;
        while( counterLength /= 10) {
          counterLength++;
        }
        compIdx += counterLength+1;
      }
    }
  }

  if( foundBigger)
    return compedStr;

  return str;
}
