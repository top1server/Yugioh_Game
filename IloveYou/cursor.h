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
public:
	int curX, curY;
	Cursor();
	~Cursor();

	void SetImage(const std::string& path);
	void GetPositionOfCursor();
	void DrawCursor();
	void ChangeImage(const std::string& path);

	SDL_bool IsCursorInRect(const SDL_Rect* rect);
	SDL_bool isCursorCollidingWithTexture(SDL_Renderer* renderer, SDL_Texture* texture);
	

};
#endif