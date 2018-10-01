#include "Trackable.h"
#include "EventListener.h"
#pragma once
#ifndef INPUT_TRANSLATOR_H
#define INPUT_TRANSLATOR_H

class InputTranslator : public EventListener
{
public:
	InputTranslator(EventSystem *pSystem);
	~InputTranslator();

	void init();
	void cleanup();

	void handleEvent(const Event &theEvent);
private:
};

#endif // !INPUT_TRANSLATOR_H

//allegro event queue?
//don't wait for inputs.
