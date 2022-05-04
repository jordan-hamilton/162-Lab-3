#include "LoadedDie.hpp"


/***********************************************************************************************
** Description: Uses the rand() function and modular arithmetic to return a number between 1 and
** the number of sides on the Die object. Since this is a loaded die object, a random number
** between 0 and 2 is added to each roll, as long as this bonus would not exceed the number of
** sides on the die.
***********************************************************************************************/
int LoadedDie::rollDie() {

  int bonus, roll;

  bonus = rand() % 3;
  roll = rand() % getSides() + 1;

  if (roll + bonus < getSides()) {
    roll += bonus;
  }

  return roll;
}
