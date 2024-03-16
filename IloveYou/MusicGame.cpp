#include "MusicGame.h"

MusicGame::MusicGame() {
    gRepeatMusic = false;
    gVolumeMusic = 100;
    gStateMusic = stateMusic::STOP;
    gMusic = nullptr;
}

MusicGame::~MusicGame() {
    Stop(); 
}

void MusicGame::SetMusic(const std::string& l) {
    gMusic = Mix_LoadMUS(l.c_str());
    if (gMusic == nullptr) {
        std::cerr << "Error: Failed to load music file: " << l << " Error: " << Mix_GetError() << std::endl;
    }
}

void MusicGame::SetRepeat() {
    gRepeatMusic = true;
}

void MusicGame::Play() {
    if (gMusic != nullptr) {
        if (Mix_PlayMusic(gMusic, gRepeatMusic ? -1 : 0) == -1) {
            std::cerr << "Error: Failed to play music! Error: " << Mix_GetError() << std::endl;
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
