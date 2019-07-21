#include <iostream>
#include "common.hpp"
using namespace std;

int main() {
  SetOfStacks<int> setOfStacks = SetOfStacks<int>();
  for(auto i=0; i <40; i++) {
    setOfStacks.push(5);
  }
  // setOfStacks.push(5);
  for( auto i=0; i<10; ++i)
    setOfStacks.popAt( 2);
  // setOfStacks.pop();
  setOfStacks.display();

  return 0;
}
