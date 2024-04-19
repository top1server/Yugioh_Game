#include "Start.h"
#include "MenuGame.h"
int main(int argc, char* argv[])
{
	MenuGame MENU;
	StateMenu gState = MENU.InitiationMenuState();
	if (gState == StateMenu::DUEL_MODE)
	{
		ModeGame gMode = MENU.InitiationMenuMode();
		Start gStart;
		if (gMode == ModeGame::PvP)
		{
			gStart.StartAnimation();
		}
	}
	else if (gState == StateMenu::DECK_CONSTRUCTION)
	{
		MENU.Deckconstruction();
	}
	
	return 0;
}