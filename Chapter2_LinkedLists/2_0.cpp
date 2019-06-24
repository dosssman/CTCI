#include <iostream>
#include "common.hpp"
using namespace std;

void rearrange( LinkedNode *);

int main() {
	auto head = new LinkedNode( 0);

	for( auto i=1; i<20; i++)
		head->appendToTail( i);

	// cout << "List length = " << getListLength( head) << endl;
	cout << "List before rearrange" << endl;
	displayLinkedList( head);

	cout << "List After rearrange" << endl;
	rearrange( head);
	displayLinkedList( head);

	return 0;
}

void rearrange( LinkedNode *head) {
	if (head == NULL || head->getNext() == NULL) {
		cout << "Invalid list provided";
		return;
	}

	LinkedNode *pFast = head->getNext(), *pSlow = head;
	while( pFast->getNext() != NULL && pFast->getNext()->getNext() != NULL) {
		pFast = pFast->getNext()->getNext();
		pSlow = pSlow->getNext();
	}

	// cout << "PSLOW " << pSlow << endl;
	// cout << "pfast " << pFast << endl;
	// cin.get();

	pFast = head;

	while( pFast->getNext()->getNext() != NULL) {
		LinkedNode *tmp = pSlow->getNext();
		pSlow->setNext( tmp->getNext());
		tmp->setNext( pFast->getNext());
		pFast->setNext( tmp);
		pFast = pFast->getNext()->getNext();

		// displayLinkedList( head);
		//
		// cin.get();
	}
}
