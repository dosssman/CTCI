#include <iostream>
using namespace std;

const int MAXSIZE = 256;

template <typename T>
class MyStack {

private:
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

template <typename T> class MyQueue {
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
