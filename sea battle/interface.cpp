#include "interface.h"

std::vector<int> getSquare(int shipType, int shipLayout, std::string& board, Elements instance)
{
	char xCoord;
	char yCoord;

	std::vector<int> coordinates;

	while (1)
	{
		coordinates = { 0, 0 };
		system("cls");
		showBoard(board);

		std::cout << "enter x coordinate "
			<< "(from A to J)\n"
			<< "end y coordinate "
			<< "(from 1 to 9 or 0 (means 10))\n\n";

		displayChoosedShip(shipType, shipLayout, instance);

		while (1)
		{
			xCoord = _getch();
			xCoord = toupper(xCoord);
			if ((int)xCoord < 65 || (int)xCoord > 74)
			{
				Beep(247, 500);
				continue;
			}

			if (shipLayout == 1)
			{
				if (shipType == 4 && (int)xCoord > 71 || shipType == 3 && (int)xCoord > 72 || shipType == 2 && (int)xCoord > 73)
				{
					Beep(247, 500);
					continue;
				}
			}
			PlaySound(TEXT("./sound/button.wav"), NULL, SND_FILENAME | SND_ASYNC);
			std::cout << xCoord;
			break;
		}

		while (1)
		{
			yCoord = _getch();
			if ((int)yCoord < 48 || (int)yCoord > 57)
			{
				Beep(247, 500);
				continue;
			}

			if ((int)yCoord == 48)
			{
				std::cout << "10";
			}
			else
			{
				std::cout << yCoord;
			}

			break;
		}

		if (shipLayout == 0)
		{
			if (shipType == 4 && ((int)yCoord > 55 || (int)yCoord == 48) || shipType == 3 && ((int)yCoord > 56 || (int)yCoord == 48) || shipType == 2 && ((int)yCoord > 57 || (int)yCoord == 48))
			{
				Beep(247, 500);
				continue;
			}
		}

		coordinates[0] = (int)xCoord - 65;

		if (yCoord == '0')
		{
			coordinates[1] = 9;
		}
		else
		{
			coordinates[1] = (int)yCoord - 49;
		}

		if (checkIfCorrectPlace(coordinates[0], coordinates[1], board, shipType, shipLayout))
		{
			PlaySound(TEXT("./sound/button.wav"), NULL, SND_FILENAME | SND_ASYNC);
			break;
		}
		Beep(247, 500);
	}


	return coordinates;
}

std::vector<int> aim(std::string& board)
{
	std::vector<int> coordinates = { 0, 0 };
	while (1)
	{
		system("cls");
		showBoard(board);
		std::cout << "enter x coordinate "
			<< "(from A to J)\n"
			<< "end y coordinate "
			<< "(from 1 to 9 or 0 (means 10))\n\n";

		char xCoord;
		char yCoord;

		while (1)
		{
			xCoord = _getch();
			xCoord = toupper(xCoord);
			if ((int)xCoord < 65 || (int)xCoord > 74)
			{
				Beep(247, 500);
				continue;
			}

			PlaySound(TEXT("./sound/button.wav"), NULL, SND_FILENAME | SND_ASYNC);
			std::cout << xCoord;
			break;
		}

		while (1)
		{
			yCoord = _getch();

			if ((int)yCoord < 48 || (int)yCoord > 57)
			{
				Beep(247, 500);
				continue;
			}


			if ((int)yCoord == 48)
			{
				std::cout << "10";
			}
			else
			{
				std::cout << yCoord;
			}

			break;
		}

		coordinates[0] = (int)xCoord - 65;

		if (yCoord == '0')
		{
			coordinates[1] = 9;
		}
		else
		{
			coordinates[1] = (int)yCoord - 49;
		}
		if (isCorrectAim(coordinates[1], coordinates[0], board))
		{
			PlaySound(TEXT("./sound/button.wav"), NULL, SND_FILENAME | SND_ASYNC);
			break;
		}
		Beep(247, 500);
	}
	PlaySound(TEXT("./sound/morze.wav"), NULL, SND_FILENAME);
	return coordinates;
}

