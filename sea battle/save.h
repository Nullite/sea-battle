#pragma once
#include "programm.h"
#include <fstream>
#include <string>
#include <iostream>

void saveStrings(User player, Bot bot1, Bot bot2, Game game);
void saveVec(User player, Bot bot1, Bot bot2);
void saveBool(User player, Bot bot1, Bot bot2, Game game);
void getStrings(User& player, Bot& bot1, Bot& bot2, Game& game);
void getVec(User& player, Bot& bot1, Bot& bot2);
void getBool(User& player, Bot& bot1, Bot& bot2, Game& game);
void savemgmt();
void preloadSave(bool& isSaved);
void deleteSave();
void globalSave(User& player, Bot bot1, Bot bot2, Game& game);
void globalGet(User& player, Bot& bot1, Bot& bot2, Game& game);