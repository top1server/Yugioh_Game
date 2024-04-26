#include "MenuGame.h"

MenuGame::MenuGame()
{

}
MenuGame::~MenuGame()
{
    Cleanup1();
}

void MenuGame::RunCursorAndMusicAndSound1()
{
    // Creat window and icon game
    gWindowGameMenu1.SetUp("MAGIC DUEL", SCREEN_WIDTH, SCREEN_HEIGHT);
    SDL_Surface* iconSurface = IMG_Load("images/icon/icon1.png");
    SDL_SetWindowIcon(gWindowGameMenu1.GetWindow(), iconSurface);

    // Load music menu
    gMusicMenu.SetMusic("musics//MenuMusic.wav");
    gMusicMenu.SetRepeat();
    gMusicMenu.Play();

    // Load cursor click sound
    gSoundMenu.SetSoundBuffer("musics//ClickCursor.mp3");
    gSoundMenu.ChangeVolumeSound(45);

    // Cursor
    gCursorMenu.SetImageDefault("images/mouse/mouse1.png");
    gCursorMenu.DrawCursorDefault();
    gCursorMenu.SetImageCustom("images/mouse/cursor1.png");
}

void MenuGame::RunCursorAndMusicAndSound2()
{
    gWindowGameMenu2.SetUp("MAGIC DUEL", SCREEN_WIDTH, SCREEN_HEIGHT);
    SDL_Surface* iconSurface = IMG_Load("images/icon/icon1.png");
    SDL_SetWindowIcon(gWindowGameMenu2.GetWindow(), iconSurface);

    // Load music menu
    gMusicMenu.SetMusic("musics/choosemode.mp3");
    gMusicMenu.SetRepeat();
    gMusicMenu.Play();

    // Load cursor click sound
    gSoundMenu.SetSoundBuffer("musics/sound.mp3");
    gSoundMenu.ChangeVolumeSound(45);

    // Cursor
    gCursorMenu.SetImageDefault("images/mouse/mouse1.png");
    gCursorMenu.DrawCursorDefault();
    gCursorMenu.SetImageCustom("images/mouse/cursor1.png");
}

void MenuGame::RunCursorAndMusicAndSound3()
{
    // Creat window and icon game
    gWindowGameMenu3.SetUp("MAGIC DUEL", SCREEN_WIDTH, SCREEN_HEIGHT);
    SDL_Surface* iconSurface = IMG_Load("images/icon/icon1.png");
    SDL_SetWindowIcon(gWindowGameMenu3.GetWindow(), iconSurface);

    // Load music menu
    gMusicMenu.SetMusic("musics//cardlist.mp3");
    gMusicMenu.SetRepeat();
    gMusicMenu.Play();

    // Load cursor click sound
    gSoundMenu.SetSoundBuffer("musics//ClickCursor.mp3");
    gSoundMenu.ChangeVolumeSound(45);

    // Cursor
    gCursorMenu.SetImageDefault("images/mouse/mouse1.png");
    gCursorMenu.DrawCursorDefault();
    gCursorMenu.SetImageCustom("images/mouse/cursor1.png");
}

void MenuGame::RunCursorAndMusicAndSound4()
{
    // Creat window and icon game
    gWindowGameMenu4.SetUp("MAGIC DUEL", SCREEN_WIDTH, SCREEN_HEIGHT);
    SDL_Surface* iconSurface = IMG_Load("images/icon/icon1.png");
    SDL_SetWindowIcon(gWindowGameMenu3.GetWindow(), iconSurface);

    // Load music menu
    gMusicMenu.SetMusic("musics/1.mp3");
    gMusicMenu.SetRepeat();
    gMusicMenu.Play();

    // Load cursor click sound
    gSoundMenu.SetSoundBuffer("musics//ClickCursor.mp3");
    gSoundMenu.ChangeVolumeSound(45);

    // Cursor
    gCursorMenu.SetImageDefault("images/mouse/mouse1.png");
    gCursorMenu.DrawCursorDefault();
    gCursorMenu.SetImageCustom("images/mouse/cursor1.png");
}

