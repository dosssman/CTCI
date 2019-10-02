#include <iostream>
#include "common.hpp"
using namespace std;

int main() {

  MySortedStack<int> sortedStack;
  sortedStack.push(7);
  sortedStack.push(0);
  sortedStack.push(2);
  sortedStack.pop();

  sortedStack.display();

  return 0;
}
