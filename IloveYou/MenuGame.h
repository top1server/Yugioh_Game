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
    void RunCursorAndMusicAndSound();
    ModeGame InitiationMenu();
    void CursorInput();
    void Render();
    void Cleanup();
    SDL_Texture* PvP2;
    SDL_Rect PvP2Rect;
    SDL_Texture* PvE2;
    SDL_Rect PvE2Rect;
    SDL_Texture* Shop2;
    SDL_Rect Shop2Rect;
    void AnimationPvP()
    {
        PvP2 = LoadTexture("images/menu/pvp2.png");
        PvP2Rect.w = 220;
        PvP2Rect.h = 400;
        PvP2Rect.x = (1440 - PvP2Rect.w) / 2;
        PvP2Rect.y = -400;
    }
    void AnimationPvE()
    {
        PvE2 = LoadTexture("images/menu/pve2.png");
        PvE2Rect.w = 220;
        PvE2Rect.h = 400;
        PvE2Rect.x = 220;
        PvE2Rect.y = -400;
    }
    void AnimationShop()
    {
        Shop2 = LoadTexture("images/menu/shop2.png");
        Shop2Rect.w = 220;
        Shop2Rect.h = 400;
        Shop2Rect.x = 970;
        Shop2Rect.y = -400;
    }
    int isSoundPlayed = 0;
    int isChangedCursor = 0;
    SDL_Texture* LoadTexture(const char* path)
    {
        SDL_Surface* surface = IMG_Load(path);
        if (!surface)
        {
            std::cerr << "Failed to load image! Error :" << SDL_GetError() << std::endl;
            return nullptr;
        }

        SDL_Texture* texture = SDL_CreateTextureFromSurface(gWindowGameMenu.GetRenderer(), surface);
        if (!texture)
        {
            std::cerr << "Unable to create texture! Error: " << SDL_GetError() << std::endl;
        }
        SDL_FreeSurface(surface);
        return texture;
    }
    
private:
    const int DEST_X = 610;
    const int DEST_Y = 230;
    const int DEST_X1 = 220;
    const int DEST_Y1 = 230;
    const int DEST_X2 = 970;
    const int DEST_Y2 = 230;
    WindowGame gWindowGameMenu;
    Volume gVolumeMenu;
    Cursor gCursorMenu;
    MusicGame gMusicMenu;
    SoundGame gSoundMenu;
    StateMenu gStateGameMenu;
    ModeGame gModeGameMenu;
    TypeInputCursor gTypeInput;
};

#endif
