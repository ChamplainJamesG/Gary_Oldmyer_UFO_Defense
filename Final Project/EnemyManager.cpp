#include "EnemyManager.h"
#include "GraphicsSystem.h"
#include "System.h"
#include "EventSystem.h"

EnemyManager::EnemyManager()
{
	mMoveRight = true;
}

void EnemyManager::addEnemy(Enemy enemy)
{
	mEnemyList.push_back(enemy);
}

void EnemyManager::update(double dT, GraphicsSystem& theSystem)
{
	unsigned int i;
	for (i = 0; i < mEnemyList.size(); i++)
	{
		mEnemyList[i].update(dT);
	}

	mTime += (float)dT;

	if (mTime > mMaxTime)
	{
		mTime = 0;
		for (i = 0; i < mEnemyList.size(); i++)
			mEnemyList[i].setDidMove(false);

		if (mMoveRight)
		{
			
			for (i = 0; i < mEnemyList.size(); i++)
			{
				if (mEnemyList[i].getAnim().getCurrentSprite().getWidth() + mEnemyList[i].getLoc().getX() >= theSystem.getWidth())
				{
					//mMoveRight = false;
					doneMove = true;
					break;
				}
				mEnemyList[i].setDidMove(true);
				mEnemyList[i].setLoc(Vector2D(mEnemyList[i].getLoc().getX() + 50, mEnemyList[i].getLoc().getY()));
			}
			//timesMoved--;
		}

		else
		{
			
			for (i = 0; i < mEnemyList.size(); i++)
			{
				if (mEnemyList[i].getLoc().getX() - 50 <= 0)
				{
				//mMoveRight = true;
					doneMove = true;
					break;
				}
				mEnemyList[i].setDidMove(true);
				mEnemyList[i].setLoc(Vector2D(mEnemyList[i].getLoc().getX() - 50, mEnemyList[i].getLoc().getY()));
			}
		

			//timesMoved--;


		}

		if (doneMove)
		{
			mMoveRight = !mMoveRight;
			doneMove = false;
			if(!mMoveRight)
				for (unsigned int j = 0; j < mEnemyList.size(); j++)
				{
					if(mEnemyList[j].getDidMove())
						mEnemyList[j].setLoc(Vector2D(mEnemyList[j].getLoc().getX() - 50, mEnemyList[j].getLoc().getY()));
				}
			else
			{
				for (unsigned int j = 0; j < mEnemyList.size(); j++)
				{
					if (mEnemyList[j].getDidMove())
						mEnemyList[j].setLoc(Vector2D(mEnemyList[j].getLoc().getX() + 50, mEnemyList[j].getLoc().getY()));
				}
			}

			//timesMoved = 10;
			for (unsigned int i = 0; i < mEnemyList.size(); i++)
				mEnemyList[i].setLoc(Vector2D(mEnemyList[i].getLoc().getX(), mEnemyList[i].getLoc().getY() + 100));

		}

		/*
		if (timesMoved == 0)
		{
			mMoveRight = !mMoveRight;
			timesMoved = 10;
			for (int i = 0; i < mEnemyList.size(); i++)
				mEnemyList[i].setLoc(Vector2D(mEnemyList[i].getLoc().getX(), mEnemyList[i].getLoc().getY() + 100));

		}
		*/
	}
}

void EnemyManager::checkCollision(Player& player)
{
	for (unsigned int i = 0; i < mEnemyList.size(); i++)
	{
		/*
		if ((player.getBulletLoc().getY() > mEnemyList[i].getLoc().getY() + mEnemyList[i].getAnim().getCurrentSprite().getHeight() && player.getBulletLoc().getY() + player.getBulletSprite().getHeight() < mEnemyList[i].getLoc().getY()) &&
			(player.getBulletLoc().getX() >= mEnemyList[i].getLoc().getX() && player.getBulletLoc().getX() < mEnemyList[i].getAnim().getCurrentSprite().getWidth()) ||
			(mEnemyList[i].getAnim().getCurrentSprite().getWidth() >= player.getBulletLoc().getX() && mEnemyList[i].getAnim().getCurrentSprite().getWidth() < player.getBulletSprite().getWidth()))
		{
			std::cout << "collided" << std::endl;
		}
		*/

		//need to compare y position.
		if (player.getBulletLoc().getY() < mEnemyList[i].getLoc().getY() + mEnemyList[i].getAnim().getCurrentSprite().getHeight() / 2 && player.getBulletLoc().getY() + player.getBulletSprite().getHeight() / 2 > mEnemyList[i].getLoc().getY())
		{
			//then x
			//like doing that big if statement above, but cleaner
			if (player.getBulletLoc().getX() + player.getBulletSprite().getWidth() / 2 > mEnemyList[i].getLoc().getX() && player.getBulletLoc().getX() < mEnemyList[i].getLoc().getX() + mEnemyList[i].getAnim().getCurrentSprite().getWidth())
			{
				mEnemyList.erase(mEnemyList.begin() + i);
				player.setBulletLoc(Vector2D(1000, -100));

			}
		}
	}
}

