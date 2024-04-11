#include "Start.h"

void Start::StartAnimation()
{
    const int SCREEN_WIDTH = 1440;
    const int SCREEN_HEIGHT = 810;
    const int SPRITE_WIDTH = 800;
    const int SPRITE_HEIGHT = 450;
    const int ROWS = 15;
    const int COLUMNS = 10;
    const int TOTAL_FRAMES = 150;
    const int FRAME_DELAY = 60;
    SDL_Texture* gSpriteSheet = nullptr;
    gStartGame.SetUp("MAGIC DUEL", 1440, 810);
    SDL_Surface* iconSurface = IMG_Load("images/icon/icon1.png");
    if (!iconSurface)
    {
        std::cerr << "IMG_Load error: " << IMG_GetError() << std::endl;
        SDL_DestroyWindow(gStartGame.GetWindow());
        SDL_Quit();
        return;
    }
    SDL_SetWindowIcon(gStartGame.GetWindow(), iconSurface);

    SDL_Surface* loadedSurface = IMG_Load("images//background.png");
    if (loadedSurface == nullptr)
    {
        std::cerr << "Unable to load image! SDL Error: " << SDL_GetError() << std::endl;
        return;
    }

    gSpriteSheet = SDL_CreateTextureFromSurface(gStartGame.GetRenderer(), loadedSurface);
    if (gSpriteSheet == nullptr)
    {
        std::cerr << "Unable to create texture from image! SDL Error: " << SDL_GetError() << std::endl;
        return;
    }
    SDL_FreeSurface(loadedSurface);

    SDL_Event e;
    bool quit = false;
    int frame = 0;
    SDL_Rect clipRect;
    RunMusic();
    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }

        // Clear the screen
        SDL_RenderClear(gStartGame.GetRenderer());

        // Set the clip rectangle to the current frame
        clipRect.x = (frame % COLUMNS) * SPRITE_WIDTH;
        clipRect.y = (frame / COLUMNS) * SPRITE_HEIGHT;
        clipRect.w = SPRITE_WIDTH;
        clipRect.h = SPRITE_HEIGHT;

        SDL_RenderCopy(gStartGame.GetRenderer(), gSpriteSheet, &clipRect, NULL);
        gStartGame.EndDraw();
        frame++;
        //if (frame == 150) frame = 120;
        SDL_Delay(FRAME_DELAY);
    }
}
void Start::RunMusic()
{
    gStartMusic.SetMusic("musics/start1.mp3");
    gStartMusic.SetRepeat();
    gStartMusic.Play();
}
