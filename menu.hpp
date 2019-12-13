/*****************************************************************************
 * Program name: Menu Functions
 * Date: 8/4/19
 * Name: Nicole Reynoldson
 * Description: A collection of functions used for implementing a menu.
 * ***************************************************************************/
#ifndef MENUS_HPP
#define MENUS_HPP
#include "getInput.hpp"
#include <vector>
#include <iostream>
#include <string>
#include "Option.hpp"

int displayMenu(std::vector<std::string> menuOpts);
int displayMenu(std::vector<Option> menuOpts);
#endif
