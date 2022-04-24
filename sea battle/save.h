#pragma once
#include <fstream>
#include <string>
#include "variables.h"
#include <iostream>
#include "board.h"
void saveStrings(User player, Bot bot1, Bot bot2, Game game);
void getStrings(User& player, Bot& bot1, Bot& bot2, Game& game);
void saveVec(User player, Bot bot1, Bot bot2);
void getVec(User& player, Bot& bot1, Bot& bot2);
void saveBool(User player, Bot bot1, Bot bot2, Game game);
void getBool(User& player, Bot& bot1, Bot& bot2, Game& game);
void globalSave(User& player, Bot bot1, Bot bot2, Game& game);
void globalGet(User& player, Bot& bot1, Bot& bot2, Game& game);
void savemgmt();
void preloadSave(bool& isSaved);
void deleteSave();