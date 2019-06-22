#include <iostream>
#include "common.hpp"
using namespace std;

int main() {
	auto head = new LinkedNode( 0);

	// head->appendToTail(1);

	for( auto i=1; i<=10; i++) {
		head->appendToTail( i);
	}
	// cout << *head << endl;
	cout << "Before deletion" << endl;
	displayLinkedList( head);

	cout << "After deletion" << endl;
	head = deleteLinkedNode( head, 11);
	displayLinkedList(head);

	return 0;
}
