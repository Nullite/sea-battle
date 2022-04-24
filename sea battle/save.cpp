#include "save.h"


void saveStrings(User player, Bot bot1, Bot bot2, Game game)
{
	
	std::ofstream save("saveStr.sb");
	if (player.board.size())
	{
		save << player.board << '\n';
	}
	else
	{
		save << "\n\n";
	}
	
	if (bot1.board.size())
	{
		save << bot1.board << '\n';
	}
	else
	{
		save << "\n\n";
	}
	
	if (bot2.board.size())
	{
		save << bot2.board << '\n';
	}
	else
	{
		save << "\n\n";
	}

	if (player.enemyBoard.size())
	{
		save << player.enemyBoard << '\n';
	}
	else
	{
		save << "\n\n";
	}

	if (bot1.enemyBoard.size())
	{
		save << bot1.enemyBoard << '\n';
	}
	else
	{
		save << "\n\n";
	}

	if (bot2.enemyBoard.size())
	{
		save << bot2.enemyBoard << '\n';
	}
	else
	{
		save << "\n\n";
	}
	
	save << player.name << '\n';
	save << game.whoseTurn << '\n';
	save << game.whoseNext << '\n';

	save.close();
}

void getStrings(User& player, Bot& bot1, Bot& bot2, Game& game)
{
	std::ifstream get("saveStr.sb");

	std::string temp;
	getline(get, temp);

	if (temp.size())
	{
		player.board += temp;
		for (int i = 0; i < 21; i++)
		{
			getline(get, temp);
			player.board += '\n';
			player.board += temp;
		}
		player.board += '\n';
	}

	getline(get, temp);
	getline(get, temp);

	if (temp.size())
	{
		bot1.board += temp;
		for (int i = 0; i < 21; i++)
		{
			getline(get, temp);
			bot1.board += '\n';
			bot1.board += temp;
		}
		bot1.board += '\n';
	}

	getline(get, temp);
	getline(get, temp);

	if (temp.size())
	{
		bot2.board += temp;
		for (int i = 0; i < 21; i++)
		{
			getline(get, temp);
			bot2.board += '\n';
			bot2.board += temp;
		}
		bot2.board += '\n';
	}

	getline(get, temp);
	getline(get, temp);

	if (temp.size())
	{
		player.enemyBoard += temp;
		for (int i = 0; i < 21; i++)
		{
			getline(get, temp);
			player.enemyBoard += '\n';
			player.enemyBoard += temp;
		}
		player.enemyBoard += '\n';
	}

	getline(get, temp);
	getline(get, temp);

	if (temp.size())
	{
		bot1.enemyBoard += temp;
		for (int i = 0; i < 21; i++)
		{
			getline(get, temp);
			bot1.enemyBoard += '\n';
			bot1.enemyBoard += temp;
		}
		bot1.enemyBoard += '\n';
	}

	getline(get, temp);
	getline(get, temp);

	if (temp.size())
	{
		bot2.enemyBoard += temp;
		for (int i = 0; i < 21; i++)
		{
			getline(get, temp);
			bot2.enemyBoard += '\n';
			bot2.enemyBoard += temp;
		}
		bot2.enemyBoard += '\n';
	}

	getline(get, temp);
	getline(get, player.name);
	getline(get, game.whoseTurn);
	getline(get, game.whoseNext);

	get.close();
}

void saveVec(User player, Bot bot1, Bot bot2) {
	std::ofstream save("saveVec.sb");
	if (player.ships.size())
	{
		save << player.ships.size() << '\n';
		for (int i = 0; i < player.ships.size(); i++)
		{
			save << player.ships[i].size();
			for (int j = 0; j < player.ships[i].size(); j++)
			{
				save << player.ships[i][j] << '\n';
			}
		}
	}
	else
	{
		save << '\n';
	}
	
	if (bot1.ships.size())
	{
		save << bot1.ships.size() << '\n';
		for (int i = 0; i < bot1.ships.size(); i++)
		{
			save << bot1.ships[i].size();
			for (int j = 0; j < bot1.ships[i].size(); j++)
			{
				save << bot1.ships[i][j] << '\n';
			}
		}
	}
	else
	{
		save << '\n';
	}

	if (bot2.ships.size())
	{
		save << bot2.ships.size() << '\n';
		for (int i = 0; i < bot2.ships.size(); i++)
		{
			save << bot2.ships[i].size();
			for (int j = 0; j < bot2.ships[i].size(); j++)
			{
				save << bot2.ships[i][j] << '\n';
			}
		}
	}
	else
	{
		save << '\n';
	}

	for (int i = 0; i < bot1.coordsFinishing.size(); i++)
	{
		save << bot1.coordsFinishing[i] << '\n';
	}

	for (int i = 0; i < bot2.coordsFinishing.size(); i++)
	{
		save << bot2.coordsFinishing[i] << '\n';
	}
	
	save.close();
}

void getVec(User& player, Bot& bot1, Bot& bot2)
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
				player.ships.push_back(tempVec);
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
				bot1.ships.push_back(tempVec);
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
				bot2.ships.push_back(tempVec);
				tempVec.erase(tempVec.begin(), tempVec.end());
			}
		}
	}
	

	for (int i = 0; i < 4; i++)
	{
		getline(save, temp);
		bot1.coordsFinishing[i] = (stoi(temp));
	}

	
	for (int i = 0; i < 4; i++)
	{
		getline(save, temp);
		bot2.coordsFinishing[i] = (stoi(temp));
	}
	save.close();
}

void saveBool(User player, Bot bot1, Bot bot2, Game game)
{
	std::ofstream save("saveBool.sb", std::ios_base::out);

	save << player.isPlay;
	save << bot1.isPlay;
	save << bot2.isPlay;
	save << bot1.aim;
	save << bot2.aim;
	save << game.players[0];
	save << game.players[1];
	save.close();
}

void getBool(User& player, Bot& bot1, Bot& bot2, Game& game)
{
	std::ifstream save("saveBool.sb");
	char ch;
	char temp;
	save.get(temp);
	player.isPlay = (int)temp - 48;
	save.get(temp);
	bot1.isPlay = (int)temp - 48;
	save.get(temp);
	bot2.isPlay = (int)temp - 48;
	save.get(temp);
	bot1.aim = (int)temp - 48;
	save.get(temp);
	bot2.aim = (int)temp - 48;
	save.get(ch);
	game.players.push_back(ch);
	save.get(ch);
	game.players.push_back(ch);
	save.close();	
}

void savemgmt()
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

void globalSave(User& player, Bot bot1, Bot bot2,  Game& game)
{
	saveStrings(player, bot1, bot2, game);
	saveVec(player, bot1, bot2);
	saveBool(player, bot1, bot2, game);
	savemgmt();
	player.saveGame = false;
	game.saveLoad = false;
	showIfSaved();
}

void globalGet(User& player, Bot& bot1, Bot& bot2, Game& game)
{
	getStrings(player, bot1, bot2, game);
	getVec(player, bot1, bot2);
	getBool(player, bot1, bot2, game);
}