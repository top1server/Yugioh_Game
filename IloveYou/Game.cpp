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
    Turn = TurnPlayer::P1Play;
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
    E1 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Kaiba/1.png");
    E2 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Kaiba/2.png");
    E3 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Kaiba/3.png");
    E4 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Kaiba/4.png");
}

void Game::Describe(std::vector<Monster> vec, int i)
{
    SDL_Texture* D = NULL;
    if (vec[i].ID == 1)
    {
        D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/1.png");
    }
    else if (vec[i].ID == 2)
    {
        D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/2.png");
    }
    else if (vec[i].ID == 3)
    {
        D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/3.png");
    }
    else if (vec[i].ID == 4)
    {
        D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/4.png");
    }
    else if (vec[i].ID == 5)
    {
        D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/5.png");
    }
    else if (vec[i].ID == 6)
    {
        D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/6.png");
    }
    else if (vec[i].ID == 7)
    {
        D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/7.png");
    }
    else if (vec[i].ID == 8)
    {
        D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/8.png");
    }
    else if (vec[i].ID == 9)
    {
        D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/9.png");
    }
    else if (vec[i].ID == 10)
    {
        D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/10.png");
    }
    else if (vec[i].ID == 11)
    {
        D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/11.png");
    }
    else if (vec[i].ID == 12)
    {
        D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/12.png");
    }
    if (vec[i].ID == 13)
    {
        D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/13.png");
    }
    else if (vec[i].ID == 14)
    {
        D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/14.png");
    }
    else if (vec[i].ID == 15)
    {
        D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/15.png");
    }
    else if (vec[i].ID == 16)
    {
        D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/16.png");
    }
    else if (vec[i].ID == 17)
    {
        D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/17.png");
    }
    else if (vec[i].ID == 18)
    {
        D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/18.png");
    }
    else if (vec[i].ID == 19)
    {
        D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/19.png");
    }
    else if (vec[i].ID == 20)
    {
        D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/20.png");
    }
    else if (vec[i].ID == 21)
    {
        D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/21.png");
    }
    else if (vec[i].ID == 22)
    {
        D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/22.png");
    }
    else if (vec[i].ID == 23)
    {
        D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/23.png");
    }
    else if (vec[i].ID == 24)
    {
        D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/24.png");
    }
    else if (vec[i].ID == 25)
    {
        D = IMG_LoadTexture(WINDOW.GetRenderer(), "images/yugi/25.png");
    }

    SDL_Rect DRect;
    SDL_QueryTexture(D, NULL, NULL, &DRect.w, &DRect.h);
    DRect.x = (1440 - DRect.w) / 2;
    DRect.y = 100;
    WINDOW.Draw(D, &DRect);
    SDL_DestroyTexture(D);
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
        if (MODE == ModeGame::SHOP)
        {
            CreatTutorial();
        }
    }
    else if (temp == StateMenu::DECK_CONSTRUCTION)
    {
        MENU.Deckconstruction();
    }
    else if (temp == StateMenu::CARD_LIST)
    {
        MENU.Deckconstruction();
    }
    else if (temp == StateMenu::OPTION_GAME)
    {
        MENU.Option();
    }
}

void Game::CreatTutorial()
{
    WINDOW.SetUp("MAGIC DUEL", SCREEN_WIDTH, SCREEN_HEIGHT);
    SDL_Surface* iconSurface = IMG_Load("images/icon/icon1.png");
    SDL_SetWindowIcon(WINDOW.GetWindow(), iconSurface);

    MUSIC_INGAME.SetMusic("musics/tutorial.mp3");
    MUSIC_INGAME.Play();
    MUSIC_INGAME.SetRepeat();
    SDL_Event e;
    SDL_Texture* t1 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/mt1.jpg");
    SDL_Texture* t2 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/mt2.jpg");
    SDL_Texture* choose = IMG_LoadTexture(WINDOW.GetRenderer(), "images/choose.png");
    SDL_Rect r1 = { 0,0,1440,810 };
    SDL_Rect r2 = { 1110, 100, 62, 62 };
    bool quit = false;
    while (!quit)
    {
        while (SDL_PollEvent(&e))
        {
            WINDOW.RendererClear();
            WINDOW.Draw(t1, &r1);
            WINDOW.Draw(choose, &r2);
            if (e.type == SDL_QUIT)
            {
                quit = true;
            }
            else if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT && CURSOR.IsCursorInRect(&r2))
            {
                WINDOW.Draw(t2, &r1);
                WINDOW.Draw(choose, &r2);
            }
            WINDOW.EndDraw();
        }
        
        
    }
}

