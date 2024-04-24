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
    BackGround = IMG_LoadTexture(WINDOW.GetRenderer(), "images/map.png");
    BGRect = { 0, 0, 1440, 810 };
    WINDOW.Draw(BackGround, &BGRect);
    WINDOW.EndDraw();
}

void Game::IntIconInGame()
{
    Undo = IMG_LoadTexture(WINDOW.GetRenderer(), "images/icon/undo.png");
    Speed = IMG_LoadTexture(WINDOW.GetRenderer(), "images/icon/speed.png");
    Option = IMG_LoadTexture(WINDOW.GetRenderer(), "images/icon/option.png");
    UndoRect = { 12, 161, 0, 0 };
    SDL_QueryTexture(Undo, NULL, NULL, &UndoRect.w, &UndoRect.h);
    WINDOW.Draw(Undo, &UndoRect);

    SpeedRect = { 12, 240, 0, 0 };
    SDL_QueryTexture(Speed, NULL, NULL, &SpeedRect.w, &SpeedRect.h);
    WINDOW.Draw(Speed, &SpeedRect);

    OptionRect = { 12, 85, 0, 0 };
    SDL_QueryTexture(Option, NULL, NULL, &OptionRect.w, &OptionRect.h);
    WINDOW.Draw(Option, &OptionRect);
    WINDOW.EndDraw();
}

void Game::RenderStart()
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
}

void Game::LoadDeckYugi()
{
    Card1 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/phu thuy ao den.png");
    Card2 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/nu phu thuy ao den.png");
    Card3 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/yeu tinh than den.png");
    Card4 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/ao thuat gia.png");
    Card5 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/phu thuy rung den.png");
    Card6 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/ca chua than bi.png");
    Card7 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/song sing.png");
    Card8 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/kiem si diet rong.png");
    Card9 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/dung hop.png");
    Card10 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/da hien triet.png");
    Card11 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/hoi sinh.png");
    Card12 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/hu tham vong.png");
    Card13 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/khoa tan cong.png");
    Card14 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/kiem hac am.png");
    Card15 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/ma tran den.png");
    Card16 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/ruong tu than.png");
    Card17 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/song day.png");
    Card18 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/thuoc te.png");
    Card19 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/doi vi tri.png");
    Card20 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/giap phan don.png");
    Card21 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/goi hon.png");
    Card22 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/ham bay.png");
    Card23 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/la chan phan don - kinh phan xa.png");
    Card24 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/quan tai hoi sinh.png");
    Card25 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/vong luc vong tinh.png");
}

void Game::Describe(std::vector<std::pair<int, SDL_Texture*>> vec, int i)
{
    SDL_Texture* D = NULL;
    if (vec[i].first == 1)
    {
        D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/1.png");
        hand[i] = 1;
        handS[i] = 7;
    }
    else if (vec[i].first == 2)
    {
        D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/2.png");
        hand[i] = 2;
        handS[i] = 6;
    }
    else if (vec[i].first == 3)
    {
        D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/3.png");
        hand[i] = 3;
        handS[i] = 4;
    }
    else if (vec[i].first == 4)
    {
        D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/4.png");
        hand[i] = 4;
        handS[i] = 5;
    }
    else if (vec[i].first == 5)
    {
        D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/5.png");
        hand[i] = 5;
        handS[i] = 4;
    }
    else if (vec[i].first == 6)
    {
        D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/6.png");
        hand[i] = 6;
        handS[i] = 4;
    }
    else if (vec[i].first == 7)
    {
        D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/7.png");
        hand[i] = 7;
        handS[i] = 4;
    }
    else if (vec[i].first == 8)
    {
        D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/8.png");
        hand[i] = 8;
        handS[i] = 8;
    }
    else if (vec[i].first == 9)
    {
        D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/9.png");
        hand[i] = 2;
        handS[i] = -1;
    }
    else if (vec[i].first == 10)
    {
        D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/10.png");
        hand[i] = 10;
        handS[i] = -1;
    }
    else if (vec[i].first == 11)
    {
        D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/11.png");
        hand[i] = 11;
        handS[i] = -1;
    }
    else if (vec[i].first == 12)
    {
        D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/12.png");
        hand[i] = 12;
        handS[i] = -1;
    }
    if (vec[i].first == 13)
    {
        D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/13.png");
        hand[i] = 13;
        handS[i] = -1;
    }
    else if (vec[i].first == 14)
    {
        D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/14.png");
        hand[i] = 14;
        handS[i] = -1;
    }
    else if (vec[i].first == 15)
    {
        D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/15.png");
        hand[i] = 15;
        handS[i] = -1;
    }
    else if (vec[i].first == 16)
    {
        D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/16.png");
        hand[i] = 16;
        handS[i] = -1;
    }
    else if (vec[i].first == 17)
    {
        D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/17.png");
        hand[i] = 17;
        handS[i] = -1;
    }
    else if (vec[i].first == 18)
    {
        D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/18.png");
        hand[i] = 18;
        handS[i] = -1;
    }
    else if (vec[i].first == 19)
    {
        D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/19.png");
        hand[i] = 19;
        handS[i] = -2;
    }
    else if (vec[i].first == 20)
    {
        D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/20.png");
        hand[i] = 20;
        handS[i] = -2;
    }
    else if (vec[i].first == 21)
    {
        D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/21.png");
        hand[i] = 21;
        handS[i] = -2;
    }
    else if (vec[i].first == 22)
    {
        D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/22.png");
        hand[i] = 22;
        handS[i] = -2;
    }
    else if (vec[i].first == 23)
    {
        D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/23.png");
        hand[i] = 23;
        handS[i] = -2;
    }
    else if (vec[i].first == 24)
    {
        D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/24.png");
        hand[i] = 24;
        handS[i] = -2;
    }
    else if (vec[i].first == 25)
    {
        D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/25.png");
        hand[i] = 25;
        handS[i] = -2;
    }

    SDL_Rect DRect;
    SDL_QueryTexture(D, NULL, NULL, &DRect.w, &DRect.h);
    DRect.x = (1440 - DRect.w) / 2;
    DRect.y = 100;
    WINDOW.Draw(D, &DRect);
    SDL_DestroyTexture(D);
}

