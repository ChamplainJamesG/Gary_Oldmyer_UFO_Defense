#include "Player.h"
#include "GraphicsSystem.h"
#include <iostream>

Player::Player()
{

}

Player::Player(Sprite sprite, Vector2D loc)
{
	mSprite = sprite;
	mLoc = loc;
	mDirection = RIGHT;
}

Player::Player(Sprite sprite, Sprite shot, Vector2D loc, int bulletSpeed)
{
	mSprite = sprite;
	mBullet = shot;
	mLoc = loc;
	mHasBullet = false;
	mBulletSpeed = bulletSpeed;
	mLives = 3;
}

Player::~Player()
{

}

void Player::draw()
{
	GraphicsSystem::draw(mLoc, mSprite, 1.0f);
	if(mHasBullet)
		GraphicsSystem::draw(mBulletLoc, mBullet, 0.5);

}

void Player::move(float dist)
{
	if (mDirection == RIGHT)
	{
		mLoc.setX(mLoc.getX() + dist);
	}

	if (mDirection == LEFT)
	{
		mLoc.setX(mLoc.getX() - dist);
	}
}

void Player::fireBullet()
{
	if (!mHasBullet)
	{
		mHasBullet = true;
		//mBullet.setSourceLoc(Vector2D(mLoc.getX(), mLoc.getY() - 20));
		mBulletLoc.setX(mLoc.getX() + 50);
		mBulletLoc.setY(mLoc.getY() - 20);
	}
}

void Player::updateBullet()
{
	if (mHasBullet)
	{
		//mBullet.setSourceLoc(Vector2D(mLoc.getX(), mLoc.getY() + mBulletSpeed));
		mBulletLoc.setY(mBulletLoc.getY() - mBulletSpeed);

		//std::cout << mBulletLoc.getY() << std::endl;;
		
		if (mBullet.getHeight() / 2 + mBulletLoc.getY() < 0)
		{
			mHasBullet = false;
		}
	}
}
