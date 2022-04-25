#pragma once
#include "programm.h"
#include <iostream>
#include <Windows.h>
#include <mmsystem.h>

#pragma comment (lib, "Winmm.lib")

int randomizer(int from, int to);
bool isCorrectAim(int row, int col, std::string board);
bool checkEndParty(std::vector<std::vector<int>> ships, Game& game, User& player, Bot& bot1, Bot& bot2);
void swapNames(std::string& whoseTurn, std::string& whoseNext);
void initPlayer(User& player);
void playerReady(User& player, Game& game, Elements instance);
void initBot(Bot& bot, Game& game, Elements& instance);