void Game::CreateGame1()
{
    START.StartAnimation();
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

    const int SPRITE_WIDTH1 = 900;
    const int SPRITE_HEIGHT1 = 450;
    const int ROWS1 = 5;
    const int COLUMNS1 = 5;
    const int TOTAL_FRAMES1 = 23;
    const int FRAME_DELAY1 = 10;
    int frame1 = 0;
    SDL_Texture* Spell1 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Kaiba/fire.png");
    SDL_Rect clipRect1;
    SDL_Rect rect;

    const int SPRITE_WIDTH2 = 1200;
    const int SPRITE_HEIGHT2 = 675;
    const int ROWS2 = 9;
    const int COLUMNS2 = 7;
    const int TOTAL_FRAMES2 = 63;
    const int FRAME_DELAY2 = 30;
    int frame2 = 0;
    SDL_Texture* End = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Kaiba/end.png");
    SDL_Rect clipRect2;
    SDL_Rect rect2;

    std::vector<Monster> vec = { {1, 7, 2500, 2100, Card1},
                                {1, 7, 2500, 2100, Card1},
                                {1, 7, 2500, 2100, Card1},
                                {2, 6, 2000, 1700, Card2},
                                {2, 6, 2000, 1700, Card2},
                                {2, 6, 2000, 1700, Card2},
                                {3, 4, 1800, 1000, Card3},
                                {3, 4, 1800, 1000, Card3},
                                {4, 5, 2000, 1200, Card4},
                                {5, 4, 1100, 1200, Card5},
                                {5, 4, 1100, 1200, Card5},
                                {8, 8, 2600, 2300, Card8},
                                {6, 4, 1400, 1100, Card6},
                                {6, 4, 1400, 1100, Card6},
                                {6, 4, 1400, 1100, Card6},
                                {7, 4, 1700, 1650, Card7},
                                {7, 4, 1700, 1650, Card7},
                                {7, 4, 1700, 1650, Card7},
                                {9, -1, 0, 0, Card9},
                                {15, -1, 0, 0, Card15},
                                {15, -1, 0, 0, Card15},
                                {16, -1, 0, 0, Card16},
                                {10, -1, 0, 0, Card10},
                                {10, -1, 0, 0, Card10},
                                {18, -1, 0, 0, Card18},
                                {14, -1, 0, 0, Card14},
                                {14, -1, 0, 0, Card14},
                                {13, -1, 0, 0, Card13},
                                {25, -2, 0, 0, Card25},
                                {23, -2, 0, 0, Card23},
                                {23, -2, 0, 0, Card23},
                                {23, -2, 0, 0, Card23},
                                {24, -2, 0, 0, Card24},
                                {19, -2, 0, 0, Card19},
                                {20, -2, 0, 0, Card20},
                                {22, -2, 0, 0, Card22},
                                {11, -1, 0, 0, Card11},
                                {21, -2, 0, 0, Card21},
                                {12, -1, 0, 0, Card12},
                                {17, -1, 0, 0, Card17} };
    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(vec.begin(), vec.end(), gen);

    std::vector<Monster> InField(50);      // 5 vị trí trên sân 0 -> 4
    std::vector<Monster> InHand(50);       // 7 lá bài trên tay 0 -> 6
    std::vector<Monster> InSpell_Trap(50); // 5 lá bài phép bẫy
    std::vector<Monster> EnemyHand(50);
    EnemyHand[0] = { 1, -1, 0, 0, E1 };
    EnemyHand[1] = { 1, -1, 0, 0, E1 };
    EnemyHand[2] = { 2, 300, 900, 1000, E2, 1 };
    EnemyHand[3] = { 3, 3, 500, 1200, E3, 1 };
    EnemyHand[4] = { 4, 2, 800, 400, E4, 1 };
    std::vector<Monster> InFieldEnemy(50);
    std::vector<Monster> InSpell_TrapEnemy(50);

    SDL_Texture* Win = IMG_LoadTexture(WINDOW.GetRenderer(), "images/win.png");
    SDL_Texture* Loss = IMG_LoadTexture(WINDOW.GetRenderer(), "images/loss.png");
    // InHand.clear();
    // InField.clear();
    bool Start = true;
    int Card_th = 0;
    int x, y;

    HandRect[0] = { 278, 621, 140, 180 };
    HandRect[1] = { 390, 620, 140, 180 };
    HandRect[2] = { 500, 620, 140, 180 };
    HandRect[3] = { 609, 620, 140, 180 };
    HandRect[4] = { 720, 620, 140, 180 };
    HandRect[5] = { 830, 620, 140, 180 };
    HandRect[6] = { 940, 620, 140, 180 };

    FieldRect[0] = { 620, 391, 140, 180 };
    FieldRect[1] = { 435, 391, 140, 180 };
    FieldRect[2] = { 805, 391, 140, 180 };
    FieldRect[3] = { 250, 391, 140, 180 };
    FieldRect[4] = { 990, 391, 140, 180 };

    EnemyFieldRect[0] = { 620, 100, 140, 180 };
    EnemyFieldRect[1] = { 435, 100, 140, 180 };
    EnemyFieldRect[2] = { 805, 100, 140, 180 };
    EnemyFieldRect[3] = { 250, 100, 140, 180 };
    EnemyFieldRect[4] = { 990, 100, 140, 180 };

    Spell_TrapRect[0] = { 1130, 300, 140, 180 };
    Spell_TrapRect[1] = { 1200, 300, 140, 180 };
    Spell_TrapRect[2] = { 1130, 460, 140, 180 };
    Spell_TrapRect[3] = { 1200, 460, 140, 180 };
    Spell_TrapRect[4] = { 1130, 620, 140, 180 };

    SDL_Rect GraveYardRect = { 118, 180, 100, 140 };
    SDL_Rect EnemyHandRect = { 720, 50, 140, 180 };

    DEST_x[0] = 280;
    DEST_x[1] = 390;
    DEST_x[2] = 500;
    DEST_x[3] = 610;
    DEST_x[4] = 720;
    DEST_x[5] = 830;
    DEST_x[6] = 940;

    DEST_MONSTER_IN_FIELD[0] = { 620, 391 };
    DEST_MONSTER_IN_FIELD[1] = { 435, 391 };
    DEST_MONSTER_IN_FIELD[2] = { 805, 391 };
    DEST_MONSTER_IN_FIELD[3] = { 250, 391 };
    DEST_MONSTER_IN_FIELD[4] = { 990, 391 };

    DEST_MONSTER_IN_FIELDENEMY[0] = { 620, 100 };
    DEST_MONSTER_IN_FIELDENEMY[1] = { 435, 100 };
    DEST_MONSTER_IN_FIELDENEMY[2] = { 805, 100 };
    DEST_MONSTER_IN_FIELDENEMY[3] = { 250, 100 };
    DEST_MONSTER_IN_FIELDENEMY[4] = { 990, 100 };

    DEST_SPELL_TRAP_IN_FIELD[0] = { 1130, 300 };
    DEST_SPELL_TRAP_IN_FIELD[1] = { 1200, 300 };
    DEST_SPELL_TRAP_IN_FIELD[2] = { 1130, 460 };
    DEST_SPELL_TRAP_IN_FIELD[3] = { 1200, 460 };
    DEST_SPELL_TRAP_IN_FIELD[4] = { 1130, 620 };

    DEST_SPELL_TRAP_IN_FIELD1[0] = { 1205, 390 };
    DEST_SPELL_TRAP_IN_FIELD1[1] = { 1294, 390 };
    DEST_SPELL_TRAP_IN_FIELD1[2] = { 1204, 485 };
    DEST_SPELL_TRAP_IN_FIELD1[3] = { 1294, 485 };
    DEST_SPELL_TRAP_IN_FIELD1[4] = { 1204, 580 };

    bool IsE0InGraveYard = false;
    bool IsAttack = false;
    bool IsEnd = false;
    while (WINDOW.IsDone())
    {
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
        std::string Tmp1 = std::to_string(MyBlood);
        std::string Tmp2 = std::to_string(EnenyBlood);
        SDL_Texture* My_Blood = loadTextTexture(Tmp1, textColor);
        SDL_Texture* Enemy_Blood = loadTextTexture(Tmp2, textColor1);
        int textWidth, textHeight;
        int textWidth1, textHeight1;
        SDL_QueryTexture(My_Blood, NULL, NULL, &textWidth, &textHeight);
        SDL_QueryTexture(Enemy_Blood, NULL, NULL, &textWidth1, &textHeight1);
        SDL_Rect renderQuad = { 55, 680, textWidth, textHeight };
        SDL_Rect renderQuad1 = { 1330, 90, textWidth1, textHeight1 };
        WINDOW.Draw(My_Blood, &renderQuad);
        WINDOW.Draw(Enemy_Blood, &renderQuad1);
        SDL_DestroyTexture(My_Blood);
        SDL_DestroyTexture(Enemy_Blood);

        for (int i = 0; i < NumCardInHand; i++)
        {
            WINDOW.Draw(InHand[i].IMG, &HandRect[i]);
        }
        for (int i = 0; i < NumMonsterInField; i++)
        {
            if (InField[i].State == 1)
            {
                WINDOW.Draw(InField[i].IMG, &FieldRect[i]);
            }
            else
                WINDOW.DrawEx(InField[i].IMG, &FieldRect[i]);
        }
        for (int i = 0; i < NumSpellTrapInField; i++)
        {
            WINDOW.Draw(InSpell_Trap[i].IMG, &Spell_TrapRect[i]);
        }

        for (int i = 0; i < NumMonsterInFieldEnemy; i++)
        {
            if (InFieldEnemy[i].State == 1)
                WINDOW.Draw(InFieldEnemy[i].IMG, &EnemyFieldRect[i]);
            else
                WINDOW.DrawEx(InFieldEnemy[i].IMG, &EnemyFieldRect[i]);
        }
        if (IsE0InGraveYard)
            WINDOW.Draw(EnemyHand[0].IMG, &GraveYardRect);

        // Rut bai
        if (!Start && MyTurn && NewTurn && !IsDrawed && NumCardInHand < 7)
        {
            InHand[NumCardInHand] = vec[Card_th];
            NumCardInHand++;
            SDL_Rect Draw;
            for (int j = 0; j <= 140; j += 10)
            {
                Draw.w = j;
                Draw.h = (int)((float)j / 140 * 180);
                Draw.x = (int)((float)1250 - j / 2);
                Draw.y = (int)((float)330 - (float)Draw.h / 2);
                WINDOW.Draw(InHand[NumCardInHand - 1].IMG, &Draw);
                WINDOW.EndDraw();
                SDL_Delay(10);
            }
            while (true)
            {
                RenderStart();
                for (int k = 0; k < NumCardInHand; k++)
                {
                    WINDOW.Draw(InHand[k].IMG, &HandRect[k]);
                }

                for (int k = 0; k < NumMonsterInField; k++)
                {
                    if (InField[k].State == 1)
                    {
                        WINDOW.Draw(InField[k].IMG, &FieldRect[k]);
                    }
                    else
                        WINDOW.DrawEx(InField[k].IMG, &FieldRect[k]);
                }
                for (int k = 0; k < NumSpellTrapInField; k++)
                {
                    WINDOW.Draw(InSpell_Trap[k].IMG, &Spell_TrapRect[k]);
                }
                int dx = DEST_x[NumCardInHand - 1] - Draw.x;
                int dy = DEST_y - Draw.y;
                int distance = sqrt(dx * dx + dy * dy);
                if (distance > 1)
                {
                    float stepX = dx / (float)distance;
                    float stepY = dy / (float)distance;

                    Draw.x += (int)(stepX * 4);
                    Draw.y += (int)(stepY * 4);
                }
                WINDOW.Draw(InHand[NumCardInHand - 1].IMG, &Draw);
                WINDOW.EndDraw();
                if (distance < 3)
                {
                    break;
                }
            }
            IsDrawed = true;
            Card_th++;
        }
        // Start;
        else if (Start)
        {
            for (int i = 0; i < 5; i++)
            {
                SDL_Rect Start;
                for (int j = 0; j <= 140; j += 10)
                {
                    Start.w = j;
                    Start.h = (int)((float)j / 140 * 180);
                    Start.x = (int)((float)1250 - j / 2);
                    Start.y = (int)((float)330 - (float)Start.h / 2);
                    WINDOW.Draw(vec[i].IMG, &Start);
                    WINDOW.EndDraw();
                    SDL_Delay(10);
                }
                while (true)
                {
                    RenderStart();
                    for (int k = 0; k < i; k++)
                    {
                        WINDOW.Draw(InHand[k].IMG, &HandRect[k]);
                    }
                    int dx = DEST_x[i] - Start.x;
                    int dy = DEST_y - Start.y;
                    int distance = sqrt(dx * dx + dy * dy);
                    if (distance > 1 && dy > 0)
                    {
                        float stepX = dx / (float)distance;
                        float stepY = dy / (float)distance;

                        Start.x += (int)(stepX * 4);
                        Start.y += (int)(stepY * 4);
                    }
                    WINDOW.Draw(vec[i].IMG, &Start);
                    WINDOW.EndDraw();
                    if (distance < 3)
                    {
                        break;
                    }
                }
                InHand[NumCardInHand] = vec[Card_th];
                Card_th++;
                NumCardInHand++;
            }
            NumCardInHand = 5;
            Start = false;
        }

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
        for (int i = 0; i < NumCardInHand; i++)
        {
            if (CURSOR.IsCursorInRect(&HandRect[i]) == SDL_TRUE)
            {
                RenderStart();
                for (int j = 0; j < NumCardInHand; j++)
                {
                    if (j != i)
                    {
                        WINDOW.Draw(InHand[j].IMG, &HandRect[j]);
                    }
                }
                for (int k = 0; k < NumMonsterInField; k++)
                {
                    if (InField[k].State == 1)
                    {
                        WINDOW.Draw(InField[k].IMG, &FieldRect[k]);
                    }
                    else
                        WINDOW.DrawEx(InField[k].IMG, &FieldRect[k]);
                }
                for (int k = 0; k < NumSpellTrapInField; k++)
                {
                    WINDOW.Draw(InSpell_Trap[k].IMG, &Spell_TrapRect[k]);
                }

                HandRect[i].y -= 20;
                WINDOW.Draw(InHand[i].IMG, &HandRect[i]);
                HandRect[i].y += 20;
                Describe(InHand, i);
            }
        }

        for (int i = 0; i < NumSpellTrapInField; i++)
        {
            if (CURSOR.IsCursorInRect(&Spell_TrapRect[i]) == SDL_TRUE)
            {
                RenderStart();
                for (int j = 0; j < NumCardInHand; j++)
                {
                    WINDOW.Draw(InHand[j].IMG, &HandRect[j]);
                }

                for (int j = 0; j < NumMonsterInField; j++)
                {
                    WINDOW.Draw(InField[j].IMG, &FieldRect[j]);
                }
                for (int k = 0; k < NumSpellTrapInField; k++)
                {
                    if (k != i)
                        WINDOW.Draw(InSpell_Trap[k].IMG, &Spell_TrapRect[k]);
                }

                Spell_TrapRect[i].h += 20;
                Spell_TrapRect[i].w += 20;
                WINDOW.Draw(InSpell_Trap[i].IMG, &Spell_TrapRect[i]);
                Spell_TrapRect[i].h -= 20;
                Spell_TrapRect[i].w -= 20;
                Describe(InSpell_Trap, i);
            }
        }

        if (Turn == TurnPlayer::P1Play)
        {
            if (!IsAttack && NewTurn)
            {
                if (!NumMonsterInFieldEnemy)
                {
                    for (int i = 0; i < NumMonsterInField; i++)
                    {
                        if (InField[i].State == 1)
                        {
                            SDL_Rect r = { 620, 100, 140, 180 };
                            moveAndRotateTexture(InField[i].IMG, FieldRect[i], r);
                            EnenyBlood -= InField[i].ATK;
                        }
                    }
                }
                else
                {
                    for (int i = 0; i < NumMonsterInField; i++)
                    {
                        for (int j = 0; j < NumMonsterInFieldEnemy; j++)
                        {
                            if (InField[i].State == 1)
                            {
                                if (InField[i].ATK > InFieldEnemy[j].ATK && InFieldEnemy[i].State == 1)
                                {
                                    moveAndRotateTexture(InField[i].IMG, FieldRect[i], EnemyFieldRect[j]);
                                    InFieldEnemy.erase(InFieldEnemy.begin() + j);
                                    NumMonsterInFieldEnemy--;
                                    EnenyBlood -= (InField[i].ATK - InFieldEnemy[j].ATK);
                                }
                                else if (InField[i].ATK > InFieldEnemy[j].DEF && InFieldEnemy[i].State == 2)
                                {
                                    moveAndRotateTexture(InField[i].IMG, FieldRect[i], EnemyFieldRect[j]);
                                    InFieldEnemy.erase(InFieldEnemy.begin() + j);
                                    NumMonsterInFieldEnemy--;
                                }
                            }
                        }
                    }
                }
                IsAttack = true;
            }
            for (int i = 0; i < NumCardInHand; i++)
            {
                if (CURSOR.IsCursorInRect(&HandRect[i]))
                {
                    if (InHand[i].ID > 0)
                    {
                        if (InHand[i].NS <= 4 && InHand[i].NS > 0 && Summon)
                        {
                            SDL_Texture* ATK = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/atk.png");
                            SDL_Texture* DEF = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/def.png");

                            SDL_Rect ATKRect = { HandRect[i].x, HandRect[i].y + 120, HandRect[i].w, 30 };
                            SDL_Rect DEFRect = { HandRect[i].x, HandRect[i].y + 150, HandRect[i].w, 30 };
                            if (Summon)
                            {
                                WINDOW.Draw(ATK, &ATKRect);
                                WINDOW.Draw(DEF, &DEFRect);
                            }
                            if (CURSOR.IsCursorInRect(&ATKRect))
                            {
                                SDL_Texture* ATK1 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/atk1.png");
                                if (Summon)
                                    WINDOW.Draw(ATK1, &ATKRect);
                                SDL_DestroyTexture(ATK1);

                                if (CURSOR_INPUT == TypeInputCursor::LEFT_CURSOR)
                                {
                                    CURSOR_INPUT == TypeInputCursor::WAIT_CURSOR;
                                    if (NumMonsterInField < 5)
                                    {
                                        for (int j = NumMonsterInField; j < 5; j++)
                                        {
                                            if (!InHand.empty())
                                            {
                                                InField[NumMonsterInField] = InHand[i];
                                                InHand.erase(InHand.begin() + i);
                                                NumCardInHand--;
                                            }
                                            SDL_Rect TmpRect = HandRect[i];
                                            while (true)
                                            {
                                                RenderStart();
                                                for (int k = 0; k < NumCardInHand; k++)
                                                {

                                                    WINDOW.Draw(InHand[k].IMG, &HandRect[k]);
                                                }
                                                for (int k = 0; k < NumMonsterInField; k++)
                                                {
                                                    if (InField[k].State == 1)
                                                    {
                                                        WINDOW.Draw(InField[k].IMG, &FieldRect[k]);
                                                    }
                                                    else
                                                        WINDOW.DrawEx(InField[k].IMG, &FieldRect[k]);
                                                }
                                                for (int k = 0; k < NumSpellTrapInField; k++)
                                                {
                                                    WINDOW.Draw(InSpell_Trap[k].IMG, &Spell_TrapRect[k]);
                                                }
                                                int dx = DEST_MONSTER_IN_FIELD[j].first - TmpRect.x;
                                                int dy = DEST_MONSTER_IN_FIELD[j].second - TmpRect.y;
                                                float distance = sqrt(dx * dx + dy * dy);

                                                if (distance > 3)
                                                {
                                                    float stepX = dx / (float)distance;
                                                    float stepY = dy / (float)distance;
                                                    TmpRect.x += (int)(stepX * 2);
                                                    TmpRect.y += (int)(stepY * 2);
                                                }
                                                WINDOW.Draw(InField[NumMonsterInField].IMG, &TmpRect);
                                                InField[NumMonsterInField].State = 1;
                                                WINDOW.EndDraw();
                                                if (distance < 3)
                                                {
                                                    break;
                                                }
                                            }
                                            NumMonsterInField++;
                                            Summon = false;
                                            break;
                                        }
                                    }
                                }
                            }
                            else if (CURSOR.IsCursorInRect(&DEFRect) && Summon)
                            {
                                SDL_Texture* DEF1 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/def1.png");
                                if (Summon)
                                    WINDOW.Draw(DEF1, &DEFRect);
                                SDL_DestroyTexture(DEF1);

                                if (CURSOR_INPUT == TypeInputCursor::LEFT_CURSOR)
                                {
                                    CURSOR_INPUT == TypeInputCursor::WAIT_CURSOR;
                                    if (NumMonsterInField < 5)
                                    {
                                        for (int j = NumMonsterInField; j < 5; j++)
                                        {
                                            if (!InHand.empty())
                                            {
                                                InField[NumMonsterInField] = InHand[i];
                                                InHand.erase(InHand.begin() + i);
                                                NumCardInHand--;
                                            }

                                            SDL_Rect TmpRect = HandRect[i];
                                            while (true)
                                            {
                                                RenderStart();
                                                for (int k = 0; k < NumCardInHand; k++)
                                                {

                                                    WINDOW.Draw(InHand[k].IMG, &HandRect[k]);
                                                }

                                                for (int k = 0; k < NumMonsterInField; k++)
                                                {
                                                    if (InField[k].State == 1)
                                                    {
                                                        WINDOW.Draw(InField[k].IMG, &FieldRect[k]);
                                                    }
                                                    else
                                                        WINDOW.DrawEx(InField[k].IMG, &FieldRect[k]);
                                                }
                                                for (int k = 0; k < NumSpellTrapInField; k++)
                                                {
                                                    WINDOW.Draw(InSpell_Trap[k].IMG, &Spell_TrapRect[k]);
                                                }
                                                int dx = DEST_MONSTER_IN_FIELD[j].first - TmpRect.x;
                                                int dy = DEST_MONSTER_IN_FIELD[j].second - TmpRect.y;
                                                float distance = sqrt(dx * dx + dy * dy);

                                                if (distance > 3)
                                                {
                                                    float stepX = dx / (float)distance;
                                                    float stepY = dy / (float)distance;
                                                    TmpRect.x += (int)(stepX * 2);
                                                    TmpRect.y += (int)(stepY * 2);
                                                }
                                                WINDOW.Draw(InField[NumMonsterInField].IMG, &TmpRect);
                                                InField[NumMonsterInField].State = 2;
                                                WINDOW.EndDraw();
                                                if (distance < 3)
                                                {
                                                    break;
                                                }
                                            }
                                            NumMonsterInField++;
                                            Summon = false;
                                            break;
                                        }
                                    }
                                }
                            }
                            WINDOW.EndDraw();
                            SDL_DestroyTexture(ATK);
                            SDL_DestroyTexture(DEF);
                        }
                        else if (InHand[i].NS > 4)
                        {
                            SDL_Texture* ATK = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/atk.png");
                            SDL_Texture* DEF = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/def.png");

                            SDL_Rect ATKRect = { HandRect[i].x, HandRect[i].y + 120, HandRect[i].w, 30 };
                            SDL_Rect DEFRect = { HandRect[i].x, HandRect[i].y + 150, HandRect[i].w, 30 };
                            if (Summon)
                            {
                                WINDOW.Draw(ATK, &ATKRect);
                                WINDOW.Draw(DEF, &DEFRect);
                            }
                            if (CURSOR.IsCursorInRect(&ATKRect))
                            {
                                SDL_Texture* ATK1 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/atk1.png");
                                if (Summon)
                                    WINDOW.Draw(ATK1, &ATKRect);
                                SDL_DestroyTexture(ATK1);

                                if (CURSOR_INPUT == TypeInputCursor::LEFT_CURSOR)
                                {
                                    CURSOR_INPUT == TypeInputCursor::WAIT_CURSOR;
                                    for (int j = 0; j < NumMonsterInField; i++)
                                    {
                                        if (NumMonsterInField >= 1)
                                        {
                                            InField.erase(InField.begin() + j);
                                            InField[j] = InHand[i];
                                            InHand.erase(InHand.begin() + i);
                                            NumCardInHand--;
                                            break;
                                        }
                                    }
                                }
                            }
                            else if (CURSOR.IsCursorInRect(&DEFRect) && Summon)
                            {
                                SDL_Texture* DEF1 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/def1.png");
                                if (Summon)
                                    WINDOW.Draw(DEF1, &DEFRect);
                                SDL_DestroyTexture(DEF1);

                                if (CURSOR_INPUT == TypeInputCursor::LEFT_CURSOR)
                                {
                                    CURSOR_INPUT == TypeInputCursor::WAIT_CURSOR;
                                    for (int j = 0; j < NumMonsterInField; i++)
                                    {
                                        if (NumMonsterInField >= 1)
                                        {
                                            InField.erase(InField.begin() + j);
                                            InField[j] = InHand[i];
                                            InField[j].State = 2;
                                            InHand.erase(InHand.begin() + i);
                                            NumCardInHand--;
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                        else if (InHand[i].NS < 0)
                        {
                            SDL_Texture* UP = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/up.png");
                            SDL_Rect UPRect = { HandRect[i].x, HandRect[i].y + 120, HandRect[i].w, 60 };

                            WINDOW.Draw(UP, &UPRect);

                            if (CURSOR.IsCursorInRect(&UPRect))
                            {
                                SDL_Texture* UP1 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/up1.png");
                                if (MyTurn)
                                    WINDOW.Draw(UP1, &UPRect);
                                SDL_DestroyTexture(UP1);
                                if (CURSOR_INPUT == TypeInputCursor::LEFT_CURSOR)
                                {
                                    CURSOR_INPUT == TypeInputCursor::WAIT_CURSOR;
                                    if (NumSpellTrapInField < 5)
                                    {
                                        for (int j = NumSpellTrapInField; j < 5; j++)
                                        {
                                            if (!InHand.empty())
                                            {
                                                InSpell_Trap[NumSpellTrapInField] = InHand[i];
                                                InHand.erase(InHand.begin() + i);
                                                NumCardInHand--;
                                            }
                                            SDL_Rect TmpRect = HandRect[i];
                                            while (true)
                                            {
                                                RenderStart();
                                                for (int k = 0; k < NumCardInHand; k++)
                                                {
                                                    WINDOW.Draw(InHand[k].IMG, &HandRect[k]);

                                                    for (int k = 0; k < NumMonsterInField; k++)
                                                    {
                                                        if (InField[k].State == 1)
                                                        {
                                                            WINDOW.Draw(InField[k].IMG, &FieldRect[k]);
                                                        }
                                                        else
                                                            WINDOW.DrawEx(InField[k].IMG, &FieldRect[k]);
                                                    }
                                                    for (int k = 0; k < NumSpellTrapInField; k++)
                                                    {
                                                        WINDOW.Draw(InSpell_Trap[k].IMG, &Spell_TrapRect[k]);
                                                    }
                                                }
                                                int dx = DEST_SPELL_TRAP_IN_FIELD[j].first - TmpRect.x;
                                                int dy = DEST_SPELL_TRAP_IN_FIELD[j].second - TmpRect.y;
                                                float distance = sqrt(dx * dx + dy * dy);

                                                if (distance > 3)
                                                {
                                                    float stepX = dx / (float)distance;
                                                    float stepY = dy / (float)distance;
                                                    TmpRect.x += (int)(stepX * 2);
                                                    TmpRect.y += (int)(stepY * 2);
                                                }
                                                WINDOW.Draw(InSpell_Trap[NumSpellTrapInField].IMG, &TmpRect);
                                                WINDOW.EndDraw();

                                                if (distance < 3)
                                                {
                                                    NumSpellTrapInField++;
                                                    break;
                                                }
                                            }

                                            for (int k = 140; k >= 65; k -= 6)
                                            {
                                                RenderStart();
                                                for (int h = 0; h < NumCardInHand; h++)
                                                {
                                                    WINDOW.Draw(InHand[h].IMG, &HandRect[h]);
                                                }

                                                for (int h = 0; h < NumMonsterInField; h++)
                                                {
                                                    if (InField[h].State == 1)
                                                    {
                                                        WINDOW.Draw(InField[h].IMG, &FieldRect[h]);
                                                    }
                                                    else
                                                        WINDOW.DrawEx(InField[h].IMG, &FieldRect[h]);
                                                }
                                                for (int h = 0; h < NumSpellTrapInField; h++)
                                                {
                                                    WINDOW.Draw(InSpell_Trap[h].IMG, &Spell_TrapRect[h]);
                                                }
                                                TmpRect.w = k;
                                                TmpRect.h = (int)((float)k / 140 * 180);
                                                TmpRect.x = (int)((float)DEST_SPELL_TRAP_IN_FIELD1[j].first - k / 2);
                                                TmpRect.y = (int)((float)DEST_SPELL_TRAP_IN_FIELD1[j].second - (float)TmpRect.h / 2);
                                                WINDOW.Draw(InSpell_Trap[i].IMG, &TmpRect);
                                                WINDOW.EndDraw();
                                                Spell_TrapRect[j] = TmpRect;
                                                SDL_Delay(20);
                                            }
                                            break;
                                        }
                                    }
                                }
                            }
                            WINDOW.EndDraw();
                            SDL_DestroyTexture(UP);
                        }
                    }
                }
            }

            SDL_Texture* EndTurn = IMG_LoadTexture(WINDOW.GetRenderer(), "images/ketthuc.png");
            SDL_Rect EndTurnRect;
            SDL_QueryTexture(EndTurn, NULL, NULL, &EndTurnRect.w, &EndTurnRect.h);
            EndTurnRect.x = 1320;
            EndTurnRect.y = 586;
            WINDOW.Draw(EndTurn, &EndTurnRect);
            SDL_DestroyTexture(EndTurn);

            // if(!IsAttack)

            if (CURSOR.IsCursorInRect(&EndTurnRect))
            {
                if (CURSOR_INPUT == TypeInputCursor::LEFT_CURSOR)
                {
                    MyTurn = false;
                    Turn = TurnPlayer::P2Play;
                    CURSOR_INPUT == TypeInputCursor::WAIT_CURSOR;
                    NewTurn = true;
                    IsDrawed = false;
                    IsAttack = false;
                    EnemyTurn++;
                }
            }
        }
        if (Turn == TurnPlayer::P2Play)
        {
            SDL_Texture* thu = IMG_LoadTexture(WINDOW.GetRenderer(), "images/thu.png");
            SDL_Rect thuRect;
            SDL_QueryTexture(thu, NULL, NULL, &thuRect.w, &thuRect.h);
            thuRect.x = 1320;
            thuRect.y = 586;
            WINDOW.Draw(thu, &thuRect);
            SDL_DestroyTexture(thu);
            NewTurn = true;
            MyTurn = true;
            Summon = true;
            if (EnemyTurn == 1)
            {
                for (int i = 0; i <= 1; i++)
                {
                    if (i == 0)
                    {
                        SDL_Rect ETurn;
                        for (int j = 0; j <= 100; j += 10)
                        {
                            ETurn.w = j;
                            ETurn.h = (int)((float)j / 100 * 140);
                            ETurn.x = (int)((float)1250 - j / 2);
                            ETurn.y = (int)((float)330 - (float)ETurn.h / 2);
                            WINDOW.Draw(EnemyHand[i].IMG, &ETurn);
                            WINDOW.EndDraw();
                            SDL_Delay(10);
                        }

                        while (true)
                        {
                            RenderStart();
                            for (int k = 0; k < NumCardInHand; k++)
                            {
                                WINDOW.Draw(InHand[k].IMG, &HandRect[k]);
                            }
                            for (int k = 0; k < NumMonsterInField; k++)
                            {
                                if (InField[k].State == 1)
                                {
                                    WINDOW.Draw(InField[k].IMG, &FieldRect[k]);
                                }
                                else
                                    WINDOW.DrawEx(InField[k].IMG, &FieldRect[k]);
                            }
                            for (int k = 0; k < NumSpellTrapInField; k++)
                            {
                                WINDOW.Draw(InSpell_Trap[k].IMG, &Spell_TrapRect[k]);
                            }
                            int dx = GraveYardRect.x - ETurn.x;
                            int dy = GraveYardRect.y - ETurn.y;
                            float distance = sqrt(dx * dx + dy * dy);

                            if (distance > 3)
                            {
                                float stepX = dx / (float)distance;
                                float stepY = dy / (float)distance;
                                ETurn.x += (int)(stepX * 2);
                                ETurn.y += (int)(stepY * 2);
                            }
                            WINDOW.Draw(EnemyHand[0].IMG, &ETurn);

                            WINDOW.EndDraw();
                            if (distance < 3)
                            {
                                break;
                            }
                        }
                        while (true)
                        {

                            RenderStart();
                            if (IsE0InGraveYard)
                                WINDOW.Draw(EnemyHand[0].IMG, &GraveYardRect);
                            for (int i = 0; i < NumCardInHand; i++)
                            {
                                WINDOW.Draw(InHand[i].IMG, &HandRect[i]);
                            }
                            for (int i = 0; i < NumMonsterInField; i++)
                            {
                                WINDOW.Draw(InField[i].IMG, &FieldRect[i]);
                            }
                            for (int i = 0; i < NumSpellTrapInField; i++)
                            {
                                WINDOW.Draw(InSpell_Trap[i].IMG, &Spell_TrapRect[i]);
                            }
                            clipRect1.x = (frame1 % COLUMNS1) * SPRITE_WIDTH1;
                            clipRect1.y = (frame1 / COLUMNS1) * SPRITE_HEIGHT1;
                            clipRect1.w = SPRITE_WIDTH1;
                            clipRect1.h = SPRITE_HEIGHT1;
                            rect.x = 170;
                            rect.y = 810 - 450;
                            rect.w = SPRITE_WIDTH1;
                            rect.h = SPRITE_HEIGHT1;
                            WINDOW.DrawFull(Spell1, &clipRect1, &rect);
                            WINDOW.EndDraw();
                            frame1++;
                            if (frame1 == 23)
                            {
                                frame1 = 0;
                                MyBlood -= 500;
                                break;
                            }
                            SDL_Delay(30);
                        }
                        SDL_Rect ETurn1;
                        for (int j = 0; j <= 100; j += 10)
                        {
                            ETurn1.w = j;
                            ETurn1.h = (int)((float)j / 100 * 140);
                            ETurn1.x = (int)((float)1250 - j / 2);
                            ETurn1.y = (int)((float)330 - (float)ETurn1.h / 2);
                            WINDOW.Draw(EnemyHand[i].IMG, &ETurn1);
                            WINDOW.EndDraw();
                            SDL_Delay(10);
                        }

                        while (true)
                        {
                            RenderStart();
                            for (int k = 0; k < NumCardInHand; k++)
                            {
                                WINDOW.Draw(InHand[k].IMG, &HandRect[k]);
                            }
                            for (int k = 0; k < NumMonsterInField; k++)
                            {
                                if (InField[k].State == 1)
                                {
                                    WINDOW.Draw(InField[k].IMG, &FieldRect[k]);
                                }
                                else
                                    WINDOW.DrawEx(InField[k].IMG, &FieldRect[k]);
                            }
                            for (int k = 0; k < NumSpellTrapInField; k++)
                            {
                                WINDOW.Draw(InSpell_Trap[k].IMG, &Spell_TrapRect[k]);
                            }
                            int dx = GraveYardRect.x - ETurn1.x;
                            int dy = GraveYardRect.y - ETurn1.y;
                            float distance = sqrt(dx * dx + dy * dy);

                            if (distance > 3)
                            {
                                float stepX = dx / (float)distance;
                                float stepY = dy / (float)distance;
                                ETurn1.x += (int)(stepX * 2);
                                ETurn1.y += (int)(stepY * 2);
                            }
                            WINDOW.Draw(EnemyHand[0].IMG, &ETurn1);

                            WINDOW.EndDraw();
                            if (distance < 3)
                            {
                                break;
                            }
                        }
                        while (true)
                        {

                            RenderStart();
                            if (IsE0InGraveYard)
                                WINDOW.Draw(EnemyHand[0].IMG, &GraveYardRect);
                            for (int i = 0; i < NumCardInHand; i++)
                            {
                                WINDOW.Draw(InHand[i].IMG, &HandRect[i]);
                            }
                            for (int i = 0; i < NumMonsterInField; i++)
                            {
                                WINDOW.Draw(InField[i].IMG, &FieldRect[i]);
                            }
                            for (int i = 0; i < NumSpellTrapInField; i++)
                            {
                                WINDOW.Draw(InSpell_Trap[i].IMG, &Spell_TrapRect[i]);
                            }
                            clipRect1.x = (frame1 % COLUMNS1) * SPRITE_WIDTH1;
                            clipRect1.y = (frame1 / COLUMNS1) * SPRITE_HEIGHT1;
                            clipRect1.w = SPRITE_WIDTH1;
                            clipRect1.h = SPRITE_HEIGHT1;
                            rect.x = 170;
                            rect.y = 810 - 450;
                            rect.w = SPRITE_WIDTH1;
                            rect.h = SPRITE_HEIGHT1;
                            WINDOW.DrawFull(Spell1, &clipRect1, &rect);
                            WINDOW.EndDraw();
                            frame1++;
                            if (frame1 == 23)
                            {
                                frame1 = 0;
                                MyBlood -= 500;
                                break;
                            }
                            SDL_Delay(30);
                        }
                        IsE0InGraveYard = true;
                    }
                    else if (i == 1)
                    {

                        for (int j = NumMonsterInFieldEnemy; j < 5; j++)
                        {
                            if (!EnemyHand.empty())
                            {
                                InFieldEnemy[NumMonsterInFieldEnemy] = EnemyHand[2];
                                EnemyHand.erase(EnemyHand.begin() + 2);
                                NumCardInHandEnemy--;
                            }
                            SDL_Rect TmpRect = EnemyHandRect;
                            while (true)
                            {
                                RenderStart();
                                for (int k = 0; k < NumCardInHand; k++)
                                {
                                    WINDOW.Draw(InHand[k].IMG, &HandRect[k]);
                                }
                                for (int k = 0; k < NumMonsterInField; k++)
                                {
                                    if (InField[k].State == 1)
                                    {
                                        WINDOW.Draw(InField[k].IMG, &FieldRect[k]);
                                    }
                                    else
                                        WINDOW.DrawEx(InField[k].IMG, &FieldRect[k]);
                                }
                                for (int k = 0; k < NumSpellTrapInField; k++)
                                {
                                    WINDOW.Draw(InSpell_Trap[k].IMG, &Spell_TrapRect[k]);
                                }

                                for (int k = 0; k < NumMonsterInFieldEnemy; k++)
                                {
                                    if (InFieldEnemy[k].State == 1)
                                    {
                                        WINDOW.Draw(InFieldEnemy[k].IMG, &EnemyFieldRect[k]);
                                    }
                                    else
                                        WINDOW.DrawEx(InFieldEnemy[k].IMG, &EnemyFieldRect[k]);
                                }

                                int dx = DEST_MONSTER_IN_FIELDENEMY[0].first - TmpRect.x;
                                int dy = DEST_MONSTER_IN_FIELDENEMY[0].second - TmpRect.y;
                                float distance = sqrt(dx * dx + dy * dy);

                                if (distance > 3)
                                {
                                    float stepX = dx / (float)distance;
                                    float stepY = dy / (float)distance;
                                    TmpRect.x += (int)(stepX * 2);
                                    TmpRect.y += (int)(stepY * 2);
                                }
                                WINDOW.Draw(InFieldEnemy[NumMonsterInFieldEnemy].IMG, &TmpRect);

                                WINDOW.EndDraw();
                                if (distance < 3)
                                {
                                    break;
                                }
                            }
                            NumMonsterInFieldEnemy++;
                            break;
                        }
                    }
                }
                if (!NumMonsterInField)
                {
                    if (InFieldEnemy[0].State == 1)
                    {
                        SDL_Rect r = { 620, 500, 140, 180 };
                        moveAndRotateTexture(InFieldEnemy[0].IMG, EnemyFieldRect[0], r);
                        MyBlood -= 900;
                    }
                }

                for (int i = 0; i < NumMonsterInField; i++)
                {
                    if (InFieldEnemy[0].State == 1)
                    {
                        if (InFieldEnemy[0].ATK > InField[i].ATK && InField[i].State == 1)
                        {
                            moveAndRotateTexture(InFieldEnemy[0].IMG, EnemyFieldRect[0], FieldRect[i]);
                            NumMonsterInField--;
                            MyBlood -= (InFieldEnemy[0].ATK - InField[i].ATK);
                            InField.erase(InField.begin() + i);
                        }
                        else if (InFieldEnemy[0].ATK > InField[i].DEF && InField[i].State == 2)
                        {
                            moveAndRotateTexture(InFieldEnemy[0].IMG, EnemyFieldRect[0], FieldRect[i]);
                            NumMonsterInField--;
                            InField.erase(InField.begin() + i);
                        }
                    }
                }
                WINDOW.Draw(InFieldEnemy[0].IMG, &EnemyFieldRect[0]);
                WINDOW.Draw(EnemyHand[0].IMG, &GraveYardRect);
            }
            else if (EnemyTurn == 2)
            {
                for (int j = NumMonsterInFieldEnemy; j < 5; j++)
                {
                    if (!EnemyHand.empty())
                    {
                        InFieldEnemy[NumMonsterInFieldEnemy] = EnemyHand[2];
                        EnemyHand.erase(EnemyHand.begin() + 2);
                        NumCardInHandEnemy--;
                    }
                    SDL_Rect TmpRect = EnemyHandRect;
                    while (true)
                    {
                        RenderStart();
                        for (int k = 0; k < NumCardInHand; k++)
                        {
                            WINDOW.Draw(InHand[k].IMG, &HandRect[k]);
                        }
                        for (int k = 0; k < NumMonsterInField; k++)
                        {
                            if (InField[k].State == 1)
                            {
                                WINDOW.Draw(InField[k].IMG, &FieldRect[k]);
                            }
                            else
                                WINDOW.DrawEx(InField[k].IMG, &FieldRect[k]);
                        }
                        for (int k = 0; k < NumSpellTrapInField; k++)
                        {
                            WINDOW.Draw(InSpell_Trap[k].IMG, &Spell_TrapRect[k]);
                        }

                        for (int k = 0; k < NumMonsterInFieldEnemy; k++)
                        {
                            if (InFieldEnemy[k].State == 1)
                            {
                                WINDOW.Draw(InFieldEnemy[k].IMG, &EnemyFieldRect[k]);
                            }
                            else
                                WINDOW.DrawEx(InFieldEnemy[k].IMG, &EnemyFieldRect[k]);
                        }

                        int dx = DEST_MONSTER_IN_FIELDENEMY[1].first - TmpRect.x;
                        int dy = DEST_MONSTER_IN_FIELDENEMY[1].second - TmpRect.y;
                        float distance = sqrt(dx * dx + dy * dy);

                        if (distance > 3)
                        {
                            float stepX = dx / (float)distance;
                            float stepY = dy / (float)distance;
                            TmpRect.x += (int)(stepX * 2);
                            TmpRect.y += (int)(stepY * 2);
                        }

                        WINDOW.Draw(InFieldEnemy[NumMonsterInFieldEnemy].IMG, &TmpRect);

                        WINDOW.EndDraw();
                        if (distance < 3)
                        {
                            break;
                        }
                    }
                    NumMonsterInFieldEnemy++;
                    break;
                }
                for (int k = 0; k < NumMonsterInFieldEnemy; k++)
                {
                    if (InFieldEnemy[k].State == 1)
                    {
                        WINDOW.Draw(InFieldEnemy[k].IMG, &EnemyFieldRect[k]);
                    }
                    else
                        WINDOW.DrawEx(InFieldEnemy[k].IMG, &EnemyFieldRect[k]);
                }
                if (!NumMonsterInField)
                {
                    for (int i = 0; i < NumMonsterInFieldEnemy; i++)
                    {
                        SDL_Rect r = { 620, 500, 140, 180 };
                        moveAndRotateTexture(InFieldEnemy[i].IMG, EnemyFieldRect[i], r);
                        MyBlood -= InFieldEnemy[i].ATK;
                    }
                }
                for (int i = 0; i < NumMonsterInFieldEnemy; i++)
                {
                    for (int j = 0; j < NumMonsterInField; j++)
                    {
                        if (InFieldEnemy[i].State == 1)
                        {
                            if (InFieldEnemy[i].ATK > InField[j].ATK && InField[j].State == 1)
                            {

                                moveAndRotateTexture(InFieldEnemy[i].IMG, EnemyFieldRect[i], FieldRect[j]);
                                MyBlood -= InFieldEnemy[i].ATK - InField[j].ATK;
                                InField.erase(InField.begin() + j);
                                NumMonsterInField--;
                            }
                            else if (InFieldEnemy[i].ATK > InField[j].DEF && InField[j].State == 2)
                            {
                                moveAndRotateTexture(InFieldEnemy[i].IMG, EnemyFieldRect[i], FieldRect[j]);
                                InField.erase(InField.begin() + j);
                                NumMonsterInField--;
                            }
                        }
                    }
                }
            }
            else if (EnemyTurn == 3)
            {
                for (int j = NumMonsterInFieldEnemy; j < 5; j++)
                {
                    if (!EnemyHand.empty())
                    {
                        InFieldEnemy[NumMonsterInFieldEnemy] = EnemyHand[2];
                        EnemyHand.erase(EnemyHand.begin() + 2);
                        NumCardInHandEnemy--;
                    }
                    SDL_Rect TmpRect = EnemyHandRect;
                    while (true)
                    {
                        RenderStart();
                        for (int k = 0; k < NumCardInHand; k++)
                        {
                            WINDOW.Draw(InHand[k].IMG, &HandRect[k]);
                        }
                        for (int k = 0; k < NumMonsterInField; k++)
                        {
                            if (InField[k].State == 1)
                            {
                                WINDOW.Draw(InField[k].IMG, &FieldRect[k]);
                            }
                            else
                                WINDOW.DrawEx(InField[k].IMG, &FieldRect[k]);
                        }
                        for (int k = 0; k < NumSpellTrapInField; k++)
                        {
                            WINDOW.Draw(InSpell_Trap[k].IMG, &Spell_TrapRect[k]);
                        }

                        for (int k = 0; k < NumMonsterInFieldEnemy; k++)
                        {
                            if (InFieldEnemy[k].State == 1)
                            {
                                WINDOW.Draw(InFieldEnemy[k].IMG, &EnemyFieldRect[k]);
                            }
                            else
                                WINDOW.DrawEx(InFieldEnemy[k].IMG, &EnemyFieldRect[k]);
                        }

                        int dx = DEST_MONSTER_IN_FIELDENEMY[2].first - TmpRect.x;
                        int dy = DEST_MONSTER_IN_FIELDENEMY[2].second - TmpRect.y;
                        float distance = sqrt(dx * dx + dy * dy);

                        if (distance > 3)
                        {
                            float stepX = dx / (float)distance;
                            float stepY = dy / (float)distance;
                            TmpRect.x += (int)(stepX * 2);
                            TmpRect.y += (int)(stepY * 2);
                        }

                        WINDOW.Draw(InFieldEnemy[NumMonsterInFieldEnemy].IMG, &TmpRect);

                        WINDOW.EndDraw();
                        if (distance < 3)
                        {
                            break;
                        }
                    }
                    NumMonsterInFieldEnemy++;
                    break;
                }
                for (int k = 0; k < NumMonsterInFieldEnemy; k++)
                {
                    if (InFieldEnemy[k].State == 1)
                    {
                        WINDOW.Draw(InFieldEnemy[k].IMG, &EnemyFieldRect[k]);
                    }
                    else
                        WINDOW.DrawEx(InFieldEnemy[k].IMG, &EnemyFieldRect[k]);
                }
                if (!NumMonsterInField)
                {
                    for (int i = 0; i < NumMonsterInFieldEnemy; i++)
                    {
                        SDL_Rect r = { 620, 500, 140, 180 };
                        moveAndRotateTexture(InFieldEnemy[i].IMG, EnemyFieldRect[i], r);
                        MyBlood -= InFieldEnemy[i].ATK;
                    }
                }
                for (int i = 0; i < NumMonsterInFieldEnemy; i++)
                {
                    for (int j = 0; j < NumMonsterInField; j++)
                    {
                        if (InFieldEnemy[i].State == 1)
                        {
                            if (InFieldEnemy[i].ATK > InField[j].ATK && InField[j].State == 1)
                            {
                                moveAndRotateTexture(InFieldEnemy[i].IMG, EnemyFieldRect[i], FieldRect[j]);
                                MyBlood -= InFieldEnemy[i].ATK - InField[j].ATK;
                                InField.erase(InField.begin() + j);
                                NumMonsterInField--;
                            }
                            else if (InFieldEnemy[i].ATK > InField[j].DEF && InField[j].State == 2)
                            {
                                moveAndRotateTexture(InFieldEnemy[i].IMG, EnemyFieldRect[i], FieldRect[j]);

                                InField.erase(InField.begin() + j);
                                NumMonsterInField--;
                            }
                        }
                    }
                }
            }
            else
            {
                if (!NumMonsterInField)
                {
                    for (int i = 0; i < NumMonsterInFieldEnemy; i++)
                    {
                        SDL_Rect r = { 620, 500, 140, 180 };
                        moveAndRotateTexture(InFieldEnemy[i].IMG, EnemyFieldRect[i], r);
                        MyBlood -= InFieldEnemy[i].ATK;
                    }
                }
                for (int i = 0; i < NumMonsterInFieldEnemy; i++)
                {
                    for (int j = 0; j < NumMonsterInField; j++)
                    {
                        if (InFieldEnemy[i].State == 1)
                        {
                            if (InFieldEnemy[i].State == 1)
                            {
                                if (InFieldEnemy[i].ATK > InField[j].ATK && InField[j].State == 1)
                                {
                                    moveAndRotateTexture(InFieldEnemy[i].IMG, EnemyFieldRect[i], FieldRect[j]);
                                    MyBlood -= InFieldEnemy[i].ATK - InField[j].ATK;
                                    InField.erase(InField.begin() + j);
                                    NumMonsterInField--;
                                }
                                else if (InFieldEnemy[i].ATK > InField[j].DEF && InField[j].State == 2)
                                {
                                    moveAndRotateTexture(InFieldEnemy[i].IMG, EnemyFieldRect[i], FieldRect[j]);

                                    InField.erase(InField.begin() + j);
                                    NumMonsterInField--;
                                }
                            }
                        }
                    }
                }
            }
            Turn = TurnPlayer::P1Play;
        }
        for (int i = 0; i < NumMonsterInFieldEnemy; i++)
        {
            if (InFieldEnemy[i].State == 1)
                WINDOW.Draw(InFieldEnemy[i].IMG, &EnemyFieldRect[i]);
            else
                WINDOW.DrawEx(InFieldEnemy[i].IMG, &EnemyFieldRect[i]);
        }
        if (IsE0InGraveYard)
            WINDOW.Draw(EnemyHand[0].IMG, &GraveYardRect);
        if (MyBlood <= 0)
        {
            WinOrLose = 1;
            while (!IsEnd)
            {
                RenderStart();
                for (int i = 0; i < NumCardInHand; i++)
                {
                    WINDOW.Draw(InHand[i].IMG, &HandRect[i]);
                }
                for (int i = 0; i < NumMonsterInField; i++)
                {
                    if (InField[i].State == 1)
                    {
                        WINDOW.Draw(InField[i].IMG, &FieldRect[i]);
                    }
                    else
                        WINDOW.DrawEx(InField[i].IMG, &FieldRect[i]);
                }
                for (int i = 0; i < NumSpellTrapInField; i++)
                {
                    WINDOW.Draw(InSpell_Trap[i].IMG, &Spell_TrapRect[i]);
                }

                for (int i = 0; i < NumMonsterInFieldEnemy; i++)
                {
                    if (InFieldEnemy[i].State == 1)
                        WINDOW.Draw(InFieldEnemy[i].IMG, &EnemyFieldRect[i]);
                    else
                        WINDOW.DrawEx(InFieldEnemy[i].IMG, &EnemyFieldRect[i]);
                }
                if (IsE0InGraveYard)
                    WINDOW.Draw(EnemyHand[0].IMG, &GraveYardRect);

                clipRect2.x = (frame2 % COLUMNS2) * SPRITE_WIDTH2;
                clipRect2.y = (frame2 / COLUMNS2) * SPRITE_HEIGHT2;
                clipRect2.w = SPRITE_WIDTH2;
                clipRect2.h = SPRITE_HEIGHT2;
                rect2.x = 120;
                rect2.y = 800 - 675;
                rect2.w = SPRITE_WIDTH2;
                rect2.h = SPRITE_HEIGHT2;
                WINDOW.DrawFull(End, &clipRect2, &rect2);
                WINDOW.EndDraw();
                frame2++;
                if (frame2 == 63)
                {
                    frame2 = 0;
                    IsEnd = true;
                    break;
                }
                SDL_Delay(30);
            }
        }
        else if (EnenyBlood <= 0)
        {
            WinOrLose = 2;
            while (!IsEnd)
            {
                RenderStart();
                for (int i = 0; i < NumCardInHand; i++)
                {
                    WINDOW.Draw(InHand[i].IMG, &HandRect[i]);
                }
                for (int i = 0; i < NumMonsterInField; i++)
                {
                    if (InField[i].State == 1)
                    {
                        WINDOW.Draw(InField[i].IMG, &FieldRect[i]);
                    }
                    else
                        WINDOW.DrawEx(InField[i].IMG, &FieldRect[i]);
                }
                for (int i = 0; i < NumSpellTrapInField; i++)
                {
                    WINDOW.Draw(InSpell_Trap[i].IMG, &Spell_TrapRect[i]);
                }

                for (int i = 0; i < NumMonsterInFieldEnemy; i++)
                {
                    if (InFieldEnemy[i].State == 1)
                        WINDOW.Draw(InFieldEnemy[i].IMG, &EnemyFieldRect[i]);
                    else
                        WINDOW.DrawEx(InFieldEnemy[i].IMG, &EnemyFieldRect[i]);
                }
                if (IsE0InGraveYard)
                    WINDOW.Draw(EnemyHand[0].IMG, &GraveYardRect);

                clipRect2.x = (frame2 % COLUMNS2) * SPRITE_WIDTH2;
                clipRect2.y = (frame2 / COLUMNS2) * SPRITE_HEIGHT2;
                clipRect2.w = SPRITE_WIDTH2;
                clipRect2.h = SPRITE_HEIGHT2;
                rect2.x = 120;
                rect2.y = 20;
                rect2.w = SPRITE_WIDTH2;
                rect2.h = SPRITE_HEIGHT2;
                WINDOW.DrawFull(End, &clipRect2, &rect2);
                WINDOW.EndDraw();
                frame2++;
                if (frame2 == 63)
                {
                    frame2 = 0;
                    IsEnd = true;
                    break;
                }
                SDL_Delay(30);
            }
        }

        if (WinOrLose == 1 || WinOrLose == 2)
        {
            WINDOW.RendererClear();
            RenderStart();
            NumCardInHand = 0;
            NumMonsterInField = 0;
            NumMonsterInFieldEnemy = 0;
            NumSpellTrapInField = 0;
            SDL_Rect src = { 120, 200, 1200, 546 };
            if (WinOrLose == 2)
                WINDOW.Draw(Win, &src);
            else WINDOW.Draw(Loss, &src);
            SDL_Rect Back = { 638, 680, 150, 70 };
            if (CURSOR.IsCursorInRect(&Back))
            {
                SDL_Texture* BackChoose = IMG_LoadTexture(WINDOW.GetRenderer(), "images/back.png");
                WINDOW.Draw(BackChoose, &Back);
                SDL_DestroyTexture(BackChoose);
                if (CURSOR_INPUT == TypeInputCursor::LEFT_CURSOR)
                {
                    CURSOR_INPUT = TypeInputCursor::WAIT_CURSOR;
                    WinOrLose = 0;
                    IsEnd = false;
                    MyBlood = 8000;
                    EnenyBlood = 8000;
                    WINDOW.Destroy();
                    HandleInput();
                    return;
                }
            }
        }
        WINDOW.EndDraw();
    }
}
StateMenu Game::GetStateGame()
{
    return STATE;
}