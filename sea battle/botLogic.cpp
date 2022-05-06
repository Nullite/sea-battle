#include "botLogic.h"

std::vector<std::vector<int> > botFillBoard(Game& game, std::string& board, Elements instance)
{
	std::vector<std::vector<int> > ships;
	while (!shipsIsOver(game))
	{
		chooseShip(game);
		placeBotship(game.ship, board, ships, instance);
	}
	return ships;
}

std::vector<int> chooseCoord(std::vector<int>& ship, std::string& board)
{
	std::vector<int> coordinates = { 0, 0 };
	int shipLayout = ship[1];
	int shipType = ship[0];
	int xCoord;
	int yCoord;

	while (1)
	{
		while (1)
		{
			xCoord = randomizer(0, 9);

			if (shipLayout == 1)
			{
				if (shipType == 4 && xCoord > 6 || shipType == 3 && xCoord > 7 || shipType == 2 && xCoord > 8)
				{
					continue;
				}
			}
			break;
		}

		while (1)
		{
			yCoord = randomizer(0, 9);

			if (shipLayout == 0)
			{
				if (shipType == 4 && yCoord > 6 || shipType == 3 && yCoord > 7 || shipType == 2 && yCoord > 8)
				{
					continue;
				}
			}
			break;
		}

		if (checkIfCorrectPlace(xCoord, yCoord, board, shipType, shipLayout))
		{
			break;
		}

	}

	coordinates[0] = xCoord;
	coordinates[1] = yCoord;

	return coordinates;
}

std::vector<int> botAimIfBattleship(Bot& bot)
{
	std::vector<int> coordinates = { -1, 0 };
	while (bot.tact.squearsIfBattleship.size())
	{
		int temp = randomizer(0, bot.tact.squearsIfBattleship.size() - 1);
		std::vector<int> tempVec = returnCoordinates(bot.tact.squearsIfBattleship.at(temp));
		coordinates[0] = tempVec[1];
		coordinates[1] = tempVec[0];
		bot.tact.squearsIfBattleship.erase(bot.tact.squearsIfBattleship.begin() + temp);
		if (isCorrectAim(coordinates[1], coordinates[0], bot.enemyBoard)) {
			if (!bot.tact.enemyShips[3])
			{
				if (checkIfAloneSquare(bot, coordinates))
				{
					continue;
				}
			}
			break;
		};
	}
	return coordinates;
}

std::vector<int> botAimIfCruiser(Bot& bot)
{
	std::vector<int> coordinates = { -1, 0 };
	while (bot.tact.squearsIfCruiser.size())
	{
		int temp = randomizer(0, bot.tact.squearsIfCruiser.size() - 1);
		std::vector<int> tempVec = returnCoordinates(bot.tact.squearsIfCruiser.at(temp));
		coordinates[0] = tempVec[1];
		coordinates[1] = tempVec[0];
		bot.tact.squearsIfCruiser.erase(bot.tact.squearsIfCruiser.begin() + temp);
		if (isCorrectAim(coordinates[1], coordinates[0], bot.enemyBoard)) {
			if (!bot.tact.enemyShips[3])
			{
				if (checkIfAloneSquare(bot, coordinates))
				{
					continue;
				}
			}
			break;
		};
	}
	return coordinates;
}

std::vector<int> botAimIfDestroyer(Bot& bot)
{
	std::vector<int> coordinates = { -1, 0 };
	while (bot.tact.squearsIfDestroyer.size())
	{
		int temp = randomizer(0, bot.tact.squearsIfDestroyer.size() - 1);
		std::vector<int> tempVec = returnCoordinates(bot.tact.squearsIfDestroyer.at(temp));
		coordinates[0] = tempVec[1];
		coordinates[1] = tempVec[0];
		bot.tact.squearsIfDestroyer.erase(bot.tact.squearsIfDestroyer.begin() + temp);
		if (isCorrectAim(coordinates[1], coordinates[0], bot.enemyBoard)) {
			if (!bot.tact.enemyShips[3])
			{
				if (checkIfAloneSquare(bot, coordinates))
				{
					continue;
				}
			}
			break;
		};
	}
	return coordinates;
}

