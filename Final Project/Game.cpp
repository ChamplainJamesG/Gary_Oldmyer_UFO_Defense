#include "Game.h"
#include "Timer.h"
#include <fstream>

Game::Game(EventSystem *pSystem)
	:EventListener(pSystem)
{
	mSystem = NULL;
	//mUnit = new Unit();
}

Game::~Game()
{
	if (mInitG)
	{
		//mUnit->~Unit();
		//mSystem = NULL;
		//mUnit = NULL;
		//delete mUnit;
		delete mSystem;
		mInitG = false;
		//delete mGraphicsBuffer1;
		//delete mGraphicsBuffer2;
		//delete mGraphicsBuffer3;
		//delete mUnit;
	}
}

void Game::init(float width, float height, ifstream& in)
{
	if (!mInitG)
	{
		//int inInt;
		//in.open("INIT.init");
		EventSystem::initInstance();
		Sprite smurfSpriteArray[16];
		Sprite deanSpriteArray[16];
		int loc = 0;
		float startSpeed;
		in >> startSpeed;
		mPlayerManager = PlayerManager(startSpeed);

		in >> mPUSpawnRate;

		//GraphicsBuffer* gBuffer = new GraphicsBuffer((FILE_PATH + WOODS_NAME).c_str());

		//in.ignore('\n');
		in.clear();
		mInitG = true;
		mSystem = new System();
		mSystem->init(width, height);

		mInputSystem = new InputSystem();

		//GraphicsBuffer mGraphicsBuffer1((FILE_PATH + WOODS_NAME).c_str());

		//mGBManager.addGraphicsBuffer("Woods", new GraphicsBuffer((FILE_PATH + WOODS_NAME).c_str()));
		//mGBManager.addGraphicsBuffer("SmurfSprite", new GraphicsBuffer((FILE_PATH + SMURF_SPRITES).c_str()));
		//mGBManager.addGraphicsBuffer("DeanSprite", new GraphicsBuffer((FILE_PATH + DEAN_SPRITES).c_str()));

		/*To add a background:
		Add filename to the .init file and make the propper adjustments below
		Create a new sprite for the backgrounds
		*/
		mGBManager.addGraphicsBuffer("SquareSprite", new GraphicsBuffer((/*jirt + */SQUARE_NAME)));
		string imgString;
		getline(in, imgString, '\n');
		getline(in, imgString, '\n');
		mGBManager.addGraphicsBuffer("PlayerSprite", new GraphicsBuffer((imgString)));
		getline(in, imgString, '\n');
		mGBManager.addGraphicsBuffer("Player2Sprite", new GraphicsBuffer((imgString)));
		getline(in, imgString, '\n');
		mGBManager.addGraphicsBuffer("BadSquare", new GraphicsBuffer(imgString));
		getline(in, imgString, '\n');
		mGBManager.addGraphicsBuffer("Food", new GraphicsBuffer(imgString));
		//mGBManager.addGraphicsBuffer("Player2Sprite", new GraphicsBuffer(imgString));
		std::string inputFilename;
		//mGBManager.addGraphicsBuffer("Player2Sprite", new GraphicsBuffer(imgString));
		getline(in, imgString, '\n');
		mGBManager.addGraphicsBuffer("FoodPU", new GraphicsBuffer(imgString));
		getline(in, imgString, '\n');
		mGBManager.addGraphicsBuffer("PointPU", new GraphicsBuffer(imgString));
		getline(in, imgString, '\n');
		mGBManager.addGraphicsBuffer("ShrinkPU", new GraphicsBuffer(imgString));
		getline(in, imgString, '\n');
		mGBManager.addGraphicsBuffer("MainMenu", new GraphicsBuffer(imgString));
		getline(in, imgString, '\n');
		mGBManager.addGraphicsBuffer("Button", new GraphicsBuffer(imgString));
		getline(in, imgString, '\n');
		mGBManager.addGraphicsBuffer("Button2", new GraphicsBuffer(imgString));
		getline(in, imgString, '\n');
		mGBManager.addGraphicsBuffer("GameBackground", new GraphicsBuffer(imgString));
		//now for audio
		getline(in, imgString, '\n');
		mAudioPlayer.addMusic(imgString, "MainMusic");
		getline(in, imgString, '\n');
		mAudioPlayer.addSFX(imgString, "EnemyDeath");
		getline(in, imgString, '\n');
		mAudioPlayer.addSFX(imgString, "LaserShoot");
		//getting the localization file
		getline(in, imgString, '\n');
		mLanguageFilename = imgString;
		//now need the intro cinematic
		getline(in, inputFilename, '\n');
		in.close();
		in.open(inputFilename);
		for (int i = 0; i < 28; i++)
		{
			getline(in, imgString, '\n');
			mCinManager.addCinematics(imgString, i);
		}

		//float smurfWOffset = mGBManager.getGraphicsBuffer("SmurfSprite")->getWidth() / 4;
		//float smurfHOffset = mGBManager.getGraphicsBuffer("SmurfSprite")->getHeight() / 4;

		//Sprite newSprite = Sprite(*mGBManager.getGraphicsBuffer("SquareSprite"), 0, 0);

		//some sprites created in header for ease of reusability
		Sprite newSprite = Sprite(*mGBManager.getGraphicsBuffer("SquareSprite"), Vector2D(0, 0), mGBManager.getGraphicsBuffer("SquareSprite")->getWidth(), mGBManager.getGraphicsBuffer("SquareSprite")->getHeight());
		playerSprite = Sprite(*mGBManager.getGraphicsBuffer("PlayerSprite"), Vector2D(0, 0), mGBManager.getGraphicsBuffer("PlayerSprite")->getWidth(), mGBManager.getGraphicsBuffer("PlayerSprite")->getHeight());
		shot = Sprite(*mGBManager.getGraphicsBuffer("BadSquare"), Vector2D(0, 0), mGBManager.getGraphicsBuffer("BadSquare")->getWidth(), mGBManager.getGraphicsBuffer("BadSquare")->getHeight());
		Sprite foodSprite = Sprite(*mGBManager.getGraphicsBuffer("Food"), Vector2D(0, 0), mGBManager.getGraphicsBuffer("Food")->getWidth(), mGBManager.getGraphicsBuffer("Food")->getHeight());
		player2Sprite = Sprite(*mGBManager.getGraphicsBuffer("Player2Sprite"), Vector2D(0, 0), mGBManager.getGraphicsBuffer("PlayerSprite")->getWidth(), mGBManager.getGraphicsBuffer("PlayerSprite")->getHeight());
		Sprite foodPUSprite = Sprite(*mGBManager.getGraphicsBuffer("FoodPU"), Vector2D(0, 0), mGBManager.getGraphicsBuffer("FoodPU")->getWidth(), mGBManager.getGraphicsBuffer("FoodPU")->getHeight());
		Sprite pointPUSprite = Sprite(*mGBManager.getGraphicsBuffer("PointPU"), Vector2D(0, 0), mGBManager.getGraphicsBuffer("PointPU")->getWidth(), mGBManager.getGraphicsBuffer("PointPU")->getHeight());
		Sprite shrinkPUSprite = Sprite(*mGBManager.getGraphicsBuffer("ShrinkPU"), Vector2D(0, 0), mGBManager.getGraphicsBuffer("ShrinkPU")->getWidth(), mGBManager.getGraphicsBuffer("ShrinkPU")->getHeight());

		//backgrounds
		mMainMenuScreen = Sprite(*mGBManager.getGraphicsBuffer("MainMenu"), Vector2D(0, 0), mGBManager.getGraphicsBuffer("MainMenu")->getWidth(), mGBManager.getGraphicsBuffer("MainMenu")->getHeight());
		mGameBackground = Sprite(*mGBManager.getGraphicsBuffer("GameBackground"), Vector2D(0, 0), mGBManager.getGraphicsBuffer("GameBackground")->getWidth(), mGBManager.getGraphicsBuffer("GameBackground")->getHeight());

		//make buttons
		Sprite buttonUnlitSprite = Sprite(*mGBManager.getGraphicsBuffer("Button"), Vector2D(0, 0), mGBManager.getGraphicsBuffer("Button")->getWidth(), mGBManager.getGraphicsBuffer("Button")->getHeight());
		Sprite buttonLitSprite = Sprite(*mGBManager.getGraphicsBuffer("Button2"), Vector2D(0, 0), mGBManager.getGraphicsBuffer("Button2")->getWidth(), mGBManager.getGraphicsBuffer("Button2")->getHeight());

		mBaseButton = new Buttons("Play", buttonUnlitSprite, buttonLitSprite, (mGBManager.getGraphicsBuffer("MainMenu")->getWidth() / 2 - mGBManager.getGraphicsBuffer("Button")->getWidth() / 4 + 200), mGBManager.getGraphicsBuffer("MainMenu")->getHeight() / 4 - 150);
		mButtonManager.addButton(mBaseButton);

		mBaseButton = new Buttons("Options", buttonUnlitSprite, buttonLitSprite, (mGBManager.getGraphicsBuffer("MainMenu")->getWidth() / 2 - mGBManager.getGraphicsBuffer("Button")->getWidth() / 4 + 200), mGBManager.getGraphicsBuffer("MainMenu")->getHeight() / 4);
		mButtonManager.addButton(mBaseButton);

		mBaseButton = new Buttons("LoadGame", buttonUnlitSprite, buttonLitSprite, (mGBManager.getGraphicsBuffer("MainMenu")->getWidth() / 2 - mGBManager.getGraphicsBuffer("Button")->getWidth() / 4 + 200), mGBManager.getGraphicsBuffer("MainMenu")->getHeight() / 4 + 150);
		mButtonManager.addButton(mBaseButton);

		mBaseButton = new Buttons("Quit", buttonUnlitSprite, buttonLitSprite, (mGBManager.getGraphicsBuffer("MainMenu")->getWidth() / 2 - mGBManager.getGraphicsBuffer("Button")->getWidth() / 4 + 200), mGBManager.getGraphicsBuffer("MainMenu")->getHeight() / 4 + 300);
		mButtonManager.addButton(mBaseButton);

		mBaseButton = new Buttons("ReturnMenu", buttonUnlitSprite, buttonLitSprite, (mGBManager.getGraphicsBuffer("MainMenu")->getWidth() / 2 - mGBManager.getGraphicsBuffer("Button")->getWidth() / 4 + 200), mGBManager.getGraphicsBuffer("MainMenu")->getHeight() / 4 + 300);
		mButtonManager.addButton(mBaseButton);

		mBaseButton = new Buttons("Language", buttonUnlitSprite, buttonLitSprite, (mGBManager.getGraphicsBuffer("MainMenu")->getWidth() / 2 - mGBManager.getGraphicsBuffer("Button")->getWidth() / 4), mGBManager.getGraphicsBuffer("MainMenu")->getHeight() / 4 + 150);
		mButtonManager.addButton(mBaseButton);

		mBaseButton = new Buttons("Level", buttonUnlitSprite, buttonLitSprite, (mGBManager.getGraphicsBuffer("MainMenu")->getWidth() / 2 - mGBManager.getGraphicsBuffer("Button")->getWidth() / 4), mGBManager.getGraphicsBuffer("MainMenu")->getHeight() / 4 - 150);
		mButtonManager.addButton(mBaseButton);

		mBaseButton = new Buttons("MuteMusic", buttonUnlitSprite, buttonLitSprite, (mGBManager.getGraphicsBuffer("MainMenu")->getWidth() / 2 - mGBManager.getGraphicsBuffer("Button")->getWidth() / 4), mGBManager.getGraphicsBuffer("MainMenu")->getHeight() / 4);
		mButtonManager.addButton(mBaseButton);

#pragma region Old button code, ICE
		//Buttons* playButton = new Buttons("Play", buttonUnlitSprite, buttonLitSprite, (mGBManager.getGraphicsBuffer("MainMenu")->getWidth() / 2 - mGBManager.getGraphicsBuffer("Button")->getWidth() / 4 + 200), mGBManager.getGraphicsBuffer("MainMenu")->getHeight() / 3 - 150);
		//Buttons* optionsButton = new Buttons("Options", buttonUnlitSprite, buttonLitSprite, (mGBManager.getGraphicsBuffer("MainMenu")->getWidth() / 2 - mGBManager.getGraphicsBuffer("Button")->getWidth() / 4 + 200), mGBManager.getGraphicsBuffer("MainMenu")->getHeight() / 3);
		//Buttons* quitButton = new Buttons("Quit", buttonUnlitSprite, buttonLitSprite, (mGBManager.getGraphicsBuffer("MainMenu")->getWidth() / 2 - mGBManager.getGraphicsBuffer("Button")->getWidth() / 4 + 200), mGBManager.getGraphicsBuffer("MainMenu")->getHeight() / 3 + 150);
		//Buttons* mainMenuButton = new Buttons("ReturnMenu", buttonUnlitSprite, buttonLitSprite, (mGBManager.getGraphicsBuffer("MainMenu")->getWidth() / 2 - mGBManager.getGraphicsBuffer("Button")->getWidth() / 4 + 200), mGBManager.getGraphicsBuffer("MainMenu")->getHeight() / 3 + 150);

		//add the buttons
		//mButtonManager.addButton(playButton);
		//mButtonManager.addButton(optionsButton);
		//mButtonManager.addButton(quitButton);
		//mButtonManager.addButton(mainMenuButton);
#pragma endregion

		//music play
		mAudioPlayer.playMusic(mAudioPlayer.getMusic("MainMusic"));
		
		//FoodAnim created in header for ease of resta rt.
		//Animation foodAnim;
		Animation mPointAnim;
		Animation mBigFoodAnim;
		Animation mShrinkAnim;

		//draw initial background
		GraphicsSystem::draw(*mGBManager.getGraphicsBuffer("GameBackground"), Vector2D(0, 0), mGameBackground, 1);

		for (int i = 0; i < 3; i++)
		{
			foodAnim.addSprite(Sprite(*mGBManager.getGraphicsBuffer("Food"), Vector2D((mGBManager.getGraphicsBuffer("Food")->getWidth() / 3) * i, 0), mGBManager.getGraphicsBuffer("Food")->getWidth() / 3, mGBManager.getGraphicsBuffer("Food")->getHeight()));
		}

		for (int i = 0; i < 3; i++)
		{
			mPointAnim.addSprite(Sprite(*mGBManager.getGraphicsBuffer("PointPU"), Vector2D((mGBManager.getGraphicsBuffer("PointPU")->getWidth() / 3) * i, 0), mGBManager.getGraphicsBuffer("PointPU")->getWidth() / 3, mGBManager.getGraphicsBuffer("PointPU")->getHeight()));
		}		
		
		for (int i = 0; i < 3; i++)
		{
			mBigFoodAnim.addSprite(Sprite(*mGBManager.getGraphicsBuffer("FoodPU"), Vector2D((mGBManager.getGraphicsBuffer("FoodPU")->getWidth() / 3) * i, 0), mGBManager.getGraphicsBuffer("FoodPU")->getWidth() / 3, mGBManager.getGraphicsBuffer("FoodPU")->getHeight()));
		}		
		
		for (int i = 0; i < 3; i++)
		{
			mShrinkAnim.addSprite(Sprite(*mGBManager.getGraphicsBuffer("ShrinkPU"), Vector2D((mGBManager.getGraphicsBuffer("ShrinkPU")->getWidth() / 3) * i, 0), mGBManager.getGraphicsBuffer("ShrinkPU")->getWidth() / 3, mGBManager.getGraphicsBuffer("ShrinkPU")->getHeight()));
		}

		//below code for creating the game also placed in this function:
		//resetGame();

		//Enemy anEnemy(Vector2D(0, 0), foodAnim, 50);
		//mEnemyManager.addEnemy(anEnemy);
		//anEnemy = Enemy(Vector2D(75, 0), foodAnim, 50);
		Enemy anEnemy;

		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				anEnemy = Enemy(Vector2D(75.0f * i, 75.0f * j), foodAnim, .001f);
				anEnemy.setId(i + j);
				mEnemyManager.addEnemy(anEnemy);
			}

		}

		//mEnemyManager.addEnemy(anEnemy);

		mEnemyManager.setMaxTime(.001f);

		//mLevel = Level(8, 6, newSprite, badSquareSprite, foodSprite);

		//Player newPlayer = Player(mPlayerTemplate, mLevel.getSquare(1, 1).getPos());
		mPlayerTemplate = Player(playerSprite, /*mLevel.getSquare(0, 0).getPos()*/ Vector2D(1000, 1000));
		mPlayerTemplate.setX(0);
		mPlayerTemplate.setY(0);
		mPlayerManager.addPlayer(mPlayerTemplate);
		mPlayerManager.getPlayer(0).setX(1);
		mPlayerManager.getPlayer(0).setY(1);
		mPlayerTemplate.setSprite(player2Sprite);

		mPlayer = Player(playerSprite, Vector2D(0, 500));
		mPlayer = Player(playerSprite, shot, Vector2D(0, 500), 10);

		/*
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				smurfSpriteArray[loc] = Sprite(*mGBManager.getGraphicsBuffer("SmurfSprite"), Vector2D(smurfWOffset * j, smurfHOffset * i), smurfWOffset, smurfHOffset);
				loc++;
			}
		}

		loc = 0;

		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				deanSpriteArray[loc] = Sprite(*mGBManager.getGraphicsBuffer("DeanSprite"), Vector2D(smurfWOffset * j, smurfHOffset * i), smurfWOffset, smurfHOffset);
				loc++;
			}
		}

		addSprites(smurfSpriteArray, 16, true);
		addSprites(deanSpriteArray, 16, false);
		*/
		//EventSystem::getInstance().addListener(ADD_EVENT, this);
		EventSystem::getInstance()->addListener(ADD_EVENT, this);
		EventSystem::getInstance()->addListener(DELETE_EVENT, this);
		EventSystem::getInstance()->addListener(FREEZE_EVENT, this);
		EventSystem::getInstance()->addListener(CHANGE_EVENT, this);
		EventSystem::getInstance()->addListener(QUIT_EVENT, this);
		EventSystem::getInstance()->addListener(MOVE_UP, this);
		EventSystem::getInstance()->addListener(MOVE_LEFT, this);
		EventSystem::getInstance()->addListener(MOVE_DOWN, this);
		EventSystem::getInstance()->addListener(MOVE_RIGHT, this);
		EventSystem::getInstance()->addListener(TEST_MAKE_PLAYER, this);
		EventSystem::getInstance()->addListener(RESET, this);
		EventSystem::getInstance()->addListener(START_LEVEL, this);
		EventSystem::getInstance()->addListener(START_GAME, this);
		EventSystem::getInstance()->addListener(EXIT, this);
		EventSystem::getInstance()->addListener(FOOD_PU, this);
		EventSystem::getInstance()->addListener(POINT_PU, this);
		EventSystem::getInstance()->addListener(SHRINK_PU, this);
		EventSystem::getInstance()->addListener(LEFT_CLICK, this);
		EventSystem::getInstance()->addListener(PLAYER_SHOOT, this);
		EventSystem::getInstance()->addListener(HURT_PLAYER, this);


		//assert(this);

		//EventSystem::getInstance()->addListener(AL_ADD_EVENT, mTranslator);
		//EventSystem::getInstance()->addListener(AL_DELETE_EVENT, mTranslator);
		//EventSystem::getInstance()->addListener(AL_FREEZE_EVENT, mTranslator);
		//EventSystem::getInstance()->addListener(AL_CHANGE_EVENT, mTranslator);
		//EventSystem::getInstance()->addListener(AL_QUIT_EVENT, mTranslator);

		Level initLevel = Level(8, 6, newSprite, shot, foodSprite, foodPUSprite, pointPUSprite, shrinkPUSprite, foodAnim, mBigFoodAnim, mPointAnim, mShrinkAnim);
		in >> initLevel;
		mLevelManager.addLevel(initLevel);
		in >> initLevel;
		mLevelManager.addLevel(initLevel);
		in >> initLevel;
		mLevelManager.addLevel(initLevel);

		mCurLevel = 0;
		mLevel = mLevelManager.getLevel(mCurLevel);

		//mLevel.spawnFood(mPlayerManager);

		in.close();
		changeLanguage("ENGLISH");
	}

}

