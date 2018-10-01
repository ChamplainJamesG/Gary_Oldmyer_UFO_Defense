#include "ButtonManager.h"

ButtonManager::ButtonManager()
{

}

ButtonManager::~ButtonManager()
{

}

void ButtonManager::cleanup()
{
	for (int i = 0; i < mIndex - 1; i++)
	{
		delete mButtonArray[i];
	}
}

void ButtonManager::addButton(Buttons *newButton)
{
	if (mIndex < 10)
	{
	mButtonArray[mIndex] = newButton;
	mIndex++;
	}
}

void ButtonManager::update(Vector2D mousePos)
{
	for (int i = 0; i < mIndex; i++)
	{
		mButtonArray[i]->update(mousePos);
	}
}

std::string ButtonManager::getActiveButtonName()
{
	std::string buttonName = "NULL";

	for (int i = 0; i < mIndex; i++)
	{
		if (mButtonArray[i]->getIsSelected() == true)
		{
			buttonName = mButtonArray[i]->getName();
			break;
		}
	}

	return buttonName;
}

Buttons * ButtonManager::getButton(std::string index)
{
	bool found = false;

	for (int i = 0; i <= mIndex; i++)
	{
		if (mButtonArray[i]->getName() == index)
		{
			found = true;
			return mButtonArray[i];
		}
	}

	if (!found)
		return mButtonArray[0];

	return mButtonArray[0];
}