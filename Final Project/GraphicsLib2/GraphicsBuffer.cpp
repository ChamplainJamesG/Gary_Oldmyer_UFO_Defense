#include "GraphicsBuffer.h"

GraphicsBuffer::GraphicsBuffer()
{
	//al_init_image_addon();
	//mBitmap = NULL;
	//assert(mBitmap);
}

GraphicsBuffer::GraphicsBuffer(std::string fileName)
{
	//al_init_image_addon();
	//mBitmap = al_load_bitmap(fileName.c_str());
	mBitmap = NULL;
	mSurface = SDL_LoadBMP(fileName.c_str());
	//assert(mBitmap);
	//mBitmap->loadFromFile(fileName);
	//sf::Texture text;
	//text.loadFromFile(fileName);
}

GraphicsBuffer::~GraphicsBuffer()
{
	//delete mBitmap;
	//al_destroy_bitmap(mBitmap);
	if(mBitmap != NULL)
	{
		//SDL_DestroyTexture(mSurface);
		//delete mBitmap;
		//delete mSurface;
	}
}

SDL_Texture* GraphicsBuffer::getBitmap()
{
	return mBitmap;
}

int GraphicsBuffer::getWidth()
{
	//return al_get_bitmap_width(mBitmap);
	//return mBitmap->getSize().x;
	//return mBitmap.getTextureRect().width;
	return mSurface->w;
}

int GraphicsBuffer::getHeight()
{
	//return al_get_bitmap_height(mBitmap);
	//return mBitmap->getSize().y;
	//return mBitmap.getTextureRect().height;
	return mSurface->h;
}

/*
void GraphicsBuffer::setColor(Color color)
{
al_clear_to_color(color.getColor());
}
*/
