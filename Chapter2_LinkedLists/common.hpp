
#include <iostream>

class LinkedNode {

friend std::ostream &operator<<( std::ostream& output, LinkedNode *p);

private:
  LinkedNode *next;
  int *value;
public:
  LinkedNode *getNext() {
    return next;
  }
  void setNext( LinkedNode *node) {
    if( next != NULL) {
      free( next);
      next = NULL;
    }
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
