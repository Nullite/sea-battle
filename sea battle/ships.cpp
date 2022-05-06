#include "ships.h"

std::vector<int> checkShip(int ship, std::vector<std::vector<int>>& ships, bool userTurn)
{
	std::vector<int> params;
	int count = 0;
	for (int i = 2; i < ships[ship].size(); i++)
	{
		if (ships[ship][i] == 0)
		{
			count++;
		}
	}
	if (count == ships[ship].size() - 2)
	{
		params.push_back(ships[ship][0]);
		params.push_back(ships[ship][1]);
		params.push_back(count);

		ships.erase(ships.begin() + ship);
	}
	else
	{
		system("cls");
		Sleep(500);
		PlaySound(TEXT("./sound/alarm.wav"), NULL, SND_FILENAME | SND_ASYNC);
		showIfHit((int)ships[ship].size() - 2, userTurn);
		Sleep(1500);
	}
	return params;
}

bool destroyShip(std::vector<int> params, std::string& enemyBoard, Elements instance, Game& game, Bot& bot)
{

	if (!params.size())
	{
		return false;
	}
	int shipLong = params[2];
	int isHorizontal = params[0];
	int startSquare = params[1];

	Sleep(400);
	system("cls");
	showDestroyed(shipLong);
	if (game.whoseTurn == bot.name)
	{
		checkBotEnemyShips(bot, shipLong);
	}

	std::vector<int> coords = returnCoordinates(startSquare);
	int row = coords[0];
	int col = coords[1];

	if (isHorizontal)
	{
		for (int i = -1; i <= shipLong; i++)
		{
			try
			{
				if (!col) throw - 1;
				int frontSquare = returnSquare(row, col - 1);
				enemyBoard.replace(frontSquare, 2, instance.miss);
			}
			catch (int)
			{

			}
			catch (std::exception&)
			{

			}

			try
			{
				if (shipLong + col == 10) throw - 1;
				int backSquare = returnSquare(row, shipLong + col);
				enemyBoard.replace(backSquare, 2, instance.miss);
			}
			catch (int)
			{

			}
			catch (std::exception&)
			{

			}

			try
			{
				if (!row) throw - 1;
				if (i == -1 && !col) throw - 1;
				if (i > 0 && col == 9) throw - 1;
				int upperSquare = returnSquare(row - 1, col + i);
				enemyBoard.replace(upperSquare, 2, instance.miss);
			}
			catch (int)
			{

			}
			catch (std::exception&)
			{

			}

			try
			{
				if (row == 9) throw - 1;
				if (i == -1 && !col) throw - 1;
				if (i > 0 && col == 9) throw - 1;
				int lowerSquare = returnSquare(row + 1, col + i);
				enemyBoard.replace(lowerSquare, 2, instance.miss);
			}
			catch (int)
			{

			}
			catch (std::exception&)
			{

			}
		}
	}

	if (!isHorizontal)
	{
		for (int i = -1; i <= shipLong; i++)
		{
			try
			{
				int frontSquare = returnSquare(row - 1, col);
				enemyBoard.replace(frontSquare, 2, instance.miss);
			}
			catch (std::exception&)
			{

			}

			try
			{
				int backSquare = returnSquare(row + shipLong, col);
				enemyBoard.replace(backSquare, 2, instance.miss);
			}
			catch (std::exception&)
			{

			}

			try
			{
				if (!col) throw - 1;
				int leftSquare = returnSquare(row + i, col - 1);
				enemyBoard.replace(leftSquare, 2, instance.miss);
			}
			catch (int)
			{

			}
			catch (std::exception&)
			{

			}
			try
			{
				if (col == 9) throw - 1;
				int rightSquare = returnSquare(row + i, col + 1);
				enemyBoard.replace(rightSquare, 2, instance.miss);
			}
			catch (int)
			{

			}
			catch (std::exception&)
			{

			}
		}
	}
	return true;
}

bool isShip(Game& game, int shipType)
{
	if (shipType == 0 && game.ships[shipType] == 4)
	{
		return false;
	}

	if (shipType == 1 && game.ships[shipType] == 3)
	{
		return false;
	}

	if (shipType == 2 && game.ships[shipType] == 2)
	{
		return false;
	}
	if (shipType == 3 && game.ships[shipType] == 1)
	{
		return false;
	}
	return true;
}

bool shipsIsOver(Game& game)
{
	if (game.ships[0] == 4 && game.ships[1] == 3 && game.ships[2] == 2 && game.ships[3] == 1)
	{
		clearShips(game.ships);
		return true;
	}
	return false;
}

void clearShips(std::vector<int>& ships)
{
	for (int i = 0; i < 4; i++)
	{
		ships[i] = 0;
	}
}

int hitShip(int square, std::vector<std::vector<int>>& ships)
{
	int shipCheck = 1;
	for (int i = 0; i < ships.size(); i++)
	{
		for (int j = 2; j < ships[i].size(); j++)
		{
			if (ships[i][j] == square)
			{
				ships[i][j] = 0;
				shipCheck = i;
				break;
			}
		}
	}
	return shipCheck;
}

void shipCount(Game& game)
{
	switch (game.ship[0])
	{
	case 1:
		game.ships[0]++;
		break;
	case 2:
		game.ships[1]++;
		break;
	case 3:
		game.ships[2]++;
		break;
	case 4:
		game.ships[3]++;
		break;
	}
}