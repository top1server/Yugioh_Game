#include "Game.h"
Game::Game()
{
	IntGame();
}
void Game::IntGame()
{
    CURSOR.SetImageDefault("images/mouse/mouse2.png");
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
	SDL_Texture* Speed = IMG_LoadTexture(WINDOW.GetRenderer(), "images/icon/speed.png");
	SDL_Texture* Option = IMG_LoadTexture(WINDOW.GetRenderer(), "images/icon/option.png");
	SDL_Rect UndoRect = { 12,161,0,0 };
	SDL_QueryTexture(Undo, NULL, NULL, &UndoRect.w, &UndoRect.h);
	WINDOW.Draw(Undo, &UndoRect);
	
	SDL_Rect SpeedRect = { 12,240,0,0 };
	SDL_QueryTexture(Speed, NULL, NULL, &SpeedRect.w, &SpeedRect.h);
	WINDOW.Draw(Speed, &SpeedRect);

	SDL_Rect OptionRect = {12,85,0,0 };
	SDL_QueryTexture(Option, NULL, NULL, &OptionRect.w, &OptionRect.h);
	WINDOW.Draw(Option, &OptionRect);
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

	WINDOW.SetUp("MAGIC DUEL", SCREEN_WIDTH, SCREEN_HEIGHT);
	SDL_Surface* iconSurface = IMG_Load("images/icon/icon1.png");
	SDL_SetWindowIcon(WINDOW.GetWindow(), iconSurface);

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
	
	SDL_Event e;
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

	MUSIC_INGAME.SetMusic("musics/MusicInGame.mp3");
	MUSIC_INGAME.Play();
	MUSIC_INGAME.SetRepeat();

	SDL_Texture* BackGround = IMG_LoadTexture(WINDOW.GetRenderer(), "images/map.png");
	SDL_Rect BGRect;
	BGRect = { 0,0,1440,810 };

	SDL_Texture* Undo = IMG_LoadTexture(WINDOW.GetRenderer(), "images/icon/undo.png");
	SDL_Texture* Speed = IMG_LoadTexture(WINDOW.GetRenderer(), "images/icon/speed.png");
	SDL_Texture* Option = IMG_LoadTexture(WINDOW.GetRenderer(), "images/icon/option.png");

	SDL_Rect UndoRect = { 12,161,0,0 };
	SDL_QueryTexture(Undo, NULL, NULL, &UndoRect.w, &UndoRect.h);

	SDL_Rect SpeedRect = { 12,240,0,0 };
	SDL_QueryTexture(Speed, NULL, NULL, &SpeedRect.w, &SpeedRect.h);

	SDL_Rect OptionRect = { 12,85,0,0 };
	SDL_QueryTexture(Option, NULL, NULL, &OptionRect.w, &OptionRect.h);

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
	SDL_Event e;
	
	// Click
	const int SPRITE_WIDTH = 80;
	const int SPRITE_HEIGHT = 80;
	const int ROWS = 5;
	const int COLUMNS = 8;
	const int TOTAL_FRAMES = 40;
	const int FRAME_DELAY = 10;
	SDL_Texture* Click = IMG_LoadTexture(WINDOW.GetRenderer(), "images/turn.png");
	int frame = 0;
	SDL_Rect clipRect;
	SDL_Rect click;

	std::vector<int> vec = { 1,1,1,2,2,2,3,3,4,5,5,8,6,6,6,7,7,7,9,15,15,16,10,10,18,14,14,13,25,23,23,23,24,19,20,22,11,21,12,17 };
	std::random_device rd;
	std::mt19937 gen(rd());
	std::shuffle(vec.begin(), vec.end(), gen);
	bool Start = true;
	int Card_th = 0;

	int x, y;
	while (WINDOW.IsDone())
	{
		WINDOW.RendererClear();
		while (SDL_PollEvent(&e))
		{
			switch (e.type)
			{
			case SDL_QUIT:
				WINDOW.~WindowGame();
				MUSIC_INGAME.~MusicGame();
				break;
			case SDL_MOUSEMOTION:
				CURSOR_INPUT = TypeInputCursor::WAIT_CURSOR;

				break;
			case SDL_MOUSEBUTTONDOWN:
				CURSOR_INPUT = TypeInputCursor::WAIT_CURSOR;
				if (e.button.button == SDL_BUTTON_LEFT)
				{
					CURSOR_INPUT = TypeInputCursor::LEFT_CURSOR;
				}
				else if (e.button.button == SDL_BUTTON_RIGHT)
				{
					CURSOR_INPUT = TypeInputCursor::RIGHT_CURSOR;
				}
				break;
			}
		}

		WINDOW.Draw(BackGround, &BGRect);
		WINDOW.Draw(Undo, &UndoRect);
		WINDOW.Draw(Speed, &SpeedRect);
		WINDOW.Draw(Option, &OptionRect);

		if (CURSOR.IsCursorInRect(&OptionRect) == SDL_TRUE)
		{
			SDL_Texture* OptionClick = IMG_LoadTexture(WINDOW.GetRenderer(), "images/icon/option1.png");
			SDL_Rect OptionClickRect;
			SDL_QueryTexture(OptionClick, NULL, NULL, &OptionClickRect.w, &OptionClickRect.h);
			OptionClickRect.x = 12;
			OptionClickRect.y = 85;
			WINDOW.Draw(OptionClick, &OptionClickRect);
			SDL_DestroyTexture(OptionClick);
		}
		else if (CURSOR.IsCursorInRect(&UndoRect) == SDL_TRUE)
		{
			SDL_Texture* UndoClick = IMG_LoadTexture(WINDOW.GetRenderer(), "images/icon/undo1.png");
			SDL_Rect UndoClickRect;
			SDL_QueryTexture(UndoClick, NULL, NULL, &UndoClickRect.w, &UndoClickRect.h);
			UndoClickRect.x = 12;
			UndoClickRect.y = 161;
			WINDOW.Draw(UndoClick, &UndoClickRect);
			SDL_DestroyTexture(UndoClick);
		}
		else if (CURSOR.IsCursorInRect(&SpeedRect) == SDL_TRUE)
		{
			SDL_Texture* SpeedClick = IMG_LoadTexture(WINDOW.GetRenderer(), "images/icon/speed1.png");
			SDL_Rect SpeedClickRect;
			SDL_QueryTexture(SpeedClick, NULL, NULL, &SpeedClickRect.w, &SpeedClickRect.h);
			SpeedClickRect.x = 12;
			SpeedClickRect.y = 240;
			WINDOW.Draw(SpeedClick, &SpeedClickRect);
			SDL_DestroyTexture(SpeedClick);
		}
		if (CURSOR_INPUT == TypeInputCursor::LEFT_CURSOR)
		{
			CURSOR_INPUT = TypeInputCursor::WAIT_CURSOR;
			while (true) {
				clipRect.x = (frame % COLUMNS) * SPRITE_WIDTH;
				clipRect.y = (frame / COLUMNS) * SPRITE_HEIGHT;
				clipRect.w = SPRITE_WIDTH;
				clipRect.h = SPRITE_HEIGHT;
				
				SDL_GetMouseState(&x, &y);
				click.x = x - 35;
				click.y = y - 35;
				click.w = SPRITE_WIDTH;
				click.h = SPRITE_HEIGHT;
				WINDOW.DrawFull(Click, &clipRect, &click);
				WINDOW.EndDraw();
				frame++;
				if (frame == 40)
				{
					frame = 0;
					break;
				}
				SDL_Delay(FRAME_DELAY);
			}
		}
		WINDOW.EndDraw();
	}	
}

StateMenu Game::GetStateGame()
{
	return STATE;
}