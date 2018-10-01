//#include <allegro5\allegro.h>
//#include <allegro5\allegro_image.h>
#include "Trackable.h"
#include <string>
#include "Color.h"
//#include <SFML\Graphics.hpp>
#include <SDL.h>

#pragma once
#ifndef GRAPHICS_BUFFER_H
#define GRAPHICS_BUFFER_H

class GraphicsBuffer : public Trackable
{
	friend class GraphicsSystem;
	//or friend void GraphicsSystem::Draw(...);
private:
	SDL_Texture* mBitmap = NULL;
	SDL_Surface* mSurface = NULL;
	SDL_Texture* getBitmap();

	void makeTex(SDL_Renderer* rend){
		//THIS IS DESTROYING MEMORY

		//returning a new pointer, and I'm losing the old pointer?
		//nevermind fixed
		SDL_DestroyTexture(mBitmap);
		mBitmap = SDL_CreateTextureFromSurface(rend, mSurface);
	};

public:
	GraphicsBuffer();
	GraphicsBuffer(std::string fileName);
	~GraphicsBuffer();
	int getWidth();
	int getHeight();

	void setColor(Color color);
};
#endif // !GRAPHICS_BUFFER_H
