#include "botLogic.h"

void chooseShip(std::vector<int>& ship)
{
	ship = { 0, 0 };

	int shipType = randomizer(1, 4);

	if (!isShip(shipType - 1))
	{
		while (!isShip(shipType - 1))
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

	ship[0] = shipType;
	ship[1] = shipLayout;

	shipCount(ship[0]);
}

std::vector<int> chooseCoord(std::vector<int>& ship, std::string& board)
{
	std::vector<int> coordinates = {0, 0};
	int shipLayout = ship[1];
	int shipType = ship[0];
	int xCoord;
	int yCoord;

	while (1)
	{
		while (1)
		{
			xCoord = randomizer(0,9);

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
			yCoord = randomizer(0,9);

			if (shipLayout == 0)
			{
				if (shipType == 4 && yCoord > 6 || shipType == 3 && yCoord > 7  || shipType == 2 && yCoord > 8)
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

void placeBotship(std::vector<int> ship, std::string& board, std::vector<std::vector<int> > &ships)
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
		board.replace(square, 2, shipElement);
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
		board.replace(square, 2, shipElement);
		col += 1;
		newShip.push_back(square);
	}
}

ships.push_back(newShip);
}

std::vector<std::vector<int> > botFillBoard(std::string& board)
{
	std::vector<std::vector<int> > ships;
	while (!shipsIsOver())
	{
		chooseShip(ship);
		placeBotship(ship, board, ships);
	}
	return ships;
}

std::vector<int> botAim(std::string& board)
{
	std::vector<int> coordinates = { 0, 0 };
	while (1)
	{
		coordinates[0] = randomizer(0, 9);
		coordinates[1] = randomizer(0, 9);

		if (isCorrectAim(coordinates[1], coordinates[0], board))
		{
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

				newRow = downFire ?  row + 1 : row - count;
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

void botFireOnSquare(bool botAiming,bool& userSaveGame, bool& saveload, bool isUserPlay, bool& partyOver, std::vector<std::vector<int>> &enemyShips, std::vector<std::vector<int>>& compShips, std::string &enemyBoard, std::string &botEnemyBoard, std::vector<int>& coordinates, std::string& whoseTurn, std::string& whoseNext)
{
		bool miss = false;

		while (!miss)
		{
			declareTurn(whoseTurn);
			Sleep(2000);
			system("cls");
			std::vector<int> coords;
			int row;
			int col;
			int square;
			if (coordinates[0] == -1 || !botAiming)
			{
				coords = botAim(botEnemyBoard);
				row = coords[1];
				col = coords[0];
				square = returnSquare(row, col);
			}
			else
			{
				coords = finishing(coordinates, botEnemyBoard);
				row = coords[1];
				col = coords[0];
				square = returnSquare(row, col);
			}
			
			if (enemyBoard[square] != ' ')
			{
				sightMovement(enemyBoard, square);
				int hit = hitShip(square, enemyShips);
				hitShip(square, enemyBoard, botEnemyBoard);
				bool isDestroyed = destroyShip(checkShip(hit, enemyShips, isUserPlay), botEnemyBoard);
				if (!isDestroyed)
				{
					coordinates[0] = col;
					coordinates[1] = row;
					if (!coordinates[2])
					{
						coordinates[3] = col;
						coordinates[2]++;
					}
					else
					{
						coordinates[2] = coordinates[0] == coordinates[3] ? 3 : 2;
					}
					
				}

				else
				{
					coordinates[0] = -1;
					coordinates[1] = 0;
					coordinates[2] = 0;
					coordinates[3] = 0;
				}
				
			}
			else
			{
				sightMovement(enemyBoard, square);
				missed(square, enemyBoard, botEnemyBoard);
				swapNames(whoseTurn, whoseNext);
				miss = true;
			}
			system("cls");
			if (!enemyShips.size()) break;
			showBoard(enemyBoard);
			awaitPause(partyOver, userSaveGame);
			if (partyOver)
			{
				saveload = false;
				break;
			}
			system("cls");
		}		
}
