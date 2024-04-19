#ifndef CURSOR_H
#define CURSOR_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>

#include <iostream>

class Cursor
{
private:
	SDL_Surface* CursorSurfaceDefault;
	SDL_Cursor* CursorDefault;
	SDL_Surface* CursorSurfaceCustom;
	SDL_Cursor* CursorCustom;
public:
	int curX, curY;
	Cursor();
	void CleanCursorCustom();
	void CleanCursorDefault();
	bool UpdateCursor = true;
	void SetImageDefault(const std::string& path);
	void SetImageCustom(const std::string& path);
	void GetPositionOfCursor();
	void DrawCursorDefault();
	void DrawCursorCustom();
	void ChangeImage(const std::string& path);
	void NoUpdate();
	SDL_bool IsCursorInRect(const SDL_Rect* rect);
	SDL_bool isCursorCollidingWithTexture(SDL_Renderer* renderer, SDL_Texture* texture);
};
#endif