#include "Cursor.h"

Cursor::Cursor() 
{
    curX = 0;
    curY = 0;
    CursorSurfaceDefault = NULL;
    CursorDefault = NULL;
    CursorSurfaceCustom = NULL;
    CursorCustom = NULL;
}

void Cursor::CleanCursorCustom()
{
    if (CursorCustom)
    {
        SDL_FreeCursor(CursorCustom);
        CursorCustom = NULL;
    }

    if (CursorSurfaceCustom)
    {
        SDL_FreeSurface(CursorSurfaceCustom);
        CursorSurfaceCustom = NULL;
    }
}
void Cursor::CleanCursorDefault()
{
        if (CursorDefault)
        {
            SDL_FreeCursor(CursorDefault);
            CursorCustom = NULL;
        }

        if (CursorSurfaceDefault)
        {
            SDL_FreeSurface(CursorSurfaceDefault);
            CursorSurfaceDefault = NULL;
        }
}

void Cursor::SetImageDefault(const std::string& path) 
{
    CursorSurfaceDefault = IMG_Load(path.c_str());
    if (CursorSurfaceDefault == NULL) 
    {
        printf("Failed to load default Cursor image! SDL_image Error: %s\n", IMG_GetError());
        return;
    }
}
void Cursor::SetImageCustom(const std::string& path)
{
    CursorSurfaceCustom = IMG_Load(path.c_str());
    if (CursorSurfaceCustom == NULL)
    {
        printf("Failed to load custom Cursor image! SDL_image Error: %s\n", IMG_GetError());
        return;
    }

}

void Cursor::DrawCursorDefault() 
{
    if (CursorSurfaceDefault == NULL) 
    {
        std::cerr << "Cursor images Default not loaded! SDL_Error: " << SDL_GetError() << std::endl;
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
}

void Cursor::DrawCursorCustom()
{
    if (CursorSurfaceCustom == NULL)
    {
        std::cerr << "Cursor images custom not loaded! SDL_Error: " << SDL_GetError() << std::endl;
        return;
    }
    CursorCustom = SDL_CreateColorCursor(CursorSurfaceCustom, 0, 0);
    if (CursorCustom == NULL)
    {
        std::cerr << "Failed to create custom Cursor! SDL_Error: " << SDL_GetError() << std::endl;
        CursorSurfaceCustom = NULL;
        return;
    }
    SDL_SetCursor(CursorCustom);
}

void Cursor::GetPositionOfCursor()
{
    if (UpdateCursor) SDL_GetMouseState(&curX, &curY);
    else return;
}
void Cursor::NoUpdate()
{
    UpdateCursor = false;
}
void Cursor::ChangeImage(const std::string& path2)
{
    SetImageDefault(path2.c_str());
    DrawCursorDefault();
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

