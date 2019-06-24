#include <iostream>
#include "common.hpp"
using namespace std;

LinkedNode *getKthElementFromEnd( LinkedNode *head, const int &k);

int main() {
	auto head = new LinkedNode( 0);

	for( auto i=1; i<20; i++) {
		head->appendToTail( i);
	}

	displayLinkedList( head);
	cout << "3 from end " << getKthElementFromEnd( head, 3) << endl;

	return 0;
}

LinkedNode *getKthElementFromEnd( LinkedNode *head, const int &k) {
	if( head == NULL) return NULL;

	int dist = 0;

	LinkedNode *frontP = head, *backP = head;

	while( frontP != NULL) {
		frontP = frontP->getNext();
		if( dist == k) {
			backP = backP->getNext();
		} else if( dist < k) {
			dist++;
		}
	}

	if( dist == k) {
		return backP;
	} else {
		return NULL;
	}
}
