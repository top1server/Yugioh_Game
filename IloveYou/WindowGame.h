#ifndef WINDOW_GAME_H
#define WINDOW_GAME_H
#include <SDL.h>
#include<iostream>
#include<string>

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
    void Destroy();                                     
    void Create();                                      
    void SetUp(const std::string& title, int width, int height);   
    void BeginDraw();                                   
    void EndDraw();                                     
    void Updata();
    bool IsDone();
    bool IsFullScreen();                                
    void Draw(SDL_Texture* texture);                    
    SDL_Rect GetWindowSize();                           
    SDL_Window* GetWindow();                        
    SDL_Renderer* GetRenderer() {
        return gRenderer;
    }
};

#endif
