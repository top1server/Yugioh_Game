#ifndef START_H
#define START_H

#include "SDL.h"
#include "SDL_image.h"
#include "WindowGame.h"
#include "MusicGame.h"


class Start :WindowGame
{
private:
	WindowGame gStartGame;
	MusicGame gStartMusic;
public:
	bool isPlayMusic = false;
	void RunMusic();
	void StartAnimation();

};

#endif
