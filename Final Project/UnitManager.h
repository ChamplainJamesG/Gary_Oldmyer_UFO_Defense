#include "Trackable.h"
#include <vector>
#include "Unit.h"
#pragma once
#ifndef UNIT_MANAGER_H
#define UNIT_MANAGER_H

class UnitManager : public Trackable
{
public:
	UnitManager();
	~UnitManager();

	void addUnit(Unit unit);

	void deleteUnit(int loc);

	Unit& getUnit(int loc);

	void setAnim();
	void setDoAnim();
	bool checkAllFrozen();

	int getSize() { return mUnitList.size(); }

	void clear();

	void update(float dt);
	void draw(GraphicsBuffer& targetBuffer, bool anim);
private:
	std::vector<Unit> mUnitList;
};

#endif // !UNIT_MANAGER_H
