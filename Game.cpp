#include "Game.hpp"

using std::cout;
using std::endl;
using std::unique_ptr;


/***********************************************************************************************
** Description: Default constructor that initalizes a Game object without any rounds or score,
** populates the Menu objects with valid selections for the game, and initializes the Die
** pointers as nullptr.
***********************************************************************************************/
Game::Game() {
  initMenus();
  setRounds(0);
  setPlayerOneScore(0);
  setPlayerTwoScore(0);
  playerOneDie = nullptr;
  playerTwoDie = nullptr;
}


/***********************************************************************************************
** Description: Initializes a random generator seed and sets the random generator seed for dice
** rolls, the calls the configureMenu function to configure the dice and rounds in the game.
** A for loop continues rolling dice for the set number of rounds, comparing the scores in an if
** statement after each roll to display who won the round. Then the displayStats function
** shows a summary of the game data members. After the for loop, displayFinalScore is called to
** display the score after all rounds are complete.
***********************************************************************************************/
void Game::play() {

  unsigned seed = time(0);
  srand(seed);

  configureGame();

  if (playerTwoDie && playerTwoDie) {

    for (int i = 0; i < getRounds(); i++) {

      int playerOneRoll = playerOneDie->rollDie();
      int playerTwoRoll = playerTwoDie->rollDie();

      cout << endl;
      cout << "Round " << (i + 1) << ": " << endl;
      cout << "Player 1 rolls a " << playerOneRoll << "." << endl;
      cout << "Player 2 rolls a " << playerTwoRoll << "." << endl;

      if (playerOneRoll > playerTwoRoll) {
        cout << "Player 1 wins this round." << endl;
        setPlayerOneScore(getPlayerOneScore() + 1);
      } else if (playerOneRoll < playerTwoRoll) {
        cout << "Player 2 wins this round." << endl;
        setPlayerTwoScore(getPlayerTwoScore() + 1);
      } else {
        cout << "The round is a draw." << endl;
      }

      displayStats();

      cout << "-------------------------" << endl;

    }
  }

  if (getRounds() > 0) {
    displayFinalScore();
  }

}


/***********************************************************************************************
** Description: Prompts the user to begin the game, sets the number of rounds to play, and the
** specifications of each die for each player (the number of sides and whether or not the die
** should be loaded). The unique pointers for each Die object are assigned a value corresponding
** to a base or derived object (Die or LoadedDie) based on each player's selection.
***********************************************************************************************/
void Game::configureGame() {

  if (gameMenu.getIntChoiceFromPrompt("Select an available menu option.", 1 , 2, true) != 2) {

    rounds = gameMenu.getIntChoiceFromPrompt("How many rounds would you like to play?", 1, 1000, false);

    playerOneSides = sidesMenu.getIntChoiceFromPrompt("Player 1: How many sides should your die have?", 1, sidesMenu.getMenuChoices(), true);
    convertSides(&playerOneSides);

    playerTwoSides = sidesMenu.getIntChoiceFromPrompt("Player 2: How many sides should your die have?", 1, sidesMenu.getMenuChoices(), true);
    convertSides(&playerTwoSides);

    if (dieMenu.getIntChoiceFromPrompt("Player 1: Which type of die would you like?", 1, dieMenu.getMenuChoices(), true) == 1) {
      playerOneDie = unique_ptr<Die>(new Die(playerOneSides, "Standard"));
    } else {
      playerOneDie = unique_ptr<LoadedDie>(new LoadedDie(playerOneSides, "Loaded"));
    }

    if (dieMenu.getIntChoiceFromPrompt("Player 2: Which type of die would you like?", 1, dieMenu.getMenuChoices(), true) == 1) {
      playerTwoDie = unique_ptr<Die>(new Die(playerTwoSides, "Standard"));
    } else {
      playerTwoDie = unique_ptr<LoadedDie>(new LoadedDie(playerTwoSides, "Loaded"));
    }

  }

}


/***********************************************************************************************
** Description: Takes a pointer to an integer corresponding to the menu selection for the
** desired number of sides on a die, then sets the value to the actual number of sides for that
** menu choice.
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


/***********************************************************************************************
** Description: Outputs to the screen the final score and then determines who won the game after
** all rounds are played.
***********************************************************************************************/
void Game::displayFinalScore() {

  cout << endl << "FINAL SCORE:" << endl;
  cout << "------------" << endl;

  cout << "Player 1: " << getPlayerOneScore() << endl;
  cout << "Player 2: " << getPlayerTwoScore() << endl;

  if (getPlayerOneScore() > getPlayerTwoScore()) {
    cout << endl << "Player 1 wins the game." << endl;
  } else if (getPlayerOneScore() < getPlayerTwoScore()) {
    cout << endl << "Player 2 wins the game." << endl;
  } else {
    cout << endl << "The game is a draw." << endl;
  }

}


/***********************************************************************************************
** Description: Outputs to the screen with details of each player's score, die type, and die
** sides if both Die pointers point to valid addresses. This is called in the for loop in the
** play function to display the game summary after each roll.
***********************************************************************************************/
void Game::displayStats() {

  if (playerTwoDie && playerTwoDie) {

    cout << endl << "Current Score:" << endl;
    cout << "--------------" << endl;
    cout << "Player 1: " << getPlayerOneScore() << endl;
    cout << "Player 2: " << getPlayerTwoScore() << endl;
    cout << endl << "Die Type:" << endl;
    cout << "---------" << endl;
    cout << "Player 1: " << playerOneDie->getType() << endl;
    cout << "Player 2: " << playerTwoDie->getType() << endl;
    cout << endl << "Die Sides:" << endl;
    cout << "----------" << endl;
    cout << "Player 1: " << playerOneDie->getSides() << endl;
    cout << "Player 2: " << playerTwoDie->getSides() << endl;

  }

}


/***********************************************************************************************
** Description: Calls the addMenuItem function on the Game's Menu objects to add possible menu
** choices to vectors for the main menu, the menu of sides to select for a die,
** and the type of die.
***********************************************************************************************/
void Game::initMenus() {

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


/***********************************************************************************************
** Description: Returns the number of rounds in the game.
***********************************************************************************************/
int Game::getRounds() {

  return rounds;

}


/***********************************************************************************************
** Description: Returns the score for Player 1.
***********************************************************************************************/
int Game::getPlayerOneScore() {

  return playerOneScore;

}


/***********************************************************************************************
** Description: Returns the score for Player 2.
***********************************************************************************************/
int Game::getPlayerTwoScore() {

  return playerTwoScore;

}


/***********************************************************************************************
** Description: Takes an integer to set the score for Player 1.
***********************************************************************************************/
void Game::setPlayerOneScore(int score) {

  playerOneScore = score;

}


/***********************************************************************************************
** Description: Takes an integer to set the score for Player 2.
***********************************************************************************************/
void Game::setPlayerTwoScore(int score) {

  playerTwoScore = score;

}


/***********************************************************************************************
** Description: Takes an integer to set the number of rounds in the game.
***********************************************************************************************/
void Game::setRounds(int numOfRounds) {

  rounds = numOfRounds;

}