std::vector<char> menu(Bot& bot1, Bot& bot2, User& player, Game& game)
{
	PlaySound(TEXT("./sound/menu.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	std::vector<char> players = { '0', '0' };
	char start;
	char firstPlayer;
	char secondPlayer;
	system("cls");
	getStart(start);
	if (start == '2')
	{
		game.isGame = false;
		system("cls");
		return players;
	}
	else
	{
		system("cls");
		choosePlayers(firstPlayer, secondPlayer, player.name, bot1.name, bot2.name);
		switch (firstPlayer)
		{
		case '1':
			game.whoseTurn = player.name;
			break;
		case '2':
			game.whoseTurn = bot1.name;
			setBotAiming(bot1.aim, bot1.name);
			break;
		case '3':
			game.whoseTurn = bot2.name;
			setBotAiming(bot2.aim, bot2.name);
			break;
		}

		switch (secondPlayer)
		{
		case '1':
			game.whoseNext = player.name;
			break;
		case '2':
			game.whoseNext = bot1.name;
			setBotAiming(bot1.aim, bot1.name);
			break;
		case '3':
			game.whoseNext = bot2.name;
			setBotAiming(bot2.aim, bot2.name);
			break;
		}
		players[0] = firstPlayer;
		players[1] = secondPlayer;
	}
	return players;
}

bool isLoadsave()
{
	std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\x1b[33myou have saved game.\n\x1b[35m"
		<< "\t\t\t\t\t\tDo you want to load save?\n"
		<< "\t\t\t\t\t\ty/n?\n\x1b[0m";

	char getAns;

	while (1)
	{
		getAns = _getch();
		if (getAns == 'y' || getAns == 'Y')
		{
			system("cls");
			return true;
		}


		if (getAns == 'n' || getAns == 'N')
		{
			system("cls");
			std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\x1b[33myou have saved game.\n\x1b[35m"
				<< "\t\t\t\t\t\tDo you want to delete previous save?\n"
				<< "\t\t\t\t\t\ty/n?\n\x1b[0m";
			break;
		}
	}

	while (1)
	{
		getAns = _getch();
		if (getAns == 'y' || getAns == 'Y')
		{
			deleteSave();
			showIfSaveDeleted();
			break;
		}
		if (getAns == 'n' || getAns == 'N')
		{
			break;
		}
	}
	system("cls");
	return false;
}

bool userPlaceShips()
{
	bool user;
	char getUserChoice;
	system("cls");
	std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\x1b[35mDo you want to place your ships yourself?\n"
		<< "\t\t\t\t\t\ty/n\t\x1b[0m";
	while (1)
	{
		getUserChoice = _getch();
		if (getUserChoice == 'y' || getUserChoice == 'n')
		{
			break;
		}
	}
	if (getUserChoice == 'y')
	{
		user = true;
	}
	else
	{
		user = false;
	}
	return user;
}

void showDisclaimer()
{
	std::string welcome = "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\x1b[34mWelcome to Sea battle game!\x1b[0m\n";
	std::cout << welcome;
	Sleep(1000);
	system("cls");
	PlaySound(TEXT("./sound/begin.wav"), NULL, SND_FILENAME | SND_ASYNC);
	for (int i = 20; ; i++)
	{
		if (i == 20)
		{
			welcome.insert(i, "\x1b[31m");
			std::cout << welcome;
			Sleep(50);
			system("cls");
			i += 4;
			continue;
		}
		if (i == welcome.size() - 10)
		{
			welcome.erase(welcome.size() - 10, 5);
			std::cout << welcome;
			Sleep(50);
			system("cls");
			break;
		}
		welcome.erase(i, 5);
		welcome.insert(i + 1, "\x1b[34m");
		std::cout << welcome;
		Sleep(50);
		system("cls");
	}

	for (int i = 25; i < welcome.size() - 6; )
	{
		welcome.erase(i, 1);
		std::cout << welcome;
		Sleep(50);
		system("cls");
	}
}

void getStart(char& start)
{
	std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\x1b[32mPress \"1\" to begin new game\n\t\t\t\t\t\tPress \"2\" to exit\n\x1b[0m";

	while (1)
	{
		start = _getch();
		if (start == '1' || start == '2')
		{
			break;
		}
	}
}

void declareTurn(std::string& whoseTurn)
{
	std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\x1b[32mnow it is " << whoseTurn << "'s turn!\x1b[0m";
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

void displayChoosedShip(int shipType, int shipLayout, Elements instance)
{
	if (shipType == 4 && !shipLayout)
	{
		std::cout << "choosed ship:   " << instance.verticalBattleship;
	}
	else if (shipType == 4 && shipLayout)
	{
		std::cout << "choosed ship:   " << instance.horizontalBattleship;
	}
	else if (shipType == 3 && !shipLayout)
	{
		std::cout << "choosed ship:   " << instance.verticalCruiser;
	}
	else if (shipType == 3 && shipLayout)
	{
		std::cout << "choosed ship:   " << instance.horizontalCruiser;
	}
	else if (shipType == 2 && !shipLayout)
	{
		std::cout << "choosed ship:   " << instance.verticalDestroyer;
	}
	else if (shipType == 2 && shipLayout)
	{
		std::cout << "choosed ship:   " << instance.horizontalDestroyer;
	}
	else
	{
		std::cout << "choosed ship:   " << instance.submarine;
	}
}

void showIfHit(int shipLong, bool userTurn)
{
	if (userTurn)
	{
		std::string ship;
		switch (shipLong)
		{
		case 2:
			ship = "destroyer";
			break;
		case 3:
			ship = "cruiser";
			break;
		case 4:
			ship = "battleship";
			break;
		}
		std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\x1b[31mfire aboard our " << ship << "!\x1b[0m";
	}
	else
	{
		std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\x1b[31mtarget hit!\x1b[0m";
	}
}

void showDestroyed(int ship)
{
	switch (ship)
	{
	case 1:
		PlaySound(TEXT("./sound/drown.wav"), NULL, SND_FILENAME | SND_ASYNC);
		std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\x1b[32msubmarine destroyed\x1b[0m\n";
		Sleep(2500);
		break;
	case 2:
		PlaySound(TEXT("./sound/drown.wav"), NULL, SND_FILENAME | SND_ASYNC);
		std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\x1b[33mdestroyer destroyed\x1b[0m\n";
		Sleep(2500);
		break;
	case 3:
		PlaySound(TEXT("./sound/drown.wav"), NULL, SND_FILENAME | SND_ASYNC);
		std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\x1b[34mcruiser destroyed\x1b[0m\n";
		Sleep(2500);
		break;
	case 4:
		PlaySound(TEXT("./sound/drown.wav"), NULL, SND_FILENAME | SND_ASYNC);
		std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\x1b[35mbattleship destroyed\x1b[0m\n";
		Sleep(2500);
		break;
	}
}

void userFireOnSquare(Elements instance, User& player, Bot& bot, Game& game)
{
	PlaySound(0, 0, 0);
	bool miss = false;

	while (!miss)
	{
		declareTurn(game.whoseTurn);
		Sleep(2000);
		system("cls");
		std::vector<int> coords = aim(player.enemyBoard);
		int row = coords[1];
		int col = coords[0];
		int square = returnSquare(row, col);

		if (bot.board[square] != ' ')
		{
			sightMovement(player.enemyBoard, square, instance);
			int hit = hitShip(square, bot.ships);
			hitShip(square, bot.board, player.enemyBoard, instance);
			destroyShip(checkShip(hit, bot.ships, false), player.enemyBoard, instance);
		}
		else
		{
			sightMovement(player.enemyBoard, square, instance);
			missed(square, bot.board, player.enemyBoard, instance);
			swapNames(game.whoseTurn, game.whoseNext);
			miss = true;
		}
		system("cls");
		if (!bot.ships.size()) break;
		showBoard(player.enemyBoard);
		awaitPause(game.partyOver, player);
		if (game.partyOver)
		{
			game.saveLoad = false;
			break;
		}
		system("cls");
	}


}

void setBotAiming(bool& botAiming, std::string botName)
{
	system("cls");
	char aim;
	std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\x1b[34mChoose " << botName << "'s aiming level:\n"
		<< "\t\t\t\t\t\t1 - random fire\n"
		<< "\t\t\t\t\t\t2 - aimed fire\x1b[0m\n";
	while (1)
	{
		aim = _getch();
		if (aim == '1' || aim == '2')
		{
			break;
		}
	}
	if (aim == '1')
	{
		botAiming = false;
	}
	else
	{
		botAiming = true;
	}
}

void showUserBoardBeforeGame(std::string& board)
{
	showBoard(board);
	char enter;
	std::cout << "\n\n\t\t\t\t\t\t\x1b[33mPress Enter to start game\x1b[0m";
	while (1)
	{
		enter = _getch();
		if ((int)enter == 13)
		{
			break;
		}
	}
	system("cls");
}

void showBoard(std::string board)
{
	std::cout << board;
}

void sightMovement(std::string enemyBoard, int square, Elements instance)
{
	std::vector <int> coords = returnCoordinates(square);
	int col = coords[0];
	int row = coords[1];
	int horizontalMovement = randomizer(0, 1);
	switch (horizontalMovement)
	{
	case 0:
		for (int i = 0; i <= col; i++)
		{
			int square = returnSquare(i, row);
			char prevValue1 = enemyBoard[square];
			char prevValue2 = enemyBoard[square + 1];
			std::string prevValue = { prevValue1, prevValue2 };
			enemyBoard.replace(square, 2, instance.sight);
			system("cls");

			if (!i)
			{
				showBoard(enemyBoard);
				PlaySound(TEXT("./sound/aiming.wav"), NULL, SND_FILENAME | SND_ASYNC);
				Sleep(600);
				system("cls");
			}
			if (i == col)
			{
				showBoard(enemyBoard);
				Sleep(800);
				PlaySound(TEXT("./sound/launch_missile.wav"), NULL, SND_FILENAME);
				system("color 4F");
				Sleep(200);
				system("color 07");
				PlaySound(TEXT("./sound/explosion.wav"), NULL, SND_FILENAME | SND_ASYNC);
				enemyBoard.replace(square, 2, { (char)185, (char)204 });
				system("cls");
				showBoard(enemyBoard);
				Sleep(400);
			}
			else
			{
				showBoard(enemyBoard);
				PlaySound(TEXT("./sound/aiming.wav"), NULL, SND_FILENAME | SND_ASYNC);
				Sleep(80);
				enemyBoard.replace(square, 2, prevValue);
			}

		}
		break;

	case 1:
		for (int i = 0; i <= row; i++)
		{
			int square = returnSquare(col, i);
			char prevValue1 = enemyBoard[square];
			char prevValue2 = enemyBoard[square + 1];
			std::string prevValue = { prevValue1, prevValue2 };
			enemyBoard.replace(square, 2, instance.sight);
			system("cls");

			if (!i)
			{
				showBoard(enemyBoard);
				PlaySound(TEXT("./sound/aiming.wav"), NULL, SND_FILENAME | SND_ASYNC);
				Sleep(600);
				system("cls");
			}
			if (i == row)
			{
				showBoard(enemyBoard);
				Sleep(800);
				PlaySound(TEXT("./sound/launch_missile.wav"), NULL, SND_FILENAME);
				system("color 4F");
				Sleep(200);
				system("color 07");
				PlaySound(TEXT("./sound/explosion.wav"), NULL, SND_FILENAME | SND_ASYNC);
				enemyBoard.replace(square, 2, { (char)185, (char)204 });
				system("cls");
				showBoard(enemyBoard);
				Sleep(400);
			}
			else
			{
				showBoard(enemyBoard);
				PlaySound(TEXT("./sound/aiming.wav"), NULL, SND_FILENAME | SND_ASYNC);
				Sleep(80);
				enemyBoard.replace(square, 2, prevValue);
			}
		}
		break;
	}
}

void choosePlayers(char& firstPlayer, char& secondPlayer, std::string& username, std::string bot1name, std::string bot2name)
{
	if (!username.size())
	{
		std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\x1b[35menter your name\n\x1b[0m\n\t\t\t\t\t\t";
		std::getline(std::cin, username);
	}
	system("cls");
	std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\x1b[35mChoose first player: \n"
		<< "\t\t\t\t\t\t1 - " << username << "\n"
		<< "\t\t\t\t\t\t2 - " << bot1name << "\n"
		<< "\t\t\t\t\t\t3 - " << bot2name << "\x1b[0m\n";

	while (1)
	{
		firstPlayer = _getch();
		if (firstPlayer == '1' || firstPlayer == '2' || firstPlayer == '3')
		{
			break;
		}
	}
	system("cls");
	std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\x1b[35mChoose second player: \n";
	switch (firstPlayer)
	{
	case '1':
		std::cout << "\t\t\t\t\t\t2 - " << bot1name << "\n"
			<< "\t\t\t\t\t\t3 - " << bot2name << "\x1b[0m\n";
		while (1)
		{
			secondPlayer = _getch();
			if (secondPlayer == '2' || secondPlayer == '3')
			{
				break;
			}
		}
		break;
	case '2':
		std::cout << "\t\t\t\t\t\t1 - " << username << "\n"
			<< "\t\t\t\t\t\t3 - " << bot2name << "\x1b[0m\n";
		while (1)
		{
			secondPlayer = _getch();
			if (secondPlayer == '1' || secondPlayer == '3')
			{
				break;
			}
		}
		break;
	case '3':
		std::cout << "\t\t\t\t\t\t1 - " << username << "\n"
			<< "\t\t\t\t\t\t2 - " << bot1name << "\x1b[0m\n";
		while (1)
		{
			secondPlayer = _getch();
			if (secondPlayer == '1' || secondPlayer == '2')
			{
				break;
			}
		}
		break;
	}

}

void awaitPause(bool& partyOver, User& player)
{
	char isPause;
	std::cout << "\x1b[32m press P to pause or press Enter to continue\n\x1b[0m";
	while (1)
	{
		isPause = _getch();
		if (isPause == 'p' || (int)isPause == 13 || isPause == 'P')
		{
			break;
		}
	}
	if (isPause == 'p' || isPause == 'P')
	{
		pause(partyOver, player);
	}
}

void pause(bool& partyOver, User& player)
{
	system("cls");
	char isContinue;
	std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\x1b[32m Pause Mode...\n\n\n\t\t\t\t\t\t\x1b[31mPress 1 to continue\n\t\t\t\t\t\tPress 2 to exit\n\x1b[0m";
	while (1)
	{
		isContinue = _getch();
		if (isContinue == '1' || isContinue == '2')
		{
			break;
		}
	}
	if (isContinue == '2')
	{
		partyOver = true;
		system("cls");
		std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\x1b[32m Do you want to save your game?\n\n\n\t\t\t\t\t\t\x1b[31mPress 1 to save\n\t\t\t\t\t\tPress 2 to exit without saving\n\x1b[0m";

		char saveGame;
		while (1)
		{
			saveGame = _getch();
			if (saveGame == '1' || saveGame == '2')
			{
				break;
			}
		}
		if (saveGame == '1')
		{
			player.saveGame = true;
		}

	}
}

void endParty(std::string& whoseTurn, std::string userName)
{
	system("cls");

	std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\x1b[33m" << whoseTurn << " wins!!!\x1b[0m\n";
	Sleep(1000);
	if (whoseTurn == userName)
	{
		PlaySound(TEXT("./sound/applause.wav"), NULL, SND_FILENAME | SND_ASYNC);
	}
	else
	{
		PlaySound(TEXT("./sound/sad.wav"), NULL, SND_FILENAME | SND_ASYNC);
	}


	Sleep(5000);
	system("cls");
}

void showIfSaved()
{
	system("cls");
	std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\x1b[32mGame saved!\n\x1b[0m\n";
	Sleep(2000);
	system("cls");
}

void showIfSaveDeleted()
{
	system("cls");
	std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\x1b[32mSave deleted!\n\x1b[0m\n";
	Sleep(2000);
	system("cls");
}