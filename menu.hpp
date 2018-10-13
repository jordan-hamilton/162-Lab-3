/*********************************************************************
** Description: Header file for menu functions.
*********************************************************************/

#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>
#include <limits>
#include <string>

void displayMenu();
int getIntChoiceFromPrompt(const std::string &prompt, const int &minVal, const int &maxVal);
bool validateInput(const std::string &inputStr);
bool validateRange(const int &inputVal, const int &minVal, const int &maxVal);

#endif
