#pragma once
#include <string>
#include <vector>

struct Elements
{
	std::string verticalBattleship = "#\n\t\t#\n\t\t#\n\t\t#\n";
	std::string horizontalBattleship = "####\n";
	std::string verticalCruiser = "#\n\t\t#\n\t\t#\n";
	std::string horizontalCruiser = "###\n";
	std::string verticalDestroyer = "#\n\t\t#\n";
	std::string horizontalDestroyer = "##\n";
	std::string submarine = "#\n";
	std::string shipElement = { (char)178, (char)178 };
	std::string destroyedShipElement = { (char)176, (char)176 };
	std::string miss = { (char)126, (char)126 };
	std::string sight = "[]";
};

struct User
{
	bool isPlay = false;
	bool saveGame = false;
	std::string board;	
	std::vector<std::vector <int> > ships;
	std::string enemyBoard;
	std::string name;
};

struct Bot :User
{
	Bot(std::string name)
	{
		this->name = name;
	}
	void clearCoordsFinishing()
	{
		this->coordsFinishing = { -1, 0, 0, 0 };
	}

	std::vector<int> coordsFinishing = { -1, 0, 0, 0 };
	bool aim = false;
};

struct Game
{
	std::vector <int> ships = { 0, 0, 0, 0 };
	bool isGame = true;
	bool partyOver = false;
	bool isSaved = false;
	bool saveLoad = false;
	std::vector <int> ship = {0, 0};
	std::vector<char> players;
	std::string whoseTurn;
	std::string whoseNext;
};

