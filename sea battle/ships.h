#pragma once
#include "programm.h"
#include <iostream>
#include <conio.h>

std::vector<int> checkShip(int ship, std::vector<std::vector<int>>& ships, bool isUserPlay);
bool destroyShip(std::vector<int> params, std::string& enemyBoard, Elements instance);
bool isShip(Game& game, int shipType);
bool shipsIsOver(Game& game);
int hitShip(int square, std::vector<std::vector<int> >& ships);
void clearShips(std::vector<int>& ships);
void shipCount(Game& game);