StateMenu MenuGame::InitiationMenuState()
{
    gVolumeMenu.Sound = 70;
    gVolumeMenu.Music = 40;
    gStateGameMenu = StateMenu::WAIT;

    RunCursorAndMusicAndSound1();
    SDL_Texture* gWallPaper = IMG_LoadTexture(gWindowGameMenu1.GetRenderer(), "images/menu/WALLPAPER.jpg");
    SDL_Texture* gGameName = IMG_LoadTexture(gWindowGameMenu1.GetRenderer(),"images/menu/GAMENAME.png");
    SDL_Texture* gDuelMode = IMG_LoadTexture(gWindowGameMenu1.GetRenderer(),"images/menu/DUELMODE.png");
    SDL_Texture* gDeckContruction = IMG_LoadTexture(gWindowGameMenu1.GetRenderer(),"images/menu/DECKCONTRUCTION.png");
    SDL_Texture* gOption = IMG_LoadTexture(gWindowGameMenu1.GetRenderer(),"images/menu/OPTION.png");
    SDL_Texture* gCardList = IMG_LoadTexture(gWindowGameMenu1.GetRenderer(),"images/menu/CARDLIST.png");
    SDL_Texture* gQuitGame = IMG_LoadTexture(gWindowGameMenu1.GetRenderer(),"images/menu/QUITGAME.png");

    SDL_Rect WallPaperRect, DuelModeRect, GameNameRect, OptionRect, DeckContructionRect, CardListRect, QuitGameRect;
    SDL_QueryTexture(gWallPaper, NULL, NULL, &WallPaperRect.w, &WallPaperRect.h);
    SDL_QueryTexture(gGameName, NULL, NULL, &GameNameRect.w, &GameNameRect.h);
    SDL_QueryTexture(gDuelMode, NULL, NULL, &DuelModeRect.w, &DuelModeRect.h);
    SDL_QueryTexture(gOption, NULL, NULL, &OptionRect.w, &OptionRect.h);
    SDL_QueryTexture(gCardList, NULL, NULL, &CardListRect.w, &CardListRect.h);
    SDL_QueryTexture(gDeckContruction, NULL, NULL, &DeckContructionRect.w, &DeckContructionRect.h);
    SDL_QueryTexture(gQuitGame, NULL, NULL, &QuitGameRect.w, &QuitGameRect.h);

    WallPaperRect.x = 0;
    WallPaperRect.y = 0;

    GameNameRect.x = (1440 - GameNameRect.w) / 2;
    GameNameRect.y = 50;

    DuelModeRect.x = (1440 - DuelModeRect.w) / 2;
    DuelModeRect.y = 300;

    DeckContructionRect.x = (1440 - DeckContructionRect.w) / 2;
    DeckContructionRect.y = 380;

    CardListRect.x = (1440 - CardListRect.w) / 2;
    CardListRect.y = 460;

    OptionRect.x = (1440 - CardListRect.w) / 2;
    OptionRect.y = 540;

    QuitGameRect.x = (1440 - QuitGameRect.w) / 2;
    QuitGameRect.y = 620;
    int isChangedCursor = 0;
    SDL_Event e;

    while (gWindowGameMenu1.IsDone())
    {
        while (SDL_PollEvent(&e) != 0)
        {
            gWindowGameMenu1.RendererClear();
            gWindowGameMenu1.Draw(gWallPaper, &WallPaperRect);
            gWindowGameMenu1.Draw(gGameName, &GameNameRect);
            gWindowGameMenu1.Draw(gDuelMode, &DuelModeRect);
            gWindowGameMenu1.Draw(gDeckContruction, &DeckContructionRect);
            gWindowGameMenu1.Draw(gCardList, &CardListRect);
            gWindowGameMenu1.Draw(gOption, &OptionRect);
            gWindowGameMenu1.Draw(gQuitGame, &QuitGameRect);

            if (e.type == SDL_QUIT)
            {
                gWindowGameMenu1.~WindowGame();
                gMusicMenu.~MusicGame();
                gSoundMenu.~SoundGame();
            }
            if (gCursorMenu.IsCursorInRect(&DuelModeRect) == SDL_TRUE)
            {
                // Draw
                if (!isChangedCursor || isChangedCursor == 2 || isChangedCursor == 3 || isChangedCursor == 4 || isChangedCursor == 5)
                {
                    gCursorMenu.CleanCursorDefault();
                    gCursorMenu.SetImageCustom("images/mouse/cursor1.png");
                    gCursorMenu.DrawCursorCustom();
                    isChangedCursor = 1;
                }
                SDL_Texture* gDuelModeBig = IMG_LoadTexture(gWindowGameMenu1.GetRenderer(), "images/menu/DUELMODE_BIG.png");
                SDL_Rect DuelModeBigRect;
                SDL_QueryTexture(gDuelModeBig, NULL, NULL, &DuelModeBigRect.w, &DuelModeBigRect.h);
                DuelModeBigRect.x = (1440 - DuelModeBigRect.w) / 2;
                DuelModeBigRect.y = 300;
                gWindowGameMenu1.Draw(gDuelModeBig, &DuelModeBigRect);
                SDL_DestroyTexture(gDuelModeBig);

                if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT)
                {

                    //gTypeInput = TypeInputCursor::WAIT_CURSOR;
                    Cleanup1();
                    SDL_DestroyTexture(gWallPaper);
                    SDL_DestroyTexture(gGameName);
                    SDL_DestroyTexture(gDuelMode);
                    SDL_DestroyTexture(gDeckContruction);
                    SDL_DestroyTexture(gCardList);
                    SDL_DestroyTexture(gOption);
                    SDL_DestroyTexture(gQuitGame);
                    return StateMenu::DUEL_MODE;
                }
            }

            else if (gCursorMenu.IsCursorInRect(&DeckContructionRect) == SDL_TRUE)
            {
                if (!isChangedCursor || isChangedCursor == 1 || isChangedCursor == 3 || isChangedCursor == 4 || isChangedCursor == 5)
                {
                    gCursorMenu.CleanCursorDefault();
                    gCursorMenu.SetImageCustom("images/mouse/cursor1.png");
                    gCursorMenu.DrawCursorCustom();
                    isChangedCursor = 2;
                }

                SDL_Texture* gDeckContructionBig = IMG_LoadTexture(gWindowGameMenu1.GetRenderer(), "images/menu/DECKCONTRUCTION_BIG.png");
                SDL_Rect DeckContructionBigRect;
                SDL_QueryTexture(gDeckContructionBig, NULL, NULL, &DeckContructionBigRect.w, &DeckContructionBigRect.h);
                DeckContructionBigRect.x = (1440 - DeckContructionBigRect.w) / 2;
                DeckContructionBigRect.y = 380;
                gWindowGameMenu1.Draw(gDeckContructionBig, &DeckContructionBigRect);
                SDL_DestroyTexture(gDeckContructionBig);

                if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT)
                {
                    //gTypeInput = TypeInputCursor::WAIT_CURSOR;
                    Cleanup1();
                    SDL_DestroyTexture(gWallPaper);
                    SDL_DestroyTexture(gGameName);
                    SDL_DestroyTexture(gDuelMode);
                    SDL_DestroyTexture(gDeckContruction);
                    SDL_DestroyTexture(gCardList);
                    SDL_DestroyTexture(gOption);
                    SDL_DestroyTexture(gQuitGame);
                    return StateMenu::DECK_CONSTRUCTION;
                }
            }

            else if (gCursorMenu.IsCursorInRect(&CardListRect) == SDL_TRUE)
            {
                if (!isChangedCursor || isChangedCursor == 1 || isChangedCursor == 2 || isChangedCursor == 4 || isChangedCursor == 5)
                {
                    gCursorMenu.CleanCursorDefault();
                    gCursorMenu.SetImageCustom("images/mouse/cursor1.png");
                    gCursorMenu.DrawCursorCustom();
                    isChangedCursor = 3;
                }
                SDL_Texture* gCardListBig = IMG_LoadTexture(gWindowGameMenu1.GetRenderer(), "images/menu/CARDLIST_BIG.png");
                SDL_Rect CardListBigRect;
                SDL_QueryTexture(gCardListBig, NULL, NULL, &CardListBigRect.w, &CardListBigRect.h);
                CardListBigRect.x = (1440 - CardListBigRect.w) / 2;
                CardListBigRect.y = 460;
                gWindowGameMenu1.Draw(gCardListBig, &CardListBigRect);
                SDL_DestroyTexture(gCardListBig);
                if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT)
                {
                    //gTypeInput = TypeInputCursor::WAIT_CURSOR;
                    Cleanup1();
                    SDL_DestroyTexture(gWallPaper);
                    SDL_DestroyTexture(gGameName);
                    SDL_DestroyTexture(gDuelMode);
                    SDL_DestroyTexture(gDeckContruction);
                    SDL_DestroyTexture(gCardList);
                    SDL_DestroyTexture(gOption);
                    SDL_DestroyTexture(gQuitGame);
                    return StateMenu::CARD_LIST;
                }
            }

            else if (gCursorMenu.IsCursorInRect(&OptionRect) == SDL_TRUE)
            {
                if (!isChangedCursor || isChangedCursor == 1 || isChangedCursor == 2 || isChangedCursor == 3 || isChangedCursor == 5)
                {
                    gCursorMenu.CleanCursorDefault();
                    gCursorMenu.SetImageCustom("images/mouse/cursor1.png");
                    gCursorMenu.DrawCursorCustom();
                    isChangedCursor = 4;
                }
                SDL_Texture* gOptionBig = IMG_LoadTexture(gWindowGameMenu1.GetRenderer(), "images/menu/OPTION_BIG.png");
                SDL_Rect OptionBigRect;
                SDL_QueryTexture(gOptionBig, NULL, NULL, &OptionBigRect.w, &OptionBigRect.h);
                OptionBigRect.x = (1440 - OptionBigRect.w) / 2;
                OptionBigRect.y = 540;
                gWindowGameMenu1.Draw(gOptionBig, &OptionBigRect);
                SDL_DestroyTexture(gOptionBig);
                if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT)
                {
                    //gTypeInput = TypeInputCursor::WAIT_CURSOR;
                    Cleanup1();
                    SDL_DestroyTexture(gWallPaper);
                    SDL_DestroyTexture(gGameName);
                    SDL_DestroyTexture(gDuelMode);
                    SDL_DestroyTexture(gDeckContruction);
                    SDL_DestroyTexture(gCardList);
                    SDL_DestroyTexture(gOption);
                    SDL_DestroyTexture(gQuitGame);
                    return StateMenu::OPTION_GAME;
                }
            }
            else if (gCursorMenu.IsCursorInRect(&QuitGameRect) == SDL_TRUE)
            {
                if (!isChangedCursor || isChangedCursor == 1 || isChangedCursor == 2 || isChangedCursor == 3 || isChangedCursor == 4)
                {
                    gCursorMenu.CleanCursorDefault();
                    gCursorMenu.SetImageCustom("images/mouse/cursor1.png");
                    gCursorMenu.DrawCursorCustom();
                    isChangedCursor = 5;
                }
                SDL_Texture* gQuitGameBig = IMG_LoadTexture(gWindowGameMenu1.GetRenderer(), "images/menu/QUITGAME_BIG.png");
                SDL_Rect QuitGameBigRect;
                SDL_QueryTexture(gQuitGameBig, NULL, NULL, &QuitGameBigRect.w, &QuitGameBigRect.h);
                QuitGameBigRect.x = (1440 - QuitGameBigRect.w) / 2;
                QuitGameBigRect.y = 620;
                gWindowGameMenu1.Draw(gQuitGameBig, &QuitGameBigRect);
                SDL_DestroyTexture(gQuitGameBig);
                if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT)
                {
                    //gTypeInput = TypeInputCursor::WAIT_CURSOR;
                    Cleanup1();
                    SDL_DestroyTexture(gWallPaper);
                    SDL_DestroyTexture(gGameName);
                    SDL_DestroyTexture(gDuelMode);
                    SDL_DestroyTexture(gDeckContruction);
                    SDL_DestroyTexture(gCardList);
                    SDL_DestroyTexture(gOption);
                    SDL_DestroyTexture(gQuitGame);
                    return StateMenu::QUIT_GAME;
                }
            }
            else
            {
                if (isChangedCursor == 1 || isChangedCursor == 2 || isChangedCursor == 3 || isChangedCursor == 4 || isChangedCursor == 5)
                {
                    gCursorMenu.CleanCursorCustom();
                    gCursorMenu.SetImageDefault("images/mouse/mouse1.png");
                    gCursorMenu.DrawCursorDefault();
                    isChangedCursor = 0;
                }
            }
            gWindowGameMenu1.EndDraw();
        }
    }
}


