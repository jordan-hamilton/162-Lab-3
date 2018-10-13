#include "Die.hpp"
#include "LoadedDie.hpp"
#include "Game.hpp"

int main() {
  Game newGame;
  newGame.play();
  return 0;
  /*int rounds, playerOneSides, playerTwoSides;
  Die newDie(4);
  LoadedDie newerDie(4);
  std::cout << "Roll: " << newDie.rollOne() << std::endl;
  displayMenu();
  if (getIntChoiceFromPrompt("Select an available menu option.", 1 , 2) == 2) {
    return 0;
  }
Game newGame;
  } else {
    rounds = newGame.getIntChoiceFromPrompt("How many rounds will be played?", 1, std::numeric_limits<int>::max());
    newGame.displayMenu(sides);
    playerOneSides = newGame.getIntChoiceFromPrompt("How many sides should player one's die have?", 1, newGame.getMenuChoices(sides));
    playerOneSides = newGame.getIntChoiceFromPrompt("How many sides should player two's die have?", 1, newGame.getMenuChoices(sides));
  }*/
}
