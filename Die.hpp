/*********************************************************************
** Description: Specification file for the Die class.
*********************************************************************/

#ifndef DIE_HPP
#define DIE_HPP

class Die {

  private:

  protected:
    int sides;

  public:
    Die();
    Die(int numOfSides);
    void setSides(int numOfSides);
    int getSides();
    int rollDie();

};

#endif