ModeGame MenuGame::InitiationMenuMode()
{
    gVolumeMenu.Sound = 70;
    gVolumeMenu.Music = 30;

    gModeGameMenu = ModeGame::WAIT;
    bool s1PvP = false, s1PvE = false, s1Shop = false;

    RunCursorAndMusicAndSound2();

    SDL_Texture* PvP2;
    SDL_Rect PvP2Rect;
    SDL_Texture* PvE2;
    SDL_Rect PvE2Rect;
    SDL_Texture* Shop2;
    SDL_Rect Shop2Rect;

    PvP2 = IMG_LoadTexture(gWindowGameMenu2.GetRenderer(), "images/menu/pvp2.png");
    PvP2Rect.w = 220;
    PvP2Rect.h = 400;
    PvP2Rect.x = (1440 - PvP2Rect.w) / 2;
    PvP2Rect.y = -400;

    PvE2 = IMG_LoadTexture(gWindowGameMenu2.GetRenderer(), "images/menu/pve2.png");
    PvE2Rect.w = 220;
    PvE2Rect.h = 400;
    PvE2Rect.x = 220;
    PvE2Rect.y = -400;

    Shop2 = IMG_LoadTexture(gWindowGameMenu2.GetRenderer(), "images/menu/shop2.png");
    Shop2Rect.w = 220;
    Shop2Rect.h = 400;
    Shop2Rect.x = 970;
    Shop2Rect.y = -400;

    SDL_Texture* PvP = IMG_LoadTexture(gWindowGameMenu2.GetRenderer(),"images\\menu\\pvp.png");
    SDL_Texture* PvE = IMG_LoadTexture(gWindowGameMenu2.GetRenderer(), "images\\menu\\pve.png");
    SDL_Texture* Shop = IMG_LoadTexture(gWindowGameMenu2.GetRenderer(), "images\\menu\\shop.png");
    SDL_Texture* ChooseMode = IMG_LoadTexture(gWindowGameMenu2.GetRenderer(), "images/menu/CHOOSEMODE.png");
    
    
    SDL_Rect ChooseModeRect;
    SDL_Rect PvP_DRect;
    SDL_Rect PvE_DRect;
    SDL_Rect PvPRect, PvERect, ShopRect; 

    SDL_QueryTexture(ChooseMode, NULL, NULL, &ChooseModeRect.w, &ChooseModeRect.h);
    
    SDL_QueryTexture(PvP, NULL, NULL, &PvPRect.w, &PvPRect.h);
    SDL_QueryTexture(PvE, NULL, NULL, &PvERect.w, &PvERect.h);
    SDL_QueryTexture(Shop, NULL, NULL, &ShopRect.w, &ShopRect.h);


    ChooseModeRect.x = 0;
    ChooseModeRect.y = 0;

    PvPRect.x = (1440 - PvPRect.w) / 2;
    PvPRect.y = 680;

    PvERect.x = 250;
    PvERect.y = 680;

    ShopRect.x = 1000;
    ShopRect.y = 680;

    while (gWindowGameMenu2.IsDone())
    {
        gWindowGameMenu2.RendererClear();
        CursorInput();

        gWindowGameMenu2.Draw(ChooseMode, &ChooseModeRect);
        gWindowGameMenu2.Draw(PvP, &PvPRect);
        gWindowGameMenu2.Draw(PvE, &PvERect);
        gWindowGameMenu2.Draw(Shop, &ShopRect);
        if (!isSoundPlayed)
        {
            isSoundPlayed = 1;
            gSoundMenu.Play();
        }
        if (gCursorMenu.IsCursorInRect(&PvPRect) == SDL_TRUE)
        {
            SDL_Texture* PvP1 = IMG_LoadTexture(gWindowGameMenu2.GetRenderer(), "images/menu/pvp - Copy.png");
            SDL_Rect PvP1Rect;
            SDL_QueryTexture(PvP1, NULL, NULL, &PvP1Rect.w, &PvP1Rect.h);
            PvP1Rect.x = (1440 - PvP1Rect.w) / 2;
            PvP1Rect.y = 680;
            gWindowGameMenu2.Draw(PvP1, &PvP1Rect);
            SDL_DestroyTexture(PvP1);

            if (gTypeInput == TypeInputCursor::LEFT_CURSOR)
            {

                gTypeInput = TypeInputCursor::WAIT_CURSOR;
                gMusicMenu.Stop();
                if (isSoundPlayed != 2)
                {
                    gSoundMenu.SetSoundBuffer("musics/modegame.mp3");
                    gSoundMenu.ChangeVolumeSound(100);
                    gSoundMenu.Play();
                    isSoundPlayed = 2;
                }
                s1PvP = true;

            }
        }
        else if (gCursorMenu.IsCursorInRect(&PvERect) == SDL_TRUE)
        {
            SDL_Texture* PvE1 = IMG_LoadTexture(gWindowGameMenu2.GetRenderer(), "images/menu/pve - Copy.png");
            SDL_Rect PvE1Rect;
            SDL_QueryTexture(PvE1, NULL, NULL, &PvE1Rect.w, &PvE1Rect.h);
            PvE1Rect.x = 250;
            PvE1Rect.y = 680;
            gWindowGameMenu2.Draw(PvE1, &PvE1Rect);
            SDL_DestroyTexture(PvE1);
            if (gTypeInput == TypeInputCursor::LEFT_CURSOR)
            {
                gTypeInput = TypeInputCursor::WAIT_CURSOR;
                gMusicMenu.Stop();
                if (isSoundPlayed != 3)
                {
                    gSoundMenu.SetSoundBuffer("musics/modegame.mp3");
                    gSoundMenu.ChangeVolumeSound(100);
                    gSoundMenu.Play();
                    isSoundPlayed = 3;
                }
                s1PvE = true;

            }
        }
        else if (gCursorMenu.IsCursorInRect(&ShopRect))
        {
            SDL_Texture* Shop1 = IMG_LoadTexture(gWindowGameMenu2.GetRenderer(), "images/menu/shop - Copy.png");
            SDL_Rect Shop1Rect;
            SDL_QueryTexture(Shop1, NULL, NULL, &Shop1Rect.w, &Shop1Rect.h);
            Shop1Rect.x = 1000;
            Shop1Rect.y = 680;
            gWindowGameMenu2.Draw(Shop1, &Shop1Rect);
            SDL_DestroyTexture(Shop1);
            if (gTypeInput == TypeInputCursor::LEFT_CURSOR)
            {
                gTypeInput = TypeInputCursor::WAIT_CURSOR;
                gMusicMenu.Stop();
                if (isSoundPlayed != 4)
                {
                    gSoundMenu.SetSoundBuffer("musics/modegame.mp3");
                    gSoundMenu.ChangeVolumeSound(100);
                    gSoundMenu.Play();
                    isSoundPlayed = 4;
                }
                s1Shop = true;
            }
        }

        if (s1PvP)
        {
            int dx = DEST_X - PvP2Rect.x;
            int dy = DEST_Y - PvP2Rect.y;
            int distance = sqrt(dx * dx + dy * dy);
            
            if (distance > 1 && dy > 0)
            {
                float stepX = dx / (float)distance;
                float stepY = dy / (float)distance;

                PvP2Rect.x += (int)(stepX * 3);
                PvP2Rect.y += (int)(stepY * 3);
            }
            gWindowGameMenu2.Draw(PvP2, &PvP2Rect);
        }
        if (s1PvE)
        {

            int dx = DEST_X1 - PvE2Rect.x;
            int dy = DEST_Y1 - PvE2Rect.y;
            int distance = sqrt(dx * dx + dy * dy);

            if (distance > 1 && dy > 0)
            {
                float stepX = dx / (float)distance;
                float stepY = dy / (float)distance;

                PvE2Rect.x += (int)(stepX * 3);
                PvE2Rect.y += (int)(stepY * 3);
            }
            gWindowGameMenu2.Draw(PvE2, &PvE2Rect);
            
        }
        if (s1Shop)
        {
            int dx = DEST_X2 - Shop2Rect.x;
            int dy = DEST_Y2 - Shop2Rect.y;
            int distance = sqrt(dx * dx + dy * dy);

            if (distance > 1 && dy > 0)
            {
                float stepX = dx / (float)distance;
                float stepY = dy / (float)distance;

                Shop2Rect.x += (int)(stepX * 3);
                Shop2Rect.y += (int)(stepY * 3);
            }
            gWindowGameMenu2.Draw(Shop2, &Shop2Rect);
        }
        if (gCursorMenu.IsCursorInRect(&PvP2Rect))
        {
            SDL_Texture* PvP_D = IMG_LoadTexture(gWindowGameMenu2.GetRenderer(), "images/menu/PvP_D.png");
            SDL_QueryTexture(PvP_D, NULL, NULL, &PvP_DRect.w, &PvP_DRect.h);
            PvP_DRect.x = (1440 - PvP_DRect.w) / 2;
            PvP_DRect.y = 100;
            gWindowGameMenu2.Draw(PvP_D, &PvP_DRect);
            SDL_DestroyTexture(PvP_D);
            if (gTypeInput == TypeInputCursor::LEFT_CURSOR)
            {
                gTypeInput = TypeInputCursor::WAIT_CURSOR;
                gModeGameMenu = ModeGame::PvP;

                Cleanup2();
                return ModeGame::PvP;
            }
            SDL_DestroyTexture(PvP_D);
        }
        if (gCursorMenu.IsCursorInRect(&PvE2Rect))
        {
            SDL_Texture* PvE_D = IMG_LoadTexture(gWindowGameMenu2.GetRenderer(), "images/menu/PvE_D.png");
            SDL_QueryTexture(PvE_D, NULL, NULL, &PvE_DRect.w, &PvE_DRect.h);
            PvE_DRect.x = (1440 - PvE_DRect.w) / 2;
            PvE_DRect.y = 100;
            gWindowGameMenu2.Draw(PvE_D, &PvE_DRect);
            SDL_DestroyTexture(PvE_D);
            if (gTypeInput == TypeInputCursor::LEFT_CURSOR)
            {
                gTypeInput = TypeInputCursor::WAIT_CURSOR;
                Cleanup2();

                gModeGameMenu = ModeGame::PvE;
                return ModeGame::PvE;
            }
            SDL_DestroyTexture(PvE_D);
        }
        if (gCursorMenu.IsCursorInRect(&Shop2Rect))
        {
            if (gTypeInput == TypeInputCursor::LEFT_CURSOR)
            {
                gTypeInput = TypeInputCursor::WAIT_CURSOR;
                Cleanup2();
                gModeGameMenu = ModeGame::SHOP;

                return ModeGame::SHOP;
            }
        }
        gWindowGameMenu2.EndDraw();
    }
}

