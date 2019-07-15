#include <iostream>
#include "common.hpp"
using namespace std;

class A {
protected:
	int aValue;
public:
		int getaValue() { return aValue;};
};
class B {
protected:
	int bValue;
public:
	int getbValue() { return bValue;};
};

class C : public A, B {
protected:
	int cValue;
public:
	int getaValue() { return aValue;};
};

int main() {
	MinStack<int> stck = MinStack<int>();
	stck.push( 5);
	stck.push( 7);
	stck.push( 0);
	cout << "Min is " << stck.min() << endl;
	stck.pop();
	cout << "Min is " << stck.min() << endl;
	
	stck.display();


	return 0;
}
