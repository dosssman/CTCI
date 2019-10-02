#include <iostream>
#include <list>
#include <string>

using namespace std;

const int MAXSIZE = 10;

template <typename T>
class MyStack {
protected:
  int curPos = -1;
  T elements[MAXSIZE] = {};
public:
  bool push( const T &v) {
    if( curPos == MAXSIZE -1) return false;

    elements[++curPos] = v;

    return true;
  }

  T pop() {
    if( curPos == -1) return NULL;

    return elements[curPos--];
  }

  T peek() {
    if( curPos == -1) return NULL;
    return elements[curPos];
  }

  int count() {
    return curPos +1;
  }

  // Debug use
  void display() {
    if ( curPos == -1) cout << "Empty stack " << endl;

    for( auto i=0; i <= curPos; ++i) {
      cout << elements[i] << " ";
      if( i == curPos) cout << endl;
    }
  }

  bool isFull() {
    if( count() == MAXSIZE)
      return true;

    return false;
  }
  bool isEmpty() {
    if( count() == 0) return true;

    return false;
  }
};

template <typename T>
class MyQueue {
private:
  int fwdPos = -1;
  T elements[MAXSIZE] = {};
public:
  bool enqueue( const T &v) {
    if( fwdPos == MAXSIZE -1) return false;
    elements[++fwdPos] = v;

    return true;
  }
  T dequeue() {
    if( size() <=0) return NULL;
    T tmp = elements[0];
    shiftLeft();
    return tmp;
  }
  int size() {
    return fwdPos+1;
  }
  void shiftLeft() {
    for( auto i=0; i<fwdPos; i++)
      elements[i] = elements[i+1];
    fwdPos--;
  }
  void display() {
    if ( fwdPos == -1) cout << "Empty queue " << endl;

    for( auto i=0; i <= fwdPos; ++i) {
      cout << elements[i] << " ";
      if( i == fwdPos) cout << endl;
    }
  }
  T peek() {
    if( size() < 0) return NULL;

    return elements[fwdPos];
  }
};

template <typename T>
class TripleStack {
private:
  int curPoss[3];
  T elements[MAXSIZE] = {};
  int stackMaxIndex( const int &stackIdx) {
    return (MAXSIZE /3) * (stackIdx+1);
  }
public:
  int stackSize( const int &stackIdx) {
    return curPoss[stackIdx] - ((MAXSIZE /3) * stackIdx) +1;
  }
  void allStackSize() {
    for( int i=0; i<3; i++)
      cout << "Stack " << i+1 << " - Size: " << stackSize( i) << endl;
  }
  bool pushToStack( const int &stackIdx, const T &v) {
    if( stackIdx < 0 || stackIdx > 2) return false;
    if( stackSize(stackIdx) == stackMaxIndex(stackIdx)) return false;

    elements[++curPoss[stackIdx]] = v;

    return true;
  }
  T popFromStack( const int &stackIdx) {
    if( curPoss[stackIdx] == ((MAXSIZE/3) * stackIdx -1)) return NULL;
    return elements[curPoss[stackIdx]--];
  }
  T peekAtStack( const int &stackIdx) {
    if( curPoss[stackIdx] == ((MAXSIZE/3) * stackIdx -1)) return NULL;
    return elements[curPoss[stackIdx]];
  }
  void displayAll() {
    for( int stackIdx = 0; stackIdx < 3; stackIdx++) {
      displayStack(stackIdx);
    }
  }
  void displayStack( const int &stackIdx) {
    cout << "Displaying stack " << stackIdx +1 << endl;
    for( int i = (MAXSIZE / 3 * (stackIdx)); i <= curPoss[stackIdx]; i++) {
      cout << elements[i] << " ";
      if( i == curPoss[stackIdx]) cout << endl;
    }
  }
TripleStack() {
  for( int i=0; i< 3; ++i) {
    curPoss[i] = (MAXSIZE / 3 ) * i -1;
    // cout << "CUrposs for " << i << " is " << curPoss[i] << endl;
  }
}
};

