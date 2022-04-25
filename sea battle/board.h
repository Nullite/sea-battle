#pragma once
#include "programm.h"
#include <string>
#include <iostream>
#include <vector>
#include <conio.h>
#include <stdexcept>

std::vector<int> returnCoordinates(int square);
std::string field();
bool checkIfCorrectPlace(int col, int row, std::string& board, int shipLong, int shipLayout);
int returnSquare(int row, int col);
void placeShip(Game& game, User& player, Elements instance);
void hitShip(int square, std::string& board, std::string& enemyBoard, Elements instance);
void missed(int square, std::string& board, std::string& enemyBoard, Elements instance);
void fillBoard(Game& game, User& player, Elements instance);