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

#pragma once
#ifndef GAME_H
#define GAME_H
const std::string FILE_PATH = "..\\..\\shared\\assets\\";
const std::string SMURF_SPRITES = "smurf_sprites.png";
const std::string DEAN_SPRITES = "dean_sprites.png";
const std::string WOODS_NAME = "Woods.png";
const std::string SQUARE_NAME = "square.png";

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

	void updateHUD(float dt);

	void loadNextLevel(int level);

	bool rollSpawn();

private:
	System *mSystem;
	GraphicsBuffer mGraphicsBuffer1;
	GraphicsBuffer mGraphicsBuffer2, mGraphicsBuffer3;
	Unit mUnit;
	bool mInitG;
	//put buffers in here
	//put a single unit in here
	GraphicsBufferManager mGBManager;
	UnitManager mUnitManager;
	InputTranslator *mTranslator;
	Level mLevel;
	PlayerManager mPlayerManager;
	Player mPlayerTemplate;
	LevelManager mLevelManager;
	int mScore = 0;
	int mPUSpawnRate;

protected:
	bool mDoneLoop = false;
	bool mDoAnim = true;
	int mCurLevel = 0;
	bool mStartLevel = false;
	bool mStartGame = false;
	bool mEndGame = false;
	bool mWinGame = false;
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