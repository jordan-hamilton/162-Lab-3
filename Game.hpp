/*********************************************************************
** Description: Specification file for the Game class.
*********************************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include <cstdlib>
#include <ctime>
#include <iostream>
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
    void displayFinalScore();
    void displayStats();
    void initMenus();
    int getRounds();
    int getPlayerOneScore();
    int getPlayerTwoScore();
    void setPlayerOneScore(int score);
    void setPlayerTwoScore(int score);
    void setRounds(int numOfRounds);

  public:
    Game();
    void play();

};

#endif
