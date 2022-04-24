#pragma once
#include "variables.h"
#include "ships.h"
#include "game.h"
#include <random>

void chooseShip(Game& game);
std::vector<int> chooseCoord(std::vector<int>& ship, std::string& board);
void placeBotship(std::vector<int> coords, std::string& board, std::vector<std::vector<int> > &ships, Elements instance);
std::vector<std::vector<int> > botFillBoard(Game& game, std::string& board, Elements instance);
std::vector<int> botAim(std::string &board);
void botFireOnSquare(Elements instance, User& player, Bot& bot, Game& game, std::vector<std::vector<int>>& enemyShips, std::string& enemyBoard);
std::vector<int> finishing(std::vector<int>& coords, std::string& botEnemyBoard);