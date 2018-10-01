#include "EventListener.h"
#include "EventSystem.h"

EventListener::EventListener(EventSystem* pEventSystem)
	:mpEventSystem(pEventSystem)
{
}

EventListener::~EventListener()
{
	if(EventSystem::getInstance() != NULL)
		mpEventSystem->removeListenerFromAllEvents(this);
}