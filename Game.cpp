#include "Game.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

Game::Game() {
  addMenuItem(game, "Play game");
  addMenuItem(game, "Exit game");
  addMenuItem(sides, "Tetrahedron (4 sides)");
  addMenuItem(sides, "Cube (6 sides)");
  addMenuItem(sides, "Pentagonal trapezohedron (10 sides)");
  addMenuItem(sides, "Dodecahedron (12 sides)");
  addMenuItem(sides, "Icosahedron (20 sides)");

}

void Game::play() {
  displayMenu(game);
  if (getIntChoiceFromPrompt("Select an available menu option.", 1 , 2) != 2) {
    displayMenu(sides);
  }
}

/***********************************************************************************************
** Description: Prints a list of options that the user can be prompted to select to the screen.
** Used before the getIntChoiceFromPrompt function so input can be retrieved.
***********************************************************************************************/
void Game::displayMenu(Menu menuList) {
  switch (menuList) {

    case game:

      for (int i = 0; i < gameOptions.size(); i++) {
        cout << i + 1 << ") " << gameOptions.at(i) << endl;
      }

      break;

    case sides:

      for (int i = 0; i < sidesOptions.size(); i++) {
        cout << i + 1 << ") " << sidesOptions.at(i) << endl;
      }

      break;
    }
  }


void Game::addMenuItem(Menu menuList, string menuItem) {
  switch (menuList) {
    case game:
      gameOptions.push_back(menuItem);
      break;

    case sides:
      sidesOptions.push_back(menuItem);
      break;
  }

}


int Game::getMenuChoices(Menu menuList) {
  switch (menuList) {
    case game: {
      return gameOptions.size();
    }

    case sides: {
      return sidesOptions.size();
    }
  }
}


/***********************************************************************************************
** Description: Takes a reference to a string used to indicate a prompt for the user to enter
** data, followed by references to integers that output valid values to hint that the user
** should enter an integer value within the entered values. Input is passed to validateInput and
** validateRange to verify that the input is an integer and falls within a valid range for the
** prompt, then the integer value the user entered is returned if it was valid. Otherwise, the
** prompt is repeated.
***********************************************************************************************/
int Game::getIntChoiceFromPrompt(const string &prompt, const int &minVal, const int &maxVal) {

  string userInput;

  do {
    cout << prompt << endl;
    cout << "Valid input range: [" << minVal << " - " << maxVal << "]: ";
    getline(cin, userInput);
  } while(!validateInput(userInput) || !validateRange(stoi(userInput), minVal, maxVal));

return stoi(userInput);

}


/*********************************************************************
** Description: This function accepts a reference to a string, which
** is then looped through to search for non-digit characters. The
** return value is true is there are only digits in the string passed
** to the function, otherwise, the function returns false.
*********************************************************************/
bool Game::validateInput(const string &inputStr) {
  bool isValid = true;

  if (inputStr.empty()) {
    isValid = false;
  }

  for (int i = 0; i < inputStr.length(); i++) {
    if (!isdigit(inputStr[i])) {
      isValid = false;
    }
  }

  return isValid;
}


/***********************************************************************************************
** Description: Takes a reference to an integer value to check, and minimum and maximum values.
** If the input is an integer and in the valid range, the function returns true. Otherwise,
** it returns false.
***********************************************************************************************/
bool Game::validateRange(const int &inputVal, const int &minVal, const int &maxVal) {

  if ((inputVal >= minVal) && (inputVal <= maxVal)) {
    return true;
  } else {
    return false;
  }
}
