#include "MenuGame.h"

MenuGame::MenuGame()
{
    
}
MenuGame::~MenuGame()
{
    Cleanup();
}

void MenuGame::RunCursorAndMusicAndSound()
{
    // Creat window and icon game
    gWindowGameMenu.SetUp("MAGIC DUEL", 1440, 810);
    SDL_Surface* iconSurface = IMG_Load("images/icon/icon1.png");
    if (!iconSurface)
    {
        std::cerr << "IMG_Load error: " << IMG_GetError() << std::endl;
        SDL_DestroyWindow(gWindowGameMenu.GetWindow());
        SDL_Quit();
        return ;
    }
    SDL_SetWindowIcon(gWindowGameMenu.GetWindow(), iconSurface);
    //Load music menu

    //gMusicMenu.SetMusic("musics//MenuMusic.wav");
    //gMusicMenu.SetRepeat();
    //gMusicMenu.Play();

    //Load cursor click sound
    gSoundMenu.SetSoundBuffer("musics//ClickCursor.mp3");
    gSoundMenu.ChangeVolumeSound(45);

    //Cursor
    gCursorMenu.SetImageDefault("images/mouse/mouse1.png");
    gCursorMenu.DrawCursorDefault();

    gCursorMenu.SetImageCustom("images/mouse/cursor1.png");

}


