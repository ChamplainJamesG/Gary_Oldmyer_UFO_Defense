#pragma once
#ifndef EVENT_LISTENER_H
#define EVENT_LISTENER_H

#include <Trackable.h>

class Event;
class EventSystem;

class EventListener :public Trackable
{
public:
	EventListener(EventSystem* pEventSystem);
	virtual ~EventListener();

	virtual void handleEvent(const Event& theEvent) = 0;

private:
	EventSystem * mpEventSystem;//the event system this lister is listening to
protected:
	EventSystem * getEventSystem() const { return mpEventSystem; };
};

#endif // !EVENT_LISTENER_H