void Game::DrawCard(std::vector<std::pair<int, SDL_Texture*>> vec, int i)
{
     
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

    LoadDeckYugi();

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

    BackGround = IMG_LoadTexture(WINDOW.GetRenderer(), "images/map.png");
    Undo = IMG_LoadTexture(WINDOW.GetRenderer(), "images/icon/undo.png");
    Speed = IMG_LoadTexture(WINDOW.GetRenderer(), "images/icon/speed.png");
    Option = IMG_LoadTexture(WINDOW.GetRenderer(), "images/icon/option.png");

    BGRect = { 0, 0, 1440, 810 };

    UndoRect = { 12, 161, 0, 0 };
    SDL_QueryTexture(Undo, NULL, NULL, &UndoRect.w, &UndoRect.h);

    SpeedRect = { 12, 240, 0, 0 };
    SDL_QueryTexture(Speed, NULL, NULL, &SpeedRect.w, &SpeedRect.h);

    OptionRect = { 12, 85, 0, 0 };
    SDL_QueryTexture(Option, NULL, NULL, &OptionRect.w, &OptionRect.h);

    LoadDeckYugi();


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

    std::vector<std::pair<int, SDL_Texture*>> vec = { {1, Card1}, {1, Card1}, {1, Card1}, {2, Card2}, {2, Card2}, {2, Card2}, {3, Card3}, {3, Card3}, {4, Card4}, {5, Card5}, {5, Card5}, {8, Card8}, {6, Card6}, {6, Card6}, {6, Card6}, {7, Card7}, {7, Card7}, {7, Card7}, {9, Card9}, {15, Card15}, {15, Card15}, {16, Card16}, {10, Card10}, {10, Card10}, {18, Card18}, {14, Card14}, {14, Card14}, {13, Card13}, {25, Card25}, {23, Card23}, {23, Card23}, {23, Card23}, {24, Card24}, {19, Card19}, {20, Card20}, {22, Card22}, {11, Card11}, {21, Card21}, {12, Card12}, {17, Card17} };

    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(vec.begin(), vec.end(), gen);

    bool Start = true;
    int Card_th;
    int x, y;
    SDL_Rect StartRect = { 1250, 330, 0, 0 };
    SDL_Rect StartRect1 = { 1250, 330, 0, 0 };
    SDL_Rect StartRect2 = { 1250, 330, 0, 0 };
    SDL_Rect StartRect3 = { 1250, 330, 0, 0 };
    SDL_Rect StartRect4 = { 1250, 330, 0, 0 };
    SDL_Rect StartRect5 = { 1250, 330, 0, 0 };
    SDL_Rect StartRect6 = { 1250, 330, 0, 0 };

    const int DEST1_x = 610;
    const int DEST1_y = 620;
    const int DEST2_x = 500;
    const int DEST3_x = 720;
    const int DEST4_x = 390;
    const int DEST5_x = 720 + 110;
    const int DEST6_x = 390 - 110;
    const int DEST7_x = 720 + 110 + 110;


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
    bool goST = true;
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

        RenderStart();

        // Start;
        if (Start)
        {
            // Card4
            for (int i = 0; i <= 140; i += 10)
            {
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
                RenderStart();

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
            for (int i = 0; i <= 140; i += 4)
            {
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
                RenderStart();
                WINDOW.Draw(vec[3].second, &StartRect3);
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
            // Card1
            for (int i = 0; i <= 140; i += 4)
            {
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
                RenderStart();

                WINDOW.Draw(vec[3].second, &StartRect3);
                WINDOW.Draw(vec[1].second, &StartRect1);

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
            for (int i = 0; i <= 140; i += 4)
            {
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
                RenderStart();

                WINDOW.Draw(vec[3].second, &StartRect3);
                WINDOW.Draw(vec[1].second, &StartRect1);
                WINDOW.Draw(vec[0].second, &StartRect);

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
            for (int i = 0; i <= 140; i += 4)
            {
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
                RenderStart();

                WINDOW.Draw(vec[3].second, &StartRect3);
                WINDOW.Draw(vec[1].second, &StartRect1);
                WINDOW.Draw(vec[0].second, &StartRect);
                WINDOW.Draw(vec[2].second, &StartRect2);

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
        // Click effect
        if (CURSOR_INPUT == TypeInputCursor::LEFT_CURSOR)
        {
            while (true)
            {
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
            RenderStart();

            WINDOW.Draw(vec[1].second, &StartRect1);
            WINDOW.Draw(vec[0].second, &StartRect);
            WINDOW.Draw(vec[2].second, &StartRect2);
            WINDOW.Draw(vec[4].second, &StartRect4);

            StartRect3.y -= 20;
            WINDOW.Draw(vec[3].second, &StartRect3);
            StartRect3.y += 20;

            Describe(vec, 3);
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

            Describe(vec, 1);
        }

        else if (CURSOR.IsCursorInRect(&StartRect) == SDL_TRUE)
        {
            RenderStart();

            WINDOW.Draw(vec[3].second, &StartRect3);
            WINDOW.Draw(vec[1].second, &StartRect1);
            WINDOW.Draw(vec[2].second, &StartRect2);
            WINDOW.Draw(vec[4].second, &StartRect4);

            StartRect.y -= 20;
            WINDOW.Draw(vec[0].second, &StartRect);
            StartRect.y += 20;

            Describe(vec, 0);
        }
        else if (CURSOR.IsCursorInRect(&StartRect2) == SDL_TRUE)
        {
            RenderStart();

            WINDOW.Draw(vec[3].second, &StartRect3);
            WINDOW.Draw(vec[1].second, &StartRect1);
            WINDOW.Draw(vec[0].second, &StartRect);
            WINDOW.Draw(vec[4].second, &StartRect4);

            StartRect2.y -= 20;
            WINDOW.Draw(vec[2].second, &StartRect2);
            StartRect2.y += 20;

            Describe(vec, 2);
        }

        else if (CURSOR.IsCursorInRect(&StartRect4) == SDL_TRUE)
        {
            RenderStart();

            WINDOW.Draw(vec[3].second, &StartRect3);
            WINDOW.Draw(vec[1].second, &StartRect1);
            WINDOW.Draw(vec[0].second, &StartRect);
            WINDOW.Draw(vec[2].second, &StartRect2);

            StartRect4.y -= 20;
            WINDOW.Draw(vec[4].second, &StartRect4);
            StartRect4.y += 20;

            Describe(vec, 4);
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
                if (hand[0] > 0)
                {
                    if (handS[0] <= 4 && handS[0] > 0)
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
                            if (go)
                                WINDOW.Draw(ATK1, &ATKRect);
                            SDL_DestroyTexture(ATK1);

                            if (CURSOR_INPUT == TypeInputCursor::LEFT_CURSOR)
                            {
                                if (!field[0])
                                {
                                    while (true)
                                    {
                                        RenderStart();
                                        WINDOW.Draw(vec[3].second, &StartRect3);
                                        WINDOW.Draw(vec[1].second, &StartRect1);
                                        WINDOW.Draw(vec[2].second, &StartRect2);
                                        WINDOW.Draw(vec[4].second, &StartRect4);

                                        int dx = 620 - StartRect.x;
                                        int dy = 391 - StartRect.y;
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
                                            field[0] = hand[0];
                                            go = false;
                                            break;
                                        }
                                    }

                                }
                                else if (!field[1])
                                {
                                    while (true)
                                    {
                                        RenderStart();
                                        WINDOW.Draw(vec[3].second, &StartRect3);
                                        WINDOW.Draw(vec[1].second, &StartRect1);
                                        WINDOW.Draw(vec[2].second, &StartRect2);
                                        WINDOW.Draw(vec[4].second, &StartRect4);

                                        int dx = 435 - StartRect.x;
                                        int dy = 391 - StartRect.y;
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
                                            field[1] = hand[0];
                                            go = false;
                                            break;
                                        }
                                    }
                                }
                                else if (!field[2])
                                {
                                    while (true)
                                    {
                                        RenderStart();
                                        WINDOW.Draw(vec[3].second, &StartRect3);
                                        WINDOW.Draw(vec[1].second, &StartRect1);
                                        WINDOW.Draw(vec[2].second, &StartRect2);
                                        WINDOW.Draw(vec[4].second, &StartRect4);

                                        int dx = 805 - StartRect.x;
                                        int dy = 391 - StartRect.y;
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
                                            field[2] = hand[0];
                                            go = false;
                                            break;
                                        }
                                    }
                                }
                                else if (!field[3])
                                {
                                    while (true)
                                    {
                                        RenderStart();
                                        WINDOW.Draw(vec[3].second, &StartRect3);
                                        WINDOW.Draw(vec[1].second, &StartRect1);
                                        WINDOW.Draw(vec[2].second, &StartRect2);
                                        WINDOW.Draw(vec[4].second, &StartRect4);

                                        int dx = 250 - StartRect.x;
                                        int dy = 391 - StartRect.y;
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
                                            field[3] = hand[0];
                                            go = false;
                                            break;
                                        }
                                    }
                                }
                                else if (!field[4])
                                {
                                    while (true)
                                    {
                                        RenderStart();
                                        WINDOW.Draw(vec[3].second, &StartRect3);
                                        WINDOW.Draw(vec[1].second, &StartRect1);
                                        WINDOW.Draw(vec[2].second, &StartRect2);
                                        WINDOW.Draw(vec[4].second, &StartRect4);

                                        int dx = 990 - StartRect.x;
                                        int dy = 391 - StartRect.y;
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
                                            field[4] = hand[0];
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
                            if (go)
                                WINDOW.Draw(DEF1, &DEFRect);
                            SDL_DestroyTexture(DEF1);
                        }

                        WINDOW.EndDraw();
                        SDL_DestroyTexture(ATK);
                        SDL_DestroyTexture(DEF);
                    }
                    else if (handS[0] == - 2)
                    {
                        SDL_Texture* UP = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/up.png");
                        SDL_Rect UPRect = { StartRect.x, StartRect.y + 120, StartRect.w, 60 };
                        if (goST)
                        {
                            WINDOW.Draw(UP, &UPRect);
                        }
                        if (CURSOR.IsCursorInRect(&UPRect))
                        {
                            SDL_Texture* UP1 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/up1.png");
                            if (goST)
                                WINDOW.Draw(UP1, &UPRect);
                            SDL_DestroyTexture(UP);
                            if (CURSOR_INPUT == TypeInputCursor::LEFT_CURSOR)
                            {

                            }
                        }

                    }

                }
                
            }
            if (CURSOR.IsCursorInRect(&StartRect1))
            {
                if (hand[1] > 0)
                {
                    if (handS[1] <= 4 && handS[1] > 0)
                    {
                        SDL_Texture* ATK = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/atk.png");
                        SDL_Texture* DEF = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/def.png");

                        SDL_Rect ATKRect = { StartRect1.x, StartRect1.y + 120, StartRect1.w, 30 };
                        SDL_Rect DEFRect = { StartRect1.x, StartRect1.y + 150, StartRect1.w, 30 };
                        if (go)
                        {
                            WINDOW.Draw(ATK, &ATKRect);
                            WINDOW.Draw(DEF, &DEFRect);
                        }

                        if (CURSOR.IsCursorInRect(&ATKRect))
                        {
                            SDL_Texture* ATK1 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/atk1.png");
                            if (go)
                                WINDOW.Draw(ATK1, &ATKRect);
                            SDL_DestroyTexture(ATK1);

                            if (CURSOR_INPUT == TypeInputCursor::LEFT_CURSOR)
                            {
                                if (!field[0])
                                {
                                    while (true)
                                    {
                                        RenderStart();
                                        WINDOW.Draw(vec[3].second, &StartRect3);
                                        WINDOW.Draw(vec[0].second, &StartRect);
                                        WINDOW.Draw(vec[2].second, &StartRect2);
                                        WINDOW.Draw(vec[4].second, &StartRect4);

                                        int dx = 620 - StartRect1.x;
                                        int dy = 391 - StartRect1.y;
                                        float distance = sqrt(dx * dx + dy * dy);

                                        if (distance > 2)
                                        {
                                            float stepX = dx / (float)distance;
                                            float stepY = dy / (float)distance;
                                            StartRect1.x += (int)(stepX * 2);
                                            StartRect1.y += (int)(stepY * 2);
                                        }
                                        WINDOW.Draw(vec[1].second, &StartRect1);
                                        WINDOW.EndDraw();
                                        if (distance < 2)
                                        {
                                            field[0] = hand[1];
                                            go = false;
                                            break;
                                        }
                                    }
                                }
                                else if (!field[1])
                                {
                                    while (true)
                                    {
                                        RenderStart();
                                        WINDOW.Draw(vec[3].second, &StartRect3);
                                        WINDOW.Draw(vec[0].second, &StartRect);
                                        WINDOW.Draw(vec[2].second, &StartRect2);
                                        WINDOW.Draw(vec[4].second, &StartRect4);

                                        int dx = 435 - StartRect1.x;
                                        int dy = 391 - StartRect1.y;
                                        float distance = sqrt(dx * dx + dy * dy);

                                        if (distance > 2)
                                        {
                                            float stepX = dx / (float)distance;
                                            float stepY = dy / (float)distance;
                                            StartRect1.x += (int)(stepX * 2);
                                            StartRect1.y += (int)(stepY * 2);
                                        }
                                        WINDOW.Draw(vec[1].second, &StartRect1);
                                        WINDOW.EndDraw();
                                        if (distance < 2)
                                        {
                                            field[1] = hand[1];
                                            go = false;
                                            break;
                                        }
                                    }
                                }
                                else if (!field[2])
                                {
                                    while (true)
                                    {
                                        RenderStart();
                                        WINDOW.Draw(vec[3].second, &StartRect3);
                                        WINDOW.Draw(vec[0].second, &StartRect);
                                        WINDOW.Draw(vec[2].second, &StartRect2);
                                        WINDOW.Draw(vec[4].second, &StartRect4);

                                        int dx = 805 - StartRect1.x;
                                        int dy = 391 - StartRect1.y;
                                        float distance = sqrt(dx * dx + dy * dy);

                                        if (distance > 2)
                                        {
                                            float stepX = dx / (float)distance;
                                            float stepY = dy / (float)distance;
                                            StartRect1.x += (int)(stepX * 2);
                                            StartRect1.y += (int)(stepY * 2);
                                        }
                                        WINDOW.Draw(vec[1].second, &StartRect1);
                                        WINDOW.EndDraw();
                                        if (distance < 2)
                                        {
                                            field[2] = hand[1];
                                            go = false;
                                            break;
                                        }
                                    }
                                }
                                else if (!field[3])
                                {
                                    while (true)
                                    {
                                        RenderStart();
                                        WINDOW.Draw(vec[3].second, &StartRect3);
                                        WINDOW.Draw(vec[0].second, &StartRect);
                                        WINDOW.Draw(vec[2].second, &StartRect2);
                                        WINDOW.Draw(vec[4].second, &StartRect4);

                                        int dx = 250 - StartRect1.x;
                                        int dy = 391 - StartRect1.y;
                                        float distance = sqrt(dx * dx + dy * dy);

                                        if (distance > 2)
                                        {
                                            float stepX = dx / (float)distance;
                                            float stepY = dy / (float)distance;
                                            StartRect1.x += (int)(stepX * 2);
                                            StartRect1.y += (int)(stepY * 2);
                                        }
                                        WINDOW.Draw(vec[1].second, &StartRect1);
                                        WINDOW.EndDraw();
                                        if (distance < 2)
                                        {
                                            field[3] = hand[1];
                                            go = false;
                                            break;
                                        }
                                    }
                                }
                                else if (!field[4])
                                {
                                    while (true)
                                    {
                                        RenderStart();
                                        WINDOW.Draw(vec[3].second, &StartRect3);
                                        WINDOW.Draw(vec[0].second, &StartRect);
                                        WINDOW.Draw(vec[2].second, &StartRect2);
                                        WINDOW.Draw(vec[4].second, &StartRect4);

                                        int dx = 990 - StartRect1.x;
                                        int dy = 391 - StartRect1.y;
                                        float distance = sqrt(dx * dx + dy * dy);

                                        if (distance > 2)
                                        {
                                            float stepX = dx / (float)distance;
                                            float stepY = dy / (float)distance;
                                            StartRect1.x += (int)(stepX * 2);
                                            StartRect1.y += (int)(stepY * 2);
                                        }
                                        WINDOW.Draw(vec[1].second, &StartRect1);
                                        WINDOW.EndDraw();
                                        if (distance < 2)
                                        {
                                            field[4] = hand[1];
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
                            if (go)
                                WINDOW.Draw(DEF1, &DEFRect);
                            SDL_DestroyTexture(DEF1);
                        }

                        WINDOW.EndDraw();
                        SDL_DestroyTexture(ATK);
                        SDL_DestroyTexture(DEF);
                    }
                }
            }
            if (CURSOR.IsCursorInRect(&StartRect2))
            {
                    if (hand[2] > 0)
                    {
                        if (handS[2] <= 4 && handS[2] > 0)
                        {
                            SDL_Texture* ATK = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/atk.png");
                            SDL_Texture* DEF = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/def.png");

                            SDL_Rect ATKRect = { StartRect2.x, StartRect2.y + 120, StartRect2.w, 30 };
                            SDL_Rect DEFRect = { StartRect2.x, StartRect2.y + 150, StartRect2.w, 30 };
                            if (go)
                            {
                                WINDOW.Draw(ATK, &ATKRect);
                                WINDOW.Draw(DEF, &DEFRect);
                            }

                            if (CURSOR.IsCursorInRect(&ATKRect))
                            {
                                SDL_Texture* ATK1 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/atk1.png");
                                if (go)
                                    WINDOW.Draw(ATK1, &ATKRect);
                                SDL_DestroyTexture(ATK1);

                                if (CURSOR_INPUT == TypeInputCursor::LEFT_CURSOR)
                                {
                                    if (!field[0])
                                    {
                                        while (true)
                                        {
                                            RenderStart();
                                            WINDOW.Draw(vec[3].second, &StartRect3);
                                            WINDOW.Draw(vec[1].second, &StartRect1);
                                            WINDOW.Draw(vec[0].second, &StartRect);
                                            
                                            WINDOW.Draw(vec[4].second, &StartRect4);

                                            int dx = 620 - StartRect2.x;
                                            int dy = 391 - StartRect2.y;
                                            float distance = sqrt(dx * dx + dy * dy);

                                            if (distance > 2)
                                            {
                                                float stepX = dx / (float)distance;
                                                float stepY = dy / (float)distance;
                                                StartRect2.x += (int)(stepX * 2);
                                                StartRect2.y += (int)(stepY * 2);
                                            }
                                            WINDOW.Draw(vec[2].second, &StartRect2);
                                            WINDOW.EndDraw();
                                            if (distance < 2)
                                            {
                                                field[0] = hand[2];
                                                go = false;
                                                break;
                                            }
                                        }
                                    }
                                    else if (!field[1])
                                    {
                                        while (true)
                                        {
                                            RenderStart();
                                            WINDOW.Draw(vec[3].second, &StartRect3);
                                            WINDOW.Draw(vec[1].second, &StartRect1);
                                            WINDOW.Draw(vec[0].second, &StartRect);
                                            
                                            WINDOW.Draw(vec[4].second, &StartRect4);

                                            int dx = 435 - StartRect2.x;
                                            int dy = 391 - StartRect2.y;
                                            float distance = sqrt(dx * dx + dy * dy);

                                            if (distance > 2)
                                            {
                                                float stepX = dx / (float)distance;
                                                float stepY = dy / (float)distance;
                                                StartRect2.x += (int)(stepX * 2);
                                                StartRect2.y += (int)(stepY * 2);
                                            }
                                            WINDOW.Draw(vec[2].second, &StartRect2);
                                            WINDOW.EndDraw();
                                            if (distance < 2)
                                            {
                                                field[1] = hand[2];
                                                go = false;
                                                break;
                                            }
                                        }
                                    }
                                    else if (!field[2])
                                    {
                                        while (true)
                                        {
                                            RenderStart();
                                            WINDOW.Draw(vec[3].second, &StartRect3);
                                            WINDOW.Draw(vec[1].second, &StartRect1);
                                            WINDOW.Draw(vec[0].second, &StartRect);
                                            
                                            WINDOW.Draw(vec[4].second, &StartRect4);

                                            int dx = 805 - StartRect2.x;
                                            int dy = 391 - StartRect2.y;
                                            float distance = sqrt(dx * dx + dy * dy);

                                            if (distance > 2)
                                            {
                                                float stepX = dx / (float)distance;
                                                float stepY = dy / (float)distance;
                                                StartRect2.x += (int)(stepX * 2);
                                                StartRect2.y += (int)(stepY * 2);
                                            }
                                            WINDOW.Draw(vec[2].second, &StartRect2);
                                            WINDOW.EndDraw();
                                            if (distance < 2)
                                            {
                                                field[2] = hand[2];
                                                go = false;
                                                break;
                                            }
                                        }
                                    }
                                    else if (!field[3])
                                    {
                                        while (true)
                                        {
                                            RenderStart();
                                            WINDOW.Draw(vec[3].second, &StartRect3);
                                            WINDOW.Draw(vec[1].second, &StartRect1);
                                            WINDOW.Draw(vec[0].second, &StartRect);
                                            WINDOW.Draw(vec[4].second, &StartRect4);

                                            int dx = 250 - StartRect2.x;
                                            int dy = 391 - StartRect2.y;
                                            float distance = sqrt(dx * dx + dy * dy);

                                            if (distance > 2)
                                            {
                                                float stepX = dx / (float)distance;
                                                float stepY = dy / (float)distance;
                                                StartRect2.x += (int)(stepX * 2);
                                                StartRect2.y += (int)(stepY * 2);
                                            }
                                            WINDOW.Draw(vec[2].second, &StartRect2);
                                            WINDOW.EndDraw();
                                            if (distance < 2)
                                            {
                                                field[3] = hand[2];
                                                go = false;
                                                break;
                                            }
                                        }
                                    }
                                    else if (!field[4])
                                    {
                                        while (true)
                                        {
                                            RenderStart();
                                            WINDOW.Draw(vec[3].second, &StartRect3);
                                            WINDOW.Draw(vec[1].second, &StartRect1);
                                            WINDOW.Draw(vec[0].second, &StartRect);
                                            
                                            WINDOW.Draw(vec[4].second, &StartRect4);

                                            int dx = 990 - StartRect2.x;
                                            int dy = 391 - StartRect2.y;
                                            float distance = sqrt(dx * dx + dy * dy);

                                            if (distance > 2)
                                            {
                                                float stepX = dx / (float)distance;
                                                float stepY = dy / (float)distance;
                                                StartRect2.x += (int)(stepX * 2);
                                                StartRect2.y += (int)(stepY * 2);
                                            }
                                            WINDOW.Draw(vec[2].second, &StartRect2);
                                            WINDOW.EndDraw();
                                            if (distance < 2)
                                            {
                                                field[4] = hand[2];
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
                            if (go)
                                WINDOW.Draw(DEF1, &DEFRect);
                            SDL_DestroyTexture(DEF1);
                        }

                        WINDOW.EndDraw();
                        SDL_DestroyTexture(ATK);
                        SDL_DestroyTexture(DEF);
                    }
                }
            }
            if (CURSOR.IsCursorInRect(&StartRect3))
            {
                if (hand[3] > 0)
                {
                    if (handS[3] <= 4 && handS[3] > 0)
                    {
                        SDL_Texture* ATK = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/atk.png");
                        SDL_Texture* DEF = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/def.png");

                        SDL_Rect ATKRect = { StartRect3.x, StartRect3.y + 120, StartRect3.w, 30 };
                        SDL_Rect DEFRect = { StartRect3.x, StartRect3.y + 150, StartRect3.w, 30 };
                        if (go)
                        {
                            WINDOW.Draw(ATK, &ATKRect);
                            WINDOW.Draw(DEF, &DEFRect);
                        }

                        if (CURSOR.IsCursorInRect(&ATKRect))
                        {
                            SDL_Texture* ATK1 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/atk1.png");
                            if (go)
                                WINDOW.Draw(ATK1, &ATKRect);
                            SDL_DestroyTexture(ATK1);

                            if (CURSOR_INPUT == TypeInputCursor::LEFT_CURSOR)
                            {
                                if (!field[0])
                                {
                                    while (true)
                                    {
                                        RenderStart();
                                        
                                        WINDOW.Draw(vec[1].second, &StartRect1);
                                        WINDOW.Draw(vec[0].second, &StartRect);
                                        WINDOW.Draw(vec[2].second, &StartRect2);
                                        WINDOW.Draw(vec[4].second, &StartRect4);

                                        int dx = 620 - StartRect3.x;
                                        int dy = 391 - StartRect3.y;
                                        float distance = sqrt(dx * dx + dy * dy);

                                        if (distance > 2)
                                        {
                                            float stepX = dx / (float)distance;
                                            float stepY = dy / (float)distance;
                                            StartRect3.x += (int)(stepX * 2);
                                            StartRect3.y += (int)(stepY * 2);
                                        }
                                        WINDOW.Draw(vec[3].second, &StartRect3);
                                        WINDOW.EndDraw();
                                        if (distance < 2)
                                        {
                                            field[0] = hand[3];
                                            go = false;
                                            break;
                                        }
                                    }
                                }
                                else if (!field[1])
                                {
                                    while (true)
                                    {
                                        RenderStart();
                                        
                                        WINDOW.Draw(vec[1].second, &StartRect1);
                                        WINDOW.Draw(vec[0].second, &StartRect);
                                        WINDOW.Draw(vec[2].second, &StartRect2);
                                        WINDOW.Draw(vec[4].second, &StartRect4);

                                        int dx = 435 - StartRect3.x;
                                        int dy = 391 - StartRect3.y;
                                        float distance = sqrt(dx * dx + dy * dy);

                                        if (distance > 2)
                                        {
                                            float stepX = dx / (float)distance;
                                            float stepY = dy / (float)distance;
                                            StartRect3.x += (int)(stepX * 2);
                                            StartRect3.y += (int)(stepY * 2);
                                        }
                                        WINDOW.Draw(vec[3].second, &StartRect3);
                                        WINDOW.EndDraw();
                                        if (distance < 2)
                                        {
                                            field[1] = hand[3];
                                            go = false;
                                            break;
                                        }
                                    }
                                }
                                else if (!field[2])
                                {
                                    while (true)
                                    {
                                        RenderStart();
                                        
                                        WINDOW.Draw(vec[1].second, &StartRect1);
                                        WINDOW.Draw(vec[0].second, &StartRect);
                                        WINDOW.Draw(vec[2].second, &StartRect2);
                                        WINDOW.Draw(vec[4].second, &StartRect4);

                                        int dx = 805 - StartRect3.x;
                                        int dy = 391 - StartRect3.y;
                                        float distance = sqrt(dx * dx + dy * dy);

                                        if (distance > 2)
                                        {
                                            float stepX = dx / (float)distance;
                                            float stepY = dy / (float)distance;
                                            StartRect3.x += (int)(stepX * 2);
                                            StartRect3.y += (int)(stepY * 2);
                                        }
                                        WINDOW.Draw(vec[3].second, &StartRect3);
                                        WINDOW.EndDraw();
                                        if (distance < 2)
                                        {
                                            field[2] = hand[3];
                                            go = false;
                                            break;
                                        }
                                    }
                                }
                                else if (!field[3])
                                {
                                    while (true)
                                    {
                                        RenderStart();
                                        
                                        WINDOW.Draw(vec[1].second, &StartRect1);
                                        WINDOW.Draw(vec[0].second, &StartRect);
                                        WINDOW.Draw(vec[2].second, &StartRect2);
                                        WINDOW.Draw(vec[4].second, &StartRect4);

                                        int dx = 250 - StartRect3.x;
                                        int dy = 391 - StartRect3.y;
                                        float distance = sqrt(dx * dx + dy * dy);

                                        if (distance > 2)
                                        {
                                            float stepX = dx / (float)distance;
                                            float stepY = dy / (float)distance;
                                            StartRect3.x += (int)(stepX * 2);
                                            StartRect3.y += (int)(stepY * 2);
                                        }
                                        WINDOW.Draw(vec[3].second, &StartRect3);
                                        WINDOW.EndDraw();
                                        if (distance < 2)
                                        {
                                            field[3] = hand[3];
                                            go = false;
                                            break;
                                        }
                                    }
                                }
                                else if (!field[4])
                                {
                                    while (true)
                                    {
                                        RenderStart();
                                        
                                        WINDOW.Draw(vec[1].second, &StartRect1);
                                        WINDOW.Draw(vec[0].second, &StartRect);
                                        WINDOW.Draw(vec[2].second, &StartRect2);
                                        WINDOW.Draw(vec[4].second, &StartRect4);

                                        int dx = 990 - StartRect3.x;
                                        int dy = 391 - StartRect3.y;
                                        float distance = sqrt(dx * dx + dy * dy);

                                        if (distance > 2)
                                        {
                                            float stepX = dx / (float)distance;
                                            float stepY = dy / (float)distance;
                                            StartRect3.x += (int)(stepX * 2);
                                            StartRect3.y += (int)(stepY * 2);
                                        }
                                        WINDOW.Draw(vec[3].second, &StartRect3);
                                        WINDOW.EndDraw();
                                        if (distance < 2)
                                        {
                                            field[4] = hand[3];
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
                            if (go)
                                WINDOW.Draw(DEF1, &DEFRect);
                            SDL_DestroyTexture(DEF1);
                        }

                        WINDOW.EndDraw();
                        SDL_DestroyTexture(ATK);
                        SDL_DestroyTexture(DEF);
                    }
                }
            }
            if (CURSOR.IsCursorInRect(&StartRect4))
            {
                if (hand[4] > 0)
                {
                    if (handS[4] <= 4 && handS[4] > 0)
                    {
                        SDL_Texture* ATK = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/atk.png");
                        SDL_Texture* DEF = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/def.png");

                        SDL_Rect ATKRect = { StartRect4.x, StartRect4.y + 120, StartRect4.w, 30 };
                        SDL_Rect DEFRect = { StartRect4.x, StartRect4.y + 150, StartRect4.w, 30 };
                        if (go)
                        {
                            WINDOW.Draw(ATK, &ATKRect);
                            WINDOW.Draw(DEF, &DEFRect);
                        }

                        if (CURSOR.IsCursorInRect(&ATKRect))
                        {
                            SDL_Texture* ATK1 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/atk1.png");
                            if (go)
                                WINDOW.Draw(ATK1, &ATKRect);
                            SDL_DestroyTexture(ATK1);

                            if (CURSOR_INPUT == TypeInputCursor::LEFT_CURSOR)
                            {
                                if (!field[0])
                                {
                                    while (true)
                                    {
                                        RenderStart();
                                        WINDOW.Draw(vec[3].second, &StartRect3);
                                        WINDOW.Draw(vec[1].second, &StartRect1);
                                        WINDOW.Draw(vec[0].second, &StartRect);
                                        WINDOW.Draw(vec[2].second, &StartRect2);
                                        

                                        int dx = 620 - StartRect4.x;
                                        int dy = 391 - StartRect4.y;
                                        float distance = sqrt(dx * dx + dy * dy);

                                        if (distance > 2)
                                        {
                                            float stepX = dx / (float)distance;
                                            float stepY = dy / (float)distance;
                                            StartRect4.x += (int)(stepX * 2);
                                            StartRect4.y += (int)(stepY * 2);
                                        }
                                        WINDOW.Draw(vec[4].second, &StartRect4);
                                        WINDOW.EndDraw();
                                        if (distance < 2)
                                        {
                                            field[0] = hand[4];
                                            go = false;
                                            break;
                                        }
                                    }
                                }
                                else if (!field[1])
                                {
                                    while (true)
                                    {
                                        RenderStart();
                                        WINDOW.Draw(vec[3].second, &StartRect3);
                                        WINDOW.Draw(vec[1].second, &StartRect1);
                                        WINDOW.Draw(vec[0].second, &StartRect);
                                        WINDOW.Draw(vec[2].second, &StartRect2);
                                        

                                        int dx = 435 - StartRect4.x;
                                        int dy = 391 - StartRect4.y;
                                        float distance = sqrt(dx * dx + dy * dy);

                                        if (distance > 2)
                                        {
                                            float stepX = dx / (float)distance;
                                            float stepY = dy / (float)distance;
                                            StartRect4.x += (int)(stepX * 2);
                                            StartRect4.y += (int)(stepY * 2);
                                        }
                                        WINDOW.Draw(vec[4].second, &StartRect4);
                                        WINDOW.EndDraw();
                                        if (distance < 2)
                                        {
                                            field[1] = hand[4];
                                            go = false;
                                            break;
                                        }
                                    }
                                }
                                else if (!field[2])
                                {
                                    while (true)
                                    {
                                        RenderStart();
                                        WINDOW.Draw(vec[3].second, &StartRect3);
                                        WINDOW.Draw(vec[1].second, &StartRect1);
                                        WINDOW.Draw(vec[0].second, &StartRect);
                                        WINDOW.Draw(vec[2].second, &StartRect2);
                                        

                                        int dx = 805 - StartRect4.x;
                                        int dy = 391 - StartRect4.y;
                                        float distance = sqrt(dx * dx + dy * dy);

                                        if (distance > 2)
                                        {
                                            float stepX = dx / (float)distance;
                                            float stepY = dy / (float)distance;
                                            StartRect4.x += (int)(stepX * 2);
                                            StartRect4.y += (int)(stepY * 2);
                                        }
                                        WINDOW.Draw(vec[4].second, &StartRect4);
                                        WINDOW.EndDraw();
                                        if (distance < 2)
                                        {
                                            field[2] = hand[4];
                                            go = false;
                                            break;
                                        }
                                    }
                                }
                                else if (!field[3])
                                {
                                    while (true)
                                    {
                                        RenderStart();
                                        WINDOW.Draw(vec[3].second, &StartRect3);
                                        WINDOW.Draw(vec[1].second, &StartRect1);
                                        WINDOW.Draw(vec[0].second, &StartRect);
                                        WINDOW.Draw(vec[2].second, &StartRect2);
                                        

                                        int dx = 250 - StartRect4.x;
                                        int dy = 391 - StartRect4.y;
                                        float distance = sqrt(dx * dx + dy * dy);

                                        if (distance > 2)
                                        {
                                            float stepX = dx / (float)distance;
                                            float stepY = dy / (float)distance;
                                            StartRect4.x += (int)(stepX * 2);
                                            StartRect4.y += (int)(stepY * 2);
                                        }
                                        WINDOW.Draw(vec[4].second, &StartRect4);
                                        WINDOW.EndDraw();
                                        if (distance < 2)
                                        {
                                            field[3] = hand[4];
                                            go = false;
                                            break;
                                        }
                                    }
                                }
                                else if (!field[4])
                                {
                                    while (true)
                                    {
                                        RenderStart();
                                        WINDOW.Draw(vec[3].second, &StartRect3);
                                        WINDOW.Draw(vec[1].second, &StartRect1);
                                        WINDOW.Draw(vec[0].second, &StartRect);
                                        WINDOW.Draw(vec[2].second, &StartRect2);
                                        

                                        int dx = 990 - StartRect4.x;
                                        int dy = 391 - StartRect4.y;
                                        float distance = sqrt(dx * dx + dy * dy);

                                        if (distance > 2)
                                        {
                                            float stepX = dx / (float)distance;
                                            float stepY = dy / (float)distance;
                                            StartRect4.x += (int)(stepX * 2);
                                            StartRect4.y += (int)(stepY * 2);
                                        }
                                        WINDOW.Draw(vec[4].second, &StartRect4);
                                        WINDOW.EndDraw();
                                        if (distance < 2)
                                        {
                                            field[4] = hand[4];
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
                            if (go)
                                WINDOW.Draw(DEF1, &DEFRect);
                            SDL_DestroyTexture(DEF1);
                        }

                        WINDOW.EndDraw();
                        SDL_DestroyTexture(ATK);
                        SDL_DestroyTexture(DEF);
                    }
                }
            }
            if (CURSOR.IsCursorInRect(&StartRect5))
            {
                if (hand[5] > 0)
                {
                    if (handS[5] <= 4 && handS[5] > 0)
                    {
                        SDL_Texture* ATK = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/atk.png");
                        SDL_Texture* DEF = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/def.png");

                        SDL_Rect ATKRect = { StartRect3.x, StartRect3.y + 120, StartRect3.w, 30 };
                        SDL_Rect DEFRect = { StartRect3.x, StartRect3.y + 150, StartRect3.w, 30 };
                        if (go)
                        {
                            WINDOW.Draw(ATK, &ATKRect);
                            WINDOW.Draw(DEF, &DEFRect);
                        }

                        if (CURSOR.IsCursorInRect(&ATKRect))
                        {
                            SDL_Texture* ATK1 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/atk1.png");
                            if (go)
                                WINDOW.Draw(ATK1, &ATKRect);
                            SDL_DestroyTexture(ATK1);

                            if (CURSOR_INPUT == TypeInputCursor::LEFT_CURSOR)
                            {
                                if (!field[0])
                                {
                                    while (true)
                                    {
                                        RenderStart();

                                        WINDOW.Draw(vec[1].second, &StartRect1);
                                        WINDOW.Draw(vec[0].second, &StartRect);
                                        WINDOW.Draw(vec[2].second, &StartRect2);
                                        WINDOW.Draw(vec[4].second, &StartRect4);

                                        int dx = 620 - StartRect3.x;
                                        int dy = 391 - StartRect3.y;
                                        float distance = sqrt(dx * dx + dy * dy);

                                        if (distance > 2)
                                        {
                                            float stepX = dx / (float)distance;
                                            float stepY = dy / (float)distance;
                                            StartRect3.x += (int)(stepX * 2);
                                            StartRect3.y += (int)(stepY * 2);
                                        }
                                        WINDOW.Draw(vec[3].second, &StartRect3);
                                        WINDOW.EndDraw();
                                        if (distance < 2)
                                        {
                                            field[0] = hand[5];
                                            go = false;
                                            break;
                                        }
                                    }
                                }
                                else if (!field[1])
                                {
                                    while (true)
                                    {
                                        RenderStart();

                                        WINDOW.Draw(vec[1].second, &StartRect1);
                                        WINDOW.Draw(vec[0].second, &StartRect);
                                        WINDOW.Draw(vec[2].second, &StartRect2);
                                        WINDOW.Draw(vec[4].second, &StartRect4);

                                        int dx = 435 - StartRect3.x;
                                        int dy = 391 - StartRect3.y;
                                        float distance = sqrt(dx * dx + dy * dy);

                                        if (distance > 2)
                                        {
                                            float stepX = dx / (float)distance;
                                            float stepY = dy / (float)distance;
                                            StartRect3.x += (int)(stepX * 2);
                                            StartRect3.y += (int)(stepY * 2);
                                        }
                                        WINDOW.Draw(vec[3].second, &StartRect3);
                                        WINDOW.EndDraw();
                                        if (distance < 2)
                                        {
                                            field[1] = hand[5];
                                            go = false;
                                            break;
                                        }
                                    }
                                }
                                else if (!field[2])
                                {
                                    while (true)
                                    {
                                        RenderStart();

                                        WINDOW.Draw(vec[1].second, &StartRect1);
                                        WINDOW.Draw(vec[0].second, &StartRect);
                                        WINDOW.Draw(vec[2].second, &StartRect2);
                                        WINDOW.Draw(vec[4].second, &StartRect4);

                                        int dx = 805 - StartRect3.x;
                                        int dy = 391 - StartRect3.y;
                                        float distance = sqrt(dx * dx + dy * dy);

                                        if (distance > 2)
                                        {
                                            float stepX = dx / (float)distance;
                                            float stepY = dy / (float)distance;
                                            StartRect3.x += (int)(stepX * 2);
                                            StartRect3.y += (int)(stepY * 2);
                                        }
                                        WINDOW.Draw(vec[3].second, &StartRect3);
                                        WINDOW.EndDraw();
                                        if (distance < 2)
                                        {
                                            field[2] = hand[5];
                                            go = false;
                                            break;
                                        }
                                    }
                                }
                                else if (!field[3])
                                {
                                    while (true)
                                    {
                                        RenderStart();

                                        WINDOW.Draw(vec[1].second, &StartRect1);
                                        WINDOW.Draw(vec[0].second, &StartRect);
                                        WINDOW.Draw(vec[2].second, &StartRect2);
                                        WINDOW.Draw(vec[4].second, &StartRect4);

                                        int dx = 250 - StartRect3.x;
                                        int dy = 391 - StartRect3.y;
                                        float distance = sqrt(dx * dx + dy * dy);

                                        if (distance > 2)
                                        {
                                            float stepX = dx / (float)distance;
                                            float stepY = dy / (float)distance;
                                            StartRect3.x += (int)(stepX * 2);
                                            StartRect3.y += (int)(stepY * 2);
                                        }
                                        WINDOW.Draw(vec[3].second, &StartRect3);
                                        WINDOW.EndDraw();
                                        if (distance < 2)
                                        {
                                            field[3] = hand[5];
                                            go = false;
                                            break;
                                        }
                                    }
                                }
                                else if (!field[4])
                                {
                                    while (true)
                                    {
                                        RenderStart();

                                        WINDOW.Draw(vec[1].second, &StartRect1);
                                        WINDOW.Draw(vec[0].second, &StartRect);
                                        WINDOW.Draw(vec[2].second, &StartRect2);
                                        WINDOW.Draw(vec[4].second, &StartRect4);

                                        int dx = 990 - StartRect3.x;
                                        int dy = 391 - StartRect3.y;
                                        float distance = sqrt(dx * dx + dy * dy);

                                        if (distance > 2)
                                        {
                                            float stepX = dx / (float)distance;
                                            float stepY = dy / (float)distance;
                                            StartRect3.x += (int)(stepX * 2);
                                            StartRect3.y += (int)(stepY * 2);
                                        }
                                        WINDOW.Draw(vec[3].second, &StartRect3);
                                        WINDOW.EndDraw();
                                        if (distance < 2)
                                        {
                                            field[4] = hand[5];
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
                            if (go)
                                WINDOW.Draw(DEF1, &DEFRect);
                            SDL_DestroyTexture(DEF1);
                        }

                        WINDOW.EndDraw();
                        SDL_DestroyTexture(ATK);
                        SDL_DestroyTexture(DEF);
                    }
                }
            }
            if (CURSOR.IsCursorInRect(&StartRect6))
            {
                if (hand[6] > 0)
                {
                    if (handS[6] <= 4 && handS[6] > 0)
                    {
                        SDL_Texture* ATK = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/atk.png");
                        SDL_Texture* DEF = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/def.png");

                        SDL_Rect ATKRect = { StartRect4.x, StartRect4.y + 120, StartRect4.w, 30 };
                        SDL_Rect DEFRect = { StartRect4.x, StartRect4.y + 150, StartRect4.w, 30 };
                        if (go)
                        {
                            WINDOW.Draw(ATK, &ATKRect);
                            WINDOW.Draw(DEF, &DEFRect);
                        }

                        if (CURSOR.IsCursorInRect(&ATKRect))
                        {
                            SDL_Texture* ATK1 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/atk1.png");
                            if (go)
                                WINDOW.Draw(ATK1, &ATKRect);
                            SDL_DestroyTexture(ATK1);

                            if (CURSOR_INPUT == TypeInputCursor::LEFT_CURSOR)
                            {
                                if (!field[0])
                                {
                                    while (true)
                                    {
                                        RenderStart();
                                        WINDOW.Draw(vec[3].second, &StartRect3);
                                        WINDOW.Draw(vec[1].second, &StartRect1);
                                        WINDOW.Draw(vec[0].second, &StartRect);
                                        WINDOW.Draw(vec[2].second, &StartRect2);


                                        int dx = 620 - StartRect4.x;
                                        int dy = 391 - StartRect4.y;
                                        float distance = sqrt(dx * dx + dy * dy);

                                        if (distance > 2)
                                        {
                                            float stepX = dx / (float)distance;
                                            float stepY = dy / (float)distance;
                                            StartRect4.x += (int)(stepX * 2);
                                            StartRect4.y += (int)(stepY * 2);
                                        }
                                        WINDOW.Draw(vec[4].second, &StartRect4);
                                        WINDOW.EndDraw();
                                        if (distance < 2)
                                        {
                                            field[0] = hand[6];
                                            go = false;
                                            break;
                                        }
                                    }
                                }
                                else if (!field[1])
                                {
                                    while (true)
                                    {
                                        RenderStart();
                                        WINDOW.Draw(vec[3].second, &StartRect3);
                                        WINDOW.Draw(vec[1].second, &StartRect1);
                                        WINDOW.Draw(vec[0].second, &StartRect);
                                        WINDOW.Draw(vec[2].second, &StartRect2);


                                        int dx = 435 - StartRect4.x;
                                        int dy = 391 - StartRect4.y;
                                        float distance = sqrt(dx * dx + dy * dy);

                                        if (distance > 2)
                                        {
                                            float stepX = dx / (float)distance;
                                            float stepY = dy / (float)distance;
                                            StartRect4.x += (int)(stepX * 2);
                                            StartRect4.y += (int)(stepY * 2);
                                        }
                                        WINDOW.Draw(vec[4].second, &StartRect4);
                                        WINDOW.EndDraw();
                                        if (distance < 2)
                                        {
                                            field[1] = hand[6];
                                            go = false;
                                            break;
                                        }
                                    }
                                }
                                else if (!field[2])
                                {
                                    while (true)
                                    {
                                        RenderStart();
                                        WINDOW.Draw(vec[3].second, &StartRect3);
                                        WINDOW.Draw(vec[1].second, &StartRect1);
                                        WINDOW.Draw(vec[0].second, &StartRect);
                                        WINDOW.Draw(vec[2].second, &StartRect2);


                                        int dx = 805 - StartRect4.x;
                                        int dy = 391 - StartRect4.y;
                                        float distance = sqrt(dx * dx + dy * dy);

                                        if (distance > 2)
                                        {
                                            float stepX = dx / (float)distance;
                                            float stepY = dy / (float)distance;
                                            StartRect4.x += (int)(stepX * 2);
                                            StartRect4.y += (int)(stepY * 2);
                                        }
                                        WINDOW.Draw(vec[4].second, &StartRect4);
                                        WINDOW.EndDraw();
                                        if (distance < 2)
                                        {
                                            field[2] = hand[6];
                                            go = false;
                                            break;
                                        }
                                    }
                                }
                                else if (!field[3])
                                {
                                    while (true)
                                    {
                                        RenderStart();
                                        WINDOW.Draw(vec[3].second, &StartRect3);
                                        WINDOW.Draw(vec[1].second, &StartRect1);
                                        WINDOW.Draw(vec[0].second, &StartRect);
                                        WINDOW.Draw(vec[2].second, &StartRect2);


                                        int dx = 250 - StartRect4.x;
                                        int dy = 391 - StartRect4.y;
                                        float distance = sqrt(dx * dx + dy * dy);

                                        if (distance > 2)
                                        {
                                            float stepX = dx / (float)distance;
                                            float stepY = dy / (float)distance;
                                            StartRect4.x += (int)(stepX * 2);
                                            StartRect4.y += (int)(stepY * 2);
                                        }
                                        WINDOW.Draw(vec[4].second, &StartRect4);
                                        WINDOW.EndDraw();
                                        if (distance < 2)
                                        {
                                            field[3] = hand[6];
                                            go = false;
                                            break;
                                        }
                                    }
                                }
                                else if (!field[4])
                                {
                                    while (true)
                                    {
                                        RenderStart();
                                        WINDOW.Draw(vec[3].second, &StartRect3);
                                        WINDOW.Draw(vec[1].second, &StartRect1);
                                        WINDOW.Draw(vec[0].second, &StartRect);
                                        WINDOW.Draw(vec[2].second, &StartRect2);


                                        int dx = 990 - StartRect4.x;
                                        int dy = 391 - StartRect4.y;
                                        float distance = sqrt(dx * dx + dy * dy);

                                        if (distance > 2)
                                        {
                                            float stepX = dx / (float)distance;
                                            float stepY = dy / (float)distance;
                                            StartRect4.x += (int)(stepX * 2);
                                            StartRect4.y += (int)(stepY * 2);
                                        }
                                        WINDOW.Draw(vec[4].second, &StartRect4);
                                        WINDOW.EndDraw();
                                        if (distance < 2)
                                        {
                                            field[4] = hand[6];
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
                            if (go)
                                WINDOW.Draw(DEF1, &DEFRect);
                            SDL_DestroyTexture(DEF1);
                        }
                        WINDOW.EndDraw();
                        SDL_DestroyTexture(ATK);
                        SDL_DestroyTexture(DEF);
                    }
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