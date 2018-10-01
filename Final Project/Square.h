#include "Vector2D.h"
#include "Trackable.h"
#include "Sprite.h"
#include "Animation.h"
#pragma once
#ifndef SQUARE_H
#define SQUARE_H

class Square : public Trackable
{
public:
	Square();
	Square(Vector2D loc, bool pass, Sprite sprite);
	Square(Vector2D loc, bool pass, Sprite sprite, int x, int y);
	Square(Vector2D loc, bool pass, Sprite sprite, Sprite sprite2, int x, int y);
	Square(Vector2D loc, bool pass, Sprite sprite, Sprite sprite2, Sprite sprite3, int x, int y);
	Square(Vector2D loc, bool pass, Sprite sprite, Sprite sprite2, Sprite sprite3, Sprite sprite4, Sprite sprite5, Sprite sprite6, int x, int y);
	Square(Vector2D loc, bool pass, Sprite sprite, Sprite sprite2, Sprite sprite3, Sprite sprite4, Sprite sprite5, Sprite sprite6, int x, int y, Animation anim1);
	Square(Vector2D loc, bool pass, Sprite sprite, Sprite sprite2, Sprite sprite3, Sprite sprite4, Sprite sprite5, Sprite sprite6, int x, int y, Animation anim1, Animation foodPAnim, Animation pointPAnim, Animation shrinkPAnim);

	~Square();

	void update(float dt);

	Vector2D getPos() { return mPos; };
	bool getPassable() { return mPassable; };
	bool getHasFood() { return mHasFood; };
	int getX() { return mX; };
	int getY() { return mY; };
	bool getHasPointPU() { return mHasPointPowerUp; };
	bool getHasFoodPU() { return mHasSuperFoodPowerUp; };
	bool getHasShrinkPU() { return mHasShrinkRayPowerUp; };


	void setPos(Vector2D pos) { mPos = pos; };
	void setPassable(bool pass) { mPassable = pass; };
	void setHasFood(bool food) { mHasFood = food; };
	void setHasPointPU(bool has) { mHasPointPowerUp = has; };
	void setHasFoodPU(bool has) { mHasSuperFoodPowerUp = has; };
	void setShrinkPU(bool has) { mHasShrinkRayPowerUp = has; };

	void setFoodAnim(Animation anim) { mAnim1 = anim; };

	void draw();
private:
	Vector2D mPos;
	bool mPassable, mHasFood = false, mHasPointPowerUp = false, mHasSuperFoodPowerUp = false, mHasShrinkRayPowerUp = false;
	Sprite mSprite;
	Sprite mSprite2;
	Sprite mSprite3, mSprite4, mSprite5, mSprite6;
	Animation mAnim1, mFoodPUAnim, mPointPUAnim, mShrinkPUAnim;
	int mX,  mY;

};

#endif // !SQUARE_H
