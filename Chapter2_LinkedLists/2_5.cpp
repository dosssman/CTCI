#include <iostream>
#include "common.hpp"
using namespace std;

LinkedNode *sumLinkedLists( LinkedNode *, LinkedNode *);

int main() {
	auto head1 = new LinkedNode( 7);
	head1->appendToTail(1);
	head1->appendToTail(6);
	head1->appendToTail(1);

	auto head2 = new LinkedNode( 5);
	head2->appendToTail(9);
	// head2->appendToTail(2);

	cout << "First list" << endl;
	displayLinkedList( head1);

	cout << "Second list" << endl;
	displayLinkedList( head2);

	cout << "Result list" << endl;
	auto sumedLIst = sumLinkedLists( head1, head2);
	displayLinkedList( sumedLIst);

	return 0;
}

LinkedNode *sumLinkedLists( LinkedNode *head1, LinkedNode *head2) {
	int carry = 0;
	LinkedNode *resNode = NULL;
	int newValue;

	while( head1 != NULL || head2 != NULL) {

		newValue = carry;
		if( head1 != NULL)
			newValue += head1->getValue();
		if( head2 != NULL)
			newValue += head2->getValue();

		carry = newValue / 10;
		newValue = newValue % 10;

		if( resNode == NULL) {
			resNode = new LinkedNode( newValue);
		} else {
			resNode->appendToTail( new LinkedNode( newValue));
		}

		if( head1 != NULL) head1 = head1->getNext();
		if( head2 != NULL) head2 = head2->getNext();
	}

	// In case result list is bigger than input
	if( carry > 0)
		resNode->appendToTail(carry);

	return resNode;
}