ModeGame MenuGame::InitiationMenu()
{
    gVolumeMenu.Sound = 70;
    gVolumeMenu.Music = 30;
    gStateGameMenu = StateMenu::WAIT;
    gModeGameMenu = ModeGame::WAIT;
    RunCursorAndMusicAndSound();
    AnimationPvP();
    AnimationPvE();
    AnimationShop();
    SDL_Texture* gWallPaper = LoadTexture("images/menu/WALLPAPER.jpg");
    SDL_Texture* gGameName = LoadTexture("images/menu/GAMENAME.png");
    SDL_Texture* gDuelMode = LoadTexture("images/menu/DUELMODE.png");
    SDL_Texture* gDeckContruction = LoadTexture("images/menu/DECKCONTRUCTION.png");
    SDL_Texture* gOption = LoadTexture("images/menu/OPTION.png");
    SDL_Texture* gCardList = LoadTexture("images/menu/CARDLIST.png");
    SDL_Texture* gQuitGame = LoadTexture("images/menu/QUITGAME.png");

    SDL_Rect WallPaperRect, DuelModeRect, GameNameRect, OptionRect, DeckContructionRect , CardListRect, QuitGameRect;
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
    bool s1 = false, s1PvP = false, s1PvE = false, s1Shop = false;
    while (gWindowGameMenu.IsDone())
    {
        CursorInput();
        
        gWindowGameMenu.RendererClear();
        gWindowGameMenu.Draw(gWallPaper, &WallPaperRect);
        gWindowGameMenu.Draw(gGameName, &GameNameRect);
        gWindowGameMenu.Draw(gDuelMode, &DuelModeRect);
        gWindowGameMenu.Draw(gDeckContruction, &DeckContructionRect);
        gWindowGameMenu.Draw(gCardList, &CardListRect);
        gWindowGameMenu.Draw(gOption, &OptionRect);
        gWindowGameMenu.Draw(gQuitGame, &QuitGameRect);
        
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
            SDL_Texture* gDuelModeBig = LoadTexture("images/menu/DUELMODE_BIG.png");
            SDL_Rect DuelModeBigRect;
            SDL_QueryTexture(gDuelModeBig, NULL, NULL, &DuelModeBigRect.w, &DuelModeBigRect.h);
            DuelModeBigRect.x = (1440 - DuelModeBigRect.w) / 2;
            DuelModeBigRect.y = 300;
            gWindowGameMenu.Draw(gDuelModeBig, &DuelModeBigRect);
            SDL_DestroyTexture(gDuelModeBig);

            if (gTypeInput == TypeInputCursor::LEFT_CURSOR)
            {
                gStateGameMenu = StateMenu::DUEL_MODE;
                s1 = true;
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
            
            SDL_Texture* gDeckContructionBig = LoadTexture("images/menu/DECKCONTRUCTION_BIG.png");
            SDL_Rect DeckContructionBigRect;
            SDL_QueryTexture(gDeckContructionBig, NULL, NULL, &DeckContructionBigRect.w, &DeckContructionBigRect.h);
            DeckContructionBigRect.x = (1440 - DeckContructionBigRect.w) / 2;
            DeckContructionBigRect.y = 380;
            gWindowGameMenu.Draw(gDeckContructionBig, &DeckContructionBigRect);
            SDL_DestroyTexture(gDeckContructionBig);

            if (gTypeInput == TypeInputCursor::LEFT_CURSOR)
            {
                gStateGameMenu = StateMenu::DECK_CONSTRUCTION;
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
            //gCursorMenu.ChangeImage("images/mouse/cursor1.png");
            SDL_Texture* gCardListBig = LoadTexture("images/menu/CARDLIST_BIG.png");
            SDL_Rect CardListBigRect;
            SDL_QueryTexture(gCardListBig, NULL, NULL, &CardListBigRect.w, &CardListBigRect.h);
            CardListBigRect.x = (1440 - CardListBigRect.w) / 2;
            CardListBigRect.y = 460;
            gWindowGameMenu.Draw(gCardListBig, &CardListBigRect);
            SDL_DestroyTexture(gCardListBig);
            if (gTypeInput == TypeInputCursor::LEFT_CURSOR)
            {
                gStateGameMenu = StateMenu::CARD_LIST;
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
            //gCursorMenu.ChangeImage("images/mouse/cursor1.png");
            SDL_Texture* gOptionBig = LoadTexture("images/menu/OPTION_BIG.png");
            SDL_Rect OptionBigRect;
            SDL_QueryTexture(gOptionBig, NULL, NULL, &OptionBigRect.w, &OptionBigRect.h);
            OptionBigRect.x = (1440 - OptionBigRect.w) / 2;
            OptionBigRect.y = 540;
            gWindowGameMenu.Draw(gOptionBig, &OptionBigRect);
            SDL_DestroyTexture(gOptionBig);
            if (gTypeInput == TypeInputCursor::LEFT_CURSOR)
            {
                gStateGameMenu = StateMenu::CARD_LIST;
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
            //gCursorMenu.ChangeImage("images/mouse/cursor1.png");
            SDL_Texture* gQuitGameBig = LoadTexture("images/menu/QUITGAME_BIG.png");
            SDL_Rect QuitGameBigRect;
            SDL_QueryTexture(gQuitGameBig, NULL, NULL, &QuitGameBigRect.w, &QuitGameBigRect.h);
            QuitGameBigRect.x = (1440 - QuitGameBigRect.w) / 2;
            QuitGameBigRect.y = 620;
            gWindowGameMenu.Draw(gQuitGameBig, &QuitGameBigRect);
            SDL_DestroyTexture(gQuitGameBig);
            if (gTypeInput == TypeInputCursor::LEFT_CURSOR)
            {
                gStateGameMenu = StateMenu::QUIT_GAME;
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
                gStateGameMenu = StateMenu::WAIT;
            }
        }

        if (s1)
        {  
            WallPaperRect.w = 0;
            WallPaperRect.h = 0;

            GameNameRect.w = 0;
            GameNameRect.h = 0;

            DuelModeRect.w = 0;
            DuelModeRect.h = 0;

            DeckContructionRect.w = 0;
            DeckContructionRect.w = 0;

            CardListRect.w = 0;
            CardListRect.h = 0;

            OptionRect.w = 0;
            OptionRect.h = 0;

            QuitGameRect.w = 0;
            QuitGameRect.h = 0;
            gMusicMenu.Stop();

            if (!isSoundPlayed)
            {
                gCursorMenu.~Cursor();
                gCursorMenu.DrawCursorCustom();
                isSoundPlayed = 1;
                gSoundMenu.Play();
            }
            SDL_Texture* ChooseMode = LoadTexture("images/menu/CHOOSEMODE.png");
            SDL_Rect ChooseModeRect;
            SDL_QueryTexture(ChooseMode, NULL, NULL, &ChooseModeRect.w, &ChooseModeRect.h);
            ChooseModeRect.x = 0;
            ChooseModeRect.y = 0;
            gWindowGameMenu.Draw(ChooseMode, &ChooseModeRect);
            SDL_DestroyTexture(ChooseMode);

            SDL_Texture* PvP = LoadTexture("images\\menu\\pvp.png");
            SDL_Texture* PvE = LoadTexture("images\\menu\\pve.png");
            SDL_Texture* Shop = LoadTexture("images\\menu\\shop.png");

            SDL_Rect PvPRect, PvERect, ShopRect;
            SDL_QueryTexture(PvP, NULL, NULL, &PvPRect.w, &PvPRect.h);
            SDL_QueryTexture(PvE, NULL, NULL, &PvERect.w, &PvERect.h);
            SDL_QueryTexture(Shop, NULL, NULL, &ShopRect.w, &ShopRect.h);

            PvPRect.x = (1440 - PvPRect.w) / 2;
            PvPRect.y = 680;

            PvERect.x = 250;
            PvERect.y = 680;

            ShopRect.x = 1000;
            ShopRect.y = 680;

            gWindowGameMenu.Draw(PvP, &PvPRect);
            gWindowGameMenu.Draw(PvE, &PvERect);
            gWindowGameMenu.Draw(Shop, &ShopRect);

            if (gCursorMenu.IsCursorInRect(&PvPRect) == SDL_TRUE)
            {

                SDL_Texture* PvP1 = LoadTexture("images/menu/pvp - Copy.png");
                SDL_Rect PvP1Rect;
                SDL_QueryTexture(PvP1, NULL, NULL, &PvP1Rect.w, &PvP1Rect.h);
                PvP1Rect.x = (1440 - PvP1Rect.w) / 2;
                PvP1Rect.y = 680;
                gWindowGameMenu.Draw(PvP1, &PvP1Rect);
                SDL_DestroyTexture(PvP1);

                if (gTypeInput == TypeInputCursor::LEFT_CURSOR)
                {
                    s1PvP = true;
                    
                }
            }
            else if (gCursorMenu.IsCursorInRect(&PvERect) == SDL_TRUE)
            {
                SDL_Texture* PvE1 = LoadTexture("images/menu/pve - Copy.png");
                SDL_Rect PvE1Rect;
                SDL_QueryTexture(PvE1, NULL, NULL, &PvE1Rect.w, &PvE1Rect.h);
                PvE1Rect.x = 250;
                PvE1Rect.y = 680;
                gWindowGameMenu.Draw(PvE1, &PvE1Rect);
                SDL_DestroyTexture(PvE1);
                if (gTypeInput == TypeInputCursor::LEFT_CURSOR)
                {
                    s1PvE = true;
                }
                
            }
            else if (gCursorMenu.IsCursorInRect(&ShopRect))
            {
                SDL_Texture* Shop1 = LoadTexture("images/menu/shop - Copy.png");
                SDL_Rect Shop1Rect;
                SDL_QueryTexture(Shop1, NULL, NULL, &Shop1Rect.w, &Shop1Rect.h);
                Shop1Rect.x = 1000;
                Shop1Rect.y = 680;
                gWindowGameMenu.Draw(Shop1, &Shop1Rect);
                SDL_DestroyTexture(Shop1);
                if (gTypeInput == TypeInputCursor::LEFT_CURSOR)
                {
                    s1Shop = true;
                }

            }
            if (s1PvP)
            {
                int dx = DEST_X - PvP2Rect.x;
                int dy = DEST_Y - PvP2Rect.y;
                int distance = sqrt(dx * dx + dy * dy);

                if (distance > 1 && dy > 0) {
                    float stepX = dx / (float)distance;
                    float stepY = dy / (float)distance;

                    PvP2Rect.x += (int)(stepX * 30);
                    PvP2Rect.y += (int)(stepY * 30);
                }
                gWindowGameMenu.Draw(PvP2, &PvP2Rect);
                gWindowGameMenu.EndDraw();
            }
            if (s1PvE)
            {
                int dx = DEST_X1 - PvE2Rect.x;
                int dy = DEST_Y1 - PvE2Rect.y;
                int distance = sqrt(dx * dx + dy * dy);

                if (distance > 1 && dy > 0) {
                    float stepX = dx / (float)distance;
                    float stepY = dy / (float)distance;

                    PvE2Rect.x += (int)(stepX * 30);
                    PvE2Rect.y += (int)(stepY * 30);
                }
                gWindowGameMenu.Draw(PvE2, &PvE2Rect);
                gWindowGameMenu.EndDraw();
            }

            if (s1Shop)
            {
                int dx = DEST_X2 - Shop2Rect.x;
                int dy = DEST_Y2 - Shop2Rect.y;
                int distance = sqrt(dx * dx + dy * dy);

                if (distance > 1 && dy > 0) {
                    float stepX = dx / (float)distance;
                    float stepY = dy / (float)distance;

                    Shop2Rect.x += (int)(stepX * 30);
                    Shop2Rect.y += (int)(stepY * 30);
                }
                gWindowGameMenu.Draw(Shop2, &Shop2Rect);
                gWindowGameMenu.EndDraw();
            }
            if (gCursorMenu.IsCursorInRect(&PvP2Rect))
            {

                SDL_Texture* PvP_D = LoadTexture("images/menu/PvP_D.png");
                SDL_Rect PvP_DRect;
                SDL_QueryTexture(PvP_D, NULL, NULL, &PvP_DRect.w, &PvP_DRect.h);
                PvP_DRect.x = (1440 - PvP_DRect.w) / 2;
                PvP_DRect.y = 100;
                gWindowGameMenu.Draw(PvP_D, &PvP_DRect);
                SDL_DestroyTexture(PvP_D);
                if (gTypeInput == TypeInputCursor::LEFT_CURSOR)
                {
                    gModeGameMenu = ModeGame::PvP;
                }

            }
            if (gCursorMenu.IsCursorInRect(&PvE2Rect))
            {

                SDL_Texture* PvE_D = LoadTexture("images/menu/PvE_D.png");
                SDL_Rect PvE_DRect;
                SDL_QueryTexture(PvE_D, NULL, NULL, &PvE_DRect.w, &PvE_DRect.h);
                PvE_DRect.x = (1440 - PvE_DRect.w) / 2;
                PvE_DRect.y = 100;
                gWindowGameMenu.Draw(PvE_D, &PvE_DRect);
                SDL_DestroyTexture(PvE_D);
                if (gTypeInput == TypeInputCursor::LEFT_CURSOR)
                {
                    gModeGameMenu = ModeGame::PvE;
                }
            }
            if (gCursorMenu.IsCursorInRect(&Shop2Rect))
            {
                if (gTypeInput == TypeInputCursor::LEFT_CURSOR)
                {
                    gModeGameMenu = ModeGame::SHOP;
                }
            }
            if (gModeGameMenu != ModeGame::WAIT)
            {
                break;
            }
        }
        gWindowGameMenu.EndDraw();
    }
    gWindowGameMenu.EndDraw();
    SDL_DestroyTexture(gWallPaper);
    SDL_DestroyTexture(gGameName);
    SDL_DestroyTexture(gDuelMode);
    SDL_DestroyTexture(gDeckContruction);
    SDL_DestroyTexture(gCardList);
    SDL_DestroyTexture(gOption);
    SDL_DestroyTexture(gQuitGame);
    return gModeGameMenu;
}

void MenuGame::CursorInput()
{
    SDL_Event gEvent;
    while (SDL_PollEvent(&gEvent) != 0)
    {
        switch (gEvent.type)
        {
        case SDL_QUIT:
            gWindowGameMenu.Destroy();
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
    gWindowGameMenu.BeginDraw();
    gWindowGameMenu.EndDraw();
}

void MenuGame::Cleanup()
{
    gCursorMenu.~Cursor();
    gSoundMenu.~SoundGame();
    gMusicMenu.~MusicGame();
    gWindowGameMenu.~WindowGame();

    IMG_Quit();
    Mix_Quit();
    SDL_Quit();
}

