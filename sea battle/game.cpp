#include "game.h"

void clearShips(std::vector<int>& ships)
{
	for (int i = 0; i < 4; i++)
	{
		ships[i] = 0;
	}
}

void declareTurn(std::string& whoseTurn)
{		
	std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\x1b[32mnow it is " << whoseTurn << "'s turn!\x1b[0m";	
}

void swapNames(std::string& whoseTurn, std::string& whoseNext)
{
		std::string temp;
		temp = whoseTurn;
		whoseTurn = whoseNext;
		whoseNext = temp;
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

void displayChoosedShip(int shipType, int shipLayout)
{
	if (shipType == 4 && !shipLayout)
	{
		std::cout << "choosed ship:   " << verticalBattleship;
	}
	else if (shipType == 4 && shipLayout)
	{
		std::cout << "choosed ship:   " << horizontalBattleship;
	}
	else if (shipType == 3 && !shipLayout)
	{
		std::cout << "choosed ship:   " << verticalCruiser;
	}
	else if (shipType == 3 && shipLayout)
	{
		std::cout << "choosed ship:   " << horizontalCruiser;
	}
	else if (shipType == 2 && !shipLayout)
	{
		std::cout << "choosed ship:   " << verticalDestroyer;
	}
	else if (shipType == 2 && shipLayout)
	{
		std::cout << "choosed ship:   " << horizontalDestroyer;
	}
	else
	{
		std::cout << "choosed ship:   " << submarine;
	}
}

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

int hitShip(int square, std::vector<std::vector<int>> &ships)
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
		params.push_back (ships[ship][0]);
		params.push_back (ships[ship][1]);
		params.push_back (count);
		
		ships.erase(ships.begin() + ship);
	}
	else
	{
		system("cls");
		Sleep(500);
		PlaySound(TEXT("./sound/alarm.wav"), NULL, SND_FILENAME | SND_ASYNC);
		showIfHit(ships[ship].size() - 2, userTurn);
		Sleep(1500);
	}
	return params;
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

bool destroyShip(std::vector<int> params, std::string &enemyBoard)
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
				enemyBoard.replace(frontSquare, 2, miss);
			}
			catch (int)
			{

			}
			
			try
			{
				if (shipLong + col == 10) throw - 1;
				int backSquare = returnSquare(row, shipLong + col);
				enemyBoard.replace(backSquare, 2, miss);
			}
			catch (int)
			{

			}
			
			try
			{
				if (!row) throw - 1;
				if (i == -1 && !col) throw - 1;
				if (i > 0 && col == 9) throw - 1;
				int upperSquare = returnSquare(row - 1, col + i);
				enemyBoard.replace(upperSquare, 2, miss);
			}
			catch (int)
			{

			}
			try
			{
				if (row == 9) throw - 1;
				if (i == -1 && !col) throw - 1;
				if (i > 0 && col == 9) throw - 1;
				int lowerSquare = returnSquare(row + 1, col + i);
				enemyBoard.replace(lowerSquare, 2, miss);
			}
			catch (int)
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
				int frontSquare = returnSquare(row -1, col);
				enemyBoard.replace(frontSquare, 2, miss);
			}
			catch (std::exception& )
			{

			}

			try
			{
				int backSquare = returnSquare(row + shipLong, col);
				enemyBoard.replace(backSquare, 2, miss);
			}
			catch (std::exception&)
			{

			}

			try
			{
				if (!col) throw - 1;
				int leftSquare = returnSquare(row + i, col - 1);
				enemyBoard.replace(leftSquare, 2, miss);
			}
			catch (int)
			{

			}
			catch (std::exception&)
			{

			}
			try
			{
				if (col  == 9) throw - 1;
				int rightSquare = returnSquare(row + i, col + 1);
				enemyBoard.replace(rightSquare, 2, miss);
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

void sightMovement(std::string enemyBoard, int square)
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
			enemyBoard.replace(square, 2, sight);
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
			enemyBoard.replace(square, 2, sight);
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

void hitShip(int square, std::string &board, std::string &enemyBoard)
{
	board.replace(square, 2, destroyedShipElement);
	enemyBoard.replace(square, 2, destroyedShipElement);
}

void missed(int square, std::string& board, std::string& enemyBoard)
{
	board.replace(square, 2, miss);
	enemyBoard.replace(square, 2, miss);
}

bool isCorrectAim(int row, int col, std::string board)
{
	int checkSquare = returnSquare(row, col);
	try
	{
		if (board.at(checkSquare) == ' ')
		{
			return true;
		}
	}
	catch (std::exception& )
	{
		return false;
	}
	
	return false;
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
		if(isCorrectAim(coordinates[1], coordinates[0], board))
		{
			PlaySound(TEXT("./sound/button.wav"), NULL, SND_FILENAME | SND_ASYNC);
			break;
		}
		Beep(247, 500);
	}
	PlaySound(TEXT("./sound/morze.wav"), NULL, SND_FILENAME);
	return coordinates;
}

void userFireOnSquare(bool& partyOver, bool& userSaveGame, bool& saveload, std::vector<std::vector <int> >&compShips, std::string &computerBoard, std::string &enemyBoard, std::string& whoseTurn, std::string& whoseNext)
{
	PlaySound(0, 0, 0);
	    bool miss = false;

		while (!miss)
		{
			declareTurn(whoseTurn);
			Sleep(2000);
			system("cls");
			std::vector<int> coords = aim(enemyBoard);
			int row = coords[1];
			int col = coords[0];
			int square = returnSquare(row, col);

			if (computerBoard[square] != ' ')
			{
				sightMovement(enemyBoard, square);
				int hit = hitShip(square, compShips);
				hitShip(square, computerBoard, enemyBoard);
				destroyShip(checkShip(hit, compShips, false), enemyBoard);
			}
			else
			{
				sightMovement(enemyBoard, square);
				missed(square, computerBoard, enemyBoard);
				swapNames(whoseTurn, whoseNext);
				miss = true;
			}
			system("cls");
			if (!compShips.size()) break;
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

void endParty(std::string& whoseTurn, std::string userName)
{
	system("cls");

		std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\x1b[33m"<< whoseTurn <<" wins!!!\x1b[0m\n";
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

std::vector<char> menu(bool& bot1Aiming, bool& bot2Aiming, bool &isGame, std::string bot1name, std::string bot2name, std::string& userName, std::string& whoseTurn, std::string& whoseNext)
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
		isGame = false;
		system("cls");
		return players;
	}
	else
	{
		system("cls");
		choosePlayers(firstPlayer, secondPlayer, userName, bot1name, bot2name);
		switch (firstPlayer)
		{
		case '1':
			whoseTurn = userName;
			break;
		case '2':
			whoseTurn = bot1name;
			setBotAiming(bot1Aiming, bot1name);
			break;
		case '3':
			whoseTurn = bot2name;
			setBotAiming(bot2Aiming, bot2name);
			break;
		}

		switch (secondPlayer)
		{
		case '1':
			whoseNext = userName;
			break;
		case '2':
			whoseNext = bot1name;
			setBotAiming(bot1Aiming, bot1name);
			break;
		case '3':
			whoseNext = bot2name;
			setBotAiming(bot2Aiming, bot2name);
			break;
		}
		players[0] = firstPlayer;
		players[1] = secondPlayer;
	}
	return players;
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

void pause(bool &partyOver, bool& userSaveGame)
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
			userSaveGame = true;
		}
		
	}
}

void awaitPause(bool& partyOver, bool& userSaveGame)
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
		pause(partyOver, userSaveGame);
	}
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

