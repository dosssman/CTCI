#include <iostream>
#include "common.hpp"
using namespace std;

int main() {
	MyQFromStacks<int> qfs;
	for( auto i=0; i <10; i++) {
		qfs.push( i);
	}
	qfs.display();
	qfs.pop();
	qfs.display();
	qfs.push(50);
	qfs.display();

  return 0;
}
