#pragma once
#include <fstream>
#include <string>
#include "variables.h"
#include <iostream>
#include "board.h"
void saveStrings(std::string userBoard, std::string comp1Board, std::string comp2Board, std::string userEnemyBoard, std::string bot1EnemyBoard, std::string bot2EnemyBoard, std::string userName, std::string whoseTurn, std::string whoseNext);
void getStrings(std::string &userBoard, std::string &comp1Board, std::string &comp2Board, std::string &userEnemyBoard, std::string &bot1EnemyBoard, std::string &bot2EnemyBoard, std::string &userName, std::string &whoseTurn, std::string &whoseNext);
void saveVec(std::vector<std::vector<int>> userShips, std::vector<std::vector<int>> comp1Ships, std::vector<std::vector <int> > comp2Ships, std::vector<int> coordsFinishingForBot1, std::vector<int> coordsFinishingForBot2);
void getVec(std::vector<std::vector<int>>& userShips, std::vector<std::vector<int>>& comp1Ships, std::vector<std::vector <int>>& comp2Ships, std::vector<int>& coordsFinishingForBot1, std::vector<int>& coordsFinishingForBot2);
void saveBool(bool isUserPlay, bool bot1Aiming, bool bot2Aiming, std::vector<char> players);
void getBool(bool& isUserPlay, bool& bot1Aiming, bool& bot2Aiming, std::vector<char>& players);
void savemgmt(bool isSaved);
void preloadSave(bool& isSaved);
void deleteSave();