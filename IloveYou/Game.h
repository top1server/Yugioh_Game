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
	P1Play,P2Play
};

class Game
{
private:
	StateMenu stateGame;
	TurnPlayer BeginPlayer;
	TurnPlayer TurnPlayer;

	


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

