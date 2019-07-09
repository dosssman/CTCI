#include <iostream>
#include "common.hpp"
#include <vector>

using namespace std;

vector<int> seenValues;

bool isValueSeen( const int &value) {
	for( auto it = seenValues.begin(); it != seenValues.end(); it++) {
		if( *it == value) return true;
	}

	return false;
}

LinkedNode *getDupeNode( LinkedNode *head) {
	auto *current = head;
	while( current != nullptr) {
		if( isValueSeen( current->getValue()) ) {
			return current;
		} else {
			seenValues.push_back( current->getValue());
		}

		current = current->getNext();
	}

	return nullptr;
}

int main() {
	auto *head = new LinkedNode( 1);
	head->appendToTail(2);
	auto loopNode = new LinkedNode( 3);
	head->appendToTail( loopNode);
	head->appendToTail(4);
	head->appendToTail(5);
	head->appendToTail(loopNode);

	cout << "Looping node" << *loopNode << endl;

	auto *dupedNode = getDupeNode( head);
	if( dupedNode == nullptr) {
		cout << "Not loop found" << endl;
	} else {
		cout << "Found lopping noodle " << *dupedNode << endl;
	}

	return 0;
}