void Game::initBuffers(std::string fileName1, std::string fileName2, std::string fileName3)
{
	//mGraphicsBuffer1 = new GraphicsBuffer(fileName1);
	//mGraphicsBuffer2 = new GraphicsBuffer(fileName2);
	//mGraphicsBuffer3 = new GraphicsBuffer(fileName3);
}

void Game::addSprites(Sprite sprite[], int count, bool anim)
{
	//Sprite *ptr = sprite;
	for (int i = 0; i < count; i++)
	{
		if (anim)
			mUnit.addAnim(sprite[i], anim);
		else
			mUnit.addAnim(sprite[i], anim);
	}
}

void Game::createUnit(Unit unit)
{
	mUnitManager.addUnit(unit);
}

void Game::makeUnit()
{
	Unit unit = mUnit;
	mUnit.setSourceLoc(Vector2D(mSystem->getMouseLoc().getX() - mGBManager.getGraphicsBuffer("SmurfSprite")->getWidth() / 8, mSystem->getMouseLoc().getY() - mGBManager.getGraphicsBuffer("SmurfSprite")->getHeight() / 8));
	createUnit(unit);
}

void Game::removeUnit()
{
	for (int i = 0; i < mUnitManager.getSize(); i++)
	{
		if (compareLoc(mUnitManager.getUnit(i)))
		{
			mUnitManager.deleteUnit(i);
		}
	}
}

