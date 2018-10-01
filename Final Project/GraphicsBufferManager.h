#include "Trackable.h"
#include "GraphicsBuffer.h"
#include <vector>
#include <map>
#pragma once
#ifndef GRAPHICS_BUFFER_MANAGER_H
#define GRAPHICS_BUFFER_MANAGER_H

class GraphicsBufferManager : public Trackable
{
public:
	GraphicsBufferManager();
	~GraphicsBufferManager();

	void addGraphicsBuffer(std::string name, GraphicsBuffer *graphicsBuffer);
	void removeGraphicsBuffer(std::string name);
	GraphicsBuffer* getGraphicsBuffer(std::string name);

	void clear();

private:
	//std::vector<GraphicsBuffer> mGraphicsBuffer;
	std::map<std::string, GraphicsBuffer*> mGraphicsDict;
};

//need to know specific buffers by name

#endif // !1