void MenuGame::Deckconstruction()
{
    bool IsPlayed = false;
    bool YugiDeck = false, KaibaDeck = false, JounochiDeck = false;
    gVolumeMenu.Sound = 80;
    gVolumeMenu.Music = 40;

    RunCursorAndMusicAndSound3();
    SDL_Texture* DCMenu = IMG_LoadTexture(gWindowGameMenu3.GetRenderer(), "images\\Deck construction\\dc.jpg");
    SDL_Texture* Menu1 = IMG_LoadTexture(gWindowGameMenu3.GetRenderer(), "images\\Deck construction\\1.png");
    SDL_Rect DCMenuRect;
    SDL_Rect Menu1Rect;

    SDL_QueryTexture(DCMenu, NULL, NULL, &DCMenuRect.w, &DCMenuRect.h);
    SDL_QueryTexture(Menu1, NULL, NULL, &Menu1Rect.w, &Menu1Rect.h);

    DCMenuRect.x = 0;
    DCMenuRect.y = 0;

    Menu1Rect.x = (1440 - Menu1Rect.w) / 2;
    Menu1Rect.y = 50;

    SDL_Rect Chitiet1Rect = { 689 + Menu1Rect.x,186 + Menu1Rect.y,830 - 690,250 - 190 };
    SDL_Rect Chitiet2Rect = { 689 + Menu1Rect.x,305 + Menu1Rect.y,830 - 690,250 - 190 };
    SDL_Rect Chitiet3Rect = { 689 + Menu1Rect.x,420 + Menu1Rect.y,830 - 690,250 - 190 };
    SDL_Rect XRect = { 793 + Menu1Rect.x,27 + Menu1Rect.y,100,58 };
    SDL_Rect X1Rect = { 808 + Menu1Rect.x,23 + Menu1Rect.y ,88,50 };
    SDL_Rect dstRect = { 720 , 405, 0, 0 };

    SDL_Texture* YugiDeckMenu = IMG_LoadTexture(gWindowGameMenu3.GetRenderer(), "images/Deck construction/1_1.png");
    SDL_Texture* KaibaDeckMenu = IMG_LoadTexture(gWindowGameMenu3.GetRenderer(), "images/Deck construction/1_2.png");
    SDL_Texture* JounochiDeckMenu = IMG_LoadTexture(gWindowGameMenu3.GetRenderer(), "images/Deck construction/1_3.png");
    SDL_QueryTexture(YugiDeckMenu, NULL, NULL, &Menu1Rect.w, &Menu1Rect.h);

    SDL_Texture* Yugi = IMG_LoadTexture(gWindowGameMenu3.GetRenderer(), "images/Deck construction/yugi.png");
    SDL_Texture* Kaiba = IMG_LoadTexture(gWindowGameMenu3.GetRenderer(), "images/Deck construction/kaiba.png");
    SDL_Texture* Jounochi = IMG_LoadTexture(gWindowGameMenu3.GetRenderer(), "images/Deck construction/jounochi.png");
    SDL_Rect RectYugi = { 20 + Menu1Rect.x , 280 + Menu1Rect.y , 830,335 };

    SDL_Rect srcrect = {0,0,830,335};

    bool quit = false;
    bool isScrolling = false;
    int startX = 0;
    int startY = 250;
    int lastX = 0;
    int lastY = 0;
    SDL_Event e;

    int CardWidth = 185;
    int CardHeight = 270;

    SDL_Rect KaibaCard1 = { 25, 30, CardWidth, CardHeight };
    SDL_Rect Card1;
    while (gWindowGameMenu3.IsDone())
    {
        gWindowGameMenu3.RendererClear();
        CursorInput();
        gWindowGameMenu3.Draw(DCMenu, &DCMenuRect);
        if (!IsPlayed)
        {
            for (int i = 0; i <= 900; i += 10) {
                dstRect.w = i;
                dstRect.h = (int)((float)i / 900 * 702);
                dstRect.x = (int)((float)720 - i / 2);
                dstRect.y = (int)((float)405 - (float)dstRect.h / 2);
                //gWindowGameMenu3.RendererClear();
                gWindowGameMenu3.Draw(Menu1, &dstRect);
                gWindowGameMenu3.EndDraw();
                SDL_Delay(5);
            }
            IsPlayed = true;
        }

        gWindowGameMenu3.Draw(Menu1, &Menu1Rect);
        if (gCursorMenu.IsCursorInRect(&Chitiet1Rect) && !YugiDeck && !KaibaDeck && !JounochiDeck)
        {
            SDL_Texture* Chitiet1 = IMG_LoadTexture(gWindowGameMenu3.GetRenderer(), "images/Deck construction/chitiet.png");
            SDL_QueryTexture(Chitiet1, NULL, NULL, &Chitiet1Rect.w, &Chitiet1Rect.h);

            gWindowGameMenu3.Draw(Chitiet1, &Chitiet1Rect);
            SDL_DestroyTexture(Chitiet1);
            if (gTypeInput == TypeInputCursor::LEFT_CURSOR)
            {
                gTypeInput = TypeInputCursor::WAIT_CURSOR;
                KaibaDeck = true;
            }
        }
        else if (gCursorMenu.IsCursorInRect(&Chitiet2Rect) && !YugiDeck && !KaibaDeck && !JounochiDeck)
        {
            SDL_Texture* Chitiet1 = IMG_LoadTexture(gWindowGameMenu3.GetRenderer(), "images/Deck construction/chitiet.png");
            SDL_QueryTexture(Chitiet1, NULL, NULL, &Chitiet2Rect.w, &Chitiet2Rect.h);

            gWindowGameMenu3.Draw(Chitiet1, &Chitiet2Rect);
            SDL_DestroyTexture(Chitiet1);
            if (gTypeInput == TypeInputCursor::LEFT_CURSOR)
            {
                gTypeInput = TypeInputCursor::WAIT_CURSOR;
                YugiDeck = true;
            }
        }
        else if (gCursorMenu.IsCursorInRect(&Chitiet3Rect) && !YugiDeck && !KaibaDeck && !JounochiDeck)
        {
            SDL_Texture* Chitiet1 = IMG_LoadTexture(gWindowGameMenu3.GetRenderer(), "images/Deck construction/chitiet.png");
            SDL_QueryTexture(Chitiet1, NULL, NULL, &Chitiet3Rect.w, &Chitiet3Rect.h);

            gWindowGameMenu3.Draw(Chitiet1, &Chitiet3Rect);
            SDL_DestroyTexture(Chitiet1);
            if (gTypeInput == TypeInputCursor::LEFT_CURSOR)
            {
                gTypeInput = TypeInputCursor::WAIT_CURSOR;
                JounochiDeck = true;
            }
        }
        else if (gCursorMenu.IsCursorInRect(&XRect) && !YugiDeck && !KaibaDeck && !JounochiDeck)
        {
            SDL_Texture* X = IMG_LoadTexture(gWindowGameMenu3.GetRenderer(), "images/Deck construction/x.png");
            SDL_QueryTexture(X, NULL, NULL, &XRect.w, &XRect.h);

            gWindowGameMenu3.Draw(X, &XRect);
            SDL_DestroyTexture(X);
            if (gTypeInput == TypeInputCursor::LEFT_CURSOR)
            {
                gTypeInput = TypeInputCursor::WAIT_CURSOR;
                Cleanup3();

            }
        }
        if (KaibaDeck)
        {
            SDL_Texture* X1 = IMG_LoadTexture(gWindowGameMenu3.GetRenderer(), "images/Deck construction/x1.png");
            SDL_QueryTexture(X1, NULL, NULL, &X1Rect.w, &X1Rect.h);

            if (Menu1 != NULL) SDL_DestroyTexture(Menu1);
            gWindowGameMenu3.Draw(KaibaDeckMenu, &Menu1Rect);
            gWindowGameMenu3.DrawFull(Kaiba, &srcrect, &RectYugi);

            if (gCursorMenu.IsCursorInRect(&X1Rect) == SDL_TRUE)
            {
                gWindowGameMenu3.Draw(X1, &X1Rect);
                SDL_DestroyTexture(X1);
            }
            gWindowGameMenu3.EndDraw();
            Card1.x = KaibaCard1.x + RectYugi.x - srcrect.x;
            Card1.y = KaibaCard1.y + RectYugi.y - srcrect.y;
            if (Card1.x < 0) Card1.w = 0;
            if (Card1.x > 0);
            while (SDL_PollEvent(&e) != 0)
            {
                if (gCursorMenu.IsCursorInRect(&X1Rect) == SDL_TRUE)
                {
                    if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT)
                    {
                        Cleanup3();
                        Deckconstruction();
                    }
                }
                else if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT) {
                    isScrolling = true;
                    startX = e.button.x;
                    startY = e.button.y;
                    lastX = startX;
                    lastY = startY;
                }
                else if (e.type == SDL_MOUSEBUTTONUP && e.button.button == SDL_BUTTON_LEFT)
                {
                    isScrolling = false;
                }
                else if (e.type == SDL_MOUSEMOTION && isScrolling)
                {
                    int dx = -e.motion.x + lastX;
                    srcrect.x += dx;
                    if (srcrect.x < 0)
                    {
                        srcrect.x = 0;
                    }
                    else if (srcrect.x > 5609 - 830)
                    {
                        srcrect.x = 5609 - 830;
                    }
                }

                lastX = e.motion.x;
                gWindowGameMenu3.DrawFull(Kaiba, &srcrect, &RectYugi);
                gWindowGameMenu3.EndDraw();
            }
            SDL_DestroyTexture(X1);
        }
        else if (YugiDeck)
        {
            SDL_Texture* X1 = IMG_LoadTexture(gWindowGameMenu3.GetRenderer(), "images/Deck construction/x1.png");
            SDL_QueryTexture(X1, NULL, NULL, &X1Rect.w, &X1Rect.h);

            if (Menu1 != NULL) SDL_DestroyTexture(Menu1);
            gWindowGameMenu3.Draw(YugiDeckMenu, &Menu1Rect);
            gWindowGameMenu3.DrawFull(Yugi, &srcrect, &RectYugi);

            if (gCursorMenu.IsCursorInRect(&X1Rect) == SDL_TRUE)
            {
                gWindowGameMenu3.Draw(X1, &X1Rect);
                SDL_DestroyTexture(X1);
            }
            gWindowGameMenu3.EndDraw();

            while (SDL_PollEvent(&e) != 0)
            {
                if (gCursorMenu.IsCursorInRect(&X1Rect) == SDL_TRUE)
                {

                    if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT)
                    {
                        Cleanup3();
                        Deckconstruction();
                    }
                }
                else if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT) {
                    isScrolling = true;
                    startX = e.button.x;
                    startY = e.button.y;
                    lastX = startX;
                    lastY = startY;
                }
                else if (e.type == SDL_MOUSEBUTTONUP && e.button.button == SDL_BUTTON_LEFT)
                {
                    isScrolling = false;
                }
                else if (e.type == SDL_MOUSEMOTION && isScrolling)
                {
                    int dx = -e.motion.x + lastX;
                    srcrect.x += dx;
                    if (srcrect.x < 0)
                    {
                        srcrect.x = 0;
                    }
                    else if (srcrect.x > 5321 - 830)
                    {
                        srcrect.x = 5321 - 830;
                    }
                }

                lastX = e.motion.x;
                gWindowGameMenu3.DrawFull(Yugi, &srcrect, &RectYugi);
                gWindowGameMenu3.EndDraw();
            }
            SDL_DestroyTexture(X1);
        }
        else if (JounochiDeck)
        {
            SDL_Texture* X1 = IMG_LoadTexture(gWindowGameMenu3.GetRenderer(), "images/Deck construction/x1.png");
            SDL_QueryTexture(X1, NULL, NULL, &X1Rect.w, &X1Rect.h);

            if (Menu1 != NULL) SDL_DestroyTexture(Menu1);
            gWindowGameMenu3.Draw(JounochiDeckMenu, &Menu1Rect);
            gWindowGameMenu3.DrawFull(Jounochi, &srcrect, &RectYugi);

            if (gCursorMenu.IsCursorInRect(&X1Rect) == SDL_TRUE)
            {
                gWindowGameMenu3.Draw(X1, &X1Rect);
                SDL_DestroyTexture(X1);
            }
            gWindowGameMenu3.EndDraw();

            while (SDL_PollEvent(&e) != 0)
            {
                if (gCursorMenu.IsCursorInRect(&X1Rect) == SDL_TRUE)
                {

                    if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT)
                    {
                        Cleanup3();
                        Deckconstruction();
                    }
                }
                else if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT) {
                    isScrolling = true;
                    startX = e.button.x;
                    startY = e.button.y;
                    lastX = startX;
                    lastY = startY;
                }
                else if (e.type == SDL_MOUSEBUTTONUP && e.button.button == SDL_BUTTON_LEFT)
                {
                    isScrolling = false;
                }
                else if (e.type == SDL_MOUSEMOTION && isScrolling)
                {
                    int dx = -e.motion.x + lastX;
                    srcrect.x += dx;
                    if (srcrect.x < 0)
                    {
                        srcrect.x = 0;
                    }
                    else if (srcrect.x > 5479 - 830)
                    {
                        srcrect.x = 5479 - 830;
                    }
                }

                lastX = e.motion.x;
                gWindowGameMenu3.DrawFull(Jounochi, &srcrect, &RectYugi);
                gWindowGameMenu3.EndDraw();
            }
            SDL_DestroyTexture(X1);
        }
        gWindowGameMenu3.EndDraw();
    }
}

