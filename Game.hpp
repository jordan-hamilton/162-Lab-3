/*********************************************************************
** Description: Specification file for the Game class.
*********************************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include <cstdlib>
#include <ctime>
#include <memory>

#include "Die.hpp"
#include "LoadedDie.hpp"
#include "Menu.hpp"

class Game {

  private:
    int playerOneScore, playerTwoScore, playerOneSides, playerTwoSides, rounds;
    std::unique_ptr<Die> playerOneDie, playerTwoDie;
    Menu gameMenu, sidesMenu, dieMenu;

    void configureGame();
    void convertSides(int* sideChoice);
    void populateMenus();

  public:
    Game();
    void play();

};

#endif
