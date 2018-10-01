#include "Trackable.h"
#include "Animation.h"
#include "Vector2D.h"
#pragma once
#ifndef UNIT_H
#define UNIT_H

class Unit : public Trackable
{
public:
	Unit();
	~Unit();

	void update(float dT);
	void draw(GraphicsBuffer &targetBuffer);
	void setAnimation();
	void addAnim(Sprite sprite, bool anim);
	void setSourceLoc(Vector2D sourceLoc);

	void speedUpAnim(bool anim);
	void slowDownAnim(bool anim);

	void setDoAnim(bool anim) { mDoAnim = anim; };
	bool getDoAnim(){ return mDoAnim; };

	Vector2D getOrigLoc();
	Vector2D getLocation() { return mLocation; }
private:
	Vector2D mLocation;
	Animation mAnim;
	Animation mAnim2;
	bool useAnim2;
	bool mDoAnim = true;
};


#endif // !UNIT_H
