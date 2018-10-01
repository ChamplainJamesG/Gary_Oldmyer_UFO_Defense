#include "Buttons.h"

Buttons::Buttons()
{
//nada
}

Buttons::Buttons(std::string buttonName, Sprite buttonUnlit, Sprite buttonLit, int xPos, int yPos)
{
	mButtonUnlit = buttonUnlit;
	mButtonLit = buttonLit;
	mXPos = xPos;
	mYPos = yPos;
	mName = buttonName;

	mActiveSprite = buttonUnlit;
	
	mSelected = false;
}

void Buttons::update(Vector2D mousePos)
{
	if (isDrawn)
	{
		if ((mousePos.getX() > mXPos && mousePos.getX() < mXPos + mActiveSprite.getWidth()) && (mousePos.getY() > mYPos && mousePos.getY() < mYPos + mActiveSprite.getHeight() / 2))
		{
			mActiveSprite = mButtonLit;
			mSelected = true;
		}

		else
		{
			mActiveSprite = mButtonUnlit;
			mSelected = false;
		}
	}

}

Vector2D Buttons::getLocation()
{
	Vector2D temp = Vector2D(mXPos, mYPos);
	return temp;
}