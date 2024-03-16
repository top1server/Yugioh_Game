#include "cursor.h"

cursor::cursor() {
    curX = 0;
    curY = 0;
    cursorSurfaceDefault = NULL;
    cursorDefault = NULL;
}

cursor::~cursor() 
{
    if (cursorDefault)
        SDL_FreeCursor(cursorDefault);
    if (cursorSurfaceDefault)
        SDL_FreeSurface(cursorSurfaceDefault);
}

void cursor::SetImage(const std::string& path1) {
    cursorSurfaceDefault = IMG_Load(path1.c_str());
    if (!cursorSurfaceDefault) {
        printf("Failed to load default cursor image! SDL_image Error: %s\n", IMG_GetError());
        return;
    }
    
}

void cursor::DrawCursor() {
    if (!cursorSurfaceDefault) {
        std::cerr << "Cursor images not loaded! SDL_Error: " << SDL_GetError() << std::endl;
        return;
    }
    cursorDefault = SDL_CreateColorCursor(cursorSurfaceDefault, 0, 0);
    if (!cursorDefault) {
        std::cerr << "Failed to create default cursor! SDL_Error: " << SDL_GetError() << std::endl;
        return;
    }
    SDL_SetCursor(cursorDefault);
}

void cursor::GetPositionOfCursor() 
{
    SDL_GetMouseState(&curX, &curY);
}

void cursor::ChangeImage(const std::string& path2) 
{
    SetImage(path2.c_str());
    DrawCursor();
}

SDL_bool cursor::IsCursorInRect(const SDL_Rect* rect) {
    GetPositionOfCursor();
    SDL_Point point = { curX, curY };
    return SDL_PointInRect(&point, rect);
}

SDL_bool cursor::isCursorCollidingWithTexture(SDL_Renderer* renderer, SDL_Texture* texture)
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