bool Game::compareLoc(Unit unit)
{
	if (mSystem->getMouseLoc().getX() > unit.getLocation().getX() && mSystem->getMouseLoc().getX() < unit.getLocation().getX() + mGBManager.getGraphicsBuffer("SmurfSprite")->getWidth() / 4
		&& mSystem->getMouseLoc().getY() > unit.getLocation().getY() && mSystem->getMouseLoc().getY() < unit.getLocation().getY() + mGBManager.getGraphicsBuffer("SmurfSprite")->getHeight() / 4)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Game::cleanup()
{
	if (mInitG)
	{
		//mUnit->~Unit();
		//mSystem = NULL;
		//mUnit = NULL;
		//delete mUnit;
		delete mSystem;
		delete mBaseButton;
		mButtonManager.cleanup();
		mGBManager.clear();
		mInitG = false;
		delete mGBManager.getGraphicsBuffer("Woods");
		delete mGBManager.getGraphicsBuffer("SmurfSprites");
		delete mGBManager.getGraphicsBuffer("DeanSprites");
		delete mGBManager.getGraphicsBuffer("PlayerSprite");
		delete mGBManager.getGraphicsBuffer("Player2Sprite");
		delete mGBManager.getGraphicsBuffer("BadSquare");
		delete mGBManager.getGraphicsBuffer("Food");
		delete mGBManager.getGraphicsBuffer("FoodPU");
		delete mGBManager.getGraphicsBuffer("PointPU");
		delete mGBManager.getGraphicsBuffer("ShrinkPU");
		delete mGBManager.getGraphicsBuffer("SquareSprite");
		delete mGBManager.getGraphicsBuffer("MainMenu");
		delete mGBManager.getGraphicsBuffer("Button");
		delete mGBManager.getGraphicsBuffer("Button2");
		delete mGBManager.getGraphicsBuffer("GameBackground");

		delete mInputSystem;
		EventSystem::cleanupInstance();

		save();

		//delete mGraphicsBuffer1;
		//delete mGraphicsBuffer2;
		//delete mGraphicsBuffer3;
		//delete mUnit;
	}
}

void Game::doLoop()
{
#pragma region Values and info
	Timer timer;
	//worry about timing inside here. 
	//Sprite stepsSprite(mGraphicsBuffer1, 0, 0);
	//Sprite stepsSprite(*mGBManager.getGraphicsBuffer("Woods"), 0, 0);
	bool anim = true;
	//bool done = false;
	bool leftClick = false;
	bool rightClick = false;
	//bool doAnim = true;
	//bool firstFlip = false;
	mPlayerManager.setMaxTime(mPlayerManager.getMaxTime() - mLevel.getSubFactor());

	mShownLanguageOption = mLanguageMap["ENGLISH"];
	mShownLevelOption = mLanguageMap["EASY"];

#pragma region setting the text positions & font
	Font mMenuFont = Font("Roboto-Bold.ttf", 50);
	mMenuButtonPosMENU = Vector2D((mButtonManager.getButton("Play")->getLocation().getX() + mPlayOffset), (mButtonManager.getButton("Play")->getLocation().getY() + 50));
	mOptionsButtonPosMENU = Vector2D((mButtonManager.getButton("Options")->getLocation().getX() + mOptionsOffset), (mButtonManager.getButton("Options")->getLocation().getY() + 50));
	mLoadGameButtonPosMENU = Vector2D((mButtonManager.getButton("LoadGame")->getLocation().getX() + mLoadOffset), (mButtonManager.getButton("LoadGame")->getLocation().getY() + 50));
	mQuitButtonPosMENU = Vector2D((mButtonManager.getButton("Quit")->getLocation().getX() + mQuitOffset), (mButtonManager.getButton("Quit")->getLocation().getY() + 50));
	mMenuButtonPosOPTIONS = Vector2D((mButtonManager.getButton("ReturnMenu")->getLocation().getX() + mReturnOffset), (mButtonManager.getButton("ReturnMenu")->getLocation().getY() + 50));
	mEnglishButtonPosOPTIONS = Vector2D((mButtonManager.getButton("Language")->getLocation().getX() + mEnglishOffset), (mButtonManager.getButton("Language")->getLocation().getY() + 50));
	mLatinButtonPosOPTIONS = Vector2D((mButtonManager.getButton("Language")->getLocation().getX() + mLatinOffset), (mButtonManager.getButton("Language")->getLocation().getY() + 50));
	mFrenchButtonPosOPTIONS = Vector2D((mButtonManager.getButton("Language")->getLocation().getX() + mFrenchOffset), (mButtonManager.getButton("Language")->getLocation().getY() + 50));
	mEasyButtonPosOPTIONS = Vector2D((mButtonManager.getButton("Level")->getLocation().getX() + mEasyOffset), (mButtonManager.getButton("Level")->getLocation().getY() + 50));
	mMediumButtonPosOPTIONS = Vector2D((mButtonManager.getButton("Level")->getLocation().getX() + mMediumOffset), (mButtonManager.getButton("Level")->getLocation().getY() + 50));
	mHardButtonPosOPTIONS = Vector2D((mButtonManager.getButton("Level")->getLocation().getX() + mHardOffset), (mButtonManager.getButton("Level")->getLocation().getY() + 50));
	mMuteMusicPosOPTIONS = Vector2D((mButtonManager.getButton("MuteMusic")->getLocation().getX() + mMuteOffset), (mButtonManager.getButton("MuteMusic")->getLocation().getY() + 50));
#pragma endregion

	int counter = 10;
	int frameCounter = 0;

#pragma endregion
	while (!mIsGameDone)
	{
		while (!mStartGame)
		{
			//Intro cinematic
			while (mInCinematic)
			{
				timer.start();

				counter--;
				if (counter == 0)
				{
					//hardcoded for now, will fix later
					mIntroCineBackground = Sprite(mCinManager.getCinematicBuffer("Intro", frameCounter), Vector2D(0, 0), 800, 600);
					GraphicsSystem::draw(mCinManager.getCinematicBuffer("Intro", frameCounter), Vector2D(0, 0), mIntroCineBackground, 1);
					counter = 10;
					frameCounter++;
					mSystem->flip();

					if (frameCounter == 28)
					{
						mInCinematic = false;
						mInStart = true;
						setDrawnButtons("MainMenu");
					}
				}

				timer.sleepUntilElapsed(16.67);
			}

			//start menu
			while (mInStart)
			{
				timer.start();

				//draws the background
				GraphicsSystem::draw(*mGBManager.getGraphicsBuffer("MainMenu"), Vector2D(0, 0), mMainMenuScreen, 1);

				//draws the buttons
				for (int i = 0; i <= mButtonManager.getAmountFull() - 1; i++)
				{
					if (mButtonManager.getButton(i)->getIsDrawn() == true)
						GraphicsSystem::draw(mButtonManager.getButton(i)->getLocation(), mButtonManager.getButton(i)->getActiveSprite(), .5);
				}

				//draw the text on the buttons
				GraphicsSystem::writeText(mMenuButtonPosMENU, mMenuFont, Color(0, 0, 0), mLanguageMap["PLAY"]);
				GraphicsSystem::writeText(mOptionsButtonPosMENU, mMenuFont, Color(0, 0, 0), mLanguageMap["OPTIONS"]);
				GraphicsSystem::writeText(mLoadGameButtonPosMENU, mMenuFont, Color(0, 0, 0), mLanguageMap["LOAD"]);
				GraphicsSystem::writeText(mQuitButtonPosMENU, mMenuFont, Color(0, 0, 0), mLanguageMap["QUIT"]);

				mSystem->update();
				//mButtonManager.update(mSystem->getMousePosition());
				mButtonManager.update(mSystem->getInputSystem().getMousePosition());

				mSystem->flip();
				timer.sleepUntilElapsed(16.67);
			}

			//options menu
			while (mInOptions)
			{
				timer.start();

				//draws the background
				GraphicsSystem::draw(*mGBManager.getGraphicsBuffer("GameBackground"), Vector2D(0, 0), mGameBackground, 1);

				//draws the menu return button
				//draws the buttons
				for (int i = 0; i <= mButtonManager.getAmountFull() - 1; i++)
				{
					if (mButtonManager.getButton(i)->getIsDrawn() == true)
						GraphicsSystem::draw(mButtonManager.getButton(i)->getLocation(), mButtonManager.getButton(i)->getActiveSprite(), .5);
				}

				//draw the text on the button
				GraphicsSystem::writeText(mMenuButtonPosOPTIONS, mMenuFont, Color(0, 0, 0), mLanguageMap["RETURN"]);
				GraphicsSystem::writeText(mMuteMusicPosOPTIONS, mMenuFont, Color(0, 0, 0), mLanguageMap["MUTE"]);

				//set up the specific offsets for the words
				if (mLanguageNumChoice == 0)
				{
					GraphicsSystem::writeText(mEnglishButtonPosOPTIONS, mMenuFont, Color(0, 0, 0), mShownLanguageOption);
				}
				else if (mLanguageNumChoice == 1)
				{
					GraphicsSystem::writeText(mLatinButtonPosOPTIONS, mMenuFont, Color(0, 0, 0), mShownLanguageOption);
				}
				else if (mLanguageNumChoice == 2)
				{
					GraphicsSystem::writeText(mFrenchButtonPosOPTIONS, mMenuFont, Color(0, 0, 0), mShownLanguageOption);
				}

				if (mLevelNumChoice == 0)
				{
					GraphicsSystem::writeText(mEasyButtonPosOPTIONS, mMenuFont, Color(0, 0, 0), mShownLevelOption);
				}
				else if (mLevelNumChoice == 1)
				{
					GraphicsSystem::writeText(mMediumButtonPosOPTIONS, mMenuFont, Color(0, 0, 0), mShownLevelOption);
				}
				else if (mLevelNumChoice == 2)
				{
					GraphicsSystem::writeText(mHardButtonPosOPTIONS, mMenuFont, Color(0, 0, 0), mShownLevelOption);
				}

				mSystem->update();
				//mButtonManager.update(mSystem->getMousePosition());
				mButtonManager.update(mSystem->getInputSystem().getMousePosition());

				mSystem->flip();
				timer.sleepUntilElapsed(16.67);
			}
		}
		//GAME ENGINE STUFF IS HERE
		mPlayerManager.getPlayer(0).setDir(RIGHT);
		while (!mDoneLoop)
		{

			timer.start();
			mSystem->update();

			//draws the background
			GraphicsSystem::draw(*mGBManager.getGraphicsBuffer("GameBackground"), Vector2D(0, 0), mGameBackground, 1);

			if (mStartLevel)
			{
				timer.start();
				//input

				checkEnd();


				//update
				//render
				//mUnit.setSourceLoc(mSystem->getMouseState(mUnit.getOrigLoc()));
				//mSystem->getMouseState(Vector2D(0, 0), leftClick, rightClick);
				/*
				if (leftClick)
				{
				makeUnit();
				leftClick = false;
				}

				if (rightClick)
				{
				removeUnit();
				rightClick = false;
				}
				*/

				//mUnit.update(timer.getElapsedTime(), anim);

				mPlayer.updateBullet();
				//mUnitManager.update((float)timer.getElapsedTime());
				//mPlayerManager.update(timer.getElapsedTime(), mLevel);

				mEnemyManager.update(timer.getElapsedTime(), mSystem->getSystem());
				if (mEnemyManager.checkCollisionB(mPlayer))
				{
					mScore += 100;
					mAudioPlayer.playSFX(mAudioPlayer.getSFX("EnemyDeath"));
				}

				if (mEnemyManager.checkEnemiesDead())
				{
					resetEnemies();
					mPlayer.setLoc(Vector2D(0, 500));
				}

				if (mEnemyManager.checkEnemyDistance(*mSystem))
				{
					mEnemyManager.moveEnemiesToStart();
					mPlayer.setLives(mPlayer.getLives() - 1);

					if (mPlayer.getLives() <= 0)
					{
						EventSystem::getInstance()->fireEvent(EXIT);
					}
				}

				//mLevel.update(timer.getElapsedTime());
				//GraphicsSystem::draw(*mGBManager.getGraphicsBuffer("Woods"), Vector2D(0, 0), stepsSprite, .5);

				//mUnitManager.draw(*mGBManager.getGraphicsBuffer("SmurfSprite"), anim);


				//firstFlip = true;


				//checkLevel();
				//if (rollSpawn())
				//	mPowerUpSpawn = true;

			}

			//mLevel.drawLevel(mGBManager.getGraphicsBuffer("SquareSprite"));

			//mUnit.draw(*mGBManager.getGraphicsBuffer("SmurfSprite"), anim);
			//mPlayerManager.draw();
			mPlayer.draw();
			mEnemyManager.draw();

			if (!mStartLevel)
			{
				//GraphicsSystem::writeText(Vector2D(200, 450), mSystem->getFont(), Color(50, 20, 255), "Press SPACE to start");
				int j = 0;
			}

			timer.sleepUntilElapsed(16.67);
			std::cout << timer.getElapsedTime() << std::endl;
			updateHUD(timer.getElapsedTime());

			mSystem->flip();

			//std::cout << timer.getElapsedTime() << std::endl;

		}
	}

	if (!mIsQuit)
	{
		if (!mWinGame)
			while (!mEndGame)
			{
				timer.start();
				//GraphicsSystem::writeText(Vector2D(100, 350), mSystem->getFont(), Color(50, 20, 255), "Gary Oldmyer has died.");
				//GraphicsSystem::writeText(Vector2D(100, 400), mSystem->getFont(), Color(50, 20, 255), "It was inevitable.");
				//GraphicsSystem::writeText(Vector2D(100, 450), mSystem->getFont(), Color(50, 20, 255), "Press ESC to exit");
				mSystem->update();
				mSystem->flip();
				timer.sleepUntilElapsed(16.67);
			}

		else
			while (!mEndGame)
			{
				timer.start();
				//GraphicsSystem::writeText(Vector2D(100, 350), mSystem->getFont(), Color(50, 20, 255), "Gary Oldmyer has won.");
				//GraphicsSystem::writeText(Vector2D(100, 400), mSystem->getFont(), Color(50, 20, 255), "Good job.");
				//GraphicsSystem::writeText(Vector2D(100, 450), mSystem->getFont(), Color(50, 20, 255), "Press ESC to exit.");
				mSystem->update();
				mSystem->flip();
				timer.sleepUntilElapsed(16.67);
			}
	}

	std::cout << "quiting" << endl;

	mSystem->cleanup();

}

void Game::changePlayerDir(DIRECTION dir)
{
	mPlayerManager.getPlayer(0).setDir(dir);
}

void Game::handleEvent(const Event &theEvent)
{
	//cout << endl << "ExampleListener#" << mID << endl;
	//cout << "\t" << theEvent.getEventName() << " Received";
	std::cout << "Firing game event" << std::endl;
	if (theEvent.getType() == ADD_EVENT)
	{
		//const MoveEvent& moveEvent = static_cast<const MoveEvent&>(theEvent);
		//add a sprite
		makeUnit();
	}

	if (theEvent.getType() == DELETE_EVENT)
	{
		//delete a sprite
		removeUnit();
	}

	if (theEvent.getType() == FREEZE_EVENT)
	{
		mUnitManager.setDoAnim();
	}

	if (theEvent.getType() == QUIT_EVENT)
	{
		mDoneLoop = !mDoneLoop;
	}

	if (theEvent.getType() == CHANGE_EVENT)
	{
		mUnitManager.setAnim();
	}

	if (theEvent.getType() == MOVE_UP)
	{
		changePlayerDir(UP);
	}

	if (theEvent.getType() == MOVE_LEFT)
	{
		mPlayer.setDir(LEFT);
		mPlayer.move(5);
	}

	if (theEvent.getType() == MOVE_DOWN)
	{
		changePlayerDir(DOWN);
	}

	if (theEvent.getType() == MOVE_RIGHT)
	{
		mPlayer.setDir(RIGHT);
		mPlayer.move(5);
	}

	if (theEvent.getType() == TEST_MAKE_PLAYER)
	{
		addPlayer();
		mLevel.getSquare(mPlayerManager.getPlayer(0).getX(), mPlayerManager.getPlayer(0).getY()).setHasFood(false);
		mLevel.spawnFood(mPlayerManager);
		mScore += 1;
	}

	if (theEvent.getType() == FOOD_PU)
	{
		mLevel.getSquare(mPlayerManager.getPlayer(0).getX(), mPlayerManager.getPlayer(0).getY()).setHasFoodPU(false);
		addPlayer();
		addPlayer();
		mScore += 2;
		mPowerUpSpawn = false;

	}

	if (theEvent.getType() == POINT_PU)
	{
		mLevel.getSquare(mPlayerManager.getPlayer(0).getX(), mPlayerManager.getPlayer(0).getY()).setHasPointPU(false);
		mScore += 1;
		mPowerUpSpawn = false;

	}

	if (theEvent.getType() == SHRINK_PU)
	{
		mLevel.getSquare(mPlayerManager.getPlayer(0).getX(), mPlayerManager.getPlayer(0).getY()).setShrinkPU(false);
		mPowerUpSpawn = false;
		if (mPlayerManager.getNumPlayer() > 3)
		{
			mPlayerManager.removeOnePlayer();
		}
	}

	if (theEvent.getType() == RESET)
	{
		mCurLevel++;
		loadNextLevel(mCurLevel);
	}

	if (theEvent.getType() == START_LEVEL)
	{
		if(mStartGame)
			mStartLevel = true;
	}

	if (theEvent.getType() == START_GAME)
	{
		mStartGame = true;
	}

	//if in game, brings player back to menu
	if (theEvent.getType() == EXIT)
	{
		if (mStartGame)
		{
			mStartGame = false;
			mDoneLoop = true;
			mInStart = true;
		}
	}

	if (theEvent.getType() == PLAYER_SHOOT)
	{
		if (!mPlayer.doesHaveBullet())
			mAudioPlayer.playSFX(mAudioPlayer.getSFX("LaserShoot"));
		mPlayer.fireBullet();
	}

	if (theEvent.getType() == LEFT_CLICK)
	{
		std::string test = "";
		if (!mStartGame)
		{
			test = mButtonManager.getActiveButtonName();
			if (test == "Play")
			{
				//reset values if come from quit
				resetGame();

				mStartGame = true;
				mInStart = false;
				mDoneLoop = false;
			}
			else if (test == "Options")
			{
				setDrawnButtons("Options");
				mInOptions = true;
				mInStart = false;
			}
			else if (test == "LoadGame")
			{
				std::cout << "Attempting to load save file" << endl;
				//load game functionality here
			}
			else if (test == "ReturnMenu")
			{
				setDrawnButtons("MainMenu");
				mInOptions = false;
				mInStart = true;
			}
			else if (test == "Quit")
			{
				mIsGameDone = true;
				mStartGame = true;
				mInStart = false;
				mDoneLoop = true;
				mIsQuit = true;
			}
			else if (test == "Language")
			{
				mLanguageNumChoice++;
				if (mLanguageNumChoice == 3)
					mLanguageNumChoice = 0;
				
				//set up new language
				if (mLanguageNumChoice == 0)
				{
					changeLanguage("ENGLISH");
					mShownLanguageOption = mLanguageMap["ENGLISH"];
				}
				else if (mLanguageNumChoice == 1)
				{
					changeLanguage("LATIN");
					mShownLanguageOption = mLanguageMap["LATIN"];
				}
				else if (mLanguageNumChoice == 2)
				{
					changeLanguage("FRENCH");
					mShownLanguageOption = mLanguageMap["FRENCH"];
				}

				if (mLevelNumChoice == 0)
				{
					mShownLevelOption = mLanguageMap["EASY"];
				}
				else if (mLevelNumChoice == 1)
				{
					mShownLevelOption = mLanguageMap["MEDIUM"];
				}
				else if (mLevelNumChoice == 2)
				{
					mShownLevelOption = mLanguageMap["HARD"];
				}
			}
			else if (test == "Level")
			{
				mLevelNumChoice++;
				if (mLevelNumChoice == 3)
					mLevelNumChoice = 0;

				//set up new language
				if (mLevelNumChoice == 0)
				{
					mShownLevelOption = mLanguageMap["EASY"];
					//change difficulty code
				}
				else if (mLevelNumChoice == 1)
				{
					mShownLevelOption = mLanguageMap["MEDIUM"];
					//change difficulty code
				}
				else if (mLevelNumChoice == 2)
				{
					mShownLevelOption = mLanguageMap["HARD"];
					//change difficulty code
				}
			}
			else if (test == "MuteMusic")
			{
				//mute music code
				mAudioPlayer.muteUnmuteAll();
			}
		}
	}

	if (theEvent.getType() == HURT_PLAYER)
	{
		//mplayer loses a life
		//reset without losing all enemies

		mEnemyManager.moveEnemiesToStart();
	}
}

void Game::addPlayer()
{
	Player newPlayer = mPlayerTemplate;
	mPlayerManager.addPlayer(newPlayer);
}

void Game::checkEnd()
{
	if (mPlayerManager.getDead())
		EventSystem::getInstance()->fireEvent(QUIT_EVENT);
}

void Game::checkLevel()
{
	if (mScore > mLevelManager.getLevel(mCurLevel).getScoreToWin())
	{
		EventSystem::getInstance()->fireEvent(RESET);
	}
}

void Game::updateHUD(double dt)
{
	double fps = 1000 / dt;
//	roundf(fps);

	mSystem->doHud((int)fps, mScore, mLanguageMap["SCORE"], mLanguageMap["LIVES"], mPlayer.getLives());
}

void Game::loadNextLevel(int level)
{
	if (mCurLevel > 2)
	{
		mWinGame = true;
		mDoneLoop = true;
		return;
	}
	mLevel = mLevelManager.getLevel(level);
	mPlayerManager.resetPlayer();
	mLevel.spawnFood(mPlayerManager);
	mPlayerManager.setMaxTime(mPlayerManager.getMaxTime() - mLevel.getSubFactor());
	EventSystem::getInstance()->fireEvent(MOVE_RIGHT);
	mStartLevel = false;


}

bool Game::rollSpawn()
{
	int random = rand() % mPUSpawnRate;
	if (random <= 1)
	{
		mLevel.spawnPowerup(mPlayerManager);
		return true;
	}

	return false;
}

//sets all the buttons to draw or not draw per scene
void Game::setDrawnButtons(std::string sceneName)
{
	if (sceneName == "MainMenu")
	{
		mButtonManager.getButton(0)->setIsDrawn(true);
		mButtonManager.getButton(1)->setIsDrawn(true);
		mButtonManager.getButton(2)->setIsDrawn(true);
		mButtonManager.getButton(3)->setIsDrawn(true);
		mButtonManager.getButton(4)->setIsDrawn(false);
		mButtonManager.getButton(5)->setIsDrawn(false);
		mButtonManager.getButton(6)->setIsDrawn(false);
		mButtonManager.getButton(7)->setIsDrawn(false);
	}
	else if (sceneName == "Options")
	{
		mButtonManager.getButton(0)->setIsDrawn(false);
		mButtonManager.getButton(1)->setIsDrawn(false);
		mButtonManager.getButton(2)->setIsDrawn(false);
		mButtonManager.getButton(3)->setIsDrawn(false);
		mButtonManager.getButton(4)->setIsDrawn(true);
		mButtonManager.getButton(5)->setIsDrawn(true);
		mButtonManager.getButton(6)->setIsDrawn(true);
		mButtonManager.getButton(7)->setIsDrawn(true);
	}

	mButtonManager.getButton(0)->setIsSelected(false);
	mButtonManager.getButton(1)->setIsSelected(false);
	mButtonManager.getButton(2)->setIsSelected(false);
	mButtonManager.getButton(3)->setIsSelected(false);
	mButtonManager.getButton(4)->setIsSelected(false);
	mButtonManager.getButton(5)->setIsSelected(false);
	mButtonManager.getButton(6)->setIsSelected(false);
	mButtonManager.getButton(7)->setIsSelected(false);
}

//needed for when the player quits a game then goes back in from the menu
void Game::resetGame()
{
	mEnemyManager.clearList();
	Enemy anEnemy;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			anEnemy = Enemy(Vector2D(75.0f * i, 75.0f * j), foodAnim, 0.1f);
			mEnemyManager.addEnemy(anEnemy);
		}

	}

	//mEnemyManager.addEnemy(anEnemy);

	mEnemyManager.setMaxTime(.1f);

	//mLevel = Level(8, 6, newSprite, badSquareSprite, foodSprite);

	//Player newPlayer = Player(mPlayerTemplate, mLevel.getSquare(1, 1).getPos());
	mPlayerTemplate = Player(playerSprite, /*mLevel.getSquare(0, 0).getPos()*/ Vector2D(1000, 1000));
	mPlayerTemplate.setX(0);
	mPlayerTemplate.setY(0);
	mPlayerManager.addPlayer(mPlayerTemplate);
	mPlayerManager.getPlayer(0).setX(1);
	mPlayerManager.getPlayer(0).setY(1);
	mPlayerTemplate.setSprite(player2Sprite);

	mPlayer = Player(playerSprite, Vector2D(0, 500));
	mPlayer = Player(playerSprite, shot, Vector2D(0, 500), 10);
}

