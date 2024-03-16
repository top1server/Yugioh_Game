#include "WindowGame.h"

WindowGame::WindowGame() {
    gWindow = NULL;
    gRenderer = NULL;
    gWindowRect = { 0,0,0,0 };
    gWindowTitle = "";
    gIsFullScreen = false;
    gIsDone = false;
}

void WindowGame::SetUp(const std::string& title, int SCREEN_WIDTH , int SCREEN_HEIGHT) {
    gWindowTitle = title;
    gWindowRect.w = SCREEN_WIDTH;
    gWindowRect.h = SCREEN_HEIGHT;
    Create();
}

WindowGame::~WindowGame() {
    Destroy();
}

void WindowGame::Create() {
    int flags = gIsFullScreen ? SDL_WINDOW_FULLSCREEN : 0;
    gWindow = SDL_CreateWindow(gWindowTitle.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, gWindowRect.w, gWindowRect.h, flags);
    if (gWindow == NULL)
    {
        std::cerr << "Window could not be created! Error: " << SDL_GetError() << std::endl;
    }

    gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
    if (gRenderer == NULL)
    {
        std::cerr << "Renderer could not be created! Error :" << SDL_GetError() << std::endl;
    }
}

void WindowGame::Destroy() {
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
}

void WindowGame::BeginDraw() {
    SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255);
    SDL_RenderClear(gRenderer);
}

void WindowGame::EndDraw() {
    SDL_RenderPresent(gRenderer);
}

bool WindowGame::IsDone() {
    return !gIsDone;
}

bool WindowGame::IsFullScreen() {
    return gIsFullScreen;
}

SDL_Rect WindowGame::GetWindowSize() {
    return gWindowRect;
}

void WindowGame::Draw(SDL_Texture* texture) {
    SDL_RenderCopy(gRenderer, texture, NULL, NULL);
}

SDL_Window* WindowGame::GetWindow() {
    return gWindow;
}
