#pragma once
#include "programm.h"
#include <random>

std::vector<std::vector<int> > botFillBoard(Game& game, std::string& board, Elements instance);
std::vector<int> chooseCoord(std::vector<int>& ship, std::string& board);
std::vector<int> botAimIfBattleship(Bot& bot);
std::vector<int> botAimIfCruiser(Bot& bot);
std::vector<int> botAimIfDestroyer(Bot& bot);
std::vector<int> botAimIfSubmarine(Bot& bot);
std::vector<int> randomFire(Bot& bot);
std::vector<int> botAim(Bot& bot);
std::vector<int> finishing(std::vector<int>& coords, std::string& botEnemyBoard);
bool checkIfAloneSquare(Bot& bot, std::vector<int>& coordinates);
void placeBotship(std::vector<int> coords, std::string& board, std::vector<std::vector<int> >& ships, Elements instance);
void chooseShip(Game& game);
void botFireOnSquare(Elements instance, User& player, Bot& bot, Game& game, std::vector<std::vector<int>>& enemyShips, std::string& enemyBoard);