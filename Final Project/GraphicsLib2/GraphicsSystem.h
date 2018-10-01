#pragma once
#ifndef GRAPHICS_SYSTEM_H
#define GRAPHICS_SYSTEM_H

//#include <allegro5/allegro.h>
//#include <SFML\Graphics.hpp>
#include <SDL.h>
#include "Trackable.h"
#include "Sprite.h"
#include "Font.h"
#include "Color.h"
#include <string>

class GraphicsSystem : public Trackable
{
private:
//	ALLEGRO_DISPLAY* mDisplay;
//	static sf::RenderWindow* mWindow;
	SDL_Window * mDisplay;
	static SDL_Renderer *mRenderer;
	bool mIsInit;

	//TTF_Font* myFont = TTF_OpenFont("cour.ttf", 24);

public:
	GraphicsSystem();
	GraphicsSystem(int width, int height);
	
	~GraphicsSystem();

	void initGraphicsSystem(int width, int height);
	void cleanupGraphicsSystem();

	//int getWidth();
	int const getWidth();
	int getWidthNC() {	SDL_DisplayMode DM;
	SDL_GetCurrentDisplayMode(0, &DM);
	return DM.w;
	};
	int getHeight();

	void flip();

	static void draw(Vector2D targetLoc, Sprite sprite, float scale = 1.0);
	static void draw(GraphicsBuffer &targetBuffer, Vector2D targetLoc, Sprite sprite, float scale = 1.0);
	static void drawAColor(GraphicsBuffer &targetBuffer, Color color);
	static void writeText(const Vector2D& targetLoc, Font& font, Color color, const std::string& text);
	static void writeText(GraphicsBuffer &targetBuffer, Vector2D targetLoc, Font &font, Color color, std::string text);
	void saveBuffer(GraphicsBuffer &saveBuffer, std::string fileName);
};

#endif // !GRAPHICS_SYSTEM_H
