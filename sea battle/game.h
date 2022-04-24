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
void displayChoosedShip(int shipType, int shipLayout, Elements instance);
int randomizer(int from, int to);
int hitShip(int square, std::vector<std::vector<int> > &ships);
void hitShip(int square, std::string &board, std::string& enemyBoard, Elements instance);
void missed(int square, std::string& board, std::string& enemyBoard, Elements instance);
std::vector<int> checkShip(int ship, std::vector<std::vector<int>>& ships, bool isUserPlay);
bool destroyShip(std::vector<int> params, std::string& enemyBoard, Elements instance);
std::vector<int> aim(std::string& board);
bool isCorrectAim(int row, int col, std::string board);
void userFireOnSquare(Elements instance, User& player, Bot& bot, Game& game);
void sightMovement(std::string enemyBoard, int square, Elements instance);
void endParty(std::string& whoseTurn, std::string userName);
void showIfHit(int shipLong, bool isUserPlay);
void showDisclaimer();
void getStart(char& start);
std::vector<char> menu(Bot& bot1, Bot& bot2, User& player, Game& game);
void choosePlayers(char& firstPlayer, char& secondPlayer, std::string& username, std::string bot1name, std::string bot2name);
bool userPlaceShips();
void showUserBoardBeforeGame(std::string& board);
void pause(bool& partyOver, User& player);
void awaitPause(bool& partyOver, User& player);
void setBotAiming(bool& botAiming, std::string botName);
void initPlayer(User& player);
void playerReady(User& player, Game& game, Elements instance);
void initBot(Bot& bot, Game& game, Elements& instance);
void introduce(User& player, Bot& bot1, Bot& bot2, Game& game);
void partyPrepare(User& player, Bot& bot1, Bot& bot2, Game& game, Elements instance);
void party(User& player, Bot& bot1, Bot& bot2, Elements instance, Game& game);
void gameFinished(User& player, Bot& bot1, Bot& bot2, Game& game);
bool isLoadsave();
void showIfSaved();
void showIfSaveDeleted();