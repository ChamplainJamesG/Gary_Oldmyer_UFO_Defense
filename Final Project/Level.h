#include "Vector2D.h"
#include "Trackable.h"
#include "Square.h"
#include "GraphicsBuffer.h"
#include <fstream>
#include "Animation.h"
#pragma once
#ifndef LEVEL_H
#define LEVEL_H

const int GRID_X = 15, GRID_Y = 15;

class PlayerManager;

class Level : public Trackable
{
public:
	Level();
	Level(float width, float height, Sprite sprite);
	Level(float width, float height, Sprite sprite, Sprite sprite2);
	Level(float width, float height, Sprite sprite, Sprite sprite2, Sprite sprite3);
	Level(float width, float height, Sprite sprite, Sprite sprite2, Sprite sprite3, Sprite sprite4, Sprite sprite5, Sprite sprite6);
	Level(float width, float height, Sprite sprite, Sprite sprite2, Sprite sprite3, Sprite sprite4, Sprite sprite5, Sprite sprite6, Animation anim1);
	Level(float width, float height, Sprite sprite, Sprite sprite2, Sprite sprite3, Sprite sprite4, Sprite sprite5, Sprite sprite6, Animation anim1, Animation foodPAnim, Animation pointPAnim, Animation shrinkPAnim);


	~Level();

	void update(float dt);

	Square& getSquare(int x, int y) { return mLevel[x][y]; };
	float getSubFactor() { return mSubFactor; };

	int getScoreToWin() { return mScoreToWin; };


	void setSubFactor(float factor) { mSubFactor = factor; };

	void drawLevel(GraphicsBuffer *graphicsBuffer);

	void spawnFood(PlayerManager playerManager);
	void spawnPowerup(PlayerManager playerManager);

	friend std::ifstream& operator >>(std::ifstream& fin, Level &level);

private:
	Square mLevel[GRID_X][GRID_Y];
	int mX, mY;
	float mSubFactor;
	int mScoreToWin;
	int mPowerSpawn1, mPowerSpawn2, mPowerSpawn3;
};

#endif // !LEVEL_H
