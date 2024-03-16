#ifndef GAME_MENU_H
#define GAME_MENU_H

#include <SDL.h>
#include <vector>
#include <string>

class GameMenu {
public:
    enum MenuItem {
        PAUSE,
        EXIT,
        CONTINUE
    };

    GameMenu(SDL_Renderer* renderer, int screenWidth, int screenHeight);
    ~GameMenu();

    void render();
    MenuItem handleEvent(SDL_Event& e);

private:
    SDL_Renderer* mRenderer;
    int mScreenWidth;
    int mScreenHeight;
    std::vector<SDL_Rect> mMenuItemRects;
    std::vector<SDL_Texture*> mMenuItemTextures;
    int mCurrentItem;
};

#endif // GAME_MENU_H
