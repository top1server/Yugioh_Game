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
	SDL_Surface* cursorSurfaceCustom;
	SDL_Cursor* cursorCustom;
	int curX, curY;

	cursor();
	~cursor();

	void SetImage(const std::string& path1 ,const std::string& path2);
	void GetPositionOfCursor();
	void DrawCursor();
	void ChangeImage();

	SDL_bool IsCursorInRect(const SDL_Rect* rect);
	SDL_bool isCursorCollidingWithTexture(SDL_Renderer* renderer, SDL_Texture* texture);

};
#endif