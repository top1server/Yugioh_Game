
#include "Game.h"
int main(int argc, char* argv[])
{
	Game GAME;
	while (GAME.GetStateGame() != StateMenu::QUIT_GAME)
	{
		GAME.IntGame();
		GAME.HandleInput();
	}
	return 0;
}