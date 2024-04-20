#include "Start.h"

void Start::StartAnimation()
{

    SDL_Texture *gSpriteSheet = nullptr;

    gStartGame.SetUp("MAGIC DUEL", SCREEN_WIDTH, SCREEN_HEIGHT);

    SDL_Surface *iconSurface = IMG_Load("images/icon/icon1.png");
    SDL_SetWindowIcon(gStartGame.GetWindow(), iconSurface);
    gSpriteSheet = IMG_LoadTexture(gStartGame.GetRenderer(), "images/bk.png");
    SDL_Event e;
    bool quit = false;
    int frame = 0;
    SDL_Rect clipRect;
    RunMusic();
    while (!quit)
    {
        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT && frame == 68)
            {
                gStartGame.Destroy();
                SDL_DestroyTexture(gSpriteSheet);
                quit = true;
            }
            
            else if (e.type == SDL_QUIT)
            {
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

        if (frame == 69)
        {
            frame = 68;
            
        }

        SDL_Delay(FRAME_DELAY);
    }
}
void Start::RunMusic()
{
    gStartMusic.SetMusic("musics/start.mp3");
    // gStartMusic.SetRepeat();
    gStartMusic.Play();
}
