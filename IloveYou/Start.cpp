#include "Start.h"

void Start::StartAnimation()
{
    const int SCREEN_WIDTH = 1440;
    const int SCREEN_HEIGHT = 810;
    const int SPRITE_WIDTH = 800;
    const int SPRITE_HEIGHT = 450;
    const int ROWS = 10;
    const int COLUMNS = 7;
    const int TOTAL_FRAMES = 70;
    const int FRAME_DELAY = 35;
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

    gSpriteSheet = IMG_LoadTexture(gStartGame.GetRenderer(), "images/bk.png");
    
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
        SDL_RenderClear(gStartGame.GetRenderer());

        clipRect.x = (frame % COLUMNS) * SPRITE_WIDTH;
        clipRect.y = (frame / COLUMNS) * SPRITE_HEIGHT;
        clipRect.w = SPRITE_WIDTH;
        clipRect.h = SPRITE_HEIGHT;

        SDL_RenderCopy(gStartGame.GetRenderer(), gSpriteSheet, &clipRect, NULL);
        gStartGame.EndDraw();
        frame++;
        if (frame == 71) gStartGame.Destroy();
        SDL_Delay(FRAME_DELAY);
    }
}
void Start::RunMusic()
{
    gStartMusic.SetMusic("musics/start.mp3");
    //gStartMusic.SetRepeat();
    gStartMusic.Play();
}
