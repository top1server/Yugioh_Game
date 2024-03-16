#include "cursor.h"

cursor::cursor() {
    curX = 0;
    curY = 0;
    cursorSurfaceDefault = nullptr;
    cursorDefault = nullptr;
    cursorSurfaceCustom = nullptr;
    cursorCustom = nullptr;
}

cursor::~cursor() 
{
    if (cursorDefault)
        SDL_FreeCursor(cursorDefault);
    if (cursorCustom)
        SDL_FreeCursor(cursorCustom);
    if (cursorSurfaceDefault)
        SDL_FreeSurface(cursorSurfaceDefault);
    if (cursorSurfaceCustom)
        SDL_FreeSurface(cursorSurfaceCustom);
}

void cursor::SetImage(const std::string& path1, const std::string& path2) {
    cursorSurfaceDefault = IMG_Load(path1.c_str());
    if (!cursorSurfaceDefault) {
        printf("Failed to load default cursor image! SDL_image Error: %s\n", IMG_GetError());
        return;
    }
    cursorSurfaceCustom = IMG_Load(path2.c_str());
    if (!cursorSurfaceCustom) {
        printf("Failed to load custom cursor image! SDL_image Error: %s\n", IMG_GetError());
        return;
    }
}

void cursor::DrawCursor() {
    if (!cursorSurfaceDefault || !cursorSurfaceCustom) {
        printf("Cursor images not loaded!\n");
        return;
    }

    cursorDefault = SDL_CreateColorCursor(cursorSurfaceDefault, 0, 0);
    if (!cursorDefault) {
        printf("Failed to create default cursor! SDL_Error: %s\n", SDL_GetError());
        return;
    }
    cursorCustom = SDL_CreateColorCursor(cursorSurfaceCustom, 0, 0);
    if (!cursorCustom) {
        printf("Failed to create custom cursor! SDL_Error: %s\n", SDL_GetError());
        return;
    }
    SDL_SetCursor(cursorDefault);
}

void cursor::GetPositionOfCursor() 
{
    SDL_GetMouseState(&curX, &curY);
}

void cursor::ChangeImage() 
{
    if (!cursorCustom) 
    {
        printf("Custom cursor not initialized!\n");
        return;
    }
    SDL_SetCursor(cursorCustom);
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
