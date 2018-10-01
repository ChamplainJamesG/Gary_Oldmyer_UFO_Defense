#pragma once
#ifndef ENEMY_MANAGER_H
#define ENEMY_MANAGER_H
#include "Enemy.h"
#include "Trackable.h"
#include "Player.h"
#include <vector>
#include <fstream>

const class GraphicsSystem;
class System;

class EnemyManager : public Trackable
{
public:
	EnemyManager();

	void addEnemy(Enemy enemy);

	void draw();

	void update(double dT, GraphicsSystem& system);
	void setMaxTime(float maxTime) { mMaxTime = maxTime; };

	void checkCollision(Player& player);
	bool checkCollisionB(Player& player);

	bool checkEnemyDistance(System& system);

	bool checkEnemiesDead();

	void moveEnemiesToStart();

	void clearList();

	friend std::ofstream& operator<<(std::ofstream& out, EnemyManager manager);
	friend std::ifstream& operator>>(std::ifstream& in, EnemyManager manager);

private:
	std::vector<Enemy> mEnemyList;
	float mTime, mMaxTime;
	bool mMoveRight;
	bool doneMove = false;
	int timesMoved = 10;

};


#endif // !ENEMY_MANAGER_H
