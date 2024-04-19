#ifndef GAME_H
#define GAME_H

#include "WindowGame.h"
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "MenuGame.h"
#include "Cursor.h"
#include "WindowGame.h"

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
	SoundGame SOUND;
	SoundGame CLICK;
	SoundGame CLICK_BUTTON;
	MusicGame MUSIC_MENU;
	MusicGame MUSIC_INGAME;
	ModeGame MODE;
	WindowGame WINDOW;
	Volume VOLUME;

	SDL_Texture* Background = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/map.png");

	SDL_Texture* Card1 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/phu thuy ao den.png");
	SDL_Texture* Card2 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/nu phu thuy ao den.png");
	SDL_Texture* Card3 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/yeu tinh than den.png");
	SDL_Texture* Card4 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/ao thuat gia.png");
	SDL_Texture* Card5 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/phu thuy rung den.png");
	SDL_Texture* Card6 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/ca chua than bi.png");
	SDL_Texture* Card7 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/song sing.png");
	SDL_Texture* Card8 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/kiem si diet rong.png");
	SDL_Texture* Card9 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/dung hop.png");
	SDL_Texture* Card10 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/da hien triet.png");
	SDL_Texture* Card11 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/hoi sinh.png");
	SDL_Texture* Card12 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/hu tham vong.png");
	SDL_Texture* Card13 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/khoa tan cong.png");
	SDL_Texture* Card14 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/kiem hac am.png");
	SDL_Texture* Card15 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/ma tran den.png");
	SDL_Texture* Card16 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/ruong tu than.png");
	SDL_Texture* Card17 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/song day.png");
	SDL_Texture* Card18 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/thuoc te.png");
	SDL_Texture* Card19 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/doi vi tri.png");
	SDL_Texture* Card20 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/giap phan don.png");
	SDL_Texture* Card21 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/goi hon.png");
	SDL_Texture* Card22 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/ham bay.png");
	SDL_Texture* Card23 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/la chan phan don - kinh phan xa.png");
	SDL_Texture* Card24 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/quan tai hoi sinh.png");
	SDL_Texture* Card25 = IMG_LoadTexture(WINDOW.GetRenderer(), "images/Yugi/vong luc vong tinh.png");

public:
	Game();
	void IntImageBackground(const std::string& l);
	void IntIconInGame();
	void HandleInput();
	void CreateGame1();// PvP
	void CreateGame2();// PvE
	void DrawIconInGame();
	void OutPutMenuGame();
	StateMenu GetStateGame();
	
	void DrawTurnPlayer();
	int WinOrLose();
};



#endif

