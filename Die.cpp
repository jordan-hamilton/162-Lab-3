#include "Die.hpp"
#include <iostream>

Die::Die() {
  sides = 0;
}

Die::Die(int numOfSides) {
  this->sides = numOfSides;
}

int Die::getSides() {
  return this->sides;
}

void Die::setSides(int numOfSides) {
  this->sides = numOfSides;
}

int Die::rollDie() {
  int roll;
  roll = rand() % this->sides + 1;
  return roll;
}
