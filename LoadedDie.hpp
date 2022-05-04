/*********************************************************************
** Description: Specification file for the LoadedDie class.
*********************************************************************/

#ifndef LOADEDDIE_HPP
#define LOADEDDIE_HPP

#include "Die.hpp"

class LoadedDie : public Die {

  private:

  public:
    LoadedDie() {};
    LoadedDie(int numOfSides, std::string type) : Die(numOfSides, type) {};
    virtual int rollDie();

};

#endif
