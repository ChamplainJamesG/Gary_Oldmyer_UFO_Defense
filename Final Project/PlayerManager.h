#include "Trackable.h"
#include "Player.h"
#include <vector>
#include "EventListener.h"
#pragma once
#ifndef PLAYER_MANAGER_H
#define PLAYER_MANAGER_H

class Level;

class PlayerManager : public Trackable
{
public:
	PlayerManager();
	PlayerManager(float maxTIme);
	PlayerManager(float maxTime, Sprite shot);

	void addPlayer(Player player);

	Player& getPlayer(int index) { return mPlayerList[index]; };
	int getNumPlayer() { return mPlayerList.size(); };
	float getMaxTime() { return mMaxTime; };

	void setMaxTime(float time) { mMaxTime = time; };

	void update(float dt, Level level);

	bool getDead() { return mDead; };

	void resetPlayer();

	void removeOnePlayer();

	void draw();

	static PlayerManager* getInstance() { return mpInstance; };
	static void initInstance() { mpInstance = new PlayerManager; };
	static void cleanupInstance() { delete mpInstance; mpInstance = NULL; };
private:
	std::vector<Player> mPlayerList;
	float mCurTime, mMaxTime;
	bool mDead = false;
	static PlayerManager *mpInstance;
	Sprite mPlayerShot;
};

#endif // !PLAYER_MANAGER_H
