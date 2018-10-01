#pragma once
#ifndef ENEMY_H
#define ENEMY_H

#include "Vector2D.h"
#include "Animation.h"
#include "Trackable.h"

class Enemy : public Trackable
{
public:
	Enemy();
	Enemy(Vector2D location, Animation anim, float maxTime);
	
	~Enemy();

	void update(double dT);

	void draw();

	void setAnimTime(float time) { mMaxTime = time; };
	Vector2D getLoc() { return mLocation; };
	Vector2D getOrigLoc() { return mOrigLoc; };
	void setLoc(Vector2D loc) { mLocation = loc; };
	Animation getAnim() { return mAnim; };

	void setDidMove(bool movement) { mDidMove = movement; };
	bool getDidMove() { return mDidMove; };

	void setId(int id) { mId = id; };
	int getId() { return mId; };

	int getPoints() { return mPoints; };

private:
	Vector2D mLocation;
	Animation mAnim;
	float mTime, mMaxTime;
	int mPoints;

	bool mDidMove;

	int mId;

	Vector2D mOrigLoc;
};

#endif // !ENEMY_H
