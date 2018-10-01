#pragma once
#ifndef EVENT_H
#define EVENT_H

#include <string>
#include <trackable.h>

using namespace std;

enum EventType
{
	INVALID_EVENT_TYPE = -1,
	MOVE_EVENT,
	STRING_EVENT,
	AL_ADD_EVENT,
	ADD_EVENT,
	AL_DELETE_EVENT,
	DELETE_EVENT,
	AL_FREEZE_EVENT,
	FREEZE_EVENT,
	AL_CHANGE_EVENT,
	CHANGE_EVENT,
	AL_QUIT_EVENT,
	QUIT_EVENT,

	MOVE_UP,
	MOVE_LEFT,
	MOVE_DOWN,
	MOVE_RIGHT,

	FOOD_PU,
	POINT_PU,
	SHRINK_PU,

	TEST_MAKE_PLAYER,

	START_LEVEL,
	RESET,

	START_GAME,

	PLAYER_SHOOT,

	HURT_PLAYER,

	EXIT,

	LEFT_CLICK,

	NUM_EVENT_TYPES
};

const string EVENT_NAMES[NUM_EVENT_TYPES] = { "Move Event",
"String Event"
};

class Event :public Trackable
{
public:
	Event(EventType type);
	virtual ~Event();

	EventType getType() const { return mType; };
	const string& getEventName() const;

private:
	EventType mType;

};

#endif // !EVENT_H
