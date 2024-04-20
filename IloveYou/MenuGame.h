#ifndef MENU_GAME_H
#define MENU_GAME_H

#include "WindowGame.h"
#include "SoundGame.h"
#include "MusicGame.h"
#include "Cursor.h"

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>


enum class ModeGame
{
    WAIT,
    PvP,
    PvE,
    SHOP
};

enum class StateMenu
{
    WAIT,
    DUEL_MODE,
    DECK_CONSTRUCTION,
    CARD_LIST,
    OPTION_GAME,
    QUIT_GAME
};

enum class TypeInputCursor
{
    LEFT_CURSOR,
    RIGHT_CURSOR,
    WAIT_CURSOR
};

struct Volume
{
    int Sound;
    int Music;
};

class MenuGame : WindowGame
{
public:
    MenuGame();
    ~MenuGame();
    void RunCursorAndMusicAndSound1();
    void RunCursorAndMusicAndSound2();
    void RunCursorAndMusicAndSound3();
    ModeGame InitiationMenuMode();
    StateMenu InitiationMenuState();
    void Deckconstruction();
    void CursorInput();
    void Render();
    void Cleanup();
    
    int isSoundPlayed = 0;
 
    ModeGame GetModeGame()
    {
        return gModeGameMenu;
    }

    void SetVolumeGame(Volume& v)
    {
        v.Music = gVolumeMenu.Music;
        v.Sound = gVolumeMenu.Sound;
    }
private:
    const int DEST_X = 610;
    const int DEST_Y = 220;
    const int DEST_X1 = 220;
    const int DEST_Y1 = 220;
    const int DEST_X2 = 970;
    const int DEST_Y2 = 220;
    WindowGame gWindowGameMenu1;
    WindowGame gWindowGameMenu2;
    WindowGame gWindowGameMenu3;
    Volume gVolumeMenu;
    Cursor gCursorMenu;
    MusicGame gMusicMenu;
    SoundGame gSoundMenu;
    StateMenu gStateGameMenu;
    ModeGame gModeGameMenu;
    TypeInputCursor gTypeInput;
};

#endif
