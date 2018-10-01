//Zach Phillips
//Controls the cinematics of the game
#pragma once
#include "Trackable.h"
#include <string>

#include "GraphicsBuffer.h"

class CinematicManager : public Trackable
{
	public:
		CinematicManager();
		~CinematicManager();

		void addCinematics(std::string filename, int index);
		
		GraphicsBuffer getCinematicBuffer(std::string name, int index);

		bool isInCinematic();

	private:
		bool inCinematic;

		GraphicsBuffer introCinematic[28];

		//need to start at 2 for the intro cinematic
		int mIndex = 0;
};