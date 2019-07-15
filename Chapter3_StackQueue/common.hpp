#include <iostream>
using namespace std;

const int MAXSIZE = 300;

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
	int minPoss[MAXSIZE] = {-1};
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
};
