#include "Enemy.h"
#include "GraphicsSystem.h"

Enemy::Enemy()
{
	mTime = 0;
	mMaxTime = 0;
}

Enemy::Enemy(Vector2D location, Animation anim, float maxTime)
{
	mLocation = location;
	mAnim = anim;
	mMaxTime = maxTime;
	mTime = 0;

	mOrigLoc = mLocation;
}

Enemy::~Enemy()
{

}

void Enemy::update(double dT)
{
	mTime += (float)dT;

	if (mTime > mMaxTime)
	{
		mTime = 0;
		mAnim.update();
	}
}

void Enemy::draw()
{
	GraphicsSystem::draw(mLocation, mAnim.getCurrentSprite(), .5);
}