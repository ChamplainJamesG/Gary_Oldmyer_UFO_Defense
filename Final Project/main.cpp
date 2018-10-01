/*
Jimmy Griffiths & Zach Phillips
EGP - 310-02
Final Project
*/
#include <iostream>
#include <cassert>
#include <string>

#include <PerformanceTracker.h>
#include <MemoryTracker.h>

#include "GraphicsLib.h"
#include "GraphicsSystem.h"
#include "GraphicsBuffer.h"
//#include "GraphicsLib\Color.h"

#include <random>
#include <ctime>
//#include <Game.h>
#include "Game.h"

#include "EventSystem.h"

using namespace std;

int main(int argc, char *args[])
{
	ifstream in;
	ifstream introFile;
	in.open("INIT.init");
	Game game = Game(EventSystem::getInstance());
	int width, height;
	in >> width;
	in >> height;
	
	game.init((float)width, (float)height, in);
	game.doLoop();

	game.cleanup();
	gMemoryTracker.reportAllocations(std::cout);
	system("pause");

	return 0;

}