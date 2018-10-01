#include "InputTranslator.h"
#include "Event.h"
#include "EventSystem.h"

InputTranslator::InputTranslator(EventSystem *pSystem)
	:EventListener(pSystem)
{

}

InputTranslator::~InputTranslator()
{

}

void InputTranslator::init()
{

}

void InputTranslator::cleanup()
{

}

void InputTranslator::handleEvent(const Event &theEvent)
{
	if (theEvent.getType() == AL_ADD_EVENT)
	{
		EventSystem::getInstance()->fireEvent(ADD_EVENT);
	}

	else if (theEvent.getType() == AL_DELETE_EVENT)
	{
		EventSystem::getInstance()->fireEvent(DELETE_EVENT);
	}

	else if (theEvent.getType() == AL_FREEZE_EVENT)
	{
		EventSystem::getInstance()->fireEvent(FREEZE_EVENT);
	}

	else if (theEvent.getType() == AL_CHANGE_EVENT)
	{
		EventSystem::getInstance()->fireEvent(CHANGE_EVENT);
	}

	else if (theEvent.getType() == AL_QUIT_EVENT)
	{
		EventSystem::getInstance()->fireEvent(QUIT_EVENT);
	}


}