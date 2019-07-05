#include <iostream>
using namespace std;

class LinkedNode {

// friend std::ostream &operator<<( std::ostream& output, LinkedNode &p);

private:
  LinkedNode *next;
  int *value;
public:
  LinkedNode *getNext() {
    return next;
  }

  void setNext( LinkedNode *node) {
    // if( next != NULL) {
    //   free( next);
    //   next = NULL;
    // }
    next = node;
  }

  int getValue() {
    return *value;
  }

  int *setValue( const int v) {
    if( value != NULL) {
      free( value);
      value = NULL;
    }
    value = new int( v);

    return value;
  }

  LinkedNode *appendToTail( const int &v) {
    LinkedNode *head = this;
    while( head->getNext() != NULL) {
      head = head->getNext();
    }

    head->setNext( new LinkedNode( v));

    return head->getNext();
  }

  LinkedNode *appendToTail( LinkedNode *node) {
    LinkedNode *head = this;
    while( head->getNext() != NULL) {
      head = head->getNext();
    }
    head->setNext( node);

    return head->getNext();
  }

  // Constructors and Deconstructors
  LinkedNode() {
    next = NULL;
    value = NULL;
  }
  LinkedNode( const int v) {
    this->value = new int( v);
    this->next = NULL;
  }
  LinkedNode( const int v, LinkedNode *next) {
    this->value = new int( v);
    this->next = next;
  }
  ~LinkedNode() {
    free( next);
    free( value);
  }

};

// Override cout << for easy display
ostream &operator<<( ostream &output, LinkedNode &p) {
	output << "Address: " << &p << " -- Value: " << p.getValue() << " -- Next: " << p.getNext();

	return output;
}

// Display a linked list
void displayLinkedList( LinkedNode *head) {
  if( head == NULL)
    cout << "Passed NULL" << endl;

  LinkedNode *current = head;
  while( current != NULL) {
    cout << *current << endl;
    current = current->getNext();
  }
}

// Delete a node from the list
LinkedNode *deleteLinkedNode( LinkedNode *head, const int &v) {
  if( head == NULL) {
    cout << "Passed NULL" << endl;
    return head;
  }

  if( head->getValue() == v) {
    LinkedNode *tmp = head->getNext();
    head->setNext( NULL);
    free( head);
    return tmp;
  }

  LinkedNode *current = head;
  while( current != NULL ) {
    if( current->getNext() != NULL && current->getNext()->getValue() == v) {
      break;
    } else {
      current = current->getNext();
    }
  }

  if( current == NULL) {
    cout << "Value not found" << endl;
    return head;
  } else {
    LinkedNode *tmp = current->getNext();
    current->setNext( tmp->getNext());
    tmp->setNext( NULL);
    free( tmp);

    return head;
  }

}

int getListLength( LinkedNode *head) {
  if ( head == NULL) return 0;

  LinkedNode *current = head->getNext();
  int counter = 1;

  while( current != NULL) {
    counter++;
    current = current->getNext();
  }

  return counter++;
}


LinkedNode *getNodeByValue( LinkedNode *head, const int &v) {
  if( head ==NULL)
    return NULL;

  LinkedNode *current = head;

  while( current != NULL) {
    if( current->getValue() == v)
      return current;

    current = current->getNext();
  }

  return NULL;
}

LinkedNode *getParentNodeByValue( LinkedNode *head, const int &v) {
  if( head ==NULL)
    return NULL;

  LinkedNode *current = head;

  while( current->getNext() != NULL) {
    if( current->getNext()->getValue() == v)
      return current;

    current = current->getNext();
  }

  return NULL;
}

LinkedNode *getParentNode( LinkedNode *head, LinkedNode* targetNode) {
  if( head ==NULL)
    return NULL;

  LinkedNode *current = head;
  while( current->getNext() != NULL) {
    if( current->getNext() == targetNode ) {
      return current;
    }
    current = current->getNext();
  }

  return NULL;
}
