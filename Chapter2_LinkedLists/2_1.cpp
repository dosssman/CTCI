#include <iostream>
#include "common.hpp"
using namespace std;

void removeDuplicates( LinkedNode *node);

int main() {
	auto head = new LinkedNode( 0);

	// head->appendToTail(1);

	for( auto i=1; i<5; i++) {
		head->appendToTail( i);
	}

	head->appendToTail( 4);

	for( auto i=5; i<10; i++)
		head->appendToTail( i);

	cout << "Original list" << endl;

	displayLinkedList( head);

	cout << "List after dupliactaes deletion" << endl;
	removeDuplicates( head);
	displayLinkedList( head);

	return 0;
}

void removeDuplicates( LinkedNode *node) {
	LinkedNode *head, *current;
	head = node;
	while( head != NULL) {
		current = head->getNext();
		while( current != NULL) {
			if( current->getValue() == head->getValue()) {
				// Found a dupliacte
				head->setNext( current->getNext());
				current->setNext( NULL);
				free( current);
				current = head->getNext();
			} else {
				current = current->getNext();
			}
		}

		head = head->getNext();
	}
}
