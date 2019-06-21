#include <iostream>
#include "common.hpp"
using namespace std;

ostream &operator<<( ostream &output, LinkedNode &p) {
	output << "Address: " << p << " Value: " << p.getValue() << endl;
	return output;
}

int main() {
	auto head = new LinkedNode( 0);
	cout << * head;

	return 0;
}
