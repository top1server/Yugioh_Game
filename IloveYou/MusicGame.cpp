#include "MusicGame.h"

MusicGame::MusicGame() 
{
    gRepeatMusic = false;
    gVolumeMusic = 40;
    gStateMusic = stateMusic::STOP;
    gMusic = NULL;
}

MusicGame::~MusicGame() {
    Stop(); 
}

void MusicGame::SetMusic(const std::string& path) {
    gMusic = Mix_LoadMUS(path.c_str());
    if (gMusic == NULL) {
        std::cerr << "Error: Failed to load music file: " << path << " Error: " << Mix_GetError() << std::endl;
        return;
    }
}

void MusicGame::SetRepeat() {
    gRepeatMusic = true;
}

void MusicGame::Play() {
    if (gMusic != NULL) {
        if (Mix_PlayMusic(gMusic, gRepeatMusic ? -1 : 0) == -1) {
            std::cerr << "Error: Failed to play music! Error: " << Mix_GetError() << std::endl;
            return;
        }
        else {
            gStateMusic = stateMusic::PLAY;
        }
    }
}

void MusicGame::Pause() {
    if (gStateMusic == stateMusic::PLAY) {
        Mix_PauseMusic();
        gStateMusic = stateMusic::PAUSE;
    }
}

void MusicGame::Stop() {
    Mix_HaltMusic();
    gStateMusic = stateMusic::STOP;
}

void MusicGame::ChangeVolume(int volume) {
    gVolumeMusic = volume;
    Mix_VolumeMusic(volume);
}

void MusicGame::Continue() {
    if (gStateMusic == stateMusic::PAUSE) {
        Mix_ResumeMusic();
        gStateMusic = stateMusic::PLAY;
    }
}

stateMusic MusicGame::GetStateMusic() {
    return gStateMusic;
}
