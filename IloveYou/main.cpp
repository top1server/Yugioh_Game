#include "MenuGame.h"
#include "Start.h"
int main(int argc , char* argv[])
{
	MenuGame MENU;
	if (MENU.InitiationMenu() == ModeGame::PvP)
	{
		std::cout << "HHHH";
		Start GAME;
		GAME.StartAnimation();
	}

	MENU.Cleanup();
	return 0;
}