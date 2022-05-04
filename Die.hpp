/*********************************************************************
** Description: Specification file for the Die class.
*********************************************************************/

#ifndef DIE_HPP
#define DIE_HPP

#include <cstdlib>
#include <string>

class Die {

  protected:
    int sides;
    std::string dieType;

  public:
    Die();
    Die(int numOfSides, std::string type);
    virtual ~Die() {};
    void setSides(int numOfSides);
    int getSides();
    void setType(std::string type);
    std::string getType();
    virtual int rollDie();

};

#endif
