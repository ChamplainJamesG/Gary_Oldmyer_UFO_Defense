#include "CinematicManager.h"

CinematicManager::CinematicManager()
{

}

CinematicManager::~CinematicManager()
{

}

void CinematicManager::addCinematics(std::string filename, int index)
{
	GraphicsBuffer testBuffer = GraphicsBuffer("Cinematics\\Intro\\" + filename);
	introCinematic[index] = testBuffer;
}

GraphicsBuffer CinematicManager::getCinematicBuffer(std::string name, int index)
{
	if (name == "Intro")
	{
		return introCinematic[index];
	}
	else
		return introCinematic[0];
}

bool CinematicManager::isInCinematic()
{
	return inCinematic;
}