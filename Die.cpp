#include "Die.hpp"
#include <iostream>

Die::Die() {
  sides = 0;
}

Die::Die(int numOfSides) {
  this->sides = numOfSides;
}

int Die::rollOne() {
  int roll;
  unsigned seed = time(0);
  srand(seed);
  roll = rand() % this->sides + 1;
  return roll;
}
