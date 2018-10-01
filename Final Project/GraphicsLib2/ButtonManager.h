//Zach Phillips
//Used to manage button units

#include "Buttons.h"
#include "Trackable.h"
#include "Vector2D.h"

#pragma once

class ButtonManager : public Trackable
{
public:
	ButtonManager();
	~ButtonManager();

	void cleanup();

	void addButton(Buttons* newButton);

	void update(Vector2D mousePos);

	//used if mouseButtonDown
	std::string getActiveButtonName();

	int getAmountFull() { return mIndex; };

	Buttons* getButton(int index) { return mButtonArray[index]; };
	Buttons* getButton(std::string index);
	Vector2D getLocation(Buttons button) { return button.getLocation(); };

private:
	//unsure if needed 10 units, but easier to 
	Buttons* mButtonArray[10];

	int mIndex = 0;

	std::string buttonName;
};
