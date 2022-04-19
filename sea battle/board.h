#pragma once
#include "save.h"
#include "ships.h"
#include <string>
#include <iostream>
#include <vector>
#include <conio.h>
#include <stdexcept>

std::string field();
void showBoard(std::string board);
int returnSquare(int row, int col);
std::vector<int> returnCoordinates(int square);
std::vector<int> getSquare(int shipType, int shipLayout, std::string& board);
void placeShip(std::vector<int> ship, std::string& board, std::vector<std::vector <int> > &ships);
bool checkIfCorrectPlace(int col, int row, std::string& board, int shipLong, int shipLayout);
std::vector<std::vector <int> > fillBoard(std::string& board);