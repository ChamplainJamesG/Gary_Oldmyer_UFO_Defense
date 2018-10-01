#include "Trackable.h"
#include "System.h"
#include "Unit.h"
#include "GraphicsBufferManager.h"
#include "UnitManager.h"
#include "EventListener.h"
#include "EventSystem.h"
#include "Event.h"
#include "InputTranslator.h"
#include "Level.h"
#include "PlayerManager.h"
#include "LevelManager.h"
#include "EnemyManager.h"
#include "Buttons.h"
#include "ButtonManager.h"
#include "Audio.h"
#include "CinematicManager.h"

#pragma once
#ifndef GAME_H
#define GAME_H
const std::string FILE_PATH = "..\\..\\shared\\assets\\";
const std::string SMURF_SPRITES = "smurf_sprites.png";
const std::string DEAN_SPRITES = "dean_sprites.png";
const std::string WOODS_NAME = "Woods.png";
const std::string SQUARE_NAME = "square.bmp";

const std::string GB_WOODS_NAME = "Woods";
const std::string GB_SMURF_NAME = "SmurfSprite";
const std::string GB_DEAN_NAME = "DeanSprite";

class EventSystem;

class Game : public EventListener
{
public:
	Game(EventSystem *pSystem);
	~Game();

	void init(float width, float height, ifstream& fin); //add buffers here
	void initBuffers(std::string fileName1, std::string fileName2, std::string fileName3);
	void addSprites(Sprite sprite[], int count, bool anim);
	void createUnit(Unit unit);
	void makeUnit();
	void removeUnit();
	bool compareLoc(Unit unit);
	//just have game own system
	void cleanup();
	void doLoop();

	void handleEvent(const Event& theEvent);

	void changePlayerDir(DIRECTION dir);

	void addPlayer();

	void checkEnd();
	void checkLevel();

	void updateHUD(double dt);

	void loadNextLevel(int level);

	bool rollSpawn();

	void resetEnemies();

private:
	System *mSystem;
	GraphicsBuffer mGraphicsBuffer1;
	GraphicsBuffer mGraphicsBuffer2, mGraphicsBuffer3;
	Unit mUnit;
	bool mInitG;
	Player mPlayer;
	//put buffers in here
	//put a single unit in here
	GraphicsBufferManager mGBManager;
	UnitManager mUnitManager;
	InputSystem *mInputSystem;
	Level mLevel;
	PlayerManager mPlayerManager;
	Player mPlayerTemplate;
	LevelManager mLevelManager;
	ButtonManager mButtonManager;
	int mScore = 0;
	int mPUSpawnRate;
	EnemyManager mEnemyManager;
	Audio mAudioPlayer;
	CinematicManager mCinManager;

	//setting up the language map
	std::string mLanguageFilename;
	std::string mLanguageChoice = "ENGLISH";
	std::string mShownLanguageOption = " ";
	std::string mShownLevelOption = " ";
	std::map <std::string, std::string> mLanguageMap = {
		{ "PLAY", ""},
		{ "OPTIONS", ""},
		{ "LOAD", "" },
		{ "QUIT", "" },
		{ "ENGLISH", "" },
		{ "LATIN", "" },
		{ "FRENCH", "" },
		{ "LEVEL", "" },
		{ "EASY", "" },
		{ "MEDIUM", "" },
		{ "HARD", "" },
		{ "RETURN", "" },
		{ "SCORE", "" },
		{ "YOU LOSE", "" },
		{ "LIVES", ""},
		{ "MUTE", "" }
	};
	//0 = English, 1 = Latin, 2 = French
	int mLanguageNumChoice = 0;

	//0 = Easy, 1 = Medium, 2 = End
	int mLevelNumChoice = 0;
	
	//button text offset vars due to language
	int mPlayOffset;
	int mOptionsOffset;
	int mLoadOffset;
	int mQuitOffset;
	int mEnglishOffset;
	int mLatinOffset;
	int mFrenchOffset;
	int mEasyOffset;
	int mMediumOffset;
	int mHardOffset;
	int mReturnOffset;
	int mMuteOffset;

	Vector2D mMenuButtonPosMENU;
	Vector2D mOptionsButtonPosMENU;
	Vector2D mLoadGameButtonPosMENU;
	Vector2D mQuitButtonPosMENU;
	Vector2D mMenuButtonPosOPTIONS;
	Vector2D mEnglishButtonPosOPTIONS;
	Vector2D mLatinButtonPosOPTIONS;
	Vector2D mFrenchButtonPosOPTIONS;
	Vector2D mEasyButtonPosOPTIONS;
	Vector2D mMediumButtonPosOPTIONS;
	Vector2D mHardButtonPosOPTIONS;
	Vector2D mMuteMusicPosOPTIONS;

	//needed to draw backgounds
	Sprite mMainMenuScreen;
	Sprite mOptionsScreen;
	Sprite mGameBackground;

	Sprite mIntroCineBackground;

	Buttons* mBaseButton;

	//player and enemy constants
	Animation foodAnim;
	Sprite playerSprite;
	Sprite player2Sprite;
	Sprite shot;

	void setDrawnButtons(std::string sceneName);

	void resetGame();
	void setUpLanguage();
	void setUpOffsets();
	void changeLanguage(std::string language);

	void save();
	void load();

protected:
	bool mDoneLoop = false;
	bool mDoAnim = true;
	int mCurLevel = 0;
	bool mStartLevel = false;
	bool mStartGame = false;
	bool mInCinematic = true;
	bool mInStart = false;
	bool mInOptions = false;
	bool mEndGame = false;
	bool mIsGameDone = false;
	bool mWinGame = false;
	bool mIsQuit = false;
	bool mPowerUpSpawn;
};

#endif

/*
IN GLIB
InputSystem fireEvent
into EventSystem
which handles the event

Game fires an event into the event system
which handles the event

Input Translator translates allegro input into our input. Therefore Input system goes in GraphicsLib


*/