std::vector<int> botAimIfSubmarine(Bot& bot)
{
	std::vector<int> coordinates = { -1, 0 };
	while (bot.tact.remainingSquears.size())
	{
		int temp = randomizer(0, bot.tact.remainingSquears.size() - 1);
		std::vector<int> tempVec = returnCoordinates(bot.tact.remainingSquears.at(temp));
		coordinates[0] = tempVec[1];
		coordinates[1] = tempVec[0];
		bot.tact.remainingSquears.erase(bot.tact.remainingSquears.begin() + temp);
		if (isCorrectAim(coordinates[1], coordinates[0], bot.enemyBoard)) {
			if (!bot.tact.enemyShips[3])
			{
				if (checkIfAloneSquare(bot, coordinates))
				{
					continue;
				}
			}
			break;
		};
	}
	return coordinates;
}

std::vector<int> randomFire(Bot& bot)
{
	std::vector<int> coordinates = { 0, 0 };
	while (1)
	{
		int rnd = 0;
		
			rnd = randomizer(1, 4);
			switch (rnd)
			{
			case 1:
				if (bot.tact.squearsIfBattleship.size())
				{
					coordinates = botAimIfBattleship(bot);
				}
				break;
			case 2:
				if (bot.tact.squearsIfCruiser.size())
				{
					coordinates = botAimIfCruiser(bot);
				}
				break;
			case 3:
				if (bot.tact.squearsIfDestroyer.size())
				{
					coordinates = botAimIfDestroyer(bot);
				}			
				break;
			case 4:
				if (bot.tact.remainingSquears.size())
				{
					coordinates = botAimIfSubmarine(bot);
				}
				break;
			}
		if (isCorrectAim(coordinates[1], coordinates[0], bot.enemyBoard))
		{
			break;
		}
	}
	return coordinates;
}

std::vector<int> botAim(Bot& bot)
{
	std::vector<int> coordinates = { -1, 0 };

	while (coordinates[0] == -1)
	{
		switch (bot.aim)
		{
		case true:
			if (bot.tact.enemyShips[0])
			{
				coordinates = botAimIfBattleship(bot);
				if (coordinates[0] == -1) continue;
			}
			else if (bot.tact.enemyShips[1])
			{
				switch (bot.tact.squearsIfBattleship.size())
				{
				case 0:
					coordinates = botAimIfCruiser(bot);
					if (coordinates[0] == -1) continue;
					break;
				default:
					int rnd = randomizer(0, 1);
					if (rnd)
					{
						coordinates = botAimIfCruiser(bot);
					}
					else
					{
						coordinates = botAimIfBattleship(bot);
						if (coordinates[0] == -1)
						{
							continue;
						}
					}
					break;
				}
			}
			else if (bot.tact.enemyShips[2])
			{
				if (bot.tact.squearsIfBattleship.size())
				{
					int rnd = randomizer(0, 2);
					if (rnd == 2)
					{
						coordinates = botAimIfDestroyer(bot);
						if (coordinates[0] == -1) continue;
					}
					else if (rnd == 1)
					{
						coordinates = botAimIfCruiser(bot);
						if (coordinates[0] == -1) continue;
					}
					else
					{
						coordinates = botAimIfBattleship(bot);
						if (coordinates[0] == -1) continue;
					}
				}
				else if (bot.tact.squearsIfCruiser.size())
				{
					int rnd = randomizer(0, 1);
					if (rnd)
					{
						coordinates = botAimIfDestroyer(bot);
						if (coordinates[0] == -1) continue;
					}
					else
					{
						coordinates = botAimIfCruiser(bot);
						if (coordinates[0] == -1) continue;
					}
				}
				else
				{
					coordinates = botAimIfDestroyer(bot);
					if (coordinates[0] == -1) continue;
				}
			}
			else
			{
				coordinates = randomFire(bot);
				if (coordinates[0] == -1) continue;
			}
			break;

		case false:
			coordinates = randomFire(bot);
			break;
		}
	}
	return coordinates;
}

