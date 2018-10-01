//#include <allegro5\allegro.h>
//#include <allegro5\color.h>
//#include <SFML\Graphics.hpp>

#pragma once
#ifndef COLOR_H	
#define COLOR_H

class Color
{
private:
	int mRed, mBlue, mGreen;
//	ALLEGRO_COLOR mColor;

public:
	Color();
	Color(int red, int green, int blue);
	~Color();
	int getRed();
	int getGreen();
	int getBlue();

	//ALLEGRO_COLOR getColor();
};


#endif