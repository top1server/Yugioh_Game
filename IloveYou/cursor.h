#ifndef CURSOR_H
#define CURSOR_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>

#include <iostream>

class cursor
{
public:
	
	SDL_Surface* cursorSurfaceDefault;
	SDL_Cursor* cursorDefault;
	
	int curX, curY;

	cursor();
	~cursor();

	void SetImage(const std::string& path);
	void GetPositionOfCursor();
	void DrawCursor();
	void ChangeImage(const std::string& path);

	SDL_bool IsCursorInRect(const SDL_Rect* rect);
	SDL_bool isCursorCollidingWithTexture(SDL_Renderer* renderer, SDL_Texture* texture);

};
#endif