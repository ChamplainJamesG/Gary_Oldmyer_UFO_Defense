#include "Audio.h"

Audio::Audio()
{
	init();
}

Audio::~Audio()
{
	for (int i = mMusicIndex; i >= 0; i--)
	{
		Mix_FreeMusic(mMusicArray[i].mMusicFile);
	}

	Mix_Quit();
}

void Audio::init()
{
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
	}
}

void Audio::addMusic(std::string musFilename, std::string soundName)
{
	if (mMusicIndex < 10)
	{
		MusicFile newFile;
		newFile.mMusicFile = Mix_LoadMUS(musFilename.c_str());
		newFile.mSoundName = soundName;
		mMusicArray[mMusicIndex] = newFile;
		mMusicIndex++;
	}
}

void Audio::addSFX(std::string musFilename, std::string soundName)
{
	if (mSFXIndex < 10)
	{
		SFXFile newFile;
		newFile.mSFXFile = Mix_LoadWAV(musFilename.c_str());
		newFile.mSoundName = soundName;
		mSFXArray[mSFXIndex] = newFile;
		mSFXIndex++;
	}
}

Mix_Music * Audio::getMusic(std::string name)
{
	bool foundFile = false;

	for (int i = 0; i < mMusicIndex; i++)
	{
		if (mMusicArray[i].mSoundName == name)
		{
			return mMusicArray[i].mMusicFile;
			foundFile = true;
		}
	}

	if (!foundFile)
		return NULL;

	return NULL;
}

Mix_Music * Audio::getMusic(int indexNumber)
{
	if (mMusicIndex >= indexNumber)
		return mMusicArray[mMusicIndex].mMusicFile;

	else
		return NULL;
}

Mix_Chunk * Audio::getSFX(std::string name)
{
	bool foundFile = false;

	for (int i = 0; i < mSFXIndex; i++)
	{
		if (mSFXArray[i].mSoundName == name)
		{
			return mSFXArray[i].mSFXFile;
			foundFile = true;
		}
	}

	if (!foundFile)
		return NULL;

	return NULL;
}

Mix_Chunk * Audio::getSFX(int indexNumber)
{
	if (mSFXIndex >= indexNumber)
		return mSFXArray[mSFXIndex].mSFXFile;

	else
		return NULL;
}

void Audio::playMusic(Mix_Music * music)
{
	Mix_PlayMusic(music, -1);
}

void Audio::playSFX(Mix_Chunk * sound)
{
	if (!mIsMute)
		Mix_PlayChannel(-1, sound, 0);
}

void Audio::playPauseMusic()
{
	//If the music is paused
	if (Mix_PausedMusic() == 1)
	{
		//Resume the music
		Mix_ResumeMusic();
	}
	//If the music is playing
	else
	{
		//Pause the music
		Mix_PauseMusic();
	}
}

void Audio::muteUnmuteAll()
{
	mIsMute = !mIsMute;
	playPauseMusic();
}