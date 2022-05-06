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
	struct Tactic
	{
		std::vector<int> enemyShips = { 1, 2, 3, 4 };
		std::vector<int> squearsIfBattleship = { 126, 146, 243, 263, 345, 365, 385, 452, 472, 492, 574, 594, 691, 711, 793, 813, 833, 900, 920, 940, 1022, 1042, 1139, 1159 };
		std::vector<int> squearsIfCruiser = { 141, 161, 228, 248, 268, 355, 375, 462, 482, 569, 589, 609, 676, 696, 716, 803, 823, 910, 930, 1017, 1037, 1052, 1144, 1169 };
		std::vector<int> squearsIfDestroyer = { 116, 136, 156, 233, 253, 350, 370, 467, 487, 584, 604, 681, 701, 798, 818, 915, 935, 1032, 1057, 1129, 1149 };
		std::vector<int> remainingSquears = { 121, 131, 151, 238, 258, 273, 340, 360, 380, 457, 477, 497, 564, 579, 599, 686, 706, 721, 788, 808, 828, 905, 925, 945, 1012, 1027, 1047, 1124, 1134, 1154, 1164 };
	} tact;
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

