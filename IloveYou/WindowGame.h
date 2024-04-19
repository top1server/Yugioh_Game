#ifndef WINDOW_GAME_H
#define WINDOW_GAME_H
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include<iostream>
#include<string>

const int SCREEN_WIDTH = 1440;
const int SCREEN_HEIGHT = 810;

class WindowGame
{   
private:
    SDL_Window* gWindow;
    SDL_Renderer* gRenderer;
    SDL_Rect gWindowRect;
    std::string gWindowTitle;
    bool gIsFullScreen;
    bool gIsDone;
public:
    WindowGame();
    ~WindowGame();
                                     
    void Create();                                      
    void SetUp(const std::string& title, int width, int height);   
    void BeginDraw();                                   
    void EndDraw();                                     
    bool IsDone();
    void Destroy();
    bool IsFullScreen();                                
    void Draw(SDL_Texture* texture ,SDL_Rect* rect);                    
    SDL_Rect GetWindowSize();  
    SDL_Renderer* GetRenderer() const {return gRenderer;}
    SDL_Window* GetWindow() const { return gWindow; }
    void DrawFull(SDL_Texture* texture, SDL_Rect *rect1, SDL_Rect* rect)
    {
        SDL_RenderCopy(gRenderer, texture, rect1, rect);
    }
    void RendererClear();
};

#endif
