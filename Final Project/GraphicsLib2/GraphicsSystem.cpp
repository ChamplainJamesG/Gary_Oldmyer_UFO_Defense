#include "GraphicsSystem.h"
//#include <allegro5\allegro_primitives.h>
#include <Timer.h>
#include <SDL_ttf.h>
#include <string>

//sf::RenderWindow* GraphicsSystem::mWindow = NULL;
SDL_Renderer *GraphicsSystem::mRenderer = NULL;

GraphicsSystem::GraphicsSystem()
{
//	mDisplay = NULL;
	mIsInit = false;
}

GraphicsSystem::GraphicsSystem(int width, int height)
{
	//mDisplay = al_create_display(width, height);
	//assert(mDisplay);
//	mDisplay = NULL;
	mIsInit = false;
}

GraphicsSystem::~GraphicsSystem()
{
	if(mIsInit)
//		al_destroy_display(mDisplay);

	mIsInit = false;
}

void GraphicsSystem::initGraphicsSystem(int width, int height)
{
	if (!mIsInit)
	{
		SDL_Init(SDL_INIT_EVERYTHING);
//		al_init_font_addon();
//		al_init_ttf_addon();
//		al_init_primitives_addon();
//		al_init_image_addon();
		//mDisplay = al_create_display(width, height);
		//GraphicsSystem::mWindow = new sf::RenderWindow(sf::VideoMode(width, height), "Gary Oldmyer");
		mDisplay = SDL_CreateWindow("Gary Oldmyer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_OPENGL);
		mRenderer = SDL_CreateRenderer(mDisplay, -1, 0);
//		assert(mDisplay);
		mIsInit = true;
	}

}

void GraphicsSystem::cleanupGraphicsSystem()
{
	if(mIsInit)
//		al_destroy_display(mDisplay);

	mIsInit = false;
}

/*
int GraphicsSystem::getWidth()
{
	//	return al_get_display_width(mDisplay);
	//return mWindow->getSize().x;
	SDL_DisplayMode DM;
	SDL_GetCurrentDisplayMode(0, &DM);
	return DM.w;
}
*/

int const GraphicsSystem::getWidth()
{
//	return al_get_display_width(mDisplay);
	//return mWindow->getSize().x;
	//SDL_DisplayMode DM;
	//SDL_GetCurrentDisplayMode(0, &DM);
	return SDL_GetWindowSurface(mDisplay)->w;
	//return DM.w;
}

int GraphicsSystem::getHeight()
{
//	return al_get_display_height(mDisplay);
	SDL_DisplayMode DM;
	SDL_GetCurrentDisplayMode(0, &DM);
	return DM.h;
}

void GraphicsSystem::flip()
{
	SDL_RenderPresent(mRenderer);
	//al_flip_display();
	//Timer* pTimer = new Timer;
	//pTimer->start();
	//pTimer->sleepUntilElapsed(5*1000.0);
	//delete pTimer;
}

void GraphicsSystem::draw(Vector2D targetLoc, Sprite sprite, float scale)
{
	//assert sets a target bitmap
	//set target bitmap is a function. Cache current bitmap to get back to old bitmap
	//make sure targetbuffer is reference to avoid destructor shenanigans. 
	/*al_draw_scaled_bitmap(sprite.getGraphicsBuffer()->getBitmap(), sprite.getSourceLoc().getX(), sprite.getSourceLoc().getY(),
		sprite.getWidth(), sprite.getHeight(), targetLoc.getX(), targetLoc.getY(), sprite.getWidth() * scale, sprite.getHeight() * scale, 0);*/

	SDL_Rect source;
	source.x = (int)sprite.getSourceLoc().getX();
	source.y = (int)sprite.getSourceLoc().getY();
	source.w = (int)sprite.getWidth();
	source.h = (int)sprite.getHeight();

	SDL_Rect dst;
	dst.x = (int)targetLoc.getX();
	dst.y = (int)targetLoc.getY();
	dst.w = (int)sprite.getWidth() * scale;
	dst.h = (int)sprite.getHeight() * scale;

	sprite.getGraphicsBuffer()->makeTex(mRenderer);

	//SDL_BlitSurface(sprite.getGraphicsBuffer()->getBitmap(), &source, mDisplay, &dst);
	//SDL_RenderCopy(mRenderer, )
	SDL_RenderCopy(mRenderer, sprite.getGraphicsBuffer()->getBitmap(), &source, &dst);
}

void GraphicsSystem::draw(GraphicsBuffer &targetBuffer, Vector2D targetLoc, Sprite sprite, float scale)
{
	//How to draw to specific buffer?
	/*
	ALLEGRO_BITMAP* cacheBitmap = targetBuffer.getBitmap();
	assert(targetBuffer.getBitmap());
	//al_set_target_bitmap(targetBuffer.getBitmap());
	al_draw_scaled_bitmap(sprite.getGraphicsBuffer()->getBitmap(), sprite.getSourceLoc().getX(), sprite.getSourceLoc().getY(),
		sprite.getWidth(), sprite.getHeight(), targetLoc.getX(), targetLoc.getY(), sprite.getWidth() * scale, sprite.getHeight() * scale, 0);*/
	
	//mWindow->draw(sprite.getGraphicsBuffer()->getBitmap());
	SDL_Rect source;
	source.x = (int)sprite.getSourceLoc().getX();
	source.y = (int)sprite.getSourceLoc().getY();
	source.w = (int)sprite.getWidth();
	source.h = (int)sprite.getHeight();

	SDL_Rect dst;
	dst.x = (int)targetLoc.getX();
	dst.y = (int)targetLoc.getY();
	dst.w = (int)sprite.getWidth() * scale;
	dst.h = (int)sprite.getHeight() * scale;

	sprite.getGraphicsBuffer()->makeTex(mRenderer);

	//SDL_BlitSurface(sprite.getGraphicsBuffer()->getBitmap(), &source, mDisplay, &dst);
	//SDL_RenderCopy(mRenderer, )
	SDL_RenderCopy(mRenderer, sprite.getGraphicsBuffer()->getBitmap(), &source, &dst);

	//assert(cacheBitmap);
	//al_set_target_bitmap(cacheBitmap);

}

void GraphicsSystem::drawAColor(GraphicsBuffer &targetBuffer, Color color)
{
	//ALLEGRO_BITMAP* cacheBitmap = targetBuffer.getBitmap();
	//assert(targetBuffer.getBitmap());

	//ALLEGRO_COLOR aColor = al_map_rgb(color.getRed(), color.getGreen(), color.getBlue());

	//al_clear_to_color(aColor);

}

void GraphicsSystem::writeText(const Vector2D& targetLoc, Font& font, Color color, const std::string& text)
{
	SDL_Color aColor;
	aColor.r = color.getRed();
	aColor.g = color.getGreen();
	aColor.b = color.getBlue();

	SDL_Surface message;

	//TTF_Font* myFont = TTF_OpenFont("cour.ttf", 24);

	//text2 = "text2";

	message = *TTF_RenderText_Solid(font.getFont(), text.c_str(), aColor);

	SDL_Rect source;
	source.x = 0;
	source.y = 0;
	source.w = message.w;
	source.h = message.h;

	SDL_Rect dst;
	dst.x = (int)targetLoc.getX();
	dst.y = (int)targetLoc.getY();
	dst.w = (int)message.w;
	dst.h = (int)message.h;

	SDL_BlitSurface(&message, &source, NULL, &dst);
	
	SDL_Texture* tex = SDL_CreateTextureFromSurface(mRenderer, &message);


	SDL_RenderCopy(mRenderer, tex, &source, &dst);
	/*
	ALLEGRO_COLOR aColor = al_map_rgb(color.getRed(), color.getGreen(), color.getBlue());
	ALLEGRO_FONT *aFont = al_load_ttf_font(font.getFont().c_str(), font.getSize(), 0);
	//al_draw_text(cour_font, WHITE, LOC1_X, LOC1_Y, ALLEGRO_ALIGN_CENTER, "Welcome to Allegro!");
	al_draw_text(aFont, aColor, targetLoc.getX(), targetLoc.getY(), 0, text.c_str());
	al_destroy_font(aFont);
	*/
	SDL_DestroyTexture(tex);
}

void GraphicsSystem::writeText(GraphicsBuffer &targetBuffer, Vector2D targetLoc, Font& font, Color color, std::string text)
{


	/*
	//same as 2nd Draw
	ALLEGRO_COLOR aColor = al_map_rgb(color.getRed(), color.getGreen(), color.getBlue());
	ALLEGRO_BITMAP* cacheBitmap = targetBuffer.getBitmap();
	ALLEGRO_FONT *aFont = al_load_ttf_font(font.getFont().c_str(), font.getSize(), 0);

	al_set_target_bitmap(targetBuffer.getBitmap());

	al_draw_text(aFont, aColor, targetLoc.getX(), targetLoc.getY(), 0, text.c_str());

	al_destroy_font(aFont);

	al_set_target_bitmap(cacheBitmap);
	*/

	//assert(cacheBitmap);
}

void GraphicsSystem::saveBuffer(GraphicsBuffer &saveBuffer, std::string fileName)
{
//	al_save_bitmap(fileName.c_str(), al_get_backbuffer(mDisplay));
}