#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <string>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>

#include "WindowGame.h"
#include "MenuGame.h"
#include "Cursor.h"
#include "Start.h"

struct Monster
{
	int ID = 0,NS = 0, ATK = 0, DEF = 0;
	SDL_Texture* IMG = NULL;
	int State = 1; // ATK or DEF or UP  1 , 2 , 3
};

enum class TurnPlayer
{
	P1Play,
	P2Play
};

class Game
{
private:

	WindowGame WINDOW;
	TurnPlayer Turn;
	StateMenu STATE;
	ModeGame MODE;
	MenuGame MENU;
	SoundGame SOUND_ANIMATION;
	SoundGame CLICK;
	SoundGame CLICK_BUTTON;
	MusicGame MUSIC_MENU;
	MusicGame MUSIC_INGAME;
	Cursor CURSOR;
	Volume VOLUME;
	Start START;
	TypeInputCursor CURSOR_INPUT;
	
	SDL_Texture* BackGround;
	SDL_Texture* Undo;
	SDL_Texture* Speed;
	SDL_Texture* Option;

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

	SDL_Texture* E1;
	SDL_Texture* E2;
	SDL_Texture* E3;
	SDL_Texture* E4;
	SDL_Texture* E5;

	SDL_Rect BGRect;
	SDL_Rect UndoRect;
	SDL_Rect SpeedRect;
	SDL_Rect OptionRect;

	SDL_Rect HandRect[7];
	SDL_Rect FieldRect[5];
	SDL_Rect Spell_TrapRect[5];
	SDL_Rect EnemyFieldRect[5];

	bool Start = true;

	const int DEST_y = 620;
	int DEST_x[7];
	
	std::pair<int, int> DEST_MONSTER_IN_FIELD[5];
	std::pair<int, int> DEST_SPELL_TRAP_IN_FIELD[5];
	std::pair<int, int> DEST_SPELL_TRAP_IN_FIELD1[5];
	std::pair<int, int> DEST_MONSTER_IN_FIELDENEMY[5];

	bool MyTurn = true;    // lượt của tôi
	bool NewTurn = false;  // lượt mới của tôi để bốc bài
	bool IsDrawed = false; // bốc bài chưa
	bool Summon = true;    // triệu hồi quái thú chưa ( mỗi turn chỉ được 1 lần)

	int NumCardInHand = 0;
	int NumMonsterInField = 0;
	int NumSpellTrapInField = 0;
	int EnemyTurn = 0;
	int NumCardInHandEnemy = 5;
	int NumMonsterInFieldEnemy = 0;
	int NumSpellTrapInFieldEnemy = 0;

public:
	Game();
	void IntGame();
	void IntIconInGame();
	void IntImageBackGround();
	void HandleInput();
	void CreateGame1();// PvP
	void CreateGame2();// PvE
	void RenderStart();
	void LoadDeckYugi();
	void Describe(std::vector<Monster> vec , int i);
	void CreatTutorial();
	StateMenu GetStateGame();
	int WinOrLose = 0;
	int MyBlood = 8000, EnenyBlood = 8000; // m1 : me , m2:enemy
	SDL_Texture* loadTextTexture(const std::string& text, SDL_Color textColor) {

		SDL_Texture* newTexture = NULL;

		SDL_Surface* textSurface = TTF_RenderText_Solid(WINDOW.GetFont(), text.c_str(), textColor);
		if (textSurface == NULL) {
			std::cerr << "Unable to render text surface! SDL_ttf Error: " << TTF_GetError() << std::endl;
		}
		else {
			newTexture = SDL_CreateTextureFromSurface(WINDOW.GetRenderer(), textSurface);
			if (newTexture == NULL) {
				std::cerr << "Unable to create texture from rendered text! SDL Error: " << SDL_GetError() << std::endl;
			}
			SDL_FreeSurface(textSurface);
		}
		return newTexture;
	}
	SDL_Color textColor = { 250, 0, 0, 255 };
	SDL_Color textColor1 = { 0,255,0,255 };
	void moveAndRotateTexture(SDL_Texture* Card ,SDL_Rect startRect, SDL_Rect endRect) {
		float angle = 0.0f;
		bool forward = true;

		while (true) {
			SDL_Event e;
			while (SDL_PollEvent(&e) != 0) {
				if (e.type == SDL_QUIT) {
					return;
				}
			}
			//RenderStart();
			float progress = angle / (2 * M_PI);
			SDL_Rect currentRect;
			currentRect.x = startRect.x + (endRect.x - startRect.x) * progress;
			currentRect.y = startRect.y + (endRect.y - startRect.y) * progress;
			currentRect.w = startRect.w + (endRect.w - startRect.w) * progress;
			currentRect.h = startRect.h + (endRect.h - startRect.h) * progress;
			SDL_RenderCopyEx(WINDOW.GetRenderer(), Card, NULL, &currentRect, angle * 180.0f / M_PI, NULL, SDL_FLIP_NONE);
			WINDOW.EndDraw();

			if (forward) {
				angle += 0.05f;
				if (angle >= 2 * M_PI) {
					angle = 0.0f;
					forward = false;
				}
			}
			else {
				angle -= 0.05f;
				if (angle <= 0.0f) {
					break;
				}
			}
			SDL_Delay(3);
		}
	}
};


#endif

