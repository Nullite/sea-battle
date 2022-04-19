#include "ships.h"

bool isShip(int shipType)
{
	if (shipType == 0 && ships[shipType] == 4)
	{
		return false;
	}

	if (shipType == 1 && ships[shipType] == 3)
	{
		return false;
	}

	if (shipType == 2 && ships[shipType] == 2)
	{
		return false;
	}
	if (shipType == 3 && ships[shipType] == 1)
	{
		return false;
	}
	return true;
}

void shipCount(int shipType)
{
	switch (shipType)
	{
	case 1:
		ships[0]++;
		break;
	case 2:
		ships[1]++;
		break;
	case 3:
		ships[2]++;
		break;
	case 4:
		ships[3]++;
		break;
	}
}

bool shipsIsOver()
{
	if (ships[0] == 4 && ships[1] == 3 && ships[2] == 2 && ships[3] == 1)
	{
		clearShips(ships);
		return true;
	}
	return false;
}

void askShip(std::vector<int>& ship, std::string board)
{
	bool isBattleship = isShip(3);
	bool isCruiser = isShip(2);
	bool isDestroyer = isShip(1);
	bool isSubmarine = isShip(0);
	char type;
	char layout;

	std::cout << "choose ship type:\t";

	if (isBattleship)
	{
		std::cout << "1 - battleship: " << shipElement << ' ' << shipElement << ' ' << shipElement << ' ' << shipElement << "\n\n\t\t\t";
	}

	if (isCruiser)
	{
		std::cout << "2 - cruiser: " << shipElement << ' ' << shipElement << ' ' << shipElement << ' ' << "\n\n\t\t\t";
	}

	if (isDestroyer)
	{
		std::cout << "3 - destroyer: " << shipElement << ' ' << shipElement << "\n\n\t\t\t";
	}

	if (isSubmarine)
	{
		std::cout << "4 - submarine: " << shipElement << "\n";
	}

	while (1)
	{
		type = _getch();
		if ((int)type < 49 || (int)type > 52)
		{
			Beep(247, 500);
			continue;
		}

		if ((int)type == 49 && !isBattleship || (int)type == 50 && !isCruiser || (int)type == 51 && !isDestroyer || (int)type == 52 && !isSubmarine)
		{
			Beep(247, 500);
			continue;
		}
		PlaySound(TEXT("./sound/button.wav"), NULL, SND_FILENAME | SND_ASYNC);
		break;
	}
	
	system("cls");
	showBoard(board);

	if (type != '4')
	{
		std::cout << "choose ship layout:\t"
			<< "1 - horizontal\n\t\t\t"
			<< "2 - vertical\n";

		while (1)
		{
			layout = _getch();
			if ((int)layout < 49 || (int)layout > 50)
			{
				Beep(247, 500);
				continue;
			}
			PlaySound(TEXT("./sound/button.wav"), NULL, SND_FILENAME | SND_ASYNC);
			break;
		}
	}

	switch (type)
	{
	case '1':
		switch (layout)
		{
		case '1':
			ship[0] = 4;
			ship[1] = 1;
			break;
		case '2':
			ship[0] = 4;
			ship[1] = 0;
			break;
		}
		break;
	case '2':
		switch (layout)
		{
		case '1':
			ship[0] = 3;
			ship[1] = 1;
			break;
		case '2':
			ship[0] = 3;
			ship[1] = 0;
			break;
		}
		break;
	case '3':
		switch (layout)
		{
		case '1':
			ship[0] = 2;
			ship[1] = 1;
			break;
		case '2':
			ship[0] = 2;
			ship[1] = 0;
			break;
		}
		break;
	case '4':
		ship[0] = 1;
		ship[1] = 1;
		break;
	}
	shipCount(ship[0]);
}

std::vector<int> getShip(std::string board)
{
	std::vector <int> ship{ 0,0 };
	askShip(ship, board);

	return ship;
}

