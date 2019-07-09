#include <iostream>
#include "common.hpp"
using namespace std;

LinkedNode *sumLinkedLists2( LinkedNode *, LinkedNode *, int);

int main() {
	auto head1 = new LinkedNode( 6);
	head1->appendToTail(1);
	head1->appendToTail(7);

	auto head2 = new LinkedNode( 2);
	head2->appendToTail(9);
	head2->appendToTail(5);

	cout << "First list" << endl;
	displayLinkedList( head1);

	cout << "Second list" << endl;
	displayLinkedList( head2);

	cout << "Result list" << endl;
	auto sumedLIst = sumLinkedLists2( head1, head2, 0);
	displayLinkedList( sumedLIst);

	return 0;
}

LinkedNode *sumLinkedLists2( LinkedNode *head1, LinkedNode *head2, int rank) {
	LinkedNode *resNode = new LinkedNode();
	if( head1 != nullptr && head2 != nullptr) {
		if( head1->getNext() != nullptr & head2->getNext() != nullptr) {
			resNode->setNext( sumLinkedLists2(head1->getNext(),
			 	head2->getNext(), rank+1));
			resNode->setValue( resNode->getNext()->getValue() / 10
				+ head1->getValue() + head2->getValue());
			resNode->getNext()->setValue( resNode->getNext()->getValue() % 10);
		}
		else if (head1->getNext() == nullptr & head2->getNext() == nullptr) {
			resNode->setValue( head1->getValue() + head2->getValue());
			// return resNode;
		} else {
			resNode->setNext( sumLinkedLists2( head1->getNext(), head2->getNext(), rank+1));
			resNode->setValue( head1->getValue() + head2->getValue());
		}
	}
	else if ( head1 == nullptr && head2 == nullptr) {
		return nullptr;
	} else if ( head1 == nullptr && head2->getNext() != nullptr) {
		resNode->setNext( sumLinkedLists2(nullptr, head2->getNext(), rank+1));
		resNode->setValue( head2->getValue());
	} else {
		resNode->setNext( sumLinkedLists2( head1->getNext(), nullptr, rank+1));
		resNode->setValue( head1->getValue());
	}

	if( rank == 0 && resNode->getValue() > 9) {
		LinkedNode *tmp = resNode;
		resNode = new LinkedNode( tmp->getValue() /10);
		tmp->setValue( tmp->getValue() % 10);
		resNode->setNext( tmp);
	}

	return resNode;
}
