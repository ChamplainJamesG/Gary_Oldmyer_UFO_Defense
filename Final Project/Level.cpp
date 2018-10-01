#include "Level.h"
#include <iostream>
#include <time.h>
#include "PlayerManager.h"

Level::Level()
{
	srand((unsigned int)time(NULL));
	for (int i = 0; i < GRID_X; i++)
	{
		for (int j = 0; j < GRID_Y; j++)
		{
			mLevel[i][j] = Square(Vector2D(50 * i, 50 * j), true, Sprite(), i, j);
		}
	}
}

Level::Level(float width, float height, Sprite sprite)
{
	srand((unsigned int)time(NULL));
	mX = (int)width;
	mY = (int)height;
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			//sprite.setSourceLoc(Vector2D())
			mLevel[i][j] = Square(Vector2D(width * i, height * j), true, sprite, i, j);
			mLevel[i][j].setPos(Vector2D(sprite.getWidth() * i, sprite.getWidth() * j));
		}
	}

	mLevel[4][4].setPassable(false);
}

Level::Level(float width, float height, Sprite sprite, Sprite sprite2)
{
	srand((unsigned int)time(NULL));
	mX = (int)width;
	mY = (int)height;
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			//sprite.setSourceLoc(Vector2D())
			mLevel[i][j] = Square(Vector2D(width * i, height * j), true, sprite, sprite2, i, j);
			mLevel[i][j].setPos(Vector2D(sprite.getWidth() * i, sprite.getWidth() * j));
		}
	}

	mLevel[4][4].setPassable(false);
}

Level::Level(float width, float height, Sprite sprite, Sprite sprite2, Sprite sprite3)
{
	srand((unsigned int)time(NULL));
	mX = (int)width;
	mY = (int)height;
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			//sprite.setSourceLoc(Vector2D())
			mLevel[i][j] = Square(Vector2D(width * i, height * j), true, sprite, sprite2, sprite3, i, j);
			mLevel[i][j].setPos(Vector2D(sprite.getWidth() * i, sprite.getWidth() * j));
		}
	}

	mLevel[4][4].setPassable(false);
}

Level::Level(float width, float height, Sprite sprite, Sprite sprite2, Sprite sprite3, Sprite sprite4, Sprite sprite5, Sprite sprite6)
{
	srand((unsigned int)time(NULL));
	mX = (int)width;
	mY = (int)height;
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			//sprite.setSourceLoc(Vector2D())
			mLevel[i][j] = Square(Vector2D(width * i, height * j), true, sprite, sprite2, sprite3, sprite4, sprite5, sprite6, i, j);
			mLevel[i][j].setPos(Vector2D(sprite.getWidth() * i, sprite.getWidth() * j));
		}
	}

	mLevel[4][4].setPassable(false);
}

Level::Level(float width, float height, Sprite sprite, Sprite sprite2, Sprite sprite3, Sprite sprite4, Sprite sprite5, Sprite sprite6, Animation anim1)
{
	srand((unsigned int)time(NULL));
	mX = (int)width;
	mY = (int)height;
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			//sprite.setSourceLoc(Vector2D())
			mLevel[i][j] = Square(Vector2D(width * i, height * j), true, sprite, sprite2, sprite3, sprite4, sprite5, sprite6, i, j, anim1);
			mLevel[i][j].setPos(Vector2D(sprite.getWidth() * i, sprite.getWidth() * j));
		}
	}

	mLevel[4][4].setPassable(false);
}

Level::Level(float width, float height, Sprite sprite, Sprite sprite2, Sprite sprite3, Sprite sprite4, Sprite sprite5, Sprite sprite6, Animation anim1, Animation foodPAnim, Animation pointPAnim, Animation shrinkPAnim)
{
	srand((unsigned int)time(NULL));
	mX = (int)width;
	mY = (int)height;
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			//sprite.setSourceLoc(Vector2D())
			mLevel[i][j] = Square(Vector2D(width * i, height * j), true, sprite, sprite2, sprite3, sprite4, sprite5, sprite6, i, j, anim1, foodPAnim, pointPAnim, shrinkPAnim);
			mLevel[i][j].setPos(Vector2D(sprite.getWidth() * i, sprite.getWidth() * j));
		}
	}

	mLevel[4][4].setPassable(false);
}



Level::~Level()
{

}

void Level::update(float dt)
{
	for (int i = 0; i < mX; i++)
	{
		for (int j = 0; j < mY; j++)
		{
			if (mLevel[i][j].getHasFood() || mLevel[i][j].getHasFoodPU() || mLevel[i][j].getHasPointPU() || mLevel[i][j].getHasShrinkPU())
				mLevel[i][j].update(dt);
		}
	}
}

void Level::drawLevel(GraphicsBuffer *buffer)
{
	for (int i = 0; i < mX; i++)
	{
		for (int j = 0; j < mY; j++)
		{
			mLevel[i][j].draw();
		}
	}
}

void Level::spawnFood(PlayerManager playerManager)
{
	bool foodSpawned = false;
	bool canSpawn;
	do
	{
		canSpawn = true;
		int x = rand() % mX;
		int y = rand() % mY;

		for (int i = 0; i < playerManager.getNumPlayer(); i++)
		{
			if (playerManager.getPlayer(i).getX() == x && playerManager.getPlayer(i).getY() == y)
			{
				canSpawn = false;
				break;
			}
		}

		if (mLevel[x][y].getPassable() && canSpawn && !(mLevel[x][y].getHasFoodPU() || mLevel[x][y].getHasPointPU() || mLevel[x][y].getHasShrinkPU()))
		{
			mLevel[x][y].setHasFood(true);
			foodSpawned = true;
		}

	} while (!foodSpawned);
}

void Level::spawnPowerup(PlayerManager playerManager)
{
	bool powerSpawn = false;
	bool canSpawn;
	do
	{
		canSpawn = true;
		int x = rand() % mX;
		int y = rand() % mY;

		for (int i = 0; i < playerManager.getNumPlayer(); i++)
		{
			if (playerManager.getPlayer(i).getX() == x && playerManager.getPlayer(i).getY() == y)
			{
				canSpawn = false;
				break;
			}
		}

		if (mLevel[x][y].getPassable() && canSpawn && !mLevel[x][y].getHasFood())
		{
			int random = rand() % 100 + 1;
			if (random < mPowerSpawn1)
			{
				mLevel[x][y].setHasFoodPU(true);
			}
			else if (random < mPowerSpawn2)
			{
				mLevel[x][y].setHasPointPU(true);
			}
			else
			{
				mLevel[x][y].setShrinkPU(true);
			}
			//mLevel[x][y].setHasFood(true);
			powerSpawn = true;
		}

	} while (!powerSpawn);
}

std::ifstream& operator >>(std::ifstream& fin, Level &level)
{
	int i, j;
	char in;
	fin >> level.mSubFactor;
	fin >> level.mScoreToWin;
	fin >> level.mPowerSpawn1;
	fin >> level.mPowerSpawn2;
	fin >> level.mPowerSpawn3;
	for (i = 0; i < level.mY; i++)
	{
		for (j = 0; j < level.mX; j++)
		{
			fin >> in;
			if (in == 'o')
				level.mLevel[j][i].setPassable(true);
			else
				level.mLevel[j][i].setPassable(false);
		}
	}

	return fin;
}