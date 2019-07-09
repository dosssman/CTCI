#include <iostream>
#include "common.hpp"
#include <vector>

using namespace std;

bool iosPalindrome( LinkedNode *head);

int main() {
    auto *head = new LinkedNode( 0);
    for( auto i=1; i<5; i++)
        head->appendToTail( i);

    head->appendToTail( 5);
    head->appendToTail( 5);

    for( auto i=4; i>=0; i--)
        head->appendToTail(i);

    cout << "List content " << endl;
    displayLinkedList( head);

    cout << "Is palindrome ? " << iosPalindrome(head) << endl;

    return 0;
}

bool iosPalindrome( LinkedNode *head) {
    int curPos = 0;
    auto *current = head;
    auto *currOpp = getKthElementFromEnd( head, curPos+1);
    while( current != currOpp ) {
        if( current->getValue() != currOpp->getValue())
            return false;
        current = current->getNext();
        currOpp = getKthElementFromEnd( head, (++curPos)+1);
        if( current == currOpp->getNext()) break;
    }

    return true;
}
