#include "Trackable.h"
#include <vector>
#include "Level.h"
#pragma once
#ifndef LEVEL_MANAGER_H
#define LEVEL_MANAGER_H

class LevelManager :public Trackable
{
public:
	Level getLevel(int i) { return mLevelList[i]; };
	void addLevel(Level level) { mLevelList.push_back(level); };

	void update(float dt);
private:
	std::vector<Level> mLevelList;
};

#endif // !LEVEL_MANAGER_H