void MenuGame::Option()
{
    gVolumeMenu.Sound = 40;
    gVolumeMenu.Music = 40;
    RunCursorAndMusicAndSound4();

    SDL_Texture* OptionMenu = IMG_LoadTexture(gWindowGameMenu4.GetRenderer(), "images/option/optionmenu.jpg");
    SDL_Rect OptionMenuRect = { 0 , 0 , 0 , 0 };
    SDL_QueryTexture(OptionMenu, NULL, NULL, &OptionMenuRect.w, &OptionMenuRect.h);

    SDL_Texture* OptionTable = IMG_LoadTexture(gWindowGameMenu4.GetRenderer(), "images/option/optiontable.png");
    SDL_Rect OptionTableRect;

    SDL_QueryTexture(OptionTable, NULL, NULL, &OptionTableRect.w, &OptionTableRect.h);
    OptionTableRect.x = (1440 - OptionTableRect.w) / 2;
    OptionTableRect.y = -250;

    SDL_Texture* Move1 = IMG_LoadTexture(gWindowGameMenu4.GetRenderer(), "images/option/move.png");
    SDL_Texture* Move2 = IMG_LoadTexture(gWindowGameMenu4.GetRenderer(), "images/option/move.png");
    SDL_Rect MoveRect1 = { 651 , 250 + 118 , 30 , 21 };
    SDL_Rect MoveRect2 = { 651 , 250 + 118 + 46 , 30 , 21 };
    const int DEST_X1 = OptionTableRect.x;
    const int DEST_Y1 = 250;
    bool Start = true;

    bool isScrolling = false;
    int startX = 0;
    int startY = 250;
    int lastX = 0;
    int lastY = 0;

    bool isScrolling1 = false;
    int startX1 = 0;
    int startY1 = 250;
    int lastX1 = 0;
    int lastY1 = 0;

    SDL_Event e;

    SDL_Rect ChooseButtonRect = { DEST_X1 + 213,DEST_Y1 + 188,62,62 };
    gTypeInput = TypeInputCursor::WAIT_CURSOR;

    SDL_Texture* Music1 = IMG_LoadTexture(gWindowGameMenu4.GetRenderer(), "images/option/1.png");
    SDL_Texture* Music2 = IMG_LoadTexture(gWindowGameMenu4.GetRenderer(), "images/option/1.png");
    SDL_Texture* Music3 = IMG_LoadTexture(gWindowGameMenu4.GetRenderer(), "images/option/1.png");
    SDL_Texture* Music4 = IMG_LoadTexture(gWindowGameMenu4.GetRenderer(), "images/option/1.png");
    SDL_Texture* Music5 = IMG_LoadTexture(gWindowGameMenu4.GetRenderer(), "images/option/1.png");
    SDL_Texture* Music6 = IMG_LoadTexture(gWindowGameMenu4.GetRenderer(), "images/option/1.png");
    SDL_Texture* Music7 = IMG_LoadTexture(gWindowGameMenu4.GetRenderer(), "images/option/1.png");
    SDL_Texture* Music8 = IMG_LoadTexture(gWindowGameMenu4.GetRenderer(), "images/option/1.png");
    SDL_Texture* Music9 = IMG_LoadTexture(gWindowGameMenu4.GetRenderer(), "images/option/1.png");
    SDL_Texture* Music1C = IMG_LoadTexture(gWindowGameMenu4.GetRenderer(), "images/option/1 - Copy.png");
    SDL_Texture* Music2C = IMG_LoadTexture(gWindowGameMenu4.GetRenderer(), "images/option/1 - Copy.png");
    SDL_Texture* Music3C = IMG_LoadTexture(gWindowGameMenu4.GetRenderer(), "images/option/1 - Copy.png");
    SDL_Texture* Music4C = IMG_LoadTexture(gWindowGameMenu4.GetRenderer(), "images/option/1 - Copy.png");
    SDL_Texture* Music5C = IMG_LoadTexture(gWindowGameMenu4.GetRenderer(), "images/option/1 - Copy.png");
    SDL_Texture* Music6C = IMG_LoadTexture(gWindowGameMenu4.GetRenderer(), "images/option/1 - Copy.png");
    SDL_Texture* Music7C = IMG_LoadTexture(gWindowGameMenu4.GetRenderer(), "images/option/1 - Copy.png");
    SDL_Texture* Music8C = IMG_LoadTexture(gWindowGameMenu4.GetRenderer(), "images/option/1 - Copy.png");
    SDL_Texture* Music9C = IMG_LoadTexture(gWindowGameMenu4.GetRenderer(), "images/option/1 - Copy.png");

    SDL_Rect M1 = {250,100,300,150};
    SDL_Rect M1T = { 410,140,120,45 };
    SDL_Rect M2 = { 620,100,300,150 };
    SDL_Rect M2T = { 780,140,120,45 };
    SDL_Rect M3 = {620+370,100,300,150};
    SDL_Rect M3T = { 620 + 370+160,140,120,45 };
    SDL_Rect M4 = {250,320,300,150};
    SDL_Rect M4T = { 410,360,120,45 };
    SDL_Rect M5 = {620 ,320,300,150 };
    SDL_Rect M5T = { 620+160,360,120,45 };
    SDL_Rect M6 = { 620 + 370 ,320,300,150};
    SDL_Rect M6T = { 620 + 370 + 160,360,120,45 };
    SDL_Rect M7 = {250,540,300,150};
    SDL_Rect M7T = { 410,580,120,45 };
    SDL_Rect M8 = { 620 ,540,300,150 };
    SDL_Rect M8T = {620+160,580,120,45 };
    SDL_Rect M9 = { 990,540,300,150 };
    SDL_Rect M9T = {990+160,580,120,45 };

    gFont = TTF_OpenFont("font/DFVN West West Condensed.ttf", 28);
    if (gFont == NULL) {
        printf("Failed to load font! SDL_ttf Error: %s\n", TTF_GetError());
        return;
    }

    // Màu chữ
    SDL_Color textColor = { 255, 254, 255, 255 };
    SDL_Texture* MS1 = LoadTextTexture("MS1", textColor);
    SDL_Texture* MS2 = LoadTextTexture("MS2", textColor);
    SDL_Texture* MS3 = LoadTextTexture("MS3", textColor);
    SDL_Texture* MS4 = LoadTextTexture("MS4", textColor);
    SDL_Texture* MS5 = LoadTextTexture("MS5", textColor);
    SDL_Texture* MS6 = LoadTextTexture("MS6", textColor);
    SDL_Texture* MS7 = LoadTextTexture("MS7", textColor);
    SDL_Texture* MS8 = LoadTextTexture("MS8", textColor);
    SDL_Texture* MS9 = LoadTextTexture("MS9", textColor);
    bool m[10] = { false };
    while (gWindowGameMenu4.IsDone())
    {
        gWindowGameMenu4.RendererClear();
        gWindowGameMenu4.Draw(OptionMenu, &OptionMenuRect);
        if (Start)
        {
            for (int i = 0; i <= 500; i += 1)
            {
                gWindowGameMenu4.RendererClear();
                gWindowGameMenu4.Draw(OptionMenu, &OptionMenuRect);
                OptionTableRect.y += 1;
                gWindowGameMenu4.Draw(OptionTable, &OptionTableRect);
                gWindowGameMenu4.EndDraw();
            }
            Start = false;
        }

        gWindowGameMenu4.Draw(OptionTable, &OptionTableRect);
        gWindowGameMenu4.Draw(Move1, &MoveRect1);
        gWindowGameMenu4.Draw(Move2, &MoveRect2);
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT && gCursorMenu.IsCursorInRect(&MoveRect1)) {
                isScrolling = true;
                startX = e.button.x;
                startY = e.button.y;
                lastX = startX;
                lastY = startY;
            }
            else if (e.type == SDL_MOUSEBUTTONUP && e.button.button == SDL_BUTTON_LEFT)
            {
                isScrolling = false;
            }
            else if (e.type == SDL_MOUSEMOTION && isScrolling)
            {
                int dx = e.motion.x - lastX;
                MoveRect1.x += dx;
                if (MoveRect1.x < 651)
                {
                    MoveRect1.x = 651;
                }
                else if (MoveRect1.x > 900)
                {
                    MoveRect1.x = 900;
                }
            }
            if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT && gCursorMenu.IsCursorInRect(&MoveRect2)) {
                isScrolling1 = true;
                startX1 = e.button.x;
                startY1 = e.button.y;
                lastX1 = startX;
                lastY1 = startY;
            }
            else if (e.type == SDL_MOUSEBUTTONUP && e.button.button == SDL_BUTTON_LEFT)
            {
                isScrolling1 = false;
            }
            else if (e.type == SDL_MOUSEMOTION && isScrolling1)
            {
                int dx = e.motion.x - lastX1;
                MoveRect2.x += dx;
                if (MoveRect2.x < 651)
                {
                    MoveRect2.x = 651;
                }
                else if (MoveRect2.x > 900)
                {
                    MoveRect2.x = 900;
                }
            }
            gMusicMenu.ChangeVolume((int)(40+1.0*(MoveRect1.x-651)*88 / 249)) ;
            gSoundMenu.ChangeVolumeSound((int)(40 + 1.0 * (MoveRect1.x - 651) * 88/249));
            lastX = e.motion.x;
            lastX1 = e.motion.x;
            gWindowGameMenu4.Draw(Move1, &MoveRect1);
            gWindowGameMenu4.Draw(Move2, &MoveRect2);
        }
        
        if (gCursorMenu.IsCursorInRect(&ChooseButtonRect))
        {
            SDL_Texture* ChooseButton = IMG_LoadTexture(gWindowGameMenu4.GetRenderer(), "images/option/button.png");
            gWindowGameMenu4.Draw(ChooseButton, &ChooseButtonRect);
            SDL_DestroyTexture(ChooseButton);
            CursorInput();
            if (gTypeInput == TypeInputCursor::LEFT_CURSOR)
            {
                gTypeInput == TypeInputCursor::WAIT_CURSOR;
                ChooseButtonRect.w = 0;
            }
        }
        if (ChooseButtonRect.w == 0)
        {
            gWindowGameMenu4.RendererClear();
            gWindowGameMenu4.Draw(OptionMenu, &OptionMenuRect);
            gWindowGameMenu4.Draw(Music1, &M1);
            gWindowGameMenu4.Draw(Music2, &M2);
            gWindowGameMenu4.Draw(Music3, &M3);
            gWindowGameMenu4.Draw(Music4, &M4);
            gWindowGameMenu4.Draw(Music5, &M5);
            gWindowGameMenu4.Draw(Music6, &M6);
            gWindowGameMenu4.Draw(Music7, &M7);
            gWindowGameMenu4.Draw(Music8, &M8);
            gWindowGameMenu4.Draw(Music9, &M9);
            gWindowGameMenu4.Draw(MS1, &M1T);
            gWindowGameMenu4.Draw(MS2, &M2T);
            gWindowGameMenu4.Draw(MS3, &M3T);
            gWindowGameMenu4.Draw(MS4, &M4T);
            gWindowGameMenu4.Draw(MS5, &M5T);
            gWindowGameMenu4.Draw(MS6, &M6T);
            gWindowGameMenu4.Draw(MS7, &M7T);
            gWindowGameMenu4.Draw(MS8, &M8T);
            gWindowGameMenu4.Draw(MS9, &M9T);
            
            if (gCursorMenu.IsCursorInRect(&M1))
            {
                CursorInput();
                if (gTypeInput == TypeInputCursor::LEFT_CURSOR && !m[1])
                {
                    gTypeInput = TypeInputCursor::WAIT_CURSOR;
                    m[1] = true;
                }
            }
            if (m[1])
            {
                gWindowGameMenu4.RendererClear();
                gWindowGameMenu4.Draw(OptionMenu, &OptionMenuRect);
                gWindowGameMenu4.Draw(Music1C, &M1);
                gWindowGameMenu4.Draw(Music2, &M2);
                gWindowGameMenu4.Draw(Music3, &M3);
                gWindowGameMenu4.Draw(Music4, &M4);
                gWindowGameMenu4.Draw(Music5, &M5);
                gWindowGameMenu4.Draw(Music6, &M6);
                gWindowGameMenu4.Draw(Music7, &M7);
                gWindowGameMenu4.Draw(Music8, &M8);
                gWindowGameMenu4.Draw(Music9, &M9);
                gWindowGameMenu4.Draw(MS1, &M1T);
                gWindowGameMenu4.Draw(MS2, &M2T);
                gWindowGameMenu4.Draw(MS3, &M3T);
                gWindowGameMenu4.Draw(MS4, &M4T);
                gWindowGameMenu4.Draw(MS5, &M5T);
                gWindowGameMenu4.Draw(MS6, &M6T);
                gWindowGameMenu4.Draw(MS7, &M7T);
                gWindowGameMenu4.Draw(MS8, &M8T);
                gWindowGameMenu4.Draw(MS9, &M9T);
            }
        }
        gWindowGameMenu4.EndDraw();
    }
}
void MenuGame::CursorInput()
{
    SDL_Event gEvent;
    while (SDL_PollEvent(&gEvent) != 0)
    {
        switch (gEvent.type)
        {
        case SDL_QUIT:
            gWindowGameMenu1.Destroy();
            break;
        case SDL_MOUSEMOTION:
            gTypeInput = TypeInputCursor::WAIT_CURSOR;

            break;
        case SDL_MOUSEBUTTONDOWN:
            gTypeInput = TypeInputCursor::WAIT_CURSOR;
            if (gEvent.button.button == SDL_BUTTON_LEFT)
            {
                gTypeInput = TypeInputCursor::LEFT_CURSOR;
            }
            else if (gEvent.button.button == SDL_BUTTON_RIGHT)
            {
                gTypeInput = TypeInputCursor::RIGHT_CURSOR;
            }
            break;
        }
    }
}

void MenuGame::Render()
{
    gWindowGameMenu1.BeginDraw();
    gWindowGameMenu1.EndDraw();
}

void MenuGame::Cleanup1()
{
    gCursorMenu.~Cursor();
    gSoundMenu.~SoundGame();
    gMusicMenu.~MusicGame();
    gWindowGameMenu1.~WindowGame();

    IMG_Quit();
    Mix_Quit();
    //SDL_Quit();
}
void MenuGame::Cleanup2()
{
    gCursorMenu.~Cursor();
    gSoundMenu.~SoundGame();
    gMusicMenu.~MusicGame();
    gWindowGameMenu2.~WindowGame();

    IMG_Quit();
    Mix_Quit();
    //SDL_Quit();
}
void MenuGame::Cleanup3()
{
    gCursorMenu.~Cursor();
    gSoundMenu.~SoundGame();
    gMusicMenu.~MusicGame();
    gWindowGameMenu3.~WindowGame();

    IMG_Quit();
    Mix_Quit();
    //SDL_Quit();
}
