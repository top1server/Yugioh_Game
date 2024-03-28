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

    gMusicMenu.SetMusic("musics//MenuMusic.wav");
    gMusicMenu.SetRepeat();
    gMusicMenu.Play();

    //Load cursor click sound
    gSoundMenu.SetSoundBuffer("musics//ClickCursor.mp3");
    gSoundMenu.ChangeVolumeSound(45);

    //Load cursor 
    gCursorMenu.SetImage("images//mouse//mouse1.png");
    gCursorMenu.DrawCursor();
}



StateMenu MenuGame::InitiationMenu()
{
    gVolumeMenu.Sound = 70;
    gVolumeMenu.Music = 30;
    gStateGameMenu = StateMenu::WAIT;
    gModeGameMenu = ModeGame::WAIT;
    RunCursorAndMusicAndSound();

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

    bool s1 = false;
    bool s2 = false;
    bool s3 = false;
    bool s4 = false;
    bool s5 = false;
    
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
            SDL_Texture* gDuelModeBig = LoadTexture("images/menu/DUELMODE_BIG.png");
            SDL_Rect DuelModeBigRect;
            SDL_QueryTexture(gDuelModeBig, NULL, NULL, &DuelModeBigRect.w, &DuelModeBigRect.h);
            DuelModeBigRect.x = (1440 - DuelModeBigRect.w) / 2;
            DuelModeBigRect.y = 300;
            gWindowGameMenu.Draw(gDuelModeBig, &DuelModeBigRect);
            SDL_DestroyTexture(gDuelModeBig);

            if (gTypeInput == TypeInputCursor::LEFT_CURSOR)
            {
                s1 = true;
            }
        }
        
        else if (gCursorMenu.IsCursorInRect(&DeckContructionRect) == SDL_TRUE)
        {
            SDL_Texture* gDeckContructionBig = LoadTexture("images/menu/DECKCONTRUCTION_BIG.png");
            SDL_Rect DeckContructionBigRect;
            SDL_QueryTexture(gDeckContructionBig, NULL, NULL, &DeckContructionBigRect.w, &DeckContructionBigRect.h);
            DeckContructionBigRect.x = (1440 - DeckContructionBigRect.w) / 2;
            DeckContructionBigRect.y = 380;
            gWindowGameMenu.Draw(gDeckContructionBig, &DeckContructionBigRect);
            SDL_DestroyTexture(gDeckContructionBig);
        }
       

        else if (gCursorMenu.IsCursorInRect(&CardListRect) == SDL_TRUE)
        {
            SDL_Texture* gCardListBig = LoadTexture("images/menu/CARDLIST_BIG.png");
            SDL_Rect CardListBigRect;
            SDL_QueryTexture(gCardListBig, NULL, NULL, &CardListBigRect.w, &CardListBigRect.h);
            CardListBigRect.x = (1440 - CardListBigRect.w) / 2;
            CardListBigRect.y = 460;
            gWindowGameMenu.Draw(gCardListBig, &CardListBigRect);
            SDL_DestroyTexture(gCardListBig);
        }
        

        else if (gCursorMenu.IsCursorInRect(&OptionRect) == SDL_TRUE)
        {
            SDL_Texture* gOptionBig = LoadTexture("images/menu/OPTION_BIG.png");
            SDL_Rect OptionBigRect;
            SDL_QueryTexture(gOptionBig, NULL, NULL, &OptionBigRect.w, &OptionBigRect.h);
            OptionBigRect.x = (1440 - OptionBigRect.w) / 2;
            OptionBigRect.y = 540;
            gWindowGameMenu.Draw(gOptionBig, &OptionBigRect);
            SDL_DestroyTexture(gOptionBig);
        }
        

        else if (gCursorMenu.IsCursorInRect(&QuitGameRect) == SDL_TRUE)
        {
            SDL_Texture* gQuitGameBig = LoadTexture("images/menu/QUITGAME_BIG.png");
            SDL_Rect QuitGameBigRect;
            SDL_QueryTexture(gQuitGameBig, NULL, NULL, &QuitGameBigRect.w, &QuitGameBigRect.h);
            QuitGameBigRect.x = (1440 - QuitGameBigRect.w) / 2;
            QuitGameBigRect.y = 620;
            gWindowGameMenu.Draw(gQuitGameBig, &QuitGameBigRect);
            SDL_DestroyTexture(gQuitGameBig);
        }

        if (s1)
        {   
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
                SDL_Texture* PvP1 = LoadTexture("images/menu/pvp2.jpg");
                
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

    return StateMenu::QUIT_GAME;
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
                if (!isSoundPlayed)
                {
                    gSoundMenu.Play();

                    gMusicMenu.SetMusic("Musics/ChooseMode.mp3");
                    gMusicMenu.SetRepeat();
                    gMusicMenu.Play();
                }
                isSoundPlayed = true;
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

