//#include <allegro5\allegro.h>
//#include <allegro5\allegro_ttf.h>
//#include <allegro5\allegro_font.h>
#include <SDL.h>
#include <SDL_ttf.h>
#include <Trackable.h>
#pragma once
#ifndef FONT_H
#define FONT_H

class Font : public Trackable
{
private:
	friend class GraphicsSystem;
	//ALLEGRO_FONT * mFont;
	TTF_Font * mFont;
	int mSize;
	std::string mFileName;

	TTF_Font* getFont() { return mFont; };

public:
	Font();
	Font(std::string fileName, int size);
	~Font();

	std::string getFile();
	int getSize();

};

#endif