std::vector<int> finishing(std::vector<int>& coords, std::string& botEnemyBoard)
{
	int count = 0;
	std::vector<int> coordinates = { 0, 0 };
	int rndAim;
	int col = coords[0];
	int row = coords[1];

	int newRow = -1;
	int newCol = -1;

	if (coords[2] == 2)
	{

		if (col == 9)
		{
			newCol = 7;
			newRow = row;
			if (isCorrectAim(newRow, newCol, botEnemyBoard))
			{
				coordinates[0] = newCol;
				coordinates[1] = newRow;
				return coordinates;
			}
			coordinates[0] = newCol - 1;
			coordinates[1] = newRow;
			return coordinates;
		}
		if (col == 8)
		{
			int rightFire = randomizer(0, 1);
			newCol = rightFire ? 9 : 7;
			newRow = row;
			if (isCorrectAim(newRow, newCol, botEnemyBoard))
			{
				coordinates[0] = newCol;
				coordinates[1] = newRow;
				return coordinates;
			}
			else
			{
				newCol--;
				while (!isCorrectAim(newRow, newCol, botEnemyBoard))
				{
					newCol--;
				}
				coordinates[0] = newCol;
				coordinates[1] = newRow;
				return coordinates;
			}
		}
		if (!col)
		{
			newCol = 2;
			newRow = row;
			if (isCorrectAim(newRow, newCol, botEnemyBoard))
			{
				coordinates[0] = newCol;
				coordinates[1] = newRow;
				return coordinates;
			}
			else
			{
				coordinates[0] = newCol + 1;
				coordinates[1] = newRow;
				return coordinates;
			}


		}
		if (col == 1)
		{
			int rightFire = randomizer(0, 1);
			newCol = rightFire ? 2 : 0;
			newRow = row;
			if (isCorrectAim(newRow, newCol, botEnemyBoard))
			{
				coordinates[0] = newCol;
				coordinates[1] = newRow;
				return coordinates;
			}
			else
			{
				newCol--;
				while (!isCorrectAim(newRow, newCol, botEnemyBoard))
				{
					newCol--;
				}
				coordinates[0] = newCol;
				coordinates[1] = newRow;
				return coordinates;
			}
		}
		int count = 0;
		for (int i = 1; i <= 2; i++)
		{
			int square = returnSquare(row, col + i);
			if (botEnemyBoard.at(square) == (char)126)
			{
				count = 3;
				break;
			}
			if (botEnemyBoard.at(square) == ' ')
			{
				break;
			}
			if (botEnemyBoard.at(square) == (char)176)
			{
				count++;
			}
		}
		if (count == 3)
		{
			newRow = row;
			newCol = col - 1;
			while (!isCorrectAim(newRow, newCol, botEnemyBoard))
			{
				newCol--;
			}
			coordinates[0] = newCol;
			coordinates[1] = newRow;
			return coordinates;
		}
		if (count)
		{
			count++;
			int rightFire = randomizer(0, 1);

			newCol = rightFire ? col + count : col - 1;
			newRow = row;
			if (rightFire && newCol && isCorrectAim(newRow, newCol, botEnemyBoard))
			{
				coordinates[0] = newCol;
				coordinates[1] = newRow;
				return coordinates;
			}
			else if (!rightFire && isCorrectAim(newRow, newCol, botEnemyBoard))
			{
				coordinates[0] = newCol;
				coordinates[1] = newRow;
				return coordinates;
			}
			else
			{
				newCol = rightFire ? col - 1 : col + count;
				newRow = row;
				coordinates[0] = newCol;
				coordinates[1] = newRow;
				return coordinates;
			}
		}
		if (!count)
		{
			for (int i = 1; i <= 2; i++)
			{
				int square = returnSquare(row, col - i);
				if (botEnemyBoard.at(square) == (char)126)
				{
					count = 3;
					break;
				}
				if (botEnemyBoard.at(square) == ' ')
				{
					break;
				}
				if (botEnemyBoard.at(square) == (char)176)
				{
					count++;
				}
			}
			if (count == 3)
			{
				newCol = col + 1;
				newRow = row;
				coordinates[0] = newCol;
				coordinates[1] = newRow;
				return coordinates;

			}
			else
			{
				count++;
				int leftFire = randomizer(0, 1);

				newCol = leftFire ? col - count : col + 1;
				newRow = row;
				if (isCorrectAim(newRow, newCol, botEnemyBoard))
				{
					coordinates[0] = newCol;
					coordinates[1] = newRow;
					return coordinates;
				}
				else
				{
					newCol = leftFire ? col + 1 : col - count;
					newRow = row;
					coordinates[0] = newCol;
					coordinates[1] = newRow;
					return coordinates;
				}
			}
		}

	}

	if (coords[2] == 3)
	{
		if (row == 9)
		{
			newCol = col;
			newRow = 7;
			if (isCorrectAim(newRow, newCol, botEnemyBoard))
			{
				coordinates[0] = newCol;
				coordinates[1] = newRow;
				return coordinates;
			}
			coordinates[0] = newCol;
			coordinates[1] = newRow - 1;
			return coordinates;
		}
		if (row == 8)
		{
			int upFire = randomizer(0, 1);
			newCol = col;
			newRow = upFire ? 9 : 7;
			if (isCorrectAim(newRow, newCol, botEnemyBoard))
			{
				coordinates[0] = newCol;
				coordinates[1] = newRow;
				return coordinates;
			}
			else
			{
				newRow--;
				while (!isCorrectAim(newRow, newCol, botEnemyBoard))
				{
					newRow--;
				}
				coordinates[0] = newCol;
				coordinates[1] = newRow;
				return coordinates;
			}
		}
		if (!row)
		{
			newCol = col;
			newRow = 2;
			if (isCorrectAim(newRow, newCol, botEnemyBoard))
			{
				coordinates[0] = newCol;
				coordinates[1] = newRow;
				return coordinates;
			}
			else
			{
				coordinates[0] = newCol;
				coordinates[1] = newRow + 1;
				return coordinates;
			}


		}
		if (row == 1)
		{
			int upFire = randomizer(0, 1);
			newCol = col;
			newRow = upFire ? 2 : 0;
			if (isCorrectAim(newRow, newCol, botEnemyBoard))
			{
				coordinates[0] = newCol;
				coordinates[1] = newRow;
				return coordinates;
			}
			else
			{
				newRow--;
				while (!isCorrectAim(newRow, newCol, botEnemyBoard))
				{
					newRow--;
				}
				coordinates[0] = newCol;
				coordinates[1] = newRow;
				return coordinates;
			}
		}
		int count = 0;
		for (int i = 1; i <= 2; i++)
		{
			int square = returnSquare(row + i, col);
			if (botEnemyBoard.at(square) == (char)126)
			{
				count = 3;
				break;
			}
			if (botEnemyBoard.at(square) == ' ')
			{
				break;
			}
			if (botEnemyBoard.at(square) == (char)176)
			{
				count++;
			}
		}
		if (count == 3)
		{
			newRow = row - 1;
			newCol = col;
			while (!isCorrectAim(newRow, newCol, botEnemyBoard))
			{
				newRow--;
			}
			coordinates[0] = newCol;
			coordinates[1] = newRow;
			return coordinates;
		}
		if (count)
		{
			count++;
			int upFire = randomizer(0, 1);

			newCol = col;
			newRow = upFire ? row + count : row - 1;

			if (isCorrectAim(newRow, newCol, botEnemyBoard))
			{
				coordinates[0] = newCol;
				coordinates[1] = newRow;
				return coordinates;
			}
			else
			{
				newRow = upFire ? row - 1 : row + count;
				newCol = col;
				coordinates[0] = newCol;
				coordinates[1] = newRow;
				return coordinates;
			}
		}
		if (!count)
		{
			for (int i = 1; i <= 2; i++)
			{
				int square = returnSquare(row - i, col);
				if (botEnemyBoard.at(square) == (char)126)
				{
					count = 3;
					break;
				}
				if (botEnemyBoard.at(square) == ' ')
				{
					break;
				}
				if (botEnemyBoard.at(square) == (char)176)
				{
					count++;
				}
			}
			if (count == 3)
			{
				newCol = col;
				newRow = row + 1;
				coordinates[0] = newCol;
				coordinates[1] = newRow;
				return coordinates;

			}
			else
			{
				count++;
				int downFire = randomizer(0, 1);

				newRow = downFire ? row + 1 : row - count;
				newCol = col;
				if (isCorrectAim(newRow, newCol, botEnemyBoard))
				{
					coordinates[0] = newCol;
					coordinates[1] = newRow;
					return coordinates;
				}
				else
				{
					newRow = downFire ? row - count : row + 1;
					newCol = col;
					coordinates[0] = newCol;
					coordinates[1] = newRow;
					return coordinates;
				}
			}
		}
	}

	while (1)
	{
		rndAim = randomizer(1, 4);

		switch (rndAim)
		{
		case 1:
			if (row)
			{
				newRow = row - 1;
				newCol = col;
			}
			break;
		case 2:
			if (row != 9)
			{
				newRow = row + 1;
				newCol = col;
			}
			break;
		case 3:
			if (col)
			{
				newRow = row;
				newCol = col - 1;
			}
			break;
		case 4:
			if (col != 9)
			{
				newRow = row;
				newCol = col + 1;
			}
			break;
		}
		if (newRow == -1)
		{
			continue;
		}
		if (isCorrectAim(newRow, newCol, botEnemyBoard))
		{
			break;
		}
	}
	coordinates[0] = newCol;
	coordinates[1] = newRow;

	return coordinates;
}

