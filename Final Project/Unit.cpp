#include "Unit.h"
#include "GraphicsSystem.h"

Unit::Unit()
{
	//mLocation = Vector2D(0, 0);
	//mAnim = new Animation();
	//mAnim2 = new Animation();
	useAnim2 = true;
}

Unit::~Unit()
{

}

void Unit::update(float dt)
{
	if (mDoAnim)
	{
		if (useAnim2)
			mAnim.update(dt);
		else
			mAnim2.update(dt);
	}

}

void Unit::draw(GraphicsBuffer &targetBuffer)
{
	if(useAnim2)
		GraphicsSystem::draw(targetBuffer, mLocation, mAnim.getCurrentSprite(), 1);
	else
	{
		GraphicsSystem::draw(targetBuffer, mLocation, mAnim2.getCurrentSprite(), 1);
	}
}

void Unit::setAnimation()
{
	useAnim2 = !useAnim2;
}

void Unit::addAnim(Sprite sprite, bool anim2)
{
	if(anim2)
		mAnim.addSprite(sprite);
	else
	{
		mAnim2.addSprite(sprite);
	}
}

void Unit::setSourceLoc(Vector2D sourceLoc)
{
	mLocation = sourceLoc;
	//mAnim->getCurrentSprite()->setSourceLoc(sourceLoc);
	//std::cout << mLocation.getX() << " " << mLocation.getY() << std::endl;
}

Vector2D Unit::getOrigLoc()
{
	return mLocation;
}

void Unit::speedUpAnim(bool anim)
{
	if (anim)
		mAnim.speedUp();
	else
		mAnim2.speedUp();
}

void Unit::slowDownAnim(bool anim)
{
	if (anim)
		mAnim.slowDown();
	else
		mAnim2.slowDown();
}