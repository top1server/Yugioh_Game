#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = 338;
const int SPRITE_WIDTH = 600;
const int SPRITE_HEIGHT = 338;
const int ROWS = 33; // Số dòng
const int COLUMNS = 5;
const int TOTAL_FRAMES = 145;
const int FRAME_DELAY = 30; // Độ trễ giữa các frame (ms)

SDL_Window* gWindow = nullptr;
SDL_Renderer* gRenderer = nullptr;
SDL_Texture* gSpriteSheet = nullptr;

bool init() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }

    gWindow = SDL_CreateWindow("SDL Animation", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (gWindow == nullptr) {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }

    gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (gRenderer == nullptr) {
        std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }

    SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

    int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) & imgFlags)) {
        std::cerr << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << std::endl;
        return false;
    }

    return true;
}

bool loadMedia()
{
    SDL_Surface* loadedSurface = IMG_Load("images//turn.png");
    if (loadedSurface == nullptr) {
        std::cerr << "Unable to load image! SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }

    gSpriteSheet = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
    if (gSpriteSheet == nullptr) {
        std::cerr << "Unable to create texture from image! SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }
    SDL_FreeSurface(loadedSurface);
    return true;
}

void close() {
    SDL_DestroyTexture(gSpriteSheet);
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    IMG_Quit();
    SDL_Quit();
}

int main(int argc, char* args[]) {
    if (!init()) {
        std::cerr << "Failed to initialize!" << std::endl;
        return -1;
    }

    if (!loadMedia()) {
        std::cerr << "Failed to load media!" << std::endl;
        return -1;
    }

    SDL_Event e;
    bool quit = false;
    int frame = 0;
    SDL_Rect clipRect;

    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
            
        }
        SDL_RenderClear(gRenderer);

        // Set the clip rectangle to the current frame
        clipRect.x = (frame % COLUMNS) * SPRITE_WIDTH;
        clipRect.y = (frame / COLUMNS) * SPRITE_HEIGHT;
        clipRect.w = SPRITE_WIDTH;
        clipRect.h = SPRITE_HEIGHT;

        SDL_RenderCopy(gRenderer, gSpriteSheet, &clipRect, NULL);

        SDL_RenderPresent(gRenderer);
        frame++;
        if (frame == 145) frame = 0;
        SDL_Delay(FRAME_DELAY);



    }

    close();
    return 0;
}
