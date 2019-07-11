#include <iostream>
#include "common.hpp"
using namespace std;

int main() {
  MyStack<int> stck;
  stck.push( 0);
  stck.push( 1);

  cout << "Popped " << stck.pop() << endl;

  stck.display();

  MyQueue<int> q;
  q.enqueue(0);
  q.enqueue(1);
  cout << "Dequeued " << q.dequeue() << endl;

  cout << "Display queue" << endl;
  q.display();

	return 0;
}
