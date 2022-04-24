#include "ships.h"

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

bool shipsIsOver(Game& game)
{
	if (game.ships[0] == 4 && game.ships[1] == 3 && game.ships[2] == 2 && game.ships[3] == 1)
	{
		clearShips(game.ships);
		return true;
	}
	return false;
}

void askShip(Game& game, std::string& board, Elements instance)
{
	bool isBattleship = isShip(game, 3);
	bool isCruiser = isShip(game, 2);
	bool isDestroyer = isShip(game, 1);
	bool isSubmarine = isShip(game, 0);
	char type;
	char layout;

	std::cout << "choose ship type:\t";

	if (isBattleship)
	{
		std::cout << "1 - battleship: " << instance.shipElement << ' ' << instance.shipElement << ' ' << instance.shipElement << ' ' << instance.shipElement << "\n\n\t\t\t";
	}

	if (isCruiser)
	{
		std::cout << "2 - cruiser: " << instance.shipElement << ' ' << instance.shipElement << ' ' << instance.shipElement << ' ' << "\n\n\t\t\t";
	}

	if (isDestroyer)
	{
		std::cout << "3 - destroyer: " << instance.shipElement << ' ' << instance.shipElement << "\n\n\t\t\t";
	}

	if (isSubmarine)
	{
		std::cout << "4 - submarine: " << instance.shipElement << "\n";
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
			game.ship[0] = 4;
			game.ship[1] = 1;
			break;
		case '2':
			game.ship[0] = 4;
			game.ship[1] = 0;
			break;
		}
		break;
	case '2':
		switch (layout)
		{
		case '1':
			game.ship[0] = 3;
			game.ship[1] = 1;
			break;
		case '2':
			game.ship[0] = 3;
			game.ship[1] = 0;
			break;
		}
		break;
	case '3':
		switch (layout)
		{
		case '1':
			game.ship[0] = 2;
			game.ship[1] = 1;
			break;
		case '2':
			game.ship[0] = 2;
			game.ship[1] = 0;
			break;
		}
		break;
	case '4':
		game.ship[0] = 1;
		game.ship[1] = 1;
		break;
	}
	shipCount(game);
}