bool checkIfAloneSquare(Bot& bot, std::vector<int>& coordinates)
{
	int square = returnSquare(coordinates[0], coordinates[1]);
	int row = coordinates[0];
	int col = coordinates[1];
	int frontSquare;
	int backSquare;
	int upperSquare;
	int downSquare;

	if (col)
	{
		frontSquare = returnSquare(row, col - 1);
		if (bot.enemyBoard.at(frontSquare) == ' ')
		{
			return false;
		}
	}

	if (col != 9)
	{
		backSquare = returnSquare(row, col + 1);
		if (bot.enemyBoard.at(backSquare) == ' ')
		{
			return false;
		}
	}

	for (int i = -1; i < 2; i++)
	{
		try
		{
			upperSquare = returnSquare(row + 1, col + i);
			if (bot.enemyBoard.at(upperSquare) == ' ')
			{
				return false;
			}
		}
		catch (std::exception&)
		{

		}

		try
		{
			downSquare = returnSquare(row - 1, col + i);
			if (bot.enemyBoard.at(upperSquare) == ' ')
			{
				return false;
			}
		}
		catch (std::exception&)
		{

		}
	}
	bot.enemyBoard.replace(square, 2, { (char)126, (char)126 });
	return true;
}

void placeBotship(std::vector<int> ship, std::string& board, std::vector<std::vector<int> >& ships, Elements instance)
{
	int shipLong = ship[0];
	int shipHorizontalLayout = ship[1];
	std::vector<int> newShip;
	std::vector<int> coordinates = chooseCoord(ship, board);
	int col = coordinates[0];
	int row = coordinates[1];

	if (!shipHorizontalLayout)
	{
		int square = returnSquare(row, col);
		newShip.push_back(0);
		newShip.push_back(square);
		for (int i = 0; i < shipLong; i++)
		{
			int square = returnSquare(row, col);
			board.replace(square, 2, instance.shipElement);
			row += 1;
			newShip.push_back(square);
		}
	}
	else
	{
		int square = returnSquare(row, col);
		newShip.push_back(1);
		newShip.push_back(square);
		for (int i = 0; i < shipLong; i++)
		{
			int square = returnSquare(row, col);
			board.replace(square, 2, instance.shipElement);
			col += 1;
			newShip.push_back(square);
		}
	}

	ships.push_back(newShip);
}

