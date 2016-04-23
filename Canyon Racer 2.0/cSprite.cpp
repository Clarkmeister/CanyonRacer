/***********************************************************
* Author:					Arthur Clark
* Date Created:				11/15/15
* Last Modification Date:	11/18/15
* Lab Number:				Lab 6
* Filename:					cSprite.cpp
************************************************************/
#include "cSprite.h"

cSprite::cSprite() : mTexture(nullptr), mWidth(0), mHeight(0)
{
}

cSprite::~cSprite()
{
	//Deallocate
	free();
}

cSprite::cSprite(const cSprite & rhs)
{
	mTexture = rhs.mTexture;
	mWidth = rhs.mWidth;
	mHeight = rhs.mHeight;
}

cSprite & cSprite::operator=(const cSprite & rhs)
{
	mTexture = rhs.mTexture;
	mWidth = rhs.mWidth;
	mHeight = rhs.mHeight;
	return *this;
}

bool cSprite::loadFromFile(std::string path, SDL_Renderer * gRenderer)
{
	//Get rid of preexisting texture
	free();

	//The final texture
	SDL_Texture* newTexture = nullptr;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == nullptr)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		//Color key image
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));

		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
		if (newTexture == nullptr)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}
		else
		{
			//Get image dimensions
			mWidth = loadedSurface->w;
			mHeight = loadedSurface->h;
		}

		//Get rid of old loaded surface
		//SDL_FreeSurface(loadedSurface);
	}

	//Return success
	mTexture = newTexture;
	return mTexture != nullptr;
}

void cSprite::free()
{
	//Free texture if it exists
	if (mTexture != nullptr)
	{
		SDL_DestroyTexture(mTexture);
		mTexture = nullptr;
		mWidth = 0;
		mHeight = 0;
	}
}

void cSprite::render(int x, int y, SDL_Renderer * gRenderer, SDL_Rect* clip)
{
	//Set rendering space and render to screen
	SDL_Rect renderQuad = { x, y, mWidth, mHeight };

	//Set clip rendering dimensions
	if (clip != nullptr)
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	//Render to screen
	SDL_RenderCopy(gRenderer, mTexture, clip, &renderQuad);
}

int cSprite::getWidth()
{
	return mWidth;
}

int cSprite::getHeight()
{
	return mHeight;
}