void Game::setUpLanguage()
{
	ifstream in;
	std::string imgString;
	in.open(mLanguageFilename);
	
	//set start and end area
	int i = 0;
	int n = 10;

	if (mLanguageChoice == "LATIN")
	{
		i = 18;
		n = 33;
	}
	else if (mLanguageChoice == "FRENCH")
	{
		i = 35;
		n = 50;
	}
	//english
	else
	{
		i = 1;
		n = 16;
	}

	//get to the right inputs
	int j = i;
	while (j != 0)
	{
		getline(in, imgString, '\n');
		j--;
	}

	//set up the language
	getline(in, imgString, '\n');
	mLanguageMap["PLAY"] = imgString;
	getline(in, imgString, '\n');
	mLanguageMap["OPTIONS"] = imgString;
	getline(in, imgString, '\n');
	mLanguageMap["LOAD"] = imgString;
	getline(in, imgString, '\n');
	mLanguageMap["QUIT"] = imgString;
	getline(in, imgString, '\n');
	mLanguageMap["ENGLISH"] = imgString;
	getline(in, imgString, '\n');
	mLanguageMap["LATIN"] = imgString;
	getline(in, imgString, '\n');
	mLanguageMap["FRENCH"] = imgString;
	getline(in, imgString, '\n');
	mLanguageMap["LEVEL"] = imgString;
	getline(in, imgString, '\n');
	mLanguageMap["EASY"] = imgString;
	getline(in, imgString, '\n');
	mLanguageMap["MEDIUM"] = imgString;
	getline(in, imgString, '\n');
	mLanguageMap["HARD"] = imgString;
	getline(in, imgString, '\n');
	mLanguageMap["RETURN"] = imgString;
	getline(in, imgString, '\n');
	mLanguageMap["SCORE"] = imgString;
	getline(in, imgString, '\n');
	mLanguageMap["YOU LOSE"] = imgString;
	getline(in, imgString, '\n');
	mLanguageMap["LIVES"] = imgString;
	getline(in, imgString, '\n');
	mLanguageMap["MUTE"] = imgString;

	in.close();
}

