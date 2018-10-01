#include "GraphicsBufferManager.h"

GraphicsBufferManager::GraphicsBufferManager()
{

}

GraphicsBufferManager::~GraphicsBufferManager()
{
	mGraphicsDict.clear();
}

void GraphicsBufferManager::addGraphicsBuffer(std::string name, GraphicsBuffer *graphicsBuffer)
{
	//mGraphicsDict[name] = graphicsBuffer;
	mGraphicsDict.insert(std::pair<std::string, GraphicsBuffer*>(name, graphicsBuffer));
}

void GraphicsBufferManager::removeGraphicsBuffer(std::string name)
{
	mGraphicsDict.erase(name);
}

GraphicsBuffer* GraphicsBufferManager::getGraphicsBuffer(std::string name)
{
	return mGraphicsDict[name];
}

void GraphicsBufferManager::clear()
{
	std::map<std::string, GraphicsBuffer*>::iterator it;
	/*
	it = mGraphicsDict.begin();
	delete it->second;

	mGraphicsDict.erase(it);

	it = mGraphicsDict.begin();
	delete it->second;
	*/
	for (unsigned int i = 0; i < mGraphicsDict.size(); i++)
	{
		it = mGraphicsDict.begin();
		delete it->second;
		it->second = NULL;
		mGraphicsDict.erase(it);
	}
}