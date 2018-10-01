#include "Trackable.h"
#include "Sprite.h"
#include <vector>
#pragma once
#ifndef ANIMATION_H
#define ANIMATION_H

class Animation : public Trackable
{
public:
	Animation();
	~Animation();
	
	void addSprite(Sprite sprite);
	void update(float dT);
	void update();
	
	Sprite getCurrentSprite();
	int getCurSprite();
	void speedUp();
	void slowDown();
	
private:
	std::vector<Sprite> mAnimList;
	float mTimeBetweenAnim, mMaxTimeBetweenAnim;
	Sprite mCurSprite;
	bool mShouldLoop;
	unsigned int mCurSpritePos;
};

#endif

/*
List of sprites + timing animaton
array, STL Vector
need to know current sprite, where we are in the list
Need to know how long to wait before going to the next sprite
wait each update. al_rest()?

In game loop...
input -> update -> draw
In Update() in main...
we need to figure out whether it's time to go to the next frame of animation or not.
animation needs its own update() function, to keep track of time.
pass in how much time has passed in the main loop. How much time has passed since the last update


Update(dt)
{
	*Keep track of elapsed time*
	*compare to target time*
	if(time to target)
		ontonext sprite
}
*/