void Game::changeLanguage(std::string language)
{
	mLanguageChoice = language;
	setUpLanguage();
	setUpOffsets();
}

void Game::setUpOffsets()
{
	if (mLanguageChoice == "LATIN")
	{
		mPlayOffset = 50;
		mOptionsOffset = 40;
		mLoadOffset = 60;
		mQuitOffset = 75;
		mEnglishOffset = 40;
		mLatinOffset = 50;
		mFrenchOffset = 50;
		mEasyOffset = 65;
		mMediumOffset = 35;
		mHardOffset = 55;
		mReturnOffset = 75;
		mMuteOffset = 60;
	}
	else if (mLanguageChoice == "FRENCH")
	{
		mPlayOffset = 50;
		mOptionsOffset = 40;
		mLoadOffset = 40;
		mQuitOffset = 50;
		mEnglishOffset = 40;
		mLatinOffset = 50;
		mFrenchOffset = 35;
		mEasyOffset = 60;
		mMediumOffset = 50;
		mHardOffset = 40;
		mReturnOffset = 75;
		mMuteOffset = 60;
	}
	else
	{
		mPlayOffset = 75;
		mOptionsOffset = 40;
		mLoadOffset = 75;
		mQuitOffset = 75;
		mEnglishOffset = 40;
		mLatinOffset = 50;
		mFrenchOffset = 50;
		mEasyOffset = 65;
		mMediumOffset = 40;
		mHardOffset = 65;
		mReturnOffset = 50;
		mMuteOffset = 60;
	}

	mMenuButtonPosMENU = Vector2D((mButtonManager.getButton("Play")->getLocation().getX() + mPlayOffset), (mButtonManager.getButton("Play")->getLocation().getY() + 50));
	mOptionsButtonPosMENU = Vector2D((mButtonManager.getButton("Options")->getLocation().getX() + mOptionsOffset), (mButtonManager.getButton("Options")->getLocation().getY() + 50));
	mLoadGameButtonPosMENU = Vector2D((mButtonManager.getButton("LoadGame")->getLocation().getX() + mLoadOffset), (mButtonManager.getButton("LoadGame")->getLocation().getY() + 50));
	mQuitButtonPosMENU = Vector2D((mButtonManager.getButton("Quit")->getLocation().getX() + mQuitOffset), (mButtonManager.getButton("Quit")->getLocation().getY() + 50));
	mMenuButtonPosOPTIONS = Vector2D((mButtonManager.getButton("ReturnMenu")->getLocation().getX() + mReturnOffset), (mButtonManager.getButton("ReturnMenu")->getLocation().getY() + 50));
	mEnglishButtonPosOPTIONS = Vector2D((mButtonManager.getButton("Language")->getLocation().getX() + mEnglishOffset), (mButtonManager.getButton("Language")->getLocation().getY() + 50));
	mLatinButtonPosOPTIONS = Vector2D((mButtonManager.getButton("Language")->getLocation().getX() + mLatinOffset), (mButtonManager.getButton("Language")->getLocation().getY() + 50));
	mFrenchButtonPosOPTIONS = Vector2D((mButtonManager.getButton("Language")->getLocation().getX() + mFrenchOffset), (mButtonManager.getButton("Language")->getLocation().getY() + 50));
	mEasyButtonPosOPTIONS = Vector2D((mButtonManager.getButton("Level")->getLocation().getX() + mEasyOffset), (mButtonManager.getButton("Level")->getLocation().getY() + 50));
	mMediumButtonPosOPTIONS = Vector2D((mButtonManager.getButton("Level")->getLocation().getX() + mMediumOffset), (mButtonManager.getButton("Level")->getLocation().getY() + 50));
	mHardButtonPosOPTIONS = Vector2D((mButtonManager.getButton("Level")->getLocation().getX() + mHardOffset), (mButtonManager.getButton("Level")->getLocation().getY() + 50));
	mMuteMusicPosOPTIONS = Vector2D((mButtonManager.getButton("MuteMusic")->getLocation().getX() + mMuteOffset), (mButtonManager.getButton("MuteMusic")->getLocation().getY() + 50));
}

