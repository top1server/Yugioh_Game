#include "SoundGame.h"

SoundGame::SoundGame() {
    gRepeatSound = false;
    gVolumeSound = 100;
    gChunk = NULL;
}

SoundGame::~SoundGame() {
    if (gChunk != nullptr) {
        Mix_FreeChunk(gChunk);
        gChunk = NULL;
    }
}

void SoundGame::SetSoundBuffer(const std::string& path) {
    gChunk = Mix_LoadWAV(path.c_str());
    if (gChunk == NULL) {
        std::cerr << "Error: Failed to load sound file: " << path << " Error: " << Mix_GetError() << std::endl;
    }
}

void SoundGame::Play() {
    if (gChunk != NULL) {
        Mix_PlayChannel(-1, gChunk, gRepeatSound ? -1 : 0);
    }
}

void SoundGame::Pause() {
    Mix_Pause(-1); 
}

void SoundGame::Stop() {
    Mix_HaltChannel(-1); 
}

void SoundGame::SetRepeatSound() {
    gRepeatSound = true;
}

void SoundGame::ChangeVolumeSound(int volume) {
    gVolumeSound = volume;
    Mix_Volume(-1, volume * MIX_MAX_VOLUME / 100);
}
