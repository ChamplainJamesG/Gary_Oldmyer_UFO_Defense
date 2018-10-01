#include "Font.h"

Font::Font()
{
	mFileName = "";
	//assert(mFont);
	mSize = 0;
}

Font::Font(std::string fileName, int size)
{
	TTF_Init();
//	al_init_font_addon();
//	al_init_ttf_addon();
	//mFont = al_load_ttf_font(fileName.c_str(), size, 0);
	mFont = TTF_OpenFont(fileName.c_str(), size);
	mFileName = fileName;
	mSize = size;
	//assert(mFont);
}

Font::~Font()
{
	//al_destroy_font(mFont);
}

std::string Font::getFile()
{
	return mFileName;
}

int Font::getSize()
{
	return mSize;
}

