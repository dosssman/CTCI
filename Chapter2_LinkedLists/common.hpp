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
    // if( next !=  nullptr) {
    //   free( next);
    //   next =  nullptr;
    // }
    next = node;
  }

  int getValue() {
    return *value;
  }

  int *setValue( const int v) {
    if( value !=  nullptr) {
      free( value);
      value =  nullptr;
    }
    value = new int( v);

    return value;
  }

  LinkedNode *appendToTail( const int &v) {
    LinkedNode *head = this;
    while( head->getNext() !=  nullptr) {
      head = head->getNext();
    }

    head->setNext( new LinkedNode( v));

    return head->getNext();
  }

  LinkedNode *appendToTail( LinkedNode *node) {
    LinkedNode *head = this;
    while( head->getNext() !=  nullptr) {
      head = head->getNext();
    }
    head->setNext( node);

    return head->getNext();
  }

  // Constructors and Deconstructors
  LinkedNode() {
    next =  nullptr;
    value =  nullptr;
  }
  LinkedNode( const int v) {
    this->value = new int( v);
    this->next =  nullptr;
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
  if( head ==  nullptr)
    cout << "Passed  nullptr" << endl;

  LinkedNode *current = head;
  while( current !=  nullptr) {
    cout << *current << endl;
    current = current->getNext();
  }
}

// Delete a node from the list
LinkedNode *deleteLinkedNode( LinkedNode *head, const int &v) {
  if( head ==  nullptr) {
    cout << "Passed  nullptr" << endl;
    return head;
  }

  if( head->getValue() == v) {
    LinkedNode *tmp = head->getNext();
    head->setNext(  nullptr);
    free( head);
    return tmp;
  }

  LinkedNode *current = head;
  while( current !=  nullptr ) {
    if( current->getNext() !=  nullptr && current->getNext()->getValue() == v) {
      break;
    } else {
      current = current->getNext();
    }
  }

  if( current ==  nullptr) {
    cout << "Value not found" << endl;
    return head;
  } else {
    LinkedNode *tmp = current->getNext();
    current->setNext( tmp->getNext());
    tmp->setNext(  nullptr);
    free( tmp);

    return head;
  }

}

int getListLength( LinkedNode *head) {
  if ( head ==  nullptr) return 0;

  LinkedNode *current = head->getNext();
  int counter = 1;

  while( current !=  nullptr) {
    counter++;
    current = current->getNext();
  }

  return counter++;
}


LinkedNode *getNodeByValue( LinkedNode *head, const int &v) {
  if( head == nullptr)
    return  nullptr;

  LinkedNode *current = head;

  while( current !=  nullptr) {
    if( current->getValue() == v)
      return current;

    current = current->getNext();
  }

  return  nullptr;
}

LinkedNode *getParentNodeByValue( LinkedNode *head, const int &v) {
  if( head == nullptr)
    return  nullptr;

  LinkedNode *current = head;

  while( current->getNext() !=  nullptr) {
    if( current->getNext()->getValue() == v)
      return current;

    current = current->getNext();
  }

  return  nullptr;
}

LinkedNode *getParentNode( LinkedNode *head, LinkedNode* targetNode) {
  if( head == nullptr)
    return  nullptr;

  LinkedNode *current = head;
  while( current->getNext() !=  nullptr) {
    if( current->getNext() == targetNode ) {
      return current;
    }
    current = current->getNext();
  }

  return  nullptr;
}

LinkedNode *getKthElementFromEnd( LinkedNode *head, const int &k) {
	if( head ==  nullptr) return  nullptr;

	int dist = 0;

	LinkedNode *frontP = head, *backP = head;

	while( frontP !=  nullptr) {
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
		return  nullptr;
	}
}
