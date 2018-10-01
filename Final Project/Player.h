#include "Trackable.h"
#include <vector>
#include "Sprite.h"
#include "Vector2D.h"
#include "EnemyManager.h"
#pragma once
#ifndef PLAYER_H
#define PLAYER_H

const enum DIRECTION { UP = 0, LEFT, RIGHT, DOWN, NUM_DIRECTION };

class Player : public Trackable
{
public:
	Player();
	Player(Sprite sprite, Vector2D loc);
	Player(Sprite sprite, Sprite shot, Vector2D loc, int bulSpeed);
	~Player();

	Vector2D getPlayerLocation() { return mLoc; };
	const Vector2D getBulletLoc() { return mBulletLoc; };
	Vector2D getBulletLocNC() { return mBulletLoc; };
	Sprite getPlayerSprite() { return mSprite; };
	Sprite getBulletSprite() { return mBullet; };
	DIRECTION getDirection() { return mDirection; };
	int getX() { return mX; };
	int getY() { return mY; };
	int getLives() { return mLives; };

	void setLoc(Vector2D loc) { mLoc = loc; };
	void setBulletLoc(Vector2D loc) { mBulletLoc = loc; };
	void setDir(DIRECTION dir) { mDirection = dir; };
	void setX(int x) { mX = x; };
	void setY(int y) { mY = y; };
	void setSprite(Sprite sprite) { mSprite = sprite; };
	void setLives(int lives) { mLives = lives; };

	void move(float dist);
	void fireBullet();
	void updateBullet();

	bool doesHaveBullet() { return mHasBullet; };

	//void checkCollision(const EnemyManager& manager);

	void draw();
private:
	DIRECTION mDirection;
	Sprite mSprite;
	Sprite mBullet;
	Vector2D mLoc;
	Vector2D mBulletLoc;
	int mX,  mY, mBulletSpeed;
	bool mHasBullet;

	int mLives;
};

#endif // !PLAYER_H
