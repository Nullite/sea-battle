#include "save.h"


void saveStrings(std::string userBoard, std::string comp1Board, std::string comp2Board, std::string userEnemyBoard, std::string bot1EnemyBoard, std::string bot2EnemyBoard, std::string userName, std::string whoseTurn, std::string whoseNext)
{
	
	std::ofstream save("saveStr.sb");
	if (userBoard.size())
	{
		save << userBoard << '\n';
	}
	else
	{
		save << "\n\n";
	}
	
	if (comp1Board.size())
	{
		save << comp1Board << '\n';
	}
	else
	{
		save << "\n\n";
	}
	
	if (comp2Board.size())
	{
		save << comp2Board << '\n';
	}
	else
	{
		save << "\n\n";
	}

	if (userEnemyBoard.size())
	{
		save << userEnemyBoard << '\n';
	}
	else
	{
		save << "\n\n";
	}

	if (bot1EnemyBoard.size())
	{
		save << bot1EnemyBoard << '\n';
	}
	else
	{
		save << "\n\n";
	}

	if (bot2EnemyBoard.size())
	{
		save << bot2EnemyBoard << '\n';
	}
	else
	{
		save << "\n\n";
	}
	
	save << userName << '\n';
	save << whoseTurn << '\n';
	save << whoseNext << '\n';

	save.close();
}

void getStrings(std::string& userBoard, std::string& comp1Board, std::string& comp2Board, std::string& userEnemyBoard, std::string& bot1EnemyBoard, std::string& bot2EnemyBoard, std::string& userName, std::string& whoseTurn, std::string& whoseNext)
{
	std::ifstream get("saveStr.sb");

	std::string temp;
	getline(get, temp);

	if (temp.size())
	{
		userBoard += temp;
		for (int i = 0; i < 21; i++)
		{
			getline(get, temp);
			userBoard += '\n';
			userBoard += temp;
		}
		userBoard += '\n';
	}

	getline(get, temp);
	getline(get, temp);

	if (temp.size())
	{
		comp1Board += temp;
		for (int i = 0; i < 21; i++)
		{
			getline(get, temp);
			comp1Board += '\n';
			comp1Board += temp;
		}
		comp1Board += '\n';
	}

	getline(get, temp);
	getline(get, temp);

	if (temp.size())
	{
		comp2Board += temp;
		for (int i = 0; i < 21; i++)
		{
			getline(get, temp);
			comp2Board += '\n';
			comp2Board += temp;
		}
		comp2Board += '\n';
	}

	getline(get, temp);
	getline(get, temp);

	if (temp.size())
	{
		userEnemyBoard += temp;
		for (int i = 0; i < 21; i++)
		{
			getline(get, temp);
			userEnemyBoard += '\n';
			userEnemyBoard += temp;
		}
		userEnemyBoard += '\n';
	}

	getline(get, temp);
	getline(get, temp);

	if (temp.size())
	{
		bot1EnemyBoard += temp;
		for (int i = 0; i < 21; i++)
		{
			getline(get, temp);
			bot1EnemyBoard += '\n';
			bot1EnemyBoard += temp;
		}
		bot1EnemyBoard += '\n';
	}

	getline(get, temp);
	getline(get, temp);

	if (temp.size())
	{
		bot2EnemyBoard += temp;
		for (int i = 0; i < 21; i++)
		{
			getline(get, temp);
			bot2EnemyBoard += '\n';
			bot2EnemyBoard += temp;
		}
		bot2EnemyBoard += '\n';
	}

	getline(get, temp);
	getline(get, userName);
	getline(get, whoseTurn);
	getline(get, whoseNext);

	get.close();
}

void saveVec(std::vector<std::vector<int>> userShips, std::vector<std::vector<int>> comp1Ships, std::vector<std::vector <int> > comp2Ships, std::vector<int> coordsFinishingForBot1, std::vector<int> coordsFinishingForBot2)
{
	std::ofstream save("saveVec.sb");
	if (userShips.size())
	{
		save << userShips.size() << '\n';
		for (int i = 0; i < userShips.size(); i++)
		{
			save << userShips[i].size();
			for (int j = 0; j < userShips[i].size(); j++)
			{
				save << userShips[i][j] << '\n';
			}
		}
	}
	else
	{
		save << '\n';
	}
	
	if (comp1Ships.size())
	{
		save << comp1Ships.size() << '\n';
		for (int i = 0; i < comp1Ships.size(); i++)
		{
			save << comp1Ships[i].size();
			for (int j = 0; j < comp1Ships[i].size(); j++)
			{
				save << comp1Ships[i][j] << '\n';
			}
		}
	}
	else
	{
		save << '\n';
	}

	if (comp2Ships.size())
	{
		save << comp2Ships.size() << '\n';
		for (int i = 0; i < comp2Ships.size(); i++)
		{
			save << comp2Ships[i].size();
			for (int j = 0; j < comp2Ships[i].size(); j++)
			{
				save << comp2Ships[i][j] << '\n';
			}
		}
	}
	else
	{
		save << '\n';
	}

	for (int i = 0; i < coordsFinishingForBot1.size(); i++)
	{
		save << coordsFinishingForBot1[i] << '\n';
	}

	for (int i = 0; i < coordsFinishingForBot2.size(); i++)
	{
		save << coordsFinishingForBot2[i] << '\n';
	}
	
	save.close();
}

