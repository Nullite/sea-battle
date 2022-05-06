#pragma once
#include "programm.h"

std::vector<int> getSquare(int shipType, int shipLayout, std::string& board, Elements instance);
std::vector<int> aim(std::string& board);
std::vector<char> menu(Bot& bot1, Bot& bot2, User& player, Game& game);
bool isLoadsave();
bool userPlaceShips();
void showDisclaimer();
void getStart(char& start);
void declareTurn(std::string& whoseTurn);
void askShip(Game& game, std::string& board, Elements instance);
void displayChoosedShip(int shipType, int shipLayout, Elements instance);
void showIfHit(int shipLong, bool isUserPlay);
void showDestroyed(int ship);
void userFireOnSquare(Elements instance, User& player, Bot& bot, Game& game);
void setBotAiming(bool& botAiming, std::string botName);
void showUserBoardBeforeGame(std::string& board);
void showBoard(std::string board);
void sightMovement(std::string enemyBoard, int square, Elements instance);
void choosePlayers(char& firstPlayer, char& secondPlayer, std::string& username, std::string bot1name, std::string bot2name);
void awaitPause(bool& partyOver, User& player);
void pause(bool& partyOver, User& player);
void endParty(std::string& whoseTurn, std::string userName, bool userPlay, Bot& bot1, Bot& bot2);
void showIfSaved();
void showIfSaveDeleted();