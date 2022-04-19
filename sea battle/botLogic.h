#pragma once
#include "variables.h"
#include "ships.h"
#include "game.h"
#include <random>

void chooseShip(std::vector <int>& ship);
std::vector<int> chooseCoord(std::vector<int>& ship, std::string& board);
void placeBotship(std::vector<int> coords, std::string& board, std::vector<std::vector<int> > &ships);
std::vector<std::vector<int> > botFillBoard(std::string& board);
std::vector<int> botAim(std::string &board);
void botFireOnSquare(bool botAiming, bool& usergameSave, bool& saveload, bool isUserPlay, bool& partyOver, std::vector<std::vector<int>>& enemyShips, std::vector<std::vector<int>>& compShips, std::string& enemyBoard, std::string& botEnemyBoard, std::vector<int>& coordinates, std::string& whoseTurn, std::string& whoseNext);
std::vector<int> finishing(std::vector<int>& coords, std::string& botEnemyBoard);