bool EnemyManager::checkCollisionB(Player& player)
{
	for (unsigned int i = 0; i < mEnemyList.size(); i++)
	{
		/*
		if ((player.getBulletLoc().getY() > mEnemyList[i].getLoc().getY() + mEnemyList[i].getAnim().getCurrentSprite().getHeight() && player.getBulletLoc().getY() + player.getBulletSprite().getHeight() < mEnemyList[i].getLoc().getY()) &&
		(player.getBulletLoc().getX() >= mEnemyList[i].getLoc().getX() && player.getBulletLoc().getX() < mEnemyList[i].getAnim().getCurrentSprite().getWidth()) ||
		(mEnemyList[i].getAnim().getCurrentSprite().getWidth() >= player.getBulletLoc().getX() && mEnemyList[i].getAnim().getCurrentSprite().getWidth() < player.getBulletSprite().getWidth()))
		{
		std::cout << "collided" << std::endl;
		}
		*/

		//need to compare y position.
		if (player.getBulletLoc().getY() < mEnemyList[i].getLoc().getY() + mEnemyList[i].getAnim().getCurrentSprite().getHeight() / 2 && player.getBulletLoc().getY() + player.getBulletSprite().getHeight() / 2 > mEnemyList[i].getLoc().getY())
		{
			//then x
			//like doing that big if statement above, but cleaner
			if (player.getBulletLoc().getX() + player.getBulletSprite().getWidth() / 2 > mEnemyList[i].getLoc().getX() && player.getBulletLoc().getX() < mEnemyList[i].getLoc().getX() + mEnemyList[i].getAnim().getCurrentSprite().getWidth())
			{
				mEnemyList.erase(mEnemyList.begin() + i);
				player.setBulletLoc(Vector2D(1000, -100));
				return true;
			}
		}
	}

	return false;
}

bool EnemyManager::checkEnemyDistance(System& system)
{
	for (unsigned int i = 0; i < mEnemyList.size(); i++)
	{
		if (mEnemyList[i].getLoc().getY() + mEnemyList[i].getAnim().getCurrentSprite().getHeight() / 2 > system.getSystem().getHeight() / 2)
		{
			//EventSystem::getInstance()->fireEvent(HURT_PLAYER);
			return true;
		}
	}

	return false;
}

void EnemyManager::draw()
{
	for (unsigned int i = 0; i < mEnemyList.size(); i++)
		mEnemyList[i].draw();
}

bool EnemyManager::checkEnemiesDead()
{
	return mEnemyList.size() == 0;
}

void EnemyManager::moveEnemiesToStart()
{
	for (unsigned int i = 0; i < mEnemyList.size(); i++)
	{
		mEnemyList[i].setLoc(mEnemyList[i].getOrigLoc());
	}
}

void EnemyManager::clearList()
{
	mTime = 0;
	for (unsigned int i = 0; i < mEnemyList.size(); i++)
	{
		mEnemyList.erase(mEnemyList.begin(), mEnemyList.end());
	}
}

std::ofstream& operator<<(std::ofstream& fout, EnemyManager manager)
{
	fout << manager.mEnemyList.size() << "\n";

	for (unsigned int i = 0; i < manager.mEnemyList.size(); i++)
	{
		fout << manager.mEnemyList[i].getId() << "\n";
		fout << manager.mEnemyList[i].getLoc().getX() << "\n" << manager.mEnemyList[i].getLoc().getY() << "\n";
	}

	return fout;
}

std::ifstream& operator>>(std::ifstream& fin, EnemyManager manager)
{
	int size;
	Enemy enemy;
	Vector2D vector;
	fin >> size;

	std::vector<Enemy> tempList;

	int in;
	int iD;
	for (unsigned int i = 0; i < size; i++)
	{
		fin >> iD;
		fin >> in;
		vector.setX(in);
		fin >> in;
		vector.setY(in);

		enemy.setLoc(vector);
		enemy.setId(iD);

		tempList.push_back(enemy);
	}

	for (unsigned int i = 0; i < manager.mEnemyList.size(); i++)
	{
		if (manager.mEnemyList[i].getId() != tempList[i].getId())
		{
			manager.mEnemyList.erase(manager.mEnemyList.begin() + i);
		}

		else
		{
			manager.mEnemyList[i].setLoc(tempList[i].getLoc());
		}
	}

	return fin;
}