void getVec(std::vector<std::vector<int>>& userShips, std::vector<std::vector<int>>& comp1Ships, std::vector<std::vector <int>>& comp2Ships, std::vector<int>& coordsFinishingForBot1, std::vector<int> &coordsFinishingForBot2)
{
	std::string temp;
	std::ifstream save("saveVec.sb");
	getline(save, temp);

	if (temp.size())
	{
		int size = stoi(temp);
		int tempSize;

		for (int i = 0; i < size; i++)
		{
			std::vector<int> tempVec;
			getline(save, temp);
			tempSize = (int)temp[0] - 48;
			tempVec.push_back((int)temp[1] - 48);
			{
				for (int j = 0; j < tempSize - 1; j++)
				{
					getline(save, temp);
					tempVec.push_back(stoi(temp));
				}
				userShips.push_back(tempVec);
				tempVec.erase(tempVec.begin(), tempVec.end());
			}
		}
	}
	
	getline(save, temp);

	if (temp.size())
	{
		int size = stoi(temp);
		int tempSize;

		for (int i = 0; i < size; i++)
		{
			std::vector<int> tempVec;
			getline(save, temp);
			tempSize = (int)temp[0] - 48;
			tempVec.push_back((int)temp[1] - 48);
			{
				for (int j = 0; j < tempSize - 1; j++)
				{
					getline(save, temp);
					tempVec.push_back(stoi(temp));
				}
				comp1Ships.push_back(tempVec);
				tempVec.erase(tempVec.begin(), tempVec.end());
			}
		}
	}
	
	getline(save, temp);

	if (temp.size())
	{
		int size = stoi(temp);
		int tempSize;

		for (int i = 0; i < size; i++)
		{
			std::vector<int> tempVec;
			getline(save, temp);
			tempSize = (int)temp[0] - 48;
			tempVec.push_back((int)temp[1] - 48);
			{
				for (int j = 0; j < tempSize - 1; j++)
				{
					getline(save, temp);
					tempVec.push_back(stoi(temp));
				}
				comp2Ships.push_back(tempVec);
				tempVec.erase(tempVec.begin(), tempVec.end());
			}
		}
	}
	

	for (int i = 0; i < 4; i++)
	{
		getline(save, temp);
		coordsFinishingForBot1[i] = (stoi(temp));
	}

	
	for (int i = 0; i < 4; i++)
	{
		getline(save, temp);
		coordsFinishingForBot2[i] = (stoi(temp));
	}
	save.close();
}

void saveBool(bool isUserPlay, bool bot1Aiming, bool bot2Aiming, std::vector<char> players)
{
	std::ofstream clear_file("saveBool.sb", std::ios_base::out);
	clear_file.close();
	std::ofstream save("saveBool.sb");

	save << isUserPlay;
	save << bot1Aiming;
	save << bot2Aiming;
	save << players[0];
	save << players[1];
	save.close();
}

void getBool(bool& isUserPlay, bool& bot1Aiming, bool& bot2Aiming, std::vector<char>& players)
{
	std::ifstream save("saveBool.sb");
	char ch;
	char temp;
	save.get(temp);
	isUserPlay = (int)temp - 48;
	save.get(temp);
	bot1Aiming = (int)temp - 48;
	save.get(temp);
	bot2Aiming = (int)temp - 48;
	save.get(ch);
	players.push_back(ch);
	save.get(ch);
	players.push_back(ch);
	save.close();	
}

void savemgmt(bool isSaved)
{
	std::ofstream save("savemgmt.sb");
	save << 1;
	save.close();
}

void preloadSave(bool& isSaved)
{
	std::ifstream save("savemgmt.sb");
	char temp;
	save.get(temp);
	isSaved = (int)temp - 48;
	save.close();
}

void deleteSave()
{
	std::ofstream save("savemgmt.sb");
	save << 0;
	save.close();
}