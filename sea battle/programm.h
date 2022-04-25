#pragma once
#include "structs.h"
#include "board.h"
#include "botLogic.h"
#include "game.h"
#include "ships.h"
#include "save.h"
#include "interface.h"

void introduce(User& player, Bot& bot1, Bot& bot2, Game& game);
void partyPrepare(User& player, Bot& bot1, Bot& bot2, Game& game, Elements instance);
void party(User& player, Bot& bot1, Bot& bot2, Elements instance, Game& game);
void gameFinished(User& player, Bot& bot1, Bot& bot2, Game& game);