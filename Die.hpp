/*********************************************************************
** Description: Specification file for the Die class.
*********************************************************************/

#ifndef DIE_HPP
#define DIE_HPP

#include <cstdlib>
#include <ctime>

class Die {

  private:
    int sides;

  public:
    Die();
    Die(int numOfSides);
    int rollOne();

};

#endif