void Game::resetEnemies()
{
	Enemy anEnemy;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			anEnemy = Enemy(Vector2D(75 * i, 75 * j), foodAnim, 50);
			mEnemyManager.addEnemy(anEnemy);
		}

	}

	//mEnemyManager.addEnemy(anEnemy);

	mEnemyManager.setMaxTime(.1f);

}

void Game::save()
{
	ofstream fout;
	fout.open("SAVE.save");
	fout << mScore << "\n";
	fout << mPlayer.getLives() << "\n";
	fout << mPlayer.getPlayerLocation().getX() << "\n" << mPlayer.getBulletLoc().getY() << "\n";
	fout << mPlayer.getBulletLoc().getX() << "\n" << mPlayer.getBulletLoc().getY() << "\n";
	fout << mEnemyManager;

	fout.close();
}

void Game::load()
{
	ifstream fin;
	fin.open("SAVE.save");
	fin >> mScore;
	int in;
	fin >> in;
	mPlayer.setLives(in);
	fin >> in;
	mPlayer.getPlayerLocation().setX(in);
	fin >> in;
	mPlayer.getPlayerLocation().setY(in);
	fin >> in;
	mPlayer.getBulletLocNC().setX(in);
	fin >> in;
	mPlayer.getBulletLocNC().setY(in);

	fin >> mEnemyManager;

}

/*
input system does interface events
i.e mouse moves, return new vector2d

add game as a listener to event system

example event flow
input system fires event for onclick()
event system deals handles that event, which goes into inputtranslator
input translator recieves that input, which then fires a new event, to create a unit that goes back to event system
EventSystem calls handleEvent based on that create unit event, which then calls handleevent again,
which then goes into game, and creates a new unit
*/