#pragma once
#include <map>
#include "Trackable.h"

class Event;
class EventListener;
enum EventType;

using namespace std;

#ifndef EVENT_SYSTEM_H
#define EVENT_SYSTEM_H
class EventSystem :public Trackable
{
public:
	EventSystem();
	~EventSystem();

	void fireEvent(const Event& theEvent);
	void addListener(EventType type, EventListener* pListener);
	void removeListener(EventType type, EventListener* pListener);
	void removeListenerFromAllEvents(EventListener* pListener);

	static EventSystem* getInstance() { return mpInstance; };
	static void initInstance() { mpInstance = new EventSystem; };
	static void cleanupInstance() { delete mpInstance; mpInstance = NULL;  };

private:
	//static EventSystem* msInstance;
	multimap< EventType, EventListener* > mListenerMap;

	static EventSystem *mpInstance;

	void dispatchAllEvents(const Event& theEvent);

};



#endif // !EVENT_SYSTEM_H
