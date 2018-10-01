#include "Trackable.h"
//#include "allegro5\allegro.h"
#include "Event.h"
#include "Vector2D.h"
#include <SDL.h>

#pragma once
#ifndef INPUT_SYSTEM_H
#define INPUT_SYSTEM_H

class InputSystem : public Trackable
{
public:
	InputSystem();
	~InputSystem();

	void init();
	void cleanup();

	void update();

	Vector2D getMousePosition();

private:
	//allegro stuff??
	bool isInit = false;
//	ALLEGRO_EVENT mEvent;
//	ALLEGRO_EVENT_QUEUE *mEventQueue;
//	ALLEGRO_TIMER *timer;
	SDL_Event mEvent;
	bool mM1, mM2;

	//placeholder (hopefully)
	int xPos = 0;
	int yPos = 0;
};

#endif // !INPUT_SYSTEM_H

/*
while(al_get_next_event(queue, event))


*/