#include "PlayerManager.h"
#include "Level.h"
#include "Event.h"
#include "EventSystem.h"

PlayerManager::PlayerManager()
{
	mCurTime = 0;
	mMaxTime = 0;
}

PlayerManager::PlayerManager(float maxTime)
{
	mCurTime = 0;
	mMaxTime = maxTime;
}

PlayerManager::PlayerManager(float maxTime, Sprite shot)
{
	mCurTime = 0;
	mMaxTime = maxTime;
	mPlayerShot = shot;
}

void PlayerManager::addPlayer(Player player)
{
	mPlayerList.push_back(player);
}

void PlayerManager::update(float dt, Level level)
{
	mCurTime += dt;
	if (mCurTime > mMaxTime)
	{
		std::cout << mPlayerList[0].getDirection() << std::endl;

		for (int i = mPlayerList.size() - 1; i >= 1; i--)
		{
			mPlayerList[i].setLoc(mPlayerList[i - 1].getPlayerLocation());
			mPlayerList[i].setX(mPlayerList[i - 1].getX());
			mPlayerList[i].setY(mPlayerList[i - 1].getY());
			if(level.getSquare(mPlayerList[i].getX(), mPlayerList[i].getY()).getPassable())
				level.getSquare(mPlayerList[i].getX(), mPlayerList[i].getY()).setPassable(false);
		}

		if (mPlayerList[0].getDirection() == UP)
		{
			mPlayerList[0].setLoc(level.getSquare(mPlayerList[0].getX(), mPlayerList[0].getY() - 1).getPos());
			mPlayerList[0].setY(mPlayerList[0].getY() - 1);

		}

		if (mPlayerList[0].getDirection() == LEFT)
		{
			mPlayerList[0].setLoc(level.getSquare(mPlayerList[0].getX() - 1, mPlayerList[0].getY()).getPos());
			mPlayerList[0].setX(mPlayerList[0].getX() - 1);
		}

		if (mPlayerList[0].getDirection() == RIGHT)
		{
			mPlayerList[0].setLoc(level.getSquare(mPlayerList[0].getX() + 1, mPlayerList[0].getY()).getPos());
			mPlayerList[0].setX(mPlayerList[0].getX() + 1);
		}

		if (mPlayerList[0].getDirection() == DOWN)
		{
			mPlayerList[0].setLoc(level.getSquare(mPlayerList[0].getX(), mPlayerList[0].getY() + 1).getPos());
			mPlayerList[0].setY(mPlayerList[0].getY() + 1);
		}

		if (!level.getSquare(mPlayerList[0].getX(), mPlayerList[0].getY()).getPassable())
			mDead = true;

		if (level.getSquare(mPlayerList[0].getX(), mPlayerList[0].getY()).getHasFood())
		{
			EventSystem::getInstance()->fireEvent(TEST_MAKE_PLAYER);
			//std::cout << level.getSquare(mPlayerList[0].getX(), mPlayerList[0].getY()).getHasFood() << std::endl;
		}

		if (level.getSquare(mPlayerList[0].getX(), mPlayerList[0].getY()).getHasFoodPU())
		{
			EventSystem::getInstance()->fireEvent(FOOD_PU);
			//std::cout << level.getSquare(mPlayerList[0].getX(), mPlayerList[0].getY()).getHasFood() << std::endl;
		}

		if (level.getSquare(mPlayerList[0].getX(), mPlayerList[0].getY()).getHasPointPU())
		{
			EventSystem::getInstance()->fireEvent(POINT_PU);
			//std::cout << level.getSquare(mPlayerList[0].getX(), mPlayerList[0].getY()).getHasFood() << std::endl;
		}

		if (level.getSquare(mPlayerList[0].getX(), mPlayerList[0].getY()).getHasShrinkPU())
		{
			EventSystem::getInstance()->fireEvent(SHRINK_PU);
			//std::cout << level.getSquare(mPlayerList[0].getX(), mPlayerList[0].getY()).getHasFood() << std::endl;
		}

		std::cout << mPlayerList[0].getDirection() << std::endl;

		mCurTime = 0;

	}
}

void PlayerManager::resetPlayer()
{
	mPlayerList.erase(mPlayerList.begin() + 1, mPlayerList.end());
	mPlayerList[0].setX(1);
	mPlayerList[0].setY(1);
}

void PlayerManager::removeOnePlayer()
{
	mPlayerList.erase(mPlayerList.end() - 1);
}

void PlayerManager::draw()
{
	for (unsigned int i = 0; i < mPlayerList.size(); i++)
	{
		mPlayerList[i].draw();
	}
}