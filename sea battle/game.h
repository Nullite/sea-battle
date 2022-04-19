#pragma once
#include "variables.h"
#include "botLogic.h"
#include <iostream>
#include <Windows.h>
#include <mmsystem.h>

#pragma comment (lib, "Winmm.lib")

void declareTurn(std::string& whoseTurn);
void swapNames(std::string& whoseTurn, std::string& whoseNext);
void clearShips(std::vector<int>& ships);
void displayChoosedShip(int shipType, int shipLayout);
int randomizer(int from, int to);
int hitShip(int square, std::vector<std::vector<int> > &ships);
void hitShip(int square, std::string &board, std::string& enemyBoard);
void missed(int square, std::string& board, std::string& enemyBoard);
std::vector<int> checkShip(int ship, std::vector<std::vector<int>>& ships, bool isUserPlay);
bool destroyShip(std::vector<int> params, std::string& enemyBoard);
std::vector<int> aim(std::string& board);
bool isCorrectAim(int row, int col, std::string board);
void userFireOnSquare(bool&partyOver, bool& userSaveGame, bool&saveLoad, std::vector<std::vector <int> >& compShips, std::string& computerBoard, std::string& enemyBoard, std::string& whoseTurn, std::string& whoseNext);
void sightMovement(std::string enemyBoard, int square);
void endParty(std::string& whoseTurn, std::string userName);
void showIfHit(int shipLong, bool isUserPlay);
void showDisclaimer();
void getStart(char& start);
std::vector<char> menu(bool& bot1Aiming, bool& bot2Aiming, bool& isGame, std::string bot1name, std::string bot2name, std::string& userName, std::string& whoseTurn, std::string& whoseNext);
void choosePlayers(char& firstPlayer, char& secondPlayer, std::string& username, std::string bot1name, std::string bot2name);
bool userPlaceShips();
void showUserBoardBeforeGame(std::string& board);
void pause(bool& partyOver, bool& userSaveGame);
void awaitPause(bool& partyOver, bool& userSaveGame);
void setBotAiming(bool& botAiming, std::string botName);
bool isLoadsave();
void showIfSaved();
void showIfSaveDeleted();