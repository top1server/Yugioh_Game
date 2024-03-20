#ifndef MUSIC_GAME_H
#define MUSIC_GAME_H
#include <SDL.h>
#include <SDL_mixer.h>
#include <iostream>
#include <string>

enum class stateMusic
{
    PAUSE,
    PLAY,
    STOP,
};

class MusicGame {
private:
    Mix_Music* gMusic;
    std::string gLocationSound;
    bool gRepeatMusic;
    int gVolumeMusic;
    stateMusic gStateMusic;

public:
    MusicGame();
    ~MusicGame();

    void SetMusic(const std::string& l);
    void SetRepeat();
    void Play();
    void Pause();
    void Stop();
    void ChangeVolume(int volume);
    void Continue();
    stateMusic GetStateMusic();
    Mix_Music* GetMusic()const { return gMusic; }
};
#endif