// 2_2 Stack with Minimum feature
template <typename T>
class MinStack : public MyStack<T> {
private:
	int minPoss[MAXSIZE];
public:
	bool push(const T &v) {
		if( this->curPos == MAXSIZE-1) return false;
		this->elements[++this->curPos] = v;
		int curPosMin = 0;
		if( this->curPos > 0) {
			if( v <= this->elements[minPoss[this->curPos -1]])
				curPosMin = this->curPos;
			else
				curPosMin = minPoss[this->curPos-1];
		}
		minPoss[this->curPos] = curPosMin;

    return true;
	}
	T min() {
		if( this->curPos <= -1) return NULL;

		return this->elements[this->curPos];
	}

MinStack() {
  for( auto i=0; i< MAXSIZE; ++i)
    minPoss[i] = -1;
}
};

// 3_3 Deps
const int MAXSTACKS = 10;
const int STACKMAXSIZE = 10;

template <typename T>
class SetOfStacks {
private:
  MyStack<T> *stacks[MAXSTACKS];
  int curStckPtr = -1;
public:
  T pop() {
    if( curStckPtr == -1) return NULL;

    // First get the value to pop from the current stack
    T tmp = stacks[curStckPtr]->pop();
    // Clear the now useless stack
    if( stacks[curStckPtr]->isEmpty())
      free( stacks[curStckPtr--]);

    return tmp;
  }
  void display() {
    if( curStckPtr == -1) cout << "Empty set of stacks" << endl;
    // Iterate thorugh all the stacks in the set
    for( auto stckIdx = 0; stckIdx <= curStckPtr; stckIdx++) {
      cout << "Displaying content of stack " << stckIdx+1 << endl;
      // Iterate over the values of the focused stack
      // for( auto valIdx = 0; valIdx <= stackCurPosPtrs[curStckPtr]; ++valIdx) {
      //   cout << stacks[stckIdx][stackCurPosPtrs[stckIdx]] << " ";
      //   if( valIdx == stackCurPosPtrs[stckIdx])
      //     cout << endl;
      // }
      stacks[stckIdx]->display();
    }
  }
  bool push( const T &v) {
    if( curStckPtr == MAXSTACKS -1 &&
        stacks[curStckPtr]->isFull())
      return false;

    if( curStckPtr == -1 ||
      (curStckPtr < MAXSTACKS -1 &&
        stacks[curStckPtr]->isFull()))
        stacks[++curStckPtr] = new MyStack<T>();

    stacks[curStckPtr]->push( v);

    return true;
  }

  T popAt( const int &stackIdx) {
    if( stackIdx <0 || stackIdx > curStckPtr) return NULL;

    T tmp = stacks[stackIdx]->pop();

    if( stacks[stackIdx]->isEmpty()) {
      free( stacks[stackIdx]);

      for( auto i=stackIdx;i < curStckPtr; ++i) {
        stacks[i] = stacks[i+1];

      stacks[curStckPtr--] = NULL;
      }
    }

    return tmp;
  }
};

//3.5
template <typename T>
class MyQFromStacks {
private:
	MyStack<T> s1, s2;
	bool isPushing = true;
public:
	bool push( const T &v) {
		if( ! isPushing) {
			shiftStacks();
		}
		if( s1.isFull()) return false;

		s1.push( v);

		return true;
	}

	T pop() {
		if( isPushing) {
			shiftStacks();
		}
		if( s2.isEmpty()) return NULL;

		return s2.pop();
	}
	void shiftStacks() {
		if( !isPushing) {
			while(! s2.isEmpty()) {
				s1.push( s2.pop());
			}
		} else {
			while( ! s1.isEmpty()) {
				s2.push( s1.pop());
			}
		}
		isPushing = ! isPushing;
	}
	void display() {
		cout << "Display s1" << endl;
		s1.display();

		cout << "Dislay s2" << endl;
		s2.display();
	}
};

