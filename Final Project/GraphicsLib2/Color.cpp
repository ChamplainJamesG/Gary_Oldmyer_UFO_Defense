#include "Color.h"

Color::Color()
{
	mRed = 0;
	mGreen = 0;
	mBlue = 0;

	//mColor = al_map_rgb(mRed, mGreen, mBlue);
}

Color::Color(int red, int green, int blue)
{
	mRed = red;
	mGreen = green;
	mBlue = blue;

	//mColor = al_map_rgb(mRed, mGreen, mBlue);
}

Color::~Color()
{
	//?
}

/*
ALLEGRO_COLOR Color::getColor()
{
return mColor;
}
*/

int Color::getRed()
{
	return mRed;
}

int Color::getGreen()
{
	return mGreen;
}

int Color::getBlue()
{
	return mBlue;
}