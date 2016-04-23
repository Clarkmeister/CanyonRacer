/***********************************************************
* Author:					Arthur Clark
* Date Created:				11/15/15
* Last Modification Date:	11/18/15
* Lab Number:				Lab 6
* Filename:					cTexture.cpp
************************************************************/
#include "cTexture.h"

cTexture::cTexture() : mBackground(nullptr), mTexture(nullptr), mWidth(0),
						mHeight(0)
{

}

cTexture::~cTexture()
{
	//Deallocate
	free();
}

cTexture::cTexture(const cTexture & rhs)
{
}

cTexture & cTexture::operator=(const cTexture & rhs)
{
	return *this;
}

bool cTexture::loadFromFile(std::string path, SDL_Renderer*& gRenderer)
{
	bool renderedSuccessfully = true;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == nullptr)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
		renderedSuccessfully = false;
	}
	else
	{
		//Color key image
		//SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));

		//Create texture from surface
		mBackground = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
		if (mBackground == nullptr)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
			renderedSuccessfully = false;

		}
		else
		{
			//Get image dimensions
			mWidth = loadedSurface->w;
			mHeight = loadedSurface->h;
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}


	return renderedSuccessfully;
}


void cTexture::free()
{
	//Free texture if it exists
	if (mTexture != nullptr)
	{
		SDL_DestroyTexture(mTexture);
		SDL_DestroyTexture(mBackground);
		mBackground = nullptr;
		mTexture = nullptr;
		mWidth = 0;
		mHeight = 0;
	}
}



void cTexture::render(int x, int y, SDL_Renderer*& gRenderer)
{

	SDL_Rect renderQuad = { x, y, mWidth, mHeight };

	SDL_RenderCopy(gRenderer, mBackground, nullptr, nullptr);
	SDL_RenderCopy(gRenderer, mTexture, nullptr, &renderQuad);
	//SDL_RenderPresent(gRenderer);
}

int cTexture::getWidth()
{
	return mWidth;
}

int cTexture::getHeight()
{
	if (mHeight == 0)
	{
		string error = ("Height == 0");
		throw error;
	}
	return mHeight;

}