//3.6
template <typename T> class MySortedStack {
private:
  MyStack<T> main;
  MyStack<T> aux;
public:
  bool push( const T &v) {
    if( main.isFull()) return false;

    if( main.isEmpty()) {
      main.push( v);
    }  else {
      while( !main.isEmpty() && main.peek() > v) {
        aux.push( main.pop());
        if( main.isEmpty()) break;
      }
      main.push( v);
      while( !aux.isEmpty()) {
        main.push( aux.pop());
      }
    };

    return true;
  }

  T pop() {
    return main.pop();
  }

  T peek() {
    return main.peek();
  }

  int count() {
    return main.count();
  }

  // Debug use
  void display() {
    cout << "Display Main stack" << endl;
    main.display();

    cout << "Displaying Aux stack" << endl;
    aux.display();
  }

  bool isFull() {
    return main.isFull();
  }

  bool isEmpty() {
    return main.isEmpty();
  }
};

// 3.7
// Templated LinkedList
template <typename T> class ForwardListNode {
private:
  ForwardListNode *next;
  T *item;
public:
  ForwardListNode *getNext() {
    return next;
  }

  void setNext( ForwardListNode *node) {
    next = node;
  }

  T *getItem() {
    return item;
  }

  T *setItem( T *v) {
    item = v;

    return item;
  }

  // Constructors and Deconstructors
  ForwardListNode() {
    next =  nullptr;
    item =  nullptr;
  }

  ForwardListNode( T *v) {
    this->item = v;
    this->next = nullptr;
  }

  ForwardListNode *push_back(T *item) {
    ForwardListNode *head = this;
    if( head == nullptr) {
      head = new ForwardListNode( item);

      return head;
    }

    while( head->getNext() !=  nullptr) {
      head = head->getNext();
    }

    head->setNext( new ForwardListNode( item));

    return head->getNext();
  }

  void display() {
    if( this == nullptr) {
      cout << "Empty list." << endl;
      return;
    }

    ForwardListNode *head = this;
    while( head != nullptr) {
      cout << "Animal@ " << head->item << " -- Species: " << head->item->species << endl;
      head = head->getNext();
    }
  }
};


class Animal {
public:
  string species;
  Animal( const string &s) {
    species = s;
  }
  Animal( const char *s) {
    species = string( s);
  }

};

class SystemShelter {
private:
  ForwardListNode<Animal> *animals = nullptr;
public:
  bool enqueue( Animal *a) {

    if( animals == nullptr)
      animals = animals->push_back(a);
    else
      animals->push_back(a);

    return true;
  }

  Animal *dequeueAny() {
    if( animals == nullptr) return nullptr;

    Animal *adopted = animals->getItem();
    animals->setItem( nullptr);
    ForwardListNode<Animal> *nextInLine = animals->getNext();
    animals->setNext( nullptr);
    free( animals);
    animals = nextInLine;

    return adopted;
  }

  Animal *dequeueByType( const string &t) {
    if( animals == nullptr) return nullptr;

    // If the head has the mactching animal
    if (animals->getItem()->species == t) {
      Animal *adopted = animals->getItem();
      animals->setItem( nullptr);
      ForwardListNode<Animal> *nextInLine = animals->getNext();
      animals->setNext( nullptr);
      free( animals);
      animals = nextInLine;

      return adopted;
    }

    // Else if we need to look forward to find the matching animal
    ForwardListNode<Animal> *head = animals->getNext();
    ForwardListNode<Animal> *headParent = animals;

    Animal *adopted = nullptr;
    while( head != nullptr) {
      if( head->getItem()->species == t) {
        adopted = head->getItem();
        head->setItem( nullptr);
        headParent->setNext( head->getNext());
        head->setNext( nullptr);
        free( head);

        return adopted;
      }
      headParent = head;
      head = head->getNext();
    }

    return adopted;
  }

  Animal *dequeueDog() {
    return dequeueByType( string("d"));
  }

  Animal *dequeueCat() {
    return dequeueByType( string("c"));
  }

  void display() {
    animals->display();
  }
};
