#include "Cursor.h"

Cursor::Cursor() 
{
    curX = 0;
    curY = 0;
    CursorSurfaceDefault = NULL;
    CursorDefault = NULL;
}

Cursor::~Cursor()
{
    if (CursorDefault)
    {
        SDL_FreeCursor(CursorDefault);
        CursorDefault = NULL;
    }
        
    if (CursorSurfaceDefault)
    {
        SDL_FreeSurface(CursorSurfaceDefault);
        CursorSurfaceDefault = NULL;
    }
}

void Cursor::SetImage(const std::string& path) 
{
    CursorSurfaceDefault = IMG_Load(path.c_str());
    if (CursorSurfaceDefault == NULL) 
    {
        printf("Failed to load default Cursor image! SDL_image Error: %s\n", IMG_GetError());
        return;
    }

}

void Cursor::DrawCursor() 
{
    if (CursorSurfaceDefault == NULL) 
    {
        std::cerr << "Cursor images not loaded! SDL_Error: " << SDL_GetError() << std::endl;
        return;
    }
    CursorDefault = SDL_CreateColorCursor(CursorSurfaceDefault, 0, 0);
    if (CursorDefault == NULL) 
    {
        std::cerr << "Failed to create default Cursor! SDL_Error: " << SDL_GetError() << std::endl;
        CursorSurfaceDefault = NULL;
        return;
    }
    SDL_SetCursor(CursorDefault);
    //SDL_FreeCursor(CursorDefault);
    //SDL_FreeSurface(CursorSurfaceDefault);
}

void Cursor::GetPositionOfCursor()
{
    SDL_GetMouseState(&curX, &curY);
}

void Cursor::ChangeImage(const std::string& path2)
{
    SetImage(path2.c_str());
    DrawCursor();
}

SDL_bool Cursor::IsCursorInRect(const SDL_Rect* rect) 
{
    GetPositionOfCursor();
    SDL_Point point = { curX, curY };
    return SDL_PointInRect(&point, rect);
}

SDL_bool Cursor::isCursorCollidingWithTexture(SDL_Renderer* renderer, SDL_Texture* texture)
{
    GetPositionOfCursor();
    int textureWidth, textureHeight;
    SDL_QueryTexture(texture, NULL, NULL, &textureWidth, &textureHeight);
    SDL_Rect textureRect = { 0, 0, textureWidth, textureHeight };
    SDL_RenderGetViewport(renderer, &textureRect);

    if (curX >= textureRect.x && curX <= textureRect.x + textureRect.w &&
        curY >= textureRect.y && curY <= textureRect.y + textureRect.h)
    {
        return SDL_TRUE;
    }

    else
    {
        return SDL_FALSE;
    }
}

