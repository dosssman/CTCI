#include <iostream>
#include "common.hpp"
using namespace std;

int main() {

  TripleStack<int> tstack;

  tstack.pushToStack(0, 1);
  tstack.pushToStack(0, 1);
  tstack.pushToStack(1, 2);
  tstack.pushToStack(1, 2);
  tstack.pushToStack(2, 3);


  for( int i=0; i<3; i++)
    tstack.popFromStack(i);

  tstack.allStackSize();
  tstack.displayAll();

	return 0;
}
