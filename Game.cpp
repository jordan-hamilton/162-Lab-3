#include <iostream>
using std::cout;
using std::endl;

#include "Game.hpp"

using std::unique_ptr;

Game::Game() {
  populateMenus();
}

void Game::play() {
  unsigned seed = time(0);
  srand(seed);

  playerOneDie = nullptr;
  playerTwoDie = nullptr;

  if (gameMenu.getIntChoiceFromPrompt("Select an available menu option.", 1 , 2, true) != 2) {
    //How many rounds will be played
    rounds = gameMenu.getIntChoiceFromPrompt("How many rounds would you like to play?", 1, 1000, false);

    //The number of sides for dice of both players
    playerOneSides = sidesMenu.getIntChoiceFromPrompt("Player 1: How many sides should your die have?", 1, sidesMenu.getMenuChoices(), true);
    convertSides(&playerOneSides);

    playerTwoSides = sidesMenu.getIntChoiceFromPrompt("Player 2: How many sides should your die have?", 1, sidesMenu.getMenuChoices(), true);
    convertSides(&playerTwoSides);

    if (dieMenu.getIntChoiceFromPrompt("Player 1: Which type of die would you like?", 1, dieMenu.getMenuChoices(), true) == 1) {
      playerOneDie = unique_ptr<Die>(new Die(playerOneSides));
    } else {
      playerOneDie = unique_ptr<LoadedDie>(new LoadedDie(playerOneSides));
    }

    if (dieMenu.getIntChoiceFromPrompt("Player 2: Which type of die would you like?", 1, dieMenu.getMenuChoices(), true) == 1) {
      playerTwoDie = unique_ptr<Die>(new Die(playerTwoSides));
    } else {
      playerTwoDie = unique_ptr<LoadedDie>(new LoadedDie(playerTwoSides));
    }
  }

  cout << "Player one sides: " << playerOneDie->getSides() << endl;
  cout << "Player two sides: " << playerTwoDie->getSides() << endl;

}


/***********************************************************************************************
** Description: Takes a pointer to an integer corresponding to the menu selection for the
** desired number of sides on a die, then sets the value to the actual number of sides for that
** choice.
***********************************************************************************************/
void Game::convertSides(int* sideChoice) {
  if (*sideChoice) {
    switch(*sideChoice) {
      case 1:
        *sideChoice = 4;
        break;
      case 2:
        *sideChoice = 6;
        break;
      case 3:
        *sideChoice = 8;
        break;
      case 4:
        *sideChoice = 10;
        break;
      case 5:
        *sideChoice = 12;
        break;
      case 6:
        *sideChoice = 20;
        break;
    }
  }

}


void Game::populateMenus() {
  gameMenu.addMenuItem("Play game");
  gameMenu.addMenuItem("Exit game");
  sidesMenu.addMenuItem("Tetrahedron (4 sides)");
  sidesMenu.addMenuItem("Cube (6 sides)");
  sidesMenu.addMenuItem("Octahedron (8 sides)");
  sidesMenu.addMenuItem("Pentagonal trapezohedron (10 sides)");
  sidesMenu.addMenuItem("Dodecahedron (12 sides)");
  sidesMenu.addMenuItem("Icosahedron (20 sides)");
  dieMenu.addMenuItem("Standard");
  dieMenu.addMenuItem("Loaded");
}
