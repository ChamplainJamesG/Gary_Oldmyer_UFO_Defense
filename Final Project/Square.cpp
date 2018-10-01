#include "Square.h"
#include "GraphicsSystem.h"
#include "Animation.h"

Square::Square()
{

}

Square::Square(Vector2D loc, bool pass, Sprite sprite)
{
	mPos = loc;
	mPassable = pass;
	mSprite = sprite;
}

Square::Square(Vector2D loc, bool pass, Sprite sprite, int x, int y)
{
	mPos = loc;
	mPassable = pass;
	mSprite = sprite;
	mX = x;
	mY = y;
}

Square::Square(Vector2D loc, bool pass, Sprite sprite, Sprite sprite2, int x, int y)
{
	mPos = loc;
	mPassable = pass;
	mSprite = sprite;
	mSprite2 = sprite2;
	mX = x;
	mY = y;
}

Square::Square(Vector2D loc, bool pass, Sprite sprite, Sprite sprite2, Sprite sprite3, int x, int y)
{
	mPos = loc;
	mPassable = pass;
	mSprite = sprite;
	mSprite2 = sprite2;
	mSprite3 = sprite3;
	mX = x;
	mY = y;
}

Square::Square(Vector2D loc, bool pass, Sprite sprite, Sprite sprite2, Sprite sprite3, Sprite sprite4, Sprite sprite5, Sprite sprite6, int x, int y, Animation anim1)
{
	mPos = loc;
	mPassable = pass;
	mSprite = sprite;
	mSprite2 = sprite2;
	mSprite3 = sprite3;
	mSprite4 = sprite4;
	mSprite5 = sprite5;
	mSprite6 = sprite6;
	mX = x;
	mY = y;
	mAnim1 = anim1;
}


Square::Square(Vector2D loc, bool pass, Sprite sprite, Sprite sprite2, Sprite sprite3, Sprite sprite4, Sprite sprite5, Sprite sprite6, int x, int y)
{
	mPos = loc;
	mPassable = pass;
	mSprite = sprite;
	mSprite2 = sprite2;
	mSprite3 = sprite3;
	mSprite4 = sprite4;
	mSprite5 = sprite5;
	mSprite6 = sprite6;
	mX = x;
	mY = y;
}

Square::Square(Vector2D loc, bool pass, Sprite sprite, Sprite sprite2, Sprite sprite3, Sprite sprite4, Sprite sprite5, Sprite sprite6, int x, int y, Animation anim1, Animation foodPAnim, Animation pointPAnim, Animation shrinkPAnim)
{
	mPos = loc;
	mPassable = pass;
	mSprite = sprite;
	mSprite2 = sprite2;
	mSprite3 = sprite3;
	mSprite4 = sprite4;
	mSprite5 = sprite5;
	mSprite6 = sprite6;
	mX = x;
	mY = y;
	mAnim1 = anim1;
	mFoodPUAnim = foodPAnim;
	mPointPUAnim = pointPAnim;
	mShrinkPUAnim = shrinkPAnim;
}



Square::~Square()
{

}

void Square::update(float dt)
{
	if(mHasFood)
		mAnim1.update(dt);
	if (mHasPointPowerUp)
		mPointPUAnim.update(dt);
	if (mHasSuperFoodPowerUp)
		mFoodPUAnim.update(dt);
	if (mHasShrinkRayPowerUp)
		mShrinkPUAnim.update(dt);
}

void Square::draw()
{
	//GraphicsSystem::draw(Vector2D(0, 0), mSprite, 1f);
	if (mPassable)
		GraphicsSystem::draw(mPos, mSprite, 1.0f);
	if (mHasFood)
		GraphicsSystem::draw(mPos, mAnim1.getCurrentSprite(), 1.0f);
	if(mHasPointPowerUp)
		GraphicsSystem::draw(mPos, mPointPUAnim.getCurrentSprite(), 1.0f);
	if(mHasSuperFoodPowerUp)
		GraphicsSystem::draw(mPos, mFoodPUAnim.getCurrentSprite(), 1.0f);
	if(mHasShrinkRayPowerUp)
		GraphicsSystem::draw(mPos, mShrinkPUAnim.getCurrentSprite(), 1.0f);
	if(!mPassable)
		GraphicsSystem::draw(mPos, mSprite2, 1.0f);
}