#include <iostream>
#include "common.hpp"
using namespace std;

int main() {

  Animal *animal = new Animal( string("c"));

  // cout << "Animal's species: " << animal->species << endl;

  SystemShelter systemShelter;
  systemShelter.display();

  systemShelter.enqueue( animal);

  animal = new Animal( string("c"));
  // systemShelter.enqueue( animal);
  //
  // animal = new Animal( string("d"));
  // systemShelter.enqueue( animal);

  systemShelter.display();

  cout << "Poping operations" << endl;
  // auto poppedAnimal = systemShelter.dequeueAny();
  auto poppedAnimal = systemShelter.dequeueDog();

  if( poppedAnimal == nullptr) {
    cout << "No animal matching the criterian could be found" << endl;
  } else
    cout << "Popped Animal@" << poppedAnimal << " -- its species: " << poppedAnimal->species << endl;

  cout << "Shelter after dequeuing" << endl;
  systemShelter.display();

  return 0;
}
