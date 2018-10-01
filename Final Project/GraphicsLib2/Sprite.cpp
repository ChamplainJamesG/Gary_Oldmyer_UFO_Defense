#include "Sprite.h"

Sprite::Sprite()
{
	mWidth = 0;
	mHeight = 0;
	mSourceLoc = Vector2D(0, 0);
	mGraphicsBuffer = NULL;
}

Sprite::Sprite(GraphicsBuffer& graphicsBuffer, float sourceX, float sourceY)
{
	mGraphicsBuffer = &graphicsBuffer;
	mSourceLoc = Vector2D(sourceX, sourceY);
	mWidth = mGraphicsBuffer->getWidth();
	mHeight = mGraphicsBuffer->getHeight();
}

Sprite::Sprite(GraphicsBuffer& graphicsBuffer, Vector2D sourceLoc, int width, int height)
{
	mGraphicsBuffer = &graphicsBuffer;
	mSourceLoc = sourceLoc;
	mWidth = width;
	mHeight = height;
}

Sprite::~Sprite()
{
	//delete mGraphicsBuffer;
}

GraphicsBuffer* Sprite::getGraphicsBuffer()
{
	return mGraphicsBuffer;
}

Vector2D Sprite::getSourceLoc()
{
	return mSourceLoc;
}

int Sprite::getHeight()
{
	return mHeight;
}

int Sprite::getWidth()
{
	return mWidth;
}

void Sprite::setSourceLoc(Vector2D sourceLoc)
{
	mSourceLoc = sourceLoc;
}

void Sprite::setWidth(int width)
{
	mWidth = width;
}

void Sprite::setHeight(int height)
{
	mHeight = height;
}