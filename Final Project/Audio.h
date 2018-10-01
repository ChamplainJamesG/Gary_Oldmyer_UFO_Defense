//Zach Phillips
//Used to play audio and sounds
//tutorial from here: http://lazyfoo.net/tutorials/SDL/21_sound_effects_and_music/index.php
#pragma once

#include <SDL.h>
#include <SDL_mixer.h>
#include <stdio.h>
#include <string>
#include "Trackable.h"

struct SFXFile
{
	Mix_Chunk * mSFXFile;
	std::string mSoundName;
};

struct MusicFile
{
	Mix_Music * mMusicFile;
	std::string mSoundName;
};

class Audio : public Trackable
{
public:

	Audio();
	~Audio();

	void init();

	void addMusic(std::string filename, std::string soundName);
	void addSFX(std::string filename, std::string soundName);

	Mix_Music * getMusic(std::string name);
	Mix_Music * getMusic(int indexNumber);

	Mix_Chunk * getSFX(std::string name);
	Mix_Chunk * getSFX(int indexNumber);

	void playMusic(Mix_Music * sound);
	void playSFX(Mix_Chunk * sound);

	void playPauseMusic();
	void muteUnmuteAll();

private:

	MusicFile mMusicArray[10];
	SFXFile mSFXArray[10];

	int mMusicIndex = 0;
	int mSFXIndex = 0;

	bool mIsMute = false;
};
