#pragma once
#include <iostream>
#include <conio.h>
#include "game.h"
#include "variables.h"
#include "board.h"
#include "botLogic.h"

bool isShip(int shipType);
void shipCount(int shipType);
bool shipsIsOver();
void askShip(std::vector <int>& ship, std::string board);
std::vector<int> getShip(std::string board);