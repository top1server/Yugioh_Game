#ifndef START_H
#define START_H

#include "SDL.h"
#include "SDL_image.h"
#include "WindowGame.h"
#include "MusicGame.h"

const int SPRITE_WIDTH = 800;
const int SPRITE_HEIGHT = 450;
const int ROWS = 10;
const int COLUMNS = 7;
const int TOTAL_FRAMES = 69;
const int FRAME_DELAY = 20;

class Start :WindowGame
{
private:
	WindowGame gStartGame;
	MusicGame gStartMusic;
	SDL_Texture* gSpriteSheet;
	int frame = 0;
	SDL_Rect clipRect;
public:
	bool isPlayMusic = false;
	void RunMusic();
	void StartAnimation();
};

#endif
