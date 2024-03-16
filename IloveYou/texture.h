#ifndef TEXTURE_H
#define TEXTURE_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdbool.h>

#include "parameter.h"
// tạo texture ở vị trí (x , y) trên màn hình
void CreateTextureAtPosition(const std::string& path, int x, int y)
{
	SDL_Surface* gSurface = IMG_Load(path.c_str());
	if (!gSurface)
	{
		std::cerr << "Failed to load image! SDL_image Error : " << SDL_GetError() << std::endl;
		return;

	}

	SDL_Texture* gTexture = SDL_CreateTextureFromSurface(gRenderer, gSurface);
	if (!gTexture)
	{
		std::cerr << "Failed to create Image! SDL_image Error : " << SDL_GetError() << std::endl;
		return;
	}

	SDL_FreeSurface(gSurface);

	int textureWidth, textureHeight;
	SDL_QueryTexture(gTexture, NULL, NULL, &textureWidth, &textureHeight);

	SDL_Rect pos = { x , y , textureWidth, textureHeight };
	SDL_RenderCopy(gRenderer, gTexture, NULL, &pos);

	SDL_DestroyTexture(gTexture);
}

// tạo texture từ file ảnh
SDL_Texture* loadTexture(const std::string& path) 
{
	SDL_Surface* gSurface = IMG_Load(path.c_str());
	if (gSurface == nullptr) 
	{
		std::cout << "Unable to load image " << path << "! SDL_image Error: " << IMG_GetError() << std::endl;
		return nullptr;
	}
	SDL_Texture* gTexture = SDL_CreateTextureFromSurface(gRenderer, gSurface);
	SDL_FreeSurface(gSurface);
	return gTexture;
}

// Vẽ texture tại tọa độ (x, y)
void renderTexture(SDL_Texture* gTexture, int x, int y) {
	int textureWidth, textureHeight;
	SDL_QueryTexture(gTexture, NULL, NULL, &textureWidth, &textureHeight);
	SDL_Rect renderQuad = { x, y, textureWidth, textureHeight };
	SDL_RenderCopy(gRenderer, gTexture, nullptr, &renderQuad);
}

#endif
