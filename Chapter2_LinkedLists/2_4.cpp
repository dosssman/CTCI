#include <iostream>
#include "common.hpp"
using namespace std;

LinkedNode *repartition( LinkedNode *, int);

int main() {
	auto head = new LinkedNode( 6);

	for( auto i=2; i<5; i++) {
		head->appendToTail( 5+i);
	}
	head->appendToTail(5);
	for( auto i=1; i<5; i++) {
		head->appendToTail( i);
	}

	cout << "Before rearange" << endl;
	displayLinkedList( head);

	cout << "Ater rearange" << endl;
	head = repartition( head, 5);
	displayLinkedList(head);

	return 0;
}

LinkedNode *repartition( LinkedNode *head, int pivotValue) {
	if( head == NULL) {
		cout << "Passed null list" << endl;
		return head;
	}

	auto pivotNode = getNodeByValue( head, pivotValue);
	LinkedNode *current = head;
	bool isBefore = true;
	while( current != NULL) {
		if( current->getValue() == pivotValue) {
			isBefore = false;
			current = current->getNext();
		} else if( current->getValue() < pivotValue) {
			if( !isBefore) {
				LinkedNode *pivotParent = getParentNodeByValue( head, pivotValue);
				// Refactored
				LinkedNode *currentParent = getParentNode( head, current);
				currentParent->setNext( current->getNext());
				current->setNext( pivotNode);

				if( pivotParent == NULL) {
					head=current;
					current = currentParent->getNext();
				} else {
					pivotParent->setNext( current);
					current->setNext( pivotNode);
					current = currentParent->getNext();
				}
			} else {
				current = current->getNext();
			}
		} else {
			if( isBefore) {
				LinkedNode *currentParent = getParentNode( head, current);
				if( currentParent == NULL) {
					head = current->getNext();
					current->setNext( pivotNode->getNext());
					pivotNode->setNext( current);
					current = head;
				} else {
					currentParent->setNext( current->getNext());
					current->setNext( pivotNode->getNext());
					pivotNode->setNext( current);
					current = currentParent->getNext();
				}
			} else {
				current = current->getNext();
			}
		}
	}

	return head;
}
