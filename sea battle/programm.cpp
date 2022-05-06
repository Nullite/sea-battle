#include "programm.h"

void introduce(User& player, Bot& bot1, Bot& bot2, Game& game)
{
	showDisclaimer();
	preloadSave(game.isSaved);

	if (game.isSaved)
	{
		game.saveLoad = isLoadsave();
		if (game.saveLoad)
		{
			globalGet(player, bot1, bot2, game);
		}
	}
}

void partyPrepare(User& player, Bot& bot1, Bot& bot2, Game& game, Elements instance)
{
	game.partyOver = false;
	if (!game.saveLoad)
	{
		game.players = menu(bot1, bot2, player, game);

		switch (game.players[0])
		{
		case '0':
			system("cls");
			break;
		case '1':
			playerReady(player, game, instance);
			break;
		case '2':
			initBot(bot1, game, instance);
			break;
		case '3':
			initBot(bot2, game, instance);
			break;
		}

		switch (game.players[1])
		{
		case '1':
			playerReady(player, game, instance);
			break;
		case '2':
			initBot(bot1, game, instance);
			break;
		case '3':
			initBot(bot2, game, instance);
			break;
		}
	}
}
void party(User& player, Bot& bot1, Bot& bot2, Elements instance, Game& game)
{
	system("cls");
	if (!game.isGame) return;

	int bot = 0;

	if (player.isPlay == true)
	{
		bot = bot1.isPlay ? 1 : 2;
	}
	else
	{
		bot = 3;
	}

	if (bot == 1)
	{
		while (1)
		{
			if (game.whoseTurn == player.name)
			{
				userFireOnSquare(instance, player, bot1, game);
				if (checkEndParty(bot1.ships, game, player, bot1, bot2)) break;
			}

			if (game.whoseTurn == bot1.name)
			{
				botFireOnSquare(instance, player, bot1, game, player.ships, player.board);
				if (checkEndParty(player.ships, game, player, bot1, bot2)) break;
			}
		}
	}
	else if (bot == 2)
	{
		while (1)
		{
			if (game.whoseTurn == player.name)
			{
				userFireOnSquare(instance, player, bot2, game);
				if(checkEndParty(bot2.ships, game, player, bot1, bot2)) break;
			}

			if (game.whoseTurn == bot2.name)
			{
				botFireOnSquare(instance, player, bot2, game, player.ships, player.board);
				if(checkEndParty(player.ships, game, player, bot1, bot2)) break;
			}
		}
	}
	else
	{
		while (1)
		{
			if (game.whoseTurn == bot1.name)
			{
				botFireOnSquare(instance, player, bot1, game, bot2.ships, bot2.board);
				if (checkEndParty(bot2.ships, game, player, bot1, bot2)) break;
			}

			if (game.whoseTurn == bot2.name)
			{
				botFireOnSquare(instance, player, bot2, game, bot1.ships, bot1.board);
				if (checkEndParty(bot1.ships, game, player, bot1, bot2)) break;
			}
		}
	}
}

void gameFinished(User& player, Bot& bot1, Bot& bot2, Game& game)
{
	if (!game.isGame) return;
	if (!game.partyOver)
	{
		endParty(game.whoseTurn, player.name, player.isPlay, bot1, bot2);
		game.saveLoad = false;
		player.isPlay = false;
		bot1.isPlay = false;
		bot2.isPlay = false;
	}
}