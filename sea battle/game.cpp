#include "game.h"

int randomizer(int from, int to)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist(from, to);

	int compare = dist(gen);
	int random = dist(gen);

	if (random == compare)
	{
		random = dist(gen);
	}
	return random;
}

bool isCorrectAim(int row, int col, std::string board)
{
	if (col < 0 || row < 0) return false;

	int checkSquare = returnSquare(row, col);
	try
	{
		if (board.at(checkSquare) == ' ')
		{
			return true;
		}
	}
	catch (std::exception&)
	{
		return false;
	}

	return false;
}

bool checkEndParty(std::vector<std::vector<int>> ships, Game& game, User& player, Bot& bot1, Bot& bot2)
{
	if (!ships.size()) return true;
	if (game.partyOver && !player.saveGame) return true;
	if (game.partyOver && player.saveGame)
	{
		globalSave(player, bot1, bot2, game);
		return true;
	}
	return false;
}

void swapNames(std::string& whoseTurn, std::string& whoseNext)
{
		std::string temp;
		temp = whoseTurn;
		whoseTurn = whoseNext;
		whoseNext = temp;
}

void initPlayer(User& player)
{
	player.isPlay = true;
	player.board = field();
	player.enemyBoard = field();
}

void initBot(Bot& bot, Game& game, Elements& instance)
{
	bot.isPlay = true;
	bot.board = field();
	bot.enemyBoard = field();
	bot.ships = botFillBoard(game, bot.board, instance);
}

void playerReady(User& player, Game& game, Elements instance)
{
	initPlayer(player);

	if (userPlaceShips())
	{
		system("cls");
		fillBoard(game, player, instance);
	}
	else
	{
		system("cls");
		player.ships = botFillBoard(game, player.board, instance);
	}
	showUserBoardBeforeGame(player.board);
}

void checkBotEnemyShips(Bot& bot, int shipType)
{
	switch (shipType)
	{
	case 1:
		bot.tact.enemyShips[3]--;
		break;
	case 2:
		bot.tact.enemyShips[2]--;
		break;
	case 3:
		bot.tact.enemyShips[1]--;
		break;
	case 4:
		bot.tact.enemyShips[0]--;
		break;
	}
}