#include "Animation.h"

Animation::Animation()
{
	mAnimList;
	mTimeBetweenAnim = 200;
	//mCurSprite = NULL;
	mShouldLoop = false;
	mCurSpritePos = 0;
	mMaxTimeBetweenAnim = 5;
}

Animation::~Animation()
{
	//Empty out mANimList;
	/*
	for (int i = 0; i < mAnimList.size() - 1; i++)
	{
		delete(mAnimList[i]);
	}
	*/
	mAnimList.clear();
	//mCurSprite = NULL;
	//delete mCurSprite;
}

void Animation::addSprite(Sprite sprite)
{
	//std::vector<Sprite*>::iterator it;
	//it = mAnimList.end();
	//mAnimList.insert(it, sprite);
	//mAnimList.insert(mAnimList.size(), sprite);
	//mAnimList.insert(mAnimList.size(), sprite);
	mAnimList.push_back(sprite);
	mCurSprite = mAnimList[0];
}

void Animation::update(float dt)
{
	mTimeBetweenAnim += dt;
	//std::cout << mTimeBetweenAnim << " / " << mMaxTimeBetweenAnim << std::endl;

	if (mMaxTimeBetweenAnim < mTimeBetweenAnim)
	{
		mCurSpritePos++;
		if (mCurSpritePos > mAnimList.size() - 1)
			mCurSpritePos = 0;

		mCurSprite = mAnimList[mCurSpritePos];
		mTimeBetweenAnim = 0;
	}

	//update to next sprite.
}

void Animation::update()
{
	mCurSpritePos++;
	if (mCurSpritePos > mAnimList.size() - 1)
		mCurSpritePos = 0;

	mCurSprite = mAnimList[mCurSpritePos];
	mTimeBetweenAnim = 0;
}

Sprite Animation::getCurrentSprite()
{
	return mCurSprite;
}

int Animation::getCurSprite()
{
	return mCurSpritePos;
}

void Animation::speedUp()
{
	mMaxTimeBetweenAnim -= .1f;
	if (mMaxTimeBetweenAnim < 0)
		mMaxTimeBetweenAnim = 0;
}

void Animation::slowDown()
{
	mMaxTimeBetweenAnim += .1f;
}