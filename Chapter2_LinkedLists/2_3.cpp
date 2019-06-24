#include <iostream>
#include "common.hpp"
using namespace std;

void deleteThisSpecificNode( LinkedNode *node);

int main() {
	auto head = new LinkedNode( 0);

	for( auto i=1; i<5; i++) {
		head->appendToTail( i);
	}

	cout << "Before " << endl;
	displayLinkedList(head);

	cout << "After " << endl;
	deleteThisSpecificNode( getNodeByValue( head, 2));
	displayLinkedList(head);

	return 0;
}

void deleteThisSpecificNode( LinkedNode *node) {
	if( node == NULL) {
		cout << "Invalid node passed" << endl;
		return;
	}

	LinkedNode *current = node;

	while( current->getNext()->getNext() != NULL) {
		current->setValue( current->getNext()->getValue());
		current = current->getNext();
	}
	current->setValue( current->getNext()->getValue());
	free( current->getNext());
	current->setNext(NULL);
}
