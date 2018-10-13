/*********************************************************************
** Description: Specification file for the Game class.
*********************************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <string>
#include <vector>

#include "Die.hpp"
#include "LoadedDie.hpp"

enum Menu { game, sides };

class Game {

  private:
    std::vector<std::string> gameOptions, sidesOptions;
    int playerOneScore, playerTwoScore;

    void displayMenu(Menu menuList);
    void addMenuItem(Menu menuList, std::string menuItem);
    int getMenuChoices(Menu menuList);
    int getIntChoiceFromPrompt(const std::string &prompt, const int &minVal, const int &maxVal);
    bool validateInput(const std::string &inputStr);
    bool validateRange(const int &inputVal, const int &minVal, const int &maxVal);

  public:
    Game();
    void play();
};

#endif
