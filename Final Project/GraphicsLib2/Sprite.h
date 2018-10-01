#include "GraphicsBuffer.h"
#include "Trackable.h"
#include "Vector2D.h"
#pragma once
#ifndef SPRITE_H
#define SPRITE_H

class Sprite : public Trackable
{
	friend class GraphicsSystem;
private:
	GraphicsBuffer* mGraphicsBuffer;
	Vector2D mSourceLoc;
	int mWidth, mHeight;
	GraphicsBuffer* getGraphicsBuffer(); //GET RID OF THIS

public:
	Sprite();
	Sprite(GraphicsBuffer& graphicsBuffer, float sourceX, float sourceY);
	Sprite(GraphicsBuffer& graphicsBuffer, Vector2D sourceLoc, int width, int height);
	~Sprite();

	Vector2D getSourceLoc();
	int getWidth();
	int getHeight();

	void setSourceLoc(Vector2D sourceLoc);
	void setWidth(int width);
	void setHeight(int height);

};

#endif // !SPRITE_H
