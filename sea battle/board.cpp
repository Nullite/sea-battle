#include "board.h"

std::vector<int> returnCoordinates(int square)
{
	std::vector<int> coords;
	const int rows = 10;
	const int cols = 10;
	int squearsList[rows][cols]
	{
		{116, 121, 126, 131, 136, 141, 146, 151, 156, 161},
		{228, 233, 238, 243, 248, 253, 258, 263, 268, 273},
		{340, 345, 350, 355, 360, 365, 370, 375, 380, 385},
		{452, 457, 462, 467, 472, 477, 482, 487, 492, 497},
		{564, 569, 574, 579, 584, 589, 594, 599, 604, 609},
		{676, 681, 686, 691, 696, 701, 706, 711, 716, 721},
		{788, 793, 798, 803, 808, 813, 818, 823, 828, 833},
		{900, 905, 910, 915, 920, 925, 930, 935, 940, 945},
		{1012, 1017, 1022, 1027, 1032, 1037, 1042, 1047, 1052, 1057},
		{1124, 1129, 1134, 1139, 1144, 1149, 1154, 1159, 1164, 1169}
	};

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (squearsList[i][j] == square)
			{
				coords.push_back(i);
				coords.push_back(j);
				break;
			}
		}
	}
	return coords;
}

std::string field()
{
	std::string field =
		"       A    B    C    D    E    F    G    H    I    J\n";
	field += "    +----+----+----+----+----+----+----+----+----+----+\n";
	field += "  1 |    |    |    |    |    |    |    |    |    |    |\n";
	field += "    +----+----+----+----+----+----+----+----+----+----+\n";
	field += "  2 |    |    |    |    |    |    |    |    |    |    |\n";
	field += "    +----+----+----+----+----+----+----+----+----+----+\n";
	field += "  3 |    |    |    |    |    |    |    |    |    |    |\n";
	field += "    +----+----+----+----+----+----+----+----+----+----+\n";
	field += "  4 |    |    |    |    |    |    |    |    |    |    |\n";
	field += "    +----+----+----+----+----+----+----+----+----+----+\n";
	field += "  5 |    |    |    |    |    |    |    |    |    |    |\n";
	field += "    +----+----+----+----+----+----+----+----+----+----+\n";
	field += "  6 |    |    |    |    |    |    |    |    |    |    |\n";
	field += "    +----+----+----+----+----+----+----+----+----+----+\n";
	field += "  7 |    |    |    |    |    |    |    |    |    |    |\n";
	field += "    +----+----+----+----+----+----+----+----+----+----+\n";
	field += "  8 |    |    |    |    |    |    |    |    |    |    |\n";
	field += "    +----+----+----+----+----+----+----+----+----+----+\n";
	field += "  9 |    |    |    |    |    |    |    |    |    |    |\n";
	field += "    +----+----+----+----+----+----+----+----+----+----+\n";
	field += " 10 |    |    |    |    |    |    |    |    |    |    |\n";
	field += "    +----+----+----+----+----+----+----+----+----+----+\n";

	return field;
}

bool checkIfCorrectPlace(int col, int row, std::string& board, int shipLong, int shipLayout)
{

	if (shipLayout)
	{
		for (int i = -1; i <= shipLong; i++)
		{
			if (i == -1 && !col)
			{
				continue;
			}
			if (col + i == 10)
			{
				return true;
			}
			try
			{
				int square = returnSquare(row, col + i);

				if (board.at(square) != ' ')
				{
					return false;
				}


			}
			catch (const std::exception&)
			{

			}
			try
			{
				int upperSquare = returnSquare(row - 1, col + i);

				if (board.at(upperSquare) != ' ')
				{
					return false;
				}

			}
			catch (const std::exception&)
			{

			}
			try
			{
				int lowerSquare = returnSquare(row + 1, col + i);

				if (board.at(lowerSquare) != ' ')
				{
					return false;
				}

			}
			catch (const std::exception&)
			{

			}

		}
	}
	else
	{
		for (int i = -1; i <= shipLong; i++)
		{
			try
			{
				int square = returnSquare(row + i, col);
				int leftSquare = returnSquare(row + i, col - 1);
				int rightSquare = returnSquare(row + i, col + 1);


				if (board.at(square) != ' ' || board.at(leftSquare) != ' ' && col || board.at(rightSquare) != ' ' && col != 9)
				{
					return false;
				}
			}
			catch (const std::exception&)
			{
				continue;
			}

		}

	}

	return true;
}

int returnSquare(int row, int col)
{
	const int rows = 10;
	const int cols = 10;
	int squearsList[rows][cols]
	{
		{116, 121, 126, 131, 136, 141, 146, 151, 156, 161},
		{228, 233, 238, 243, 248, 253, 258, 263, 268, 273},
		{340, 345, 350, 355, 360, 365, 370, 375, 380, 385},
		{452, 457, 462, 467, 472, 477, 482, 487, 492, 497},
		{564, 569, 574, 579, 584, 589, 594, 599, 604, 609},
		{676, 681, 686, 691, 696, 701, 706, 711, 716, 721},
		{788, 793, 798, 803, 808, 813, 818, 823, 828, 833},
		{900, 905, 910, 915, 920, 925, 930, 935, 940, 945},
		{1012, 1017, 1022, 1027, 1032, 1037, 1042, 1047, 1052, 1057},
		{1124, 1129, 1134, 1139, 1144, 1149, 1154, 1159, 1164, 1169}
	};

	return squearsList[row][col];
}

void placeShip(Game& game, User& player, Elements instance)
{
	int shipLong = game.ship[0];
	int shipHorizontalLayout = game.ship[1];
	std::vector <int> newShip;
	std::vector<int> coordinates = getSquare(shipLong, shipHorizontalLayout, player.board, instance);
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
			player.board.replace(square, 2, instance.shipElement);
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
			player.board.replace(square, 2, instance.shipElement);
			col += 1;
			newShip.push_back(square);
		}
	}
	player.ships.push_back(newShip);
	PlaySound(TEXT("./sound/morze.wav"), NULL, SND_FILENAME | SND_ASYNC);
}

void hitShip(int square, std::string& board, std::string& enemyBoard, Elements instance)
{
	board.replace(square, 2, instance.destroyedShipElement);
	enemyBoard.replace(square, 2, instance.destroyedShipElement);
}

void missed(int square, std::string& board, std::string& enemyBoard, Elements instance)
{
	board.replace(square, 2, instance.miss);
	enemyBoard.replace(square, 2, instance.miss);
}

void fillBoard(Game& game, User& player, Elements instance)
{
	PlaySound(0, 0, 0);
	std::vector<std::vector <int> > ships;
	while (!shipsIsOver(game))
	{
		showBoard(player.board);
		askShip(game, player.board, instance);
		placeShip(game, player, instance);
		system("cls");
	}
}