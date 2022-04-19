#include "board.h"

int main()
{
	showDisclaimer();
	preloadSave(isSaved);
	
	if (isSaved)
	{
		saveLoad = isLoadsave();
		if (saveLoad)
		{
			getStrings(userBoard, comp1Board, comp2Board, userEnemyBoard, comp1EnemyBoard, comp2EnemyBoard, userName, whoseTurn, whoseNext);
			getVec(userShips, comp1Ships, comp2Ships, coordsFinishingForBot1, coordsFinishingForBot2);
			getBool(isUserPlay, bot1Aiming, bot2Aiming, players);
		}
	}
	while (isGame)
	{
		partyOver = false;
		if (!saveLoad)
		{
			players = menu(bot1Aiming, bot2Aiming, isGame, bot1name, bot2name, userName, whoseTurn, whoseNext);
		}
		
		if (players[0] == '0')
		{
			system("cls");
			break;
		}

		if (players[0] == '1')
		{
			if (!saveLoad)
			{
				isUserPlay = true;
				userBoard = field();
				userEnemyBoard = field();

				if (userPlaceShips())
				{
					system("cls");
					userShips = fillBoard(userBoard);
				}
				else
				{
					system("cls");
					userShips = botFillBoard(userBoard);
				}
				showUserBoardBeforeGame(userBoard);
			}
			

			if (players[1] == '2')
			{
				if (!saveLoad)
				{
					comp1Board = field();
					comp1EnemyBoard = field();
					comp1Ships = botFillBoard(comp1Board);
				}
				
				while (1)
				{
					if (whoseTurn == userName)
					{
						userFireOnSquare(partyOver, userSaveGame, saveLoad, comp1Ships, comp1Board, userEnemyBoard, whoseTurn, whoseNext);
						if (!comp1Ships.size()) break;
						if (partyOver && !userSaveGame) break;
						if (partyOver && userSaveGame)
						{
							saveStrings(userBoard, comp1Board, comp2Board, userEnemyBoard, comp1EnemyBoard, comp2EnemyBoard, userName, whoseTurn, whoseNext);
							saveVec(userShips, comp1Ships, comp2Ships, coordsFinishingForBot1, coordsFinishingForBot2);
							saveBool(isUserPlay, bot1Aiming, bot2Aiming, players);
							savemgmt(isSaved);
							userSaveGame = false;
							saveLoad = false;
							showIfSaved();
							break;
						}
					}

					if (whoseTurn == bot1name)
					{
						botFireOnSquare(bot1Aiming, userSaveGame, saveLoad, isUserPlay, partyOver, userShips, comp1Ships, userBoard, comp1EnemyBoard, coordsFinishingForBot1, whoseTurn, whoseNext);
						if (!userShips.size()) break;
						if (partyOver && !userSaveGame) break;
						if (partyOver && userSaveGame)
						{
							saveStrings(userBoard, comp1Board, comp2Board, userEnemyBoard, comp1EnemyBoard, comp2EnemyBoard, userName, whoseTurn, whoseNext);
							saveVec(userShips, comp1Ships, comp2Ships, coordsFinishingForBot1, coordsFinishingForBot2);
							saveBool(isUserPlay, bot1Aiming, bot2Aiming, players);
							savemgmt(isSaved);
							userSaveGame = false;
							saveLoad = false;
							showIfSaved();
							break;
						}
					}
				}
			}
			else
			{
				if (!saveLoad)
				{
					comp2Board = field();
					comp2EnemyBoard = field();
					comp2Ships = botFillBoard(comp2Board);
				}
				
				while (1)
				{
					if (whoseTurn == userName)
					{
						userFireOnSquare(partyOver, userSaveGame, saveLoad, comp2Ships, comp2Board, userEnemyBoard, whoseTurn, whoseNext);
						if (!comp2Ships.size()) break;
						if (partyOver && !userSaveGame) break;
						if (partyOver && userSaveGame)
						{
							saveStrings(userBoard, comp1Board, comp2Board, userEnemyBoard, comp1EnemyBoard, comp2EnemyBoard, userName, whoseTurn, whoseNext);
							saveVec(userShips, comp1Ships, comp2Ships, coordsFinishingForBot1, coordsFinishingForBot2);
							saveBool(isUserPlay, bot1Aiming, bot2Aiming, players);
							savemgmt(isSaved);
							userSaveGame = false;
							saveLoad = false;
							showIfSaved();
							break;
						}
					}

					if (whoseTurn == bot2name)
					{
						botFireOnSquare(bot2Aiming, userSaveGame, saveLoad, isUserPlay, partyOver, userShips, comp2Ships, userBoard, comp2EnemyBoard, coordsFinishingForBot2, whoseTurn, whoseNext);
						if (!userShips.size()) break;
						if (partyOver && !userSaveGame) break;
						if (partyOver && userSaveGame)
						{
							saveStrings(userBoard, comp1Board, comp2Board, userEnemyBoard, comp1EnemyBoard, comp2EnemyBoard, userName, whoseTurn, whoseNext);
							saveVec(userShips, comp1Ships, comp2Ships, coordsFinishingForBot1, coordsFinishingForBot2);
							saveBool(isUserPlay, bot1Aiming, bot2Aiming, players);
							savemgmt(isSaved);
							userSaveGame = false;
							saveLoad = false;
							showIfSaved();
							break;
						}
					}
					
				}
			}
		}
		else if (players[0] == '2')
		{
			if (!saveLoad)
			{
				comp1Board = field();
				comp1EnemyBoard = field();
				comp1Ships = botFillBoard(comp1Board);
			}
			
			if (players[1] == '1')
			{
				if (!saveLoad)
				{
					isUserPlay = true;
					userBoard = field();
					userEnemyBoard = field();

					if (userPlaceShips())
					{
						system("cls");
						userShips = fillBoard(userBoard);
					}
					else
					{
						system("cls");
						userShips = botFillBoard(userBoard);
					}
				}
				showUserBoardBeforeGame(userBoard);

				while (1)
				{
					if (whoseTurn == bot1name)
					{
						botFireOnSquare(bot1Aiming, userSaveGame, saveLoad, isUserPlay, partyOver, userShips, comp1Ships, userBoard, comp1EnemyBoard, coordsFinishingForBot1, whoseTurn, whoseNext);
						if (!userShips.size()) break;
						if (partyOver && !userSaveGame) break;
						if (partyOver && userSaveGame)
						{
							saveStrings(userBoard, comp1Board, comp2Board, userEnemyBoard, comp1EnemyBoard, comp2EnemyBoard, userName, whoseTurn, whoseNext);
							saveVec(userShips, comp1Ships, comp2Ships, coordsFinishingForBot1, coordsFinishingForBot2);
							saveBool(isUserPlay, bot1Aiming, bot2Aiming, players);
							savemgmt(isSaved);
							userSaveGame = false;
							saveLoad = false;
							showIfSaved();
							break;
						}
					}
					if (whoseTurn == userName)
					{
						userFireOnSquare(partyOver, userSaveGame, saveLoad, comp1Ships, comp1Board, userEnemyBoard, whoseTurn, whoseNext);
						if (!comp1Ships.size()) break;
						if (partyOver && !userSaveGame) break;
						if (partyOver && userSaveGame)
						{
							saveStrings(userBoard, comp1Board, comp2Board, userEnemyBoard, comp1EnemyBoard, comp2EnemyBoard, userName, whoseTurn, whoseNext);
							saveVec(userShips, comp1Ships, comp2Ships, coordsFinishingForBot1, coordsFinishingForBot2);
							saveBool(isUserPlay, bot1Aiming, bot2Aiming, players);
							savemgmt(isSaved);
							userSaveGame = false;
							saveLoad = false;
							showIfSaved();
							break;
						}
					}
				}
			}
			else
			{
				if (!saveLoad)
				{
					isUserPlay = false;
					comp2Board = field();
					comp2EnemyBoard = field();
					comp2Ships = botFillBoard(comp2Board);
				}				
				system("cls");
				while (1)
				{
					if (whoseTurn == bot1name)
					{
						botFireOnSquare(bot1Aiming, userSaveGame, saveLoad, isUserPlay, partyOver, comp2Ships, comp1Ships, comp2Board, comp1EnemyBoard, coordsFinishingForBot1, whoseTurn, whoseNext);
						if (!comp2Ships.size()) break;
						if (partyOver && !userSaveGame) break;
						if (partyOver && userSaveGame)
						{
							saveStrings(userBoard, comp1Board, comp2Board, userEnemyBoard, comp1EnemyBoard, comp2EnemyBoard, userName, whoseTurn, whoseNext);
							saveVec(userShips, comp1Ships, comp2Ships, coordsFinishingForBot1, coordsFinishingForBot2);
							saveBool(isUserPlay, bot1Aiming, bot2Aiming, players);
							savemgmt(isSaved);
							userSaveGame = false;
							saveLoad = false;
							showIfSaved();
							break;
						}
					}

					if (whoseTurn == bot2name)
					{
						botFireOnSquare(bot2Aiming, userSaveGame, saveLoad, isUserPlay, partyOver, comp1Ships, comp2Ships, comp1Board, comp2EnemyBoard, coordsFinishingForBot2, whoseTurn, whoseNext);
						if (!comp1Ships.size()) break;
						if (partyOver && !userSaveGame) break;
						if (partyOver && userSaveGame)
						{
							saveStrings(userBoard, comp1Board, comp2Board, userEnemyBoard, comp1EnemyBoard, comp2EnemyBoard, userName, whoseTurn, whoseNext);
							saveVec(userShips, comp1Ships, comp2Ships, coordsFinishingForBot1, coordsFinishingForBot2);
							saveBool(isUserPlay, bot1Aiming, bot2Aiming, players);
							savemgmt(isSaved);
							userSaveGame = false;
							saveLoad = false;
							showIfSaved();
							break;
						}
					}
				}
			}
		}
		else
		{
		if (!saveLoad)
		{
			comp2Board = field();
			comp2EnemyBoard = field();
			comp2Ships = botFillBoard(comp2Board);
		}
			

			if (players[1] == '1')
			{
				if (!saveLoad)
				{
					isUserPlay = true;
					userBoard = field();
					userEnemyBoard = field();

					if (userPlaceShips())
					{
						system("cls");
						userShips = fillBoard(userBoard);
					}
					else
					{
						system("cls");
						userShips = botFillBoard(userBoard);
					}
				}
				showUserBoardBeforeGame(userBoard);

				while (1)
				{
					if (whoseTurn == bot2name)
					{
						botFireOnSquare(bot2Aiming, userSaveGame, saveLoad, isUserPlay, partyOver, userShips, comp2Ships, userBoard, comp2EnemyBoard, coordsFinishingForBot2, whoseTurn, whoseNext);
						if (!userShips.size()) break;
						if (partyOver && !userSaveGame) break;
						if (partyOver && userSaveGame)
						{
							saveStrings(userBoard, comp1Board, comp2Board, userEnemyBoard, comp1EnemyBoard, comp2EnemyBoard, userName, whoseTurn, whoseNext);
							saveVec(userShips, comp1Ships, comp2Ships, coordsFinishingForBot1, coordsFinishingForBot2);
							saveBool(isUserPlay, bot1Aiming, bot2Aiming, players);
							savemgmt(isSaved);
							userSaveGame = false;
							saveLoad = false;
							showIfSaved();
							break;
						}
					}
					if (whoseTurn == userName)
					{
						userFireOnSquare(partyOver, userSaveGame, saveLoad, comp2Ships, comp2Board, userEnemyBoard, whoseTurn, whoseNext);
						if (!comp2Ships.size()) break;
						if (partyOver && !userSaveGame) break;
						if (partyOver && userSaveGame)
						{
							saveStrings(userBoard, comp1Board, comp2Board, userEnemyBoard, comp1EnemyBoard, comp2EnemyBoard, userName, whoseTurn, whoseNext);
							saveVec(userShips, comp1Ships, comp2Ships, coordsFinishingForBot1, coordsFinishingForBot2);
							saveBool(isUserPlay, bot1Aiming, bot2Aiming, players);
							savemgmt(isSaved);
							userSaveGame = false;
							saveLoad = false;
							showIfSaved();
							break;
						}
					}
				}
			}

			else
			{
				if (!saveLoad)
				{
					isUserPlay = false;
					comp1Board = field();
					comp1EnemyBoard = field();
					comp1Ships = botFillBoard(comp1Board);
				}				
				system("cls");
				while (1)
				{
					if (whoseTurn == bot2name)
					{
						botFireOnSquare(bot2Aiming, userSaveGame, saveLoad, isUserPlay, partyOver, comp1Ships, comp2Ships, comp1Board, comp2EnemyBoard, coordsFinishingForBot2, whoseTurn, whoseNext);
						if (!comp1Ships.size()) break;
						if (partyOver && !userSaveGame) break;
						if (partyOver && userSaveGame)
						{
							saveStrings(userBoard, comp1Board, comp2Board, userEnemyBoard, comp1EnemyBoard, comp2EnemyBoard, userName, whoseTurn, whoseNext);
							saveVec(userShips, comp1Ships, comp2Ships, coordsFinishingForBot1, coordsFinishingForBot2);
							saveBool(isUserPlay, bot1Aiming, bot2Aiming, players);
							savemgmt(isSaved);
							userSaveGame = false;
							saveLoad = false;
							showIfSaved();
							break;
						}
					}
					if (whoseTurn == bot1name)
					{
						botFireOnSquare(bot1Aiming, userSaveGame, saveLoad, isUserPlay, partyOver, comp2Ships, comp1Ships, comp2Board, comp1EnemyBoard, coordsFinishingForBot1, whoseTurn, whoseNext);
						if (!comp2Ships.size()) break;
						if (partyOver && !userSaveGame) break;
						if (partyOver && userSaveGame)
						{
							saveStrings(userBoard, comp1Board, comp2Board, userEnemyBoard, comp1EnemyBoard, comp2EnemyBoard, userName, whoseTurn, whoseNext);
							saveVec(userShips, comp1Ships, comp2Ships, coordsFinishingForBot1, coordsFinishingForBot2);
							saveBool(isUserPlay, bot1Aiming, bot2Aiming, players);
							savemgmt(isSaved);
							userSaveGame = false;
							saveLoad = false;
							showIfSaved();
							break;
						}
					}
				}
			}

		}
		if (!partyOver)
		{
			endParty(whoseTurn, userName);
			saveLoad = false;
		}
		
	}
}