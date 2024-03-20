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
    gWindowGameMenu.SetUp("MAGIC DUEL", 1440, 810);
    //Load music menu

    gMusicMenu.SetMusic("musics//MenuMusic.wav");
    gMusicMenu.SetRepeat();
    gMusicMenu.Play();

    //Load cursor click sound
    gSoundMenu.SetSoundBuffer("musics//ClickChess.wav");
    gSoundMenu.ChangeVolumeSound(35);

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
    GameNameRect.y = 200;

    DuelModeRect.x = (1440 - DuelModeRect.w) / 2;
    DuelModeRect.y = 350;

    DeckContructionRect.x = (1440 - DeckContructionRect.w) / 2;
    DeckContructionRect.y = 450;

    CardListRect.x = (1440 - CardListRect.w) / 2;
    CardListRect.y = 550;

    OptionRect.x = (1440 - CardListRect.w) / 2;
    OptionRect.y = 650;

    QuitGameRect.x = (1440 - QuitGameRect.w) / 2;
    QuitGameRect.y = 750;

    bool running = true;
    while (running)
    {
        HandleInput();
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                running = false;
            }
        }
        gWindowGameMenu.RendererClear();
        gWindowGameMenu.Draw(gWallPaper, &WallPaperRect);
        gWindowGameMenu.Draw(gGameName, &GameNameRect);

        if (gCursorMenu.IsCursorInRect(&DuelModeRect) == SDL_TRUE)
        {
            SDL_Texture* gDuelModeBig = LoadTexture("images/menu/DUELMODE_BIG.png");
            SDL_Rect DuelModeBigRect;
            SDL_QueryTexture(gDuelModeBig, NULL, NULL, &DuelModeBigRect.w, &DuelModeBigRect.h);
            DuelModeBigRect.x = (1440 - DuelModeBigRect.w) / 2;
            DuelModeBigRect.y = 350;
            gWindowGameMenu.Draw(gDuelModeBig, &DuelModeBigRect);
            SDL_DestroyTexture(gDuelModeBig);
        }
        else
        {
            gWindowGameMenu.Draw(gDuelMode, &DuelModeRect);

        }

        
        if (gCursorMenu.IsCursorInRect(&DeckContructionRect) == SDL_TRUE)
        {
            SDL_Texture* gDeckContructionBig = LoadTexture("images/menu/DECKCONTRUCTION_BIG.png");
            SDL_Rect DeckContructionBigRect;
            SDL_QueryTexture(gDeckContructionBig, NULL, NULL, &DeckContructionBigRect.w, &DeckContructionBigRect.h);
            DeckContructionBigRect.x = (1440 - DeckContructionBigRect.w) / 2;
            DeckContructionBigRect.y = 450;
            gWindowGameMenu.Draw(gDeckContructionBig, &DeckContructionBigRect);
            SDL_DestroyTexture(gDeckContructionBig);
        }
        else
        {
            gWindowGameMenu.Draw(gDeckContruction, &DeckContructionRect);
        }

        if (gCursorMenu.IsCursorInRect(&CardListRect) == SDL_TRUE)
        {
            SDL_Texture* gCardListBig = LoadTexture("images/menu/CARDLIST_BIG.png");
            SDL_Rect CardListBigRect;
            SDL_QueryTexture(gCardListBig, NULL, NULL, &CardListBigRect.w, &CardListBigRect.h);
            CardListBigRect.x = (1440 - CardListBigRect.w) / 2;
            CardListBigRect.y = 550;
            gWindowGameMenu.Draw(gCardListBig, &CardListBigRect);
            SDL_DestroyTexture(gCardListBig);
        }
        else
        {
            gWindowGameMenu.Draw(gCardList, &CardListRect);
        }

        if (gCursorMenu.IsCursorInRect(&OptionRect) == SDL_TRUE)
        {
            SDL_Texture* gOptionBig = LoadTexture("images/menu/OPTION_BIG.png");
            SDL_Rect OptionBigRect;
            SDL_QueryTexture(gOptionBig, NULL, NULL, &OptionBigRect.w, &OptionBigRect.h);
            OptionBigRect.x = (1440 - OptionBigRect.w) / 2;
            OptionBigRect.y = 650;
            gWindowGameMenu.Draw(gOptionBig, &OptionBigRect);
            SDL_DestroyTexture(gOptionBig);
        }
        else
        {
            gWindowGameMenu.Draw(gOption, &OptionRect);
        }

        if (gCursorMenu.IsCursorInRect(&QuitGameRect) == SDL_TRUE)
        {
            SDL_Texture* gQuitGameBig = LoadTexture("images/menu/QUITGAME_BIG.png");
            SDL_Rect QuitGameBigRect;
            SDL_QueryTexture(gQuitGameBig, NULL, NULL, &QuitGameBigRect.w, &QuitGameBigRect.h);
            QuitGameBigRect.x = (1440 - QuitGameBigRect.w) / 2;
            QuitGameBigRect.y = 750;
            gWindowGameMenu.Draw(gQuitGameBig, &QuitGameBigRect);
            SDL_DestroyTexture(gQuitGameBig);
        }
        else
        {
            gWindowGameMenu.Draw(gQuitGame, &QuitGameRect);
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


   




    

    return StateMenu::EXIT_GAME;
}

void MenuGame::HandleInput()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            gStateGameMenu = StateMenu::EXIT_GAME;
            break;
        case SDL_MOUSEBUTTONDOWN:
            if (event.button.button == SDL_BUTTON_LEFT)
            {
                gStateGameMenu = StateMenu::PLAY_GAME;
                break;
            }
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

