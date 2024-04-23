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
	Player = TurnPlayer::P1Play;
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
	Player = TurnPlayer::P1Play;
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
	int frame = 0;
	SDL_Texture* Click = IMG_LoadTexture(WINDOW.GetRenderer(), "images/click.png");
	SDL_Rect clipRect;
	SDL_Rect click;

	std::vector<std::pair<int, SDL_Texture*>> vec = {{1,Card1},{1,Card1},{1,Card1},{2,Card2},{2,Card2},{2,Card2},{3,Card3},{3,Card3},{4, Card4},{5,Card5},{5,Card5},
		{8,Card8},{6,Card6},{6,Card6},{6,Card6},{7,Card7},{7,Card7},{7,Card7},{9,Card9},{15,Card15},{15,Card15},{16,Card16},{10,Card10},{10,Card10},{18,Card18},
		{14,Card14},{14,Card14},{13,Card13},{25,Card25},{23,Card23},{23,Card23},{23,Card23},{24,Card24},{19,Card19},{20,Card20},{22,Card22},{11,Card11},{21,Card21},
		{12,Card12},{17,Card17} };
	
	std::random_device rd;
	std::mt19937 gen(rd());
	std::shuffle(vec.begin(), vec.end(), gen);
	
	bool Start = true;
	int Card_th;
	int x, y;
	SDL_Rect StartRect = {1250,330,0,0};
	SDL_Rect StartRect1 = { 1250,330,0,0 };
	SDL_Rect StartRect2 = { 1250,330,0,0 };
	SDL_Rect StartRect3 = { 1250,330,0,0 };
	SDL_Rect StartRect4 = { 1250,330,0,0 };
	SDL_Rect StartRect5 = { 1250,330,0,0 };
	SDL_Rect StartRect6 = { 1250,330,0,0 };

	const int DEST1_x = 610;
	const int DEST1_y = 620;
	const int DEST2_x = 500;
	const int DEST3_x = 720;
	const int DEST4_x = 390;
	const int DEST5_x = 720 + 110;
	const int DEST6_x = 390 - 110;
	const int DEST7_x = 720 + 110 + 110;	

	int hand1 = 0, hand2 = 0, hand3 = 0, hand4 = 0, hand5 = 0, hand6 = 0, hand7 = 0; // tren tay
	int hand1S = 0, hand2S = 0, hand3S = 0, hand4S = 0, hand5S = 0, hand6S = 0, hand7S = 0; //-1 : spell, -2 : trap;
	int field1 = 0, field2 = 0, field3 = 0, field4 = 0, field5 = 0; //quái thú trên sân
	int sp1 = 0, sp2 = 0, sp3 = 0, sp4 = 0, sp5 = 0; // phép bẫy trên sân 

	// effect 
	bool c1_is_used[3] = { false }, c2_is_used[3] = { false }, c3_is_used[2] = { false }, c4_is_used = false, c5_is_used[2] = { false }, c6_is_used[3] = { false },
		c7_is_used[3] = { false }, c8_is_used = false, c9_is_used = false, c10_is_used[2] = { false }, c11_is_used = false, c12_is_used = false, c13_is_used = false,
		c14_is_used[2] = { false }, c15_is_used[2] = { false }, c16_is_used = false, c17_is_used = false, c18_is_used = false, c19_is_used = false, c20_is_used = false,
		c21_is_used = false, c22_is_used = false, c23_is_used[3] = { false }, c24_is_used = false, c25_is_used = false;
	// atk
	bool c1_is_attacked[3] = { false }, c2_is_attacked[3] = { false }, c3_is_attacked[2] = { false }, c4_is_attacked = false, c5_is_attacked[2] = { false }, c6_is_attacked[3] = { false },
		c7_is_attacked[3] = { false }, c8_is_attacked = false, c9_is_attacked = false, c10_is_attacked[2] = { false }, c11_is_attacked = false, c12_is_attacked = false, c13_is_attacked = false,
		c14_is_attacked[2] = { false }, c15_is_attacked[2] = { false }, c16_is_attacked = false, c17_is_attacked = false, c18_is_attacked = false, c19_is_attacked = false, c20_is_attacked = false,
		c21_is_attacked = false, c22_is_attacked = false, c23_is_attacked[3] = { false }, c24_is_attacked = false, c25_is_attacked = false;
	// dưới mộ
	bool c1_is_grave_yard[3] = { false }, c2_is_grave_yard[3] = { false }, c3_is_grave_yard[2] = { false }, c4_is_grave_yard = false, c5_is_grave_yard[2] = { false }, c6_is_grave_yard[3] = { false },
		c7_is_grave_yard[3] = { false }, c8_is_grave_yard = false, c9_is_grave_yard = false, c10_is_grave_yard[2] = { false }, c11_is_grave_yard = false, c12_is_grave_yard = false, c13_is_grave_yard = false,
		c14_is_grave_yard[2] = { false }, c15_is_grave_yard[2] = { false }, c16_is_grave_yard = false, c17_is_grave_yard = false, c18_is_grave_yard = false, c19_is_grave_yard = false, c20_is_grave_yard = false,
		c21_is_grave_yard = false, c22_is_grave_yard = false, c23_is_grave_yard[3] = { false }, c24_is_grave_yard = false, c25_is_grave_yard = false;

	bool P2 = false;
	bool go = true;
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
		
		//Start;
		if (Start)
		{
			//Card4
			for (int i = 0; i <= 140; i += 10) {
				StartRect3.w = i;
				StartRect3.h = (int)((float)i / 140 * 180);
				StartRect3.x = (int)((float)1250 - i / 2);
				StartRect3.y = (int)((float)330 - (float)StartRect3.h / 2);
				WINDOW.Draw(vec[3].second, &StartRect3);
				WINDOW.EndDraw();
				SDL_Delay(10);
			}
			while (true)
			{
				WINDOW.RendererClear();

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

				int dx = DEST4_x - StartRect3.x;
				int dy = DEST1_y - StartRect3.y;
				int distance = sqrt(dx * dx + dy * dy);
				if (distance > 1 && dy > 0)
				{
					float stepX = dx / (float)distance;
					float stepY = dy / (float)distance;

					StartRect3.x += (int)(stepX * 4);
					StartRect3.y += (int)(stepY * 4);
				}
				WINDOW.Draw(vec[3].second, &StartRect3);

				WINDOW.EndDraw();
				if (distance < 2)
				{
					break;
				}
			}
			// Card2
			for (int i = 0; i <= 140; i += 4) {
				StartRect1.w = i;
				StartRect1.h = (int)((float)i / 140 * 180);
				StartRect1.x = (int)((float)1250 - i / 2);
				StartRect1.y = (int)((float)330 - (float)StartRect1.h / 2);
				WINDOW.Draw(vec[1].second, &StartRect1);
				WINDOW.EndDraw();
				SDL_Delay(10);
			}
			while (true)
			{
				WINDOW.RendererClear();

				WINDOW.Draw(BackGround, &BGRect);
				WINDOW.Draw(Undo, &UndoRect);
				WINDOW.Draw(Speed, &SpeedRect);
				WINDOW.Draw(Option, &OptionRect);
				WINDOW.Draw(vec[3].second, &StartRect3);

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

				int dx = DEST2_x - StartRect1.x;
				int dy = DEST1_y - StartRect1.y;
				int distance = sqrt(dx * dx + dy * dy);
				if (distance > 1 && dy > 0)
				{
					float stepX = dx / (float)distance;
					float stepY = dy / (float)distance;

					StartRect1.x += (int)(stepX * 4);
					StartRect1.y += (int)(stepY * 4);
				}
				WINDOW.Draw(vec[1].second, &StartRect1);

				WINDOW.EndDraw();
				if (distance < 2)
				{
					break;
				}
			}
			//Card1
			for (int i = 0; i <= 140; i += 4) {
				StartRect.w = i;
				StartRect.h = (int)((float)i / 140 * 180);
				StartRect.x = (int)((float)1250 - i / 2);
				StartRect.y = (int)((float)330 - (float)StartRect.h / 2);
				WINDOW.Draw(vec[0].second, &StartRect);
				WINDOW.EndDraw();
				SDL_Delay(10);
			}
			while (true)
			{
				WINDOW.RendererClear();

				WINDOW.Draw(BackGround, &BGRect);
				WINDOW.Draw(Undo, &UndoRect);
				WINDOW.Draw(Speed, &SpeedRect);
				WINDOW.Draw(Option, &OptionRect);
				WINDOW.Draw(vec[3].second, &StartRect3);
				WINDOW.Draw(vec[1].second, &StartRect1);
				

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

				int dx = DEST1_x - StartRect.x;
				int dy = DEST1_y - StartRect.y;
				int distance = sqrt(dx * dx + dy * dy);
				if (distance > 1 && dy > 0)
				{
					float stepX = dx / (float)distance;
					float stepY = dy / (float)distance;

					StartRect.x += (int)(stepX * 4);
					StartRect.y += (int)(stepY * 4);
				}
				WINDOW.Draw(vec[0].second, &StartRect);

				WINDOW.EndDraw();
				if (distance < 2)
				{
					break;
				}
			}
			
			// Card3
			for (int i = 0; i <= 140; i += 4) {
				StartRect2.w = i;
				StartRect2.h = (int)((float)i / 140 * 180);
				StartRect2.x = (int)((float)1250 - i / 2);
				StartRect2.y = (int)((float)330 - (float)StartRect2.h / 2);
				WINDOW.Draw(vec[2].second, &StartRect2);
				WINDOW.EndDraw();
				SDL_Delay(10);
			}
			while (true)
			{
				WINDOW.RendererClear();
				
				WINDOW.Draw(BackGround, &BGRect);
				WINDOW.Draw(Undo, &UndoRect);
				WINDOW.Draw(Speed, &SpeedRect);
				WINDOW.Draw(Option, &OptionRect);
				WINDOW.Draw(vec[3].second, &StartRect3);
				WINDOW.Draw(vec[1].second, &StartRect1);
				WINDOW.Draw(vec[0].second, &StartRect);
				

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

				int dx = DEST3_x - StartRect2.x;
				int dy = DEST1_y - StartRect2.y;
				int distance = sqrt(dx * dx + dy * dy);
				if (distance > 1 && dy > 0)
				{
					float stepX = dx / (float)distance;
					float stepY = dy / (float)distance;

					StartRect2.x += (int)(stepX * 4);
					StartRect2.y += (int)(stepY * 4);
				}
				WINDOW.Draw(vec[2].second, &StartRect2);

				WINDOW.EndDraw();
				if (distance < 2)
				{
					break;
				}
			}

			// Card 5
			for (int i = 0; i <= 140; i += 4) {
				StartRect4.w = i;
				StartRect4.h = (int)((float)i / 140 * 180);
				StartRect4.x = (int)((float)1250 - i / 2);
				StartRect4.y = (int)((float)330 - (float)StartRect4.h / 2);
				WINDOW.Draw(vec[4].second, &StartRect4);
				WINDOW.EndDraw();
				SDL_Delay(10);
			}
			while (true)
			{
				WINDOW.RendererClear();

				WINDOW.Draw(BackGround, &BGRect);
				WINDOW.Draw(Undo, &UndoRect);
				WINDOW.Draw(Speed, &SpeedRect);
				WINDOW.Draw(Option, &OptionRect);
				WINDOW.Draw(vec[3].second, &StartRect3);
				WINDOW.Draw(vec[1].second, &StartRect1);
				WINDOW.Draw(vec[0].second, &StartRect);
				WINDOW.Draw(vec[2].second, &StartRect2);

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

				int dx = DEST5_x - StartRect4.x;
				int dy = DEST1_y - StartRect4.y;
				int distance = sqrt(dx * dx + dy * dy);
				if (distance > 1 && dy > 0)
				{
					float stepX = dx / (float)distance;
					float stepY = dy / (float)distance;

					StartRect4.x += (int)(stepX * 4);
					StartRect4.y += (int)(stepY * 4);
				}
				WINDOW.Draw(vec[4].second, &StartRect4);

				WINDOW.EndDraw();
				if (distance < 2)
				{
					break;
				}
			}
			Card_th = 5;
			Start = false;
		}

		WINDOW.Draw(vec[3].second, &StartRect3);
		WINDOW.Draw(vec[1].second, &StartRect1);
		WINDOW.Draw(vec[0].second, &StartRect);
		WINDOW.Draw(vec[2].second, &StartRect2);
		WINDOW.Draw(vec[4].second, &StartRect4);
		//Click effect
		if (CURSOR_INPUT == TypeInputCursor::LEFT_CURSOR)
		{
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

		// Mô tả lá bài
		if (CURSOR.IsCursorInRect(&StartRect3) == SDL_TRUE)
		{
			WINDOW.RendererClear();

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

			WINDOW.Draw(vec[1].second, &StartRect1);
			WINDOW.Draw(vec[0].second, &StartRect);
			WINDOW.Draw(vec[2].second, &StartRect2);
			WINDOW.Draw(vec[4].second, &StartRect4);

			StartRect3.y -= 20;
			WINDOW.Draw(vec[3].second, &StartRect3);
			StartRect3.y += 20;

			SDL_Texture* D = NULL;
			if (vec[3].first == 1)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/1.png");
				hand4 = 1;
				hand4S = 7;
			}
			else if (vec[3].first == 2)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/2.png");
				hand4 = 2;
				hand4S = 6;
			}
			else if (vec[3].first == 3)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/3.png");
				hand4 = 3;
				hand4S = 4;
			}
			else if (vec[3].first == 4)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/4.png");
				hand4 = 4;
				hand4S = 5;
			}
			else if (vec[3].first == 5)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/5.png");
				hand4 = 5;
				hand4S = 4;
			}
			else if (vec[3].first == 6)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/6.png");
				hand4 = 6;
				hand4S = 4;
			}
			else if (vec[3].first == 7)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/7.png");
				hand4 = 7;
				hand4S = 4;
			}
			else if (vec[3].first == 8)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/8.png");
				hand4 = 8;
				hand4S = 8;
			}
			else if (vec[3].first == 9)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/9.png");
				hand4 = 2;
				hand4S = -1;
			}
			else if (vec[3].first == 10)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/10.png");
				hand4 = 10;
				hand4S = -1;

			}
			else if (vec[3].first == 11)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/11.png");
				hand4 = 11;
				hand4S = -1;
			}
			else if (vec[3].first == 12)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/12.png");
				hand4 = 12;
				hand4S = -1;
			}
			if (vec[3].first == 13)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/13.png");
				hand4 = 13;
				hand4S = -1;
			}
			else if (vec[3].first == 14)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/14.png");
				hand4 = 14;
				hand4S = -1;
			}
			else if (vec[3].first == 15)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/15.png");
				hand4 = 15;
				hand4S = -1;
			}
			else if (vec[3].first == 16)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/16.png");
				hand4 = 16;
				hand4S = -1;
			}
			else if (vec[3].first == 17)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/17.png");
				hand4 = 17;
				hand4S = -1;
			}
			else if (vec[3].first == 18)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/18.png");
				hand4 = 18;
				hand4S = -1;
			}
			else if (vec[3].first == 19)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/19.png");
				hand4 = 19;
				hand4S = -2;
			}
			else if (vec[3].first == 20)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/20.png");
				hand4 = 20;
				hand4S = -2;
			}
			else if (vec[3].first == 21)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/21.png");
				hand4 = 21;
				hand4S = -2;
			}
			else if (vec[3].first == 22)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/22.png");
				hand4 = 22;
				hand4S = -2;
			}
			else if (vec[3].first == 23)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/23.png");
				hand4 = 23;
				hand4S = -2;
			}
			else if (vec[3].first == 24)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/24.png");
				hand4 = 24;
				hand4S = -2;
			}
			else if (vec[3].first == 25)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/25.png");
				hand4 = 25;
				hand4S = -2;
			}

			SDL_Rect DRect;
			SDL_QueryTexture(D, NULL, NULL, &DRect.w, &DRect.h);
			DRect.x = (1440 - DRect.w)/2;
			DRect.y = 100;
			WINDOW.Draw(D, &DRect);
			SDL_DestroyTexture(D);
		}

		else if (CURSOR.IsCursorInRect(&StartRect1) == SDL_TRUE)
		{
			WINDOW.RendererClear();

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

			WINDOW.Draw(vec[3].second, &StartRect3);
			WINDOW.Draw(vec[0].second, &StartRect);
			WINDOW.Draw(vec[2].second, &StartRect2);
			WINDOW.Draw(vec[4].second, &StartRect4);

			StartRect1.y -= 20;
			WINDOW.Draw(vec[1].second, &StartRect1);
			StartRect1.y += 20;

			SDL_Texture* D = NULL;
			if(vec[1].first == 1)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/1.png");
				hand2 = 1;
				hand2S = 7;
			}
			else if (vec[1].first == 2)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/2.png");
				hand2 = 2;
				hand2S = 6;
			}
			else if (vec[1].first == 3)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/3.png");
				hand2 = 3;
				hand2S = 4;
			}
			else if (vec[1].first == 4)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/4.png");
				hand2 = 4;
				hand2S = 5;
			}
			else if (vec[1].first == 5)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/5.png");
				hand2 = 5;
				hand2S = 4;
			}
			else if (vec[1].first == 6)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/6.png");
				hand2 = 6;
				hand2S = 4;
			}
			else if (vec[1].first == 7)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/7.png");
				hand2 = 7;
				hand2S = 4;
			}
			else if (vec[1].first == 8)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/8.png");
				hand2 = 8;
				hand2S = 8;
			}
			else if (vec[1].first == 9)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/9.png");
				hand2 = 2;
				hand2S = -1;
			}
			else if (vec[1].first == 10)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/10.png");
				hand2 = 10;
				hand2S = -1;

			}
			else if (vec[1].first == 11)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/11.png");
				hand2 = 11;
				hand2S = -1;
			}
			else if (vec[1].first == 12)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/12.png");
				hand2 = 12;
				hand2S = -1;
			}
			if (vec[1].first == 13)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/13.png");
				hand2 = 13;
				hand2S = -1;
			}
			else if (vec[1].first == 14)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/14.png");
				hand2 = 14;
				hand2S = -1;
			}
			else if (vec[1].first == 15)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/15.png");
				hand2 = 15;
				hand2S = -1;
			}
			else if (vec[1].first == 16)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/16.png");
				hand2 = 16;
				hand2S = -1;
			}
			else if (vec[1].first == 17)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/17.png");
				hand2 = 17;
				hand2S = -1;
			}
			else if (vec[1].first == 18)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/18.png");
				hand2 = 18;
				hand2S = -1;
			}
			else if (vec[1].first == 19)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/19.png");
				hand2 = 19;
				hand2S = -2;
			}
			else if (vec[1].first == 20)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/20.png");
				hand2 = 20;
				hand2S = -2;
			}
			else if (vec[1].first == 21)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/21.png");
				hand2 = 21;
				hand2S = -2;
			}
			else if (vec[1].first == 22)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/22.png");
				hand2 = 22;
				hand2S = -2;
			}
			else if (vec[1].first == 23)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/23.png");
				hand2 = 23;
				hand2S = -2;
			}
			else if (vec[1].first == 24)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/24.png");
				hand2 = 24;
				hand2S = -2;
			}
			else if (vec[1].first == 25)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/25.png");
				hand2 = 25;
				hand2S = -2;
			}

			SDL_Rect DRect;
			SDL_QueryTexture(D, NULL, NULL, &DRect.w, &DRect.h);
			DRect.x = (1440 - DRect.w) / 2;
			DRect.y = 100;
			WINDOW.Draw(D, &DRect);
			SDL_DestroyTexture(D);
		}

		else if (CURSOR.IsCursorInRect(&StartRect) == SDL_TRUE)
		{
			WINDOW.RendererClear();

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

			WINDOW.Draw(vec[3].second, &StartRect3);
			WINDOW.Draw(vec[1].second, &StartRect1);

			WINDOW.Draw(vec[2].second, &StartRect2);
			WINDOW.Draw(vec[4].second, &StartRect4);

			StartRect.y -= 20;
			WINDOW.Draw(vec[0].second, &StartRect);
			StartRect.y += 20;

			SDL_Texture* D = NULL;
			if (vec[0].first == 1)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/1.png");
				hand1 = 1;
				hand1S = 7;
			}
			else if (vec[0].first == 2)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/2.png");
				hand1 = 2;
				hand1S = 6;
			}
			else if (vec[0].first == 3)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/3.png");
				hand1 = 3;
				hand1S = 4;
			}
			else if (vec[0].first == 4)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/4.png");
				hand1 = 4;
				hand1S = 5;
			}
			else if (vec[0].first == 5)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/5.png");
				hand1 = 5;
				hand1S = 4;
			}
			else if (vec[0].first == 6)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/6.png");
				hand1 = 6;
				hand1S = 4;
			}
			else if (vec[0].first == 7)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/7.png");
				hand1 = 7;
				hand1S = 4;
			}
			else if (vec[0].first == 8)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/8.png");
				hand1 = 8;
				hand1S = 8;
			}
			else if (vec[0].first == 9)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/9.png");
				hand1 = 2;
				hand1S = -1;
			}
			else if (vec[0].first == 10)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/10.png");
				hand1 = 10;
				hand1S = -1;

			}
			else if (vec[0].first == 11)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/11.png");
				hand1 = 11;
				hand1S = -1;
			}
			else if (vec[0].first == 12)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/12.png");
				hand1 = 12;
				hand1S = -1;
			}
			if (vec[0].first == 13)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/13.png");
				hand1 = 13;
				hand1S = -1;
			}
			else if (vec[0].first == 14)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/14.png");
				hand1 = 14;
				hand1S = -1;
			}
			else if (vec[0].first == 15)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/15.png");
				hand1 = 15;
				hand1S = -1;
			}
			else if (vec[0].first == 16)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/16.png");
				hand1 = 16;
				hand1S = -1;
			}
			else if (vec[0].first == 17)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/17.png");
				hand1 = 17;
				hand1S = -1;
			}
			else if (vec[0].first == 18)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/18.png");
				hand1 = 18;
				hand1S = -1;
			}
			else if (vec[0].first == 19)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/19.png");
				hand1 = 19;
				hand1S = -2;
			}
			else if (vec[0].first == 20)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/20.png");
				hand1 = 20;
				hand1S = -2;
			}
			else if (vec[0].first == 21)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/21.png");
				hand1 = 21;
				hand1S = -2;
			}
			else if (vec[0].first == 22)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/22.png");
				hand1 = 22;
				hand1S = -2;
			}
			else if (vec[0].first == 23)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/23.png");
				hand1 = 23;
				hand1S = -2;
			}
			else if (vec[0].first == 24)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/24.png");
				hand1 = 24;
				hand1S = -2;
			}
			else if (vec[0].first == 25)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/25.png");
				hand1 = 25;
				hand1S = -2;
			}

			SDL_Rect DRect;
			SDL_QueryTexture(D, NULL, NULL, &DRect.w, &DRect.h);
			DRect.x = (1440 - DRect.w) / 2;
			DRect.y = 100;
			WINDOW.Draw(D, &DRect);
			SDL_DestroyTexture(D);
		}
		else if (CURSOR.IsCursorInRect(&StartRect2) == SDL_TRUE)
		{
			WINDOW.RendererClear();

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

			WINDOW.Draw(vec[3].second, &StartRect3);
			WINDOW.Draw(vec[1].second, &StartRect1);
			WINDOW.Draw(vec[0].second, &StartRect);

			WINDOW.Draw(vec[4].second, &StartRect4);

			StartRect2.y -= 20;
			WINDOW.Draw(vec[2].second, &StartRect2);
			StartRect2.y += 20;

			SDL_Texture* D = NULL;
			if (vec[2].first == 1)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/1.png");
				hand3 = 1;
				hand3S = 7;
			}
			else if (vec[2].first == 2)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/2.png");
				hand3 = 2;
				hand3S = 6;
			}
			else if (vec[2].first == 3)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/3.png");
				hand3 = 3;
				hand3S = 4;
			}
			else if (vec[2].first == 4)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/4.png");
				hand3 = 4;
				hand3S = 5;
			}
			else if (vec[2].first == 5)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/5.png");
				hand3 = 5;
				hand3S = 4;
			}
			else if (vec[2].first == 6)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/6.png");
				hand3 = 6;
				hand3S = 4;
			}
			else if (vec[2].first == 7)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/7.png");
				hand3 = 7;
				hand3S = 4;
			}
			else if (vec[2].first == 8)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/8.png");
				hand3 = 8;
				hand3S = 8;
			}
			else if (vec[2].first == 9)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/9.png");
				hand3 = 2;
				hand3S = -1;
			}
			else if (vec[2].first == 10)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/10.png");
				hand3 = 10;
				hand3S = -1;

			}
			else if (vec[2].first == 11)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/11.png");
				hand3 = 11;
				hand3S = -1;
			}
			else if (vec[2].first == 12)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/12.png");
				hand3 = 12;
				hand3S = -1;
			}
			if (vec[2].first == 13)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/13.png");
				hand3 = 13;
				hand3S = -1;
			}
			else if (vec[2].first == 14)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/14.png");
				hand3 = 14;
				hand3S = -1;
			}
			else if (vec[2].first == 15)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/15.png");
				hand3 = 15;
				hand3S = -1;
			}
			else if (vec[2].first == 16)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/16.png");
				hand3 = 16;
				hand3S = -1;
			}
			else if (vec[2].first == 17)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/17.png");
				hand3 = 17;
				hand3S = -1;
			}
			else if (vec[2].first == 18)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/18.png");
				hand3 = 18;
				hand3S = -1;
			}
			else if (vec[2].first == 19)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/19.png");
				hand3 = 19;
				hand3S = -2;
			}
			else if (vec[2].first == 20)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/20.png");
				hand3 = 20;
				hand3S = -2;
			}
			else if (vec[2].first == 21)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/21.png");
				hand3 = 21;
				hand3S = -2;
			}
			else if (vec[2].first == 22)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/22.png");
				hand3 = 22;
				hand3S = -2;
			}
			else if (vec[2].first == 23)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/23.png");
				hand3 = 23;
				hand3S = -2;
			}
			else if (vec[2].first == 24)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/24.png");
				hand3 = 24;
				hand3S = -2;
			}
			else if (vec[2].first == 25)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/25.png");
				hand3 = 25;
				hand3S = -2;
			}

			SDL_Rect DRect;
			SDL_QueryTexture(D, NULL, NULL, &DRect.w, &DRect.h);
			DRect.x = (1440 - DRect.w) / 2;
			DRect.y = 100;
			WINDOW.Draw(D, &DRect);
			SDL_DestroyTexture(D);
		}

		else if (CURSOR.IsCursorInRect(&StartRect4) == SDL_TRUE)
		{
			WINDOW.RendererClear();

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

			WINDOW.Draw(vec[3].second, &StartRect3);
			WINDOW.Draw(vec[1].second, &StartRect1);
			WINDOW.Draw(vec[0].second, &StartRect);
			WINDOW.Draw(vec[2].second, &StartRect2);


			StartRect4.y -= 20;
			WINDOW.Draw(vec[4].second, &StartRect4);
			StartRect4.y += 20;

			SDL_Texture* D = NULL;
			if (vec[4].first == 1)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/1.png");
				hand5 = 1;
				hand5S = 7;
			}
			else if (vec[4].first == 2)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/2.png");
				hand5 = 2;
				hand5S = 6;
			}
			else if (vec[4].first == 3)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/3.png");
				hand5 = 3;
				hand5S = 4;
			}
			else if (vec[4].first == 4)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/4.png");
				hand5 = 4;
				hand5S = 5;
			}
			else if (vec[4].first == 5)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/5.png");
				hand5 = 5;
				hand5S = 4;
			}
			else if (vec[4].first == 6)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/6.png");
				hand5 = 6;
				hand5S = 4;
			}
			else if (vec[4].first == 7)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/7.png");
				hand5 = 7;
				hand5S = 4;
			}
			else if (vec[4].first == 8)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/8.png");
				hand5 = 8;
				hand5S = 8;
			}
			else if (vec[4].first == 9)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/9.png");
				hand5 = 2;
				hand5S = -1;
			}
			else if (vec[4].first == 10)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/10.png");
				hand5 = 10;
				hand5S = -1;

			}
			else if (vec[4].first == 11)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/11.png");
				hand5 = 11;
				hand5S = -1;
			}
			else if (vec[4].first == 12)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/12.png");
				hand5 = 12;
				hand5S = -1;
			}
			if (vec[4].first == 13)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/13.png");
				hand5 = 13;
				hand5S = -1;
			}
			else if (vec[4].first == 14)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/14.png");
				hand5 = 14;
				hand5S = -1;
			}
			else if (vec[4].first == 15)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/15.png");
				hand5 = 15;
				hand5S = -1;
			}
			else if (vec[4].first == 16)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/16.png");
				hand5 = 16;
				hand5S = -1;
			}
			else if (vec[4].first == 17)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/17.png");
				hand5 = 17;
				hand5S = -1;
			}
			else if (vec[4].first == 18)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/18.png");
				hand5 = 18;
				hand5S = -1;
			}
			else if (vec[4].first == 19)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/19.png");
				hand5 = 19;
				hand5S = -2;
			}
			else if (vec[4].first == 20)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/20.png");
				hand5 = 20;
				hand5S = -2;
			}
			else if (vec[4].first == 21)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/21.png");
				hand5 = 21;
				hand5S = -2;
			}
			else if (vec[4].first == 22)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/22.png");
				hand5 = 22;
				hand5S = -2;
			}
			else if (vec[4].first == 23)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/23.png");
				hand5 = 23;
				hand5S = -2;
			}
			else if (vec[4].first == 24)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/24.png");
				hand5 = 24;
				hand5S = -2;
			}
			else if (vec[4].first == 25)
			{
				D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/25.png");
				hand5 = 25;
				hand5S = -2;
			}
			SDL_Rect DRect;
			SDL_QueryTexture(D, NULL, NULL, &DRect.w, &DRect.h);
			DRect.x = (1440 - DRect.w) / 2;
			DRect.y = 100;
			WINDOW.Draw(D, &DRect);
			SDL_DestroyTexture(D);
		}

		if (Player == TurnPlayer::P1Play && !P2)
		{
			SDL_Texture* kt = IMG_LoadTexture(WINDOW.GetRenderer(), "images/ketthuc.png");
			SDL_Rect ktRect;
			SDL_QueryTexture(kt, NULL, NULL, &ktRect.w, &ktRect.h);
			ktRect.x = 1320;
			ktRect.y = 586;
			WINDOW.Draw(kt, &ktRect);
			SDL_DestroyTexture(kt);
			if (CURSOR.IsCursorInRect(&ktRect))
			{
				if (CURSOR_INPUT == TypeInputCursor::LEFT_CURSOR)
				{
					P2 = true;
					CURSOR_INPUT == TypeInputCursor::WAIT_CURSOR;
				}
			}
			if (CURSOR.IsCursorInRect(&StartRect))
			{
				if (hand1 > 0)
				{
					if (hand1S <= 4 && hand1S > 0)
					{
						SDL_Texture* ATK = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/atk.png");
						SDL_Texture* DEF = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/def.png");

						SDL_Rect ATKRect = { StartRect.x, StartRect.y + 120, StartRect.w, 30 };
						SDL_Rect DEFRect = { StartRect.x, StartRect.y + 150, StartRect.w, 30 };
						if (go)
						{
							WINDOW.Draw(ATK, &ATKRect);
							WINDOW.Draw(DEF, &DEFRect);
						}

						if (CURSOR.IsCursorInRect(&ATKRect))
						{
							SDL_Texture* ATK1 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/atk1.png");
							if(go) WINDOW.Draw(ATK1, &ATKRect);
							SDL_DestroyTexture(ATK1);

							if (CURSOR_INPUT == TypeInputCursor::LEFT_CURSOR)
							{
								if (!field3)
								{
									while (true)
									{
										WINDOW.RendererClear();

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
										WINDOW.Draw(vec[3].second, &StartRect3);
										WINDOW.Draw(vec[1].second, &StartRect1);
										WINDOW.Draw(vec[2].second, &StartRect2);
										WINDOW.Draw(vec[4].second, &StartRect4);

										int dx = 620 - StartRect.x;
										int dy = 390 - StartRect.y;
										float distance = sqrt(dx * dx + dy * dy);

										if (distance > 2)
										{
											float stepX = dx / (float)distance;
											float stepY = dy / (float)distance;
											StartRect.x += (int)(stepX * 2);
											StartRect.y += (int)(stepY * 2);
										}
										WINDOW.Draw(vec[0].second, &StartRect);
										WINDOW.EndDraw();
										if (distance < 2)
										{
											field3 = true;
											go = false;
											break;
										}
									}
								}
								else if (!field1)
								{
									while (true)
									{
										WINDOW.RendererClear();

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
										WINDOW.Draw(vec[3].second, &StartRect3);
										WINDOW.Draw(vec[1].second, &StartRect1);
										WINDOW.Draw(vec[2].second, &StartRect2);
										WINDOW.Draw(vec[4].second, &StartRect4);

										int dx = 620 - StartRect.x;
										int dy = 390 - StartRect.y;
										float distance = sqrt(dx * dx + dy * dy);

										if (distance > 2)
										{
											float stepX = dx / (float)distance;
											float stepY = dy / (float)distance;
											StartRect.x += (int)(stepX * 2);
											StartRect.y += (int)(stepY * 2);
										}
										WINDOW.Draw(vec[0].second, &StartRect);
										WINDOW.EndDraw();
										if (distance < 2)
										{
											field1 = true;
											go = false;
											break;
										}
									}
								}

							}
						}

						else if (CURSOR.IsCursorInRect(&DEFRect))
						{
							SDL_Texture* DEF1 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/def1.png");
							if(go) WINDOW.Draw(DEF1, &DEFRect);
							SDL_DestroyTexture(DEF1);
						}

						WINDOW.EndDraw();
						SDL_DestroyTexture(ATK);
						SDL_DestroyTexture(DEF);
						}
					}
				}
				if (CURSOR.IsCursorInRect(&StartRect1))
				{
					if (CURSOR_INPUT == TypeInputCursor::LEFT_CURSOR)
					{

					}
				}
				if (CURSOR.IsCursorInRect(&StartRect2))
				{
					if (CURSOR_INPUT == TypeInputCursor::LEFT_CURSOR)
					{

					}
				}
				if (CURSOR.IsCursorInRect(&StartRect3))
				{
					if (CURSOR_INPUT == TypeInputCursor::LEFT_CURSOR)
					{

					}
				}
				if (CURSOR.IsCursorInRect(&StartRect4))
				{
					if (CURSOR_INPUT == TypeInputCursor::LEFT_CURSOR)
					{

					}
				}
				if (CURSOR.IsCursorInRect(&StartRect5))
				{
					if (CURSOR_INPUT == TypeInputCursor::LEFT_CURSOR)
					{

					}
				}
				if (CURSOR.IsCursorInRect(&StartRect6))
				{
					if (CURSOR_INPUT == TypeInputCursor::LEFT_CURSOR)
					{

					}
				}


			}
			if (P2)
			{
				SDL_Texture* thu = IMG_LoadTexture(WINDOW.GetRenderer(), "images/thu.png");
				SDL_Rect thuRect;
				SDL_QueryTexture(thu, NULL, NULL, &thuRect.w, &thuRect.h);
				thuRect.x = 1320;
				thuRect.y = 586;
				WINDOW.Draw(thu, &thuRect);
				SDL_DestroyTexture(thu);



				P2 = false;
			}
		WINDOW.EndDraw();
		
	}	
}


StateMenu Game::GetStateGame()
{
	return STATE;
}