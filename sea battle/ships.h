#pragma once
#include <iostream>
#include <conio.h>
#include "game.h"
#include "variables.h"
#include "board.h"
#include "botLogic.h"

bool isShip(Game& game, int shipType);
void shipCount(Game& game);
bool shipsIsOver(Game& game);
void askShip(Game& game, std::string& board, Elements instance);