#include <iostream>
#include "common.hpp"
using namespace std;

int main() {
	auto head = new LinkedNode( 0);

	for( auto i=1; i<5; i++) {
		head->appendToTail( i);
	}

	return 0;
}
