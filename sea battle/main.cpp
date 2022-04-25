#include "programm.h"

int main()
{
	Elements instance;
	User player;
	Bot John("John");
	Bot Elizabeth("Elizabeth");
	Game game;

	introduce(player, John, Elizabeth, game);

	while (game.isGame)
	{
		partyPrepare(player, John, Elizabeth, game, instance);
		party(player, John, Elizabeth, instance, game);
		gameFinished(player, John, Elizabeth, game);
	}
}