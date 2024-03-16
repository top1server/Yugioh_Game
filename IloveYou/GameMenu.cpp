#include "GameMenu.h"
#include <SDL_image.h>

GameMenu::GameMenu(SDL_Renderer* renderer, int screenWidth, int screenHeight) : mRenderer(renderer), mScreenWidth(screenWidth), mScreenHeight(screenHeight) {
    mMenuItemTextures.resize(3);
    mMenuItemTextures[PAUSE] = IMG_LoadTexture(renderer, "pause.png");
    mMenuItemTextures[EXIT] = IMG_LoadTexture(renderer, "exit.png");
    mMenuItemTextures[CONTINUE] = IMG_LoadTexture(renderer, "continue.png");

    mMenuItemRects.resize(3);
    for (size_t i = 0; i < mMenuItemTextures.size(); ++i) {
        SDL_QueryTexture(mMenuItemTextures[i], NULL, NULL, &mMenuItemRects[i].w, &mMenuItemRects[i].h);
        mMenuItemRects[i].x = (screenWidth - mMenuItemRects[i].w) / 2;
        mMenuItemRects[i].y = (screenHeight / 2) + 100 * (i - mMenuItemTextures.size() / 2);
    }

    mCurrentItem = 0;
}

GameMenu::~GameMenu() {
    for (auto& texture : mMenuItemTextures) {
        SDL_DestroyTexture(texture);
    }
}

void GameMenu::render() {
    SDL_SetRenderDrawColor(mRenderer, 0, 0, 0, 255);
    SDL_RenderClear(mRenderer);

    for (size_t i = 0; i < mMenuItemTextures.size(); ++i) {
        SDL_RenderCopy(mRenderer, mMenuItemTextures[i], NULL, &mMenuItemRects[i]);
    }

    SDL_RenderPresent(mRenderer);
}

GameMenu::MenuItem GameMenu::handleEvent(SDL_Event& e) {
    if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT) {
        int x, y;
        SDL_GetMouseState(&x, &y);  
        for (size_t i = 0; i < mMenuItemRects.size(); ++i) {
            if (x >= mMenuItemRects[i].x && x < mMenuItemRects[i].x + mMenuItemRects[i].w &&
                y >= mMenuItemRects[i].y && y < mMenuItemRects[i].y + mMenuItemRects[i].h) {
                return static_cast<MenuItem>(i);
            }
        }
    }
    return CONTINUE;
}
