#include "Game.h"
Game::Game()
{
	IntGame();
}
void Game::IntGame()
{
    CURSOR.SetImageDefault("images/mouse/mouse1.png");
	CURSOR.DrawCursorDefault();
	CURSOR.SetImageCustom("images/mouse/cursor1.png");
	IntImageBackGround();
	IntIconInGame();
	TurnPlayer = TurnPlayer::P1Play;
	STATE = StateMenu::WAIT;
}

void Game::IntImageBackGround()
{
	SDL_Texture* BackGround = IMG_LoadTexture(WINDOW.GetRenderer(), "images/map.png");
	SDL_Rect BGRect;
	BGRect = { 0,0,1440,810 };
	WINDOW.Draw(BackGround, &BGRect);
	WINDOW.EndDraw();
}

void Game::IntIconInGame()
{
	SDL_Texture* Undo = IMG_LoadTexture(WINDOW.GetRenderer(), "images/icon/undo.png");
	SDL_Texture* Indo = IMG_LoadTexture(WINDOW.GetRenderer(), "images/icon/indo.png");
	SDL_Texture* Option = IMG_LoadTexture(WINDOW.GetRenderer(), "images/icon/option.png");
	SDL_Rect UndoRect = { 1000,10,0,0 };
	SDL_QueryTexture(Undo, NULL, NULL, &UndoRect.w, &UndoRect.h);
	WINDOW.Draw(Undo, &UndoRect);
	
	SDL_Rect IndoRect = { 1200,10,0,0 };
	SDL_QueryTexture(Indo, NULL, NULL, &IndoRect.w, &IndoRect.h);
	WINDOW.Draw(Indo, &IndoRect);

	SDL_Rect OptionRect = { 1100,10,0,0 };
	SDL_QueryTexture(Option, NULL, NULL, &OptionRect.w, &OptionRect.h);
	WINDOW.Draw(Option, &OptionRect);;
	WINDOW.EndDraw();
}

void Game::HandleInput()
{
	StateMenu temp = MENU.InitiationMenuState();
	if (temp == StateMenu::QUIT_GAME)
	{
		STATE = StateMenu::QUIT_GAME;
	}
	else if (temp == StateMenu::DUEL_MODE)
	{
		STATE = StateMenu::DUEL_MODE;
		MODE = MENU.InitiationMenuMode();
		MENU.SetVolumeGame(VOLUME);
		if (MODE == ModeGame::PvP)
		{
			CreateGame1();
		}
		if (MODE == ModeGame::PvE)
		{
			CreateGame2();
		}
	}
	else if (temp == StateMenu::DECK_CONSTRUCTION)
	{
		MENU.Deckconstruction();

	}
}
void Game::CreateGame1()
{
	START.StartAnimation();

	WINDOW.SetUp("DUEL", SCREEN_WIDTH, SCREEN_HEIGHT);
	SDL_Surface* iconSurface = IMG_Load("images/icon/icon1.png");
	SDL_SetWindowIcon(WINDOW.GetWindow(), iconSurface);
	SDL_Event e;

	SDL_Texture* Card1 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/phu thuy ao den.png");
	SDL_Texture* Card2 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/nu phu thuy ao den.png");
	SDL_Texture* Card3 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/yeu tinh than den.png");
	SDL_Texture* Card4 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/ao thuat gia.png");
	SDL_Texture* Card5 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/phu thuy rung den.png");
	SDL_Texture* Card6 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/ca chua than bi.png");
	SDL_Texture* Card7 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/song sing.png");
	SDL_Texture* Card8 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/kiem si diet rong.png");
	SDL_Texture* Card9 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/dung hop.png");
	SDL_Texture* Card10 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/da hien triet.png");
	SDL_Texture* Card11 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/hoi sinh.png");
	SDL_Texture* Card12 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/hu tham vong.png");
	SDL_Texture* Card13 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/khoa tan cong.png");
	SDL_Texture* Card14 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/kiem hac am.png");
	SDL_Texture* Card15 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/ma tran den.png");
	SDL_Texture* Card16 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/ruong tu than.png");
	SDL_Texture* Card17 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/song day.png");
	SDL_Texture* Card18 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/thuoc te.png");
	SDL_Texture* Card19 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/doi vi tri.png");
	SDL_Texture* Card20 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/giap phan don.png");
	SDL_Texture* Card21 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/goi hon.png");
	SDL_Texture* Card22 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/ham bay.png");
	SDL_Texture* Card23 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/la chan phan don - kinh phan xa.png");
	SDL_Texture* Card24 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/quan tai hoi sinh.png");
	SDL_Texture* Card25 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/vong luc vong tinh.png");

	IntGame();
	while (WINDOW.IsDone())
	{
		
	}

}
void Game::CreateGame2()
{
	START.StartAnimation();

	WINDOW.SetUp("DUEL", SCREEN_WIDTH, SCREEN_HEIGHT);
	SDL_Surface* iconSurface = IMG_Load("images/icon/icon1.png");
	SDL_SetWindowIcon(WINDOW.GetWindow(), iconSurface);
	SDL_Event e;

	SDL_Texture* Card1 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/phu thuy ao den.png");
	SDL_Texture* Card2 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/nu phu thuy ao den.png");
	SDL_Texture* Card3 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/yeu tinh than den.png");
	SDL_Texture* Card4 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/ao thuat gia.png");
	SDL_Texture* Card5 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/phu thuy rung den.png");
	SDL_Texture* Card6 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/ca chua than bi.png");
	SDL_Texture* Card7 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/song sing.png");
	SDL_Texture* Card8 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/kiem si diet rong.png");
	SDL_Texture* Card9 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/dung hop.png");
	SDL_Texture* Card10 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/da hien triet.png");
	SDL_Texture* Card11 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/hoi sinh.png");
	SDL_Texture* Card12 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/hu tham vong.png");
	SDL_Texture* Card13 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/khoa tan cong.png");
	SDL_Texture* Card14 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/kiem hac am.png");
	SDL_Texture* Card15 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/ma tran den.png");
	SDL_Texture* Card16 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/ruong tu than.png");
	SDL_Texture* Card17 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/song day.png");
	SDL_Texture* Card18 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/thuoc te.png");
	SDL_Texture* Card19 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/doi vi tri.png");
	SDL_Texture* Card20 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/giap phan don.png");
	SDL_Texture* Card21 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/goi hon.png");
	SDL_Texture* Card22 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/ham bay.png");
	SDL_Texture* Card23 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/la chan phan don - kinh phan xa.png");
	SDL_Texture* Card24 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/quan tai hoi sinh.png");
	SDL_Texture* Card25 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/vong luc vong tinh.png");

	IntGame();
	while (WINDOW.IsDone())
	{

	}
}

StateMenu Game::GetStateGame()
{
	return STATE;
}