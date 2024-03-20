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
    P1vsP2,
    PvsCPU,
    WAIT
};

enum class StateMenu
{
    WAIT,
    PLAY_GAME,
    OPTION_GAME,
    EXIT_GAME
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
    void HandleInput();
    void Render();
    void Cleanup();
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
};

#endif
