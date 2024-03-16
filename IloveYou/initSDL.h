#pragma once
#ifndef INIT_SDL_H
#define INIT_SDL_H

#include "parameter.h"
#include <SDL.h>
#include <SDL_image.h>


bool initSDL()
{
	bool success = true;
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cerr << "SDL couldn't initialize! Error : " << IMG_GetError() << std::endl;
		success = false;
	}

	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags))
	{
		std::cerr << "SDL_Image couldn't initialize! Error : " << IMG_GetError() << std::endl;
		success = false;
	}

	if (TTF_Init() == -1) {
		std::cerr << "SDL_ttf could not initialize! SDL_ttf Error: " << TTF_GetError() << std::endl;
		SDL_Quit();
		success = false;
	}

	gWindow = SDL_CreateWindow("SDL Window",
		                       SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		                       SCREEN_WIDTH, SCREEN_HEIGHT,
		                       SDL_WINDOW_SHOWN);
	if (gWindow == NULL) 
	{
		std::cerr << "Window could not be created! Error: " << SDL_GetError() << std::endl;
		success = false;
	}

	gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (gRenderer == NULL) 
	{
		std::cerr << "Renderer could not be created! Error :" <<  SDL_GetError() << std::endl;
		success = false;
	}

	SDL_Surface* backgroundSurface = IMG_Load("images//san dau.png");
	if (!backgroundSurface) {
		printf("Failed to load background image! SDL_image Error: %s\n", IMG_GetError());
		success = false;
	}

	gBackgroundTexture = SDL_CreateTextureFromSurface(gRenderer, backgroundSurface);
	if (!gBackgroundTexture) 
	{
		printf("Failed to create background texture! SDL_Error: %s\n", SDL_GetError());
		SDL_FreeSurface(backgroundSurface);
		success = false;
	}

	return success;
}

void closeSDL() {
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gRenderer = NULL;
	gWindow = NULL;

	IMG_Quit();
	SDL_Quit();
}

#endif