#include "GraphicsSystem.h"
#include "MemoryTracker.h"
#include "InputSystem.h"
//#include <SFML\Graphics.hpp>
#pragma once
#ifndef SYSTEM_H
#define SYSTEM_H

const enum KEYS{S = 1, F, ENTER, ESC, SPACE, INVALID_KEY};
//add an invalid key, and return that on an else for get key state

class System : public Trackable
{
public:
	System();
	System(GraphicsSystem *graphicsSystem);
	~System();

	void init(float width, float height0);
	void cleanup();

	KEYS getKeyState();
	void getMouseState(Vector2D origLoc, bool &leftClick, bool &rightClick);
	Vector2D getMouseLoc();
	Font& getFont() { return mFont; };
	//make mouse posiiton a vector2D

	GraphicsSystem getSystem() { return *mGraphicsSystem; };
	InputSystem getInputSystem() { return *mInputSystem; };

	void update();

	void flip();

	void doHud(int fps, int score, std::string scoreText, std::string livesText, int livesLeft);

private:
	GraphicsSystem *mGraphicsSystem;
	InputSystem *mInputSystem;
	Font mFont;
};



#endif // !SYSTEM_H

/*
*DONT DO AN EVENT QUEUE FOR INPUT*
*/

/*
TODO:
initialize System with a graphics system of width, height
*/

//bool isKeyPressed(enum key)
//return the pressed key