void chooseShip(Game& game)
{
	game.ship = { 0, 0 };

	int shipType = randomizer(1, 4);

	if (!isShip(game, shipType - 1))
	{
		while (!isShip(game, shipType - 1))
		{
			shipType = randomizer(1, 4);
		}
	}

	int shipLayout;

	if (shipType == 1)
	{
		shipLayout = 1;
	}
	else
	{
		shipLayout = randomizer(0, 1);
	}

	game.ship[0] = shipType;
	game.ship[1] = shipLayout;

	shipCount(game);
}

void botFireOnSquare(Elements instance, User& player, Bot& bot, Game& game, std::vector<std::vector<int>>& enemyShips, std::string& enemyBoard)
{
	bool miss = false;

	while (!miss)
	{
		declareTurn(game.whoseTurn);
		Sleep(2000);
		system("cls");
		std::vector<int> coords;
		int row;
		int col;
		int square;
		if (bot.coordsFinishing[0] == -1)
		{
			coords = botAim(bot);
			row = coords[1];
			col = coords[0];
			square = returnSquare(row, col);
		}
		else
		{
			coords = finishing(bot.coordsFinishing, bot.enemyBoard);
			row = coords[1];
			col = coords[0];
			square = returnSquare(row, col);
		}

		if (enemyBoard[square] != ' ')
		{
			sightMovement(enemyBoard, square, instance);
			int hit = hitShip(square, enemyShips);
			hitShip(square, enemyBoard, bot.enemyBoard, instance);
			bool isDestroyed = destroyShip(checkShip(hit, enemyShips, player.isPlay), bot.enemyBoard, instance, game, bot);
			if (!isDestroyed)
			{
				bot.coordsFinishing[0] = col;
				bot.coordsFinishing[1] = row;
				if (!bot.coordsFinishing[2])
				{
					bot.coordsFinishing[3] = col;
					bot.coordsFinishing[2]++;
				}
				else
				{
					bot.coordsFinishing[2] = bot.coordsFinishing[0] == bot.coordsFinishing[3] ? 3 : 2;
				}

			}

			else
			{
				bot.clearCoordsFinishing();
			}

		}
		else
		{
			sightMovement(enemyBoard, square, instance);
			missed(square, enemyBoard, bot.enemyBoard, instance);
			swapNames(game.whoseTurn, game.whoseNext);
			miss = true;
		}
		system("cls");
		if (!enemyShips.size()) break;
		showBoard(enemyBoard);
		awaitPause(game.partyOver, player);
		if (game.partyOver)
		{
			game.saveLoad = false;
			break;
		}
		system("cls");
	}
}