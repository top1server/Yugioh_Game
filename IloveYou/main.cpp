#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

const int SCREEN_WIDTH = 1440;
const int SCREEN_HEIGHT = 810;
const int SPRITE_WIDTH = 1440; // Chiều rộng của mỗi frame
const int SPRITE_HEIGHT = 810; // Chiều cao của mỗi frame
const int ROWS = 10; // Số dòng
const int COLUMNS = 8; // Số cột
const int TOTAL_FRAMES = ROWS * COLUMNS;
const int FRAME_DELAY = 100; // Độ trễ giữa các frame (ms)

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

bool loadMedia() {
    SDL_Surface* loadedSurface = IMG_Load("images//background.png");
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

        // Clear the screen
        SDL_RenderClear(gRenderer);

        // Set the clip rectangle to the current frame
        clipRect.x = (frame % COLUMNS) * SPRITE_WIDTH;
        clipRect.y = (frame / COLUMNS) * SPRITE_HEIGHT;
        clipRect.w = SPRITE_WIDTH;
        clipRect.h = SPRITE_HEIGHT;

        // Render the current frame
        SDL_RenderCopy(gRenderer, gSpriteSheet, &clipRect, NULL);

        // Update the screen
        SDL_RenderPresent(gRenderer);

        // Go to the next frame
        frame = (frame + 1) % TOTAL_FRAMES;

        // Delay to control frame rate
        SDL_Delay(FRAME_DELAY);
    }

    close();
    return 0;
}
