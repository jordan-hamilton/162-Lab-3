/*********************************************************************
** Program name: Lab 3
** Author: Jordan Hamilton
** Date: 10/14/2018
** Description: This program creates a Game object, and calls the play
** method to prompt the user to play a game or exit, then asks the
** user to select the number of rounds they wish to play if the option
** to play the game is chosen. Two players are then prompted to select
** the type of die they'd like to use, based on the number of sides
** whether or not the die should be loaded to increase the likelihood
** of a higher roll. This initializes two pointers to Die objects with
** the chosen properties, which are rolled for the selected number of
** rounds, displaying the score, winner of a round and the dice
** properties. The final score is then calculated and displayed to the
** user.
*********************************************************************/

#include "Game.hpp"


/***********************************************************************************************
** Description: This program can be run via the lab3 executable generated by make.
***********************************************************************************************/
int main() {

  Game newGame;
  newGame.play();

  return 0;

}
