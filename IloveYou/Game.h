#ifndef GAME_H
#define GAME_H

#include "WindowGame.h"
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "MenuGame.h"
#include "Cursor.h"
#include "WindowGame.h"
#include "Start.h"

enum class TurnPlayer
{
	P1Play,
	P2Play
};
class Game
{
private:
	StateMenu STATE;
	TurnPlayer BeginPlayer;
	TurnPlayer TurnPlayer;
	MenuGame MENU;
	SoundGame SOUND_ANIMATION;
	SoundGame CLICK;
	SoundGame CLICK_BUTTON;
	MusicGame MUSIC_MENU;
	MusicGame MUSIC_INGAME;
	Cursor CURSOR;
	ModeGame MODE;
	WindowGame WINDOW;
	Volume VOLUME;
	Start START;

	SDL_Texture* Card1;
	SDL_Texture* Card2;
	SDL_Texture* Card3;
	SDL_Texture* Card4;
	SDL_Texture* Card5;
	SDL_Texture* Card6;
	SDL_Texture* Card7;
	SDL_Texture* Card8;
	SDL_Texture* Card9;
	SDL_Texture* Card10;
	SDL_Texture* Card11;
	SDL_Texture* Card12;
	SDL_Texture* Card13;
	SDL_Texture* Card14;
	SDL_Texture* Card15;
	SDL_Texture* Card16;
	SDL_Texture* Card17;
	SDL_Texture* Card18;
	SDL_Texture* Card19;
	SDL_Texture* Card20;
	SDL_Texture* Card21;
	SDL_Texture* Card22;
	SDL_Texture* Card23;
	SDL_Texture* Card24;
	SDL_Texture* Card25;

public:
	Game();
	void IntGame();
	void IntIconInGame();
	void IntImageBackGround();
	void HandleInput();
	void CreateGame1();// PvP
	void CreateGame2();// PvE
	void OutPutMenuGame();
	StateMenu GetStateGame();
	
	void DrawTurnPlayer();
	int WinOrLose();

};



#endif

