#include "WindowGame.h"

WindowGame::WindowGame() 
{
    gWindow = NULL;
    gRenderer = NULL;
    gWindowRect = { 0,0,0,0 };
    gWindowTitle = "";
    gIsFullScreen = false;
    gIsDone = false;
}

void WindowGame::SetUp(const std::string& title, int SCREEN_WIDTH , int SCREEN_HEIGHT) 
{
    gWindowTitle = title;
    gWindowRect.w = SCREEN_WIDTH;
    gWindowRect.h = SCREEN_HEIGHT;
    Create();
}

WindowGame::~WindowGame() 
{
    Destroy();
}

void WindowGame::Create() {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
    {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return;
    }
    int flags = gIsFullScreen ? SDL_WINDOW_FULLSCREEN : 0;
    gWindow = SDL_CreateWindow(gWindowTitle.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, gWindowRect.w, gWindowRect.h, flags);
    if (gWindow == NULL)
    {
        std::cerr << "Window could not be created! Error: " << SDL_GetError() << std::endl;
        return;
    }

    gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
    if (gRenderer == NULL)
    {
        std::cerr << "Renderer could not be created! Error :" << SDL_GetError() << std::endl;

    }
    int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) & imgFlags))
    {
        std::cerr << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << std::endl;
        
        return;
    }

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    {
        std::cerr << "SDL_mixer could not initialize! SDL_mixer Error: " << Mix_GetError() << std::endl;
        return;
    }
}

void WindowGame::Destroy() 
{
        SDL_DestroyRenderer(gRenderer);
        gRenderer = NULL;

        SDL_DestroyWindow(gWindow);
        gWindow = NULL;
}

void WindowGame::BeginDraw() 
{
    SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 255);
    SDL_RenderClear(gRenderer);
}

void WindowGame::EndDraw() 
{
    SDL_RenderPresent(gRenderer);
}

bool WindowGame::IsDone() 
{
    return !gIsDone;
}

bool WindowGame::IsFullScreen() 
{
    return gIsFullScreen;
}

SDL_Rect WindowGame::GetWindowSize() 
{
    return gWindowRect;
}

void WindowGame::Draw(SDL_Texture* texture ,SDL_Rect* rect) 
{
    SDL_RenderCopy(gRenderer, texture, NULL, rect);
}


void WindowGame::RendererClear()
{
    SDL_RenderClear(GetRenderer());
}


