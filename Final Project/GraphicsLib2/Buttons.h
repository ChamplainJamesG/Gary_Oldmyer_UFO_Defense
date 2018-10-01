//Zach Phillips
//Used to create button units

#pragma once

#include "Trackable.h"
#include "Sprite.h"
#include <string>

class Buttons : public Trackable
{
public:

	Buttons();
	Buttons(std::string buttonName, Sprite buttonUnlit, Sprite buttonLit, int xPos, int yPos);

	//the bool is for Game's compareLoc(Unit unit) function
	void update(Vector2D mousePos);

	bool getIsSelected() { return mSelected; };
	void setIsSelected(bool choice) { mSelected = choice; };

	std::string getName() { return mName; };

	Vector2D getLocation();

	Sprite getActiveSprite() { return mActiveSprite; };
	void setIsDrawn(bool choice) { isDrawn = choice; };
	bool getIsDrawn() { return isDrawn; };

private:
	Sprite mActiveSprite;
	Sprite mButtonUnlit;
	Sprite mButtonLit;
	int mXPos;
	int mYPos;

	//this bool is needed so that when we check to see if mouse button down, it will say it's selected
	bool mSelected = false;
	bool isDrawn = false;

	std::string mName;
};