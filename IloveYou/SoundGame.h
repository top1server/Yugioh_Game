#ifndef SOUND_GAME_H
#define SOUND_GAME_H

#pragma once
#include <SDL.h>
#include <SDL_mixer.h>
#include <iostream>
#include <string>

class SoundGame {
private:
    Mix_Chunk* gChunk;
    std::string gLocationSound;
    bool gRepeatSound;
    int gVolumeSound;
public:
    SoundGame();
    ~SoundGame();
    void SetSoundBuffer(const std::string& path);
    void SetRepeatSound();
    void Play();
    void Pause();
    void Stop();
    void ChangeVolumeSound(int volume);
    Mix_Chunk* GetSound() const { return gChunk; }
};



#endif
