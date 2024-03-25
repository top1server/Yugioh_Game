#ifndef MENU_GAME_H
#define MENU_GAME_H

#include "WindowGame.h"
#include "SoundGame.h"
#include "MusicGame.h"
#include "Cursor.h"
#include <thread>


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
    CARD_CONSTRUCTION,
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
    StateMenu InitiationMenu();
    void CursorInput();
    void Render();
    void Cleanup();
    bool isSoundPlayed = false;
    SDL_Texture* LoadTexture(const char* path)
    {
        SDL_Surface* surface = IMG_Load(path);
        if (!surface)
        {
            std::cerr << "Failed to load image! Error :" << SDL_GetError() << std::endl;
            return nullptr;
        }

        // Tạo texture từ surface
        SDL_Texture* texture = SDL_CreateTextureFromSurface(gWindowGameMenu.GetRenderer(), surface);
        if (!texture)
        {
            std::cerr << "Unable to create texture! Error: " << SDL_GetError() << std::endl;
        }
        SDL_FreeSurface(surface);
        return texture;
    }
private:
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
