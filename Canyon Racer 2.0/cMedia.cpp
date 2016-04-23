/***********************************************************
* Author:					Arthur Clark
* Date Created:				11/15/15
* Last Modification Date:	11/18/15
* Lab Number:				Lab 6
* Filename:					cMedia.cpp
************************************************************/
#include "cMedia.h"

const int THROW_EXCEPTION = 1;

cMedia::cMedia()
{
	//No Data Members
}

cMedia::~cMedia()
{
	//No Data Members
}

cMedia::cMedia(const cMedia & rhs)
{
	//No Data Members
}

cMedia & cMedia::operator=(const cMedia & rhs)
{
	//No Data Members
	return *this;
}

bool cMedia::loadMedia(SDL_Renderer*& m_Renderer, SDL_Texture*& gTexture,
	cMusic & Music, cTexture & Background, 	//Scene sprites
	SDL_Rect * gSpriteClips, cSprite & gSpriteSheetTexture, cSprite &vehicle)
{
	//Loading success flag
	bool success = true;

	//Load music 
	Music.GetMusic() = Mix_LoadMUS("rambleon.wav");
	if (Music.GetMusic() == nullptr)
	{
		printf("Failed to load beat music! SDL_mixer Error: %s\n",
			Mix_GetError());
		success = false;
	}

	//Load sound effects 
	Music.GetCrash() = Mix_LoadWAV("crash.wav");
	if (Music.GetCrash() == nullptr)
	{
		printf("Failed to load scratch sound effect! SDL_mixer Error: %s\n",
			Mix_GetError());
		success = false;
	}

	//Load sound effects 
	Music.GetCruising() = Mix_LoadWAV("cruising.wav");
	if (Music.GetCruising() == nullptr)
	{
		printf("Failed to load scratch sound effect! SDL_mixer Error: %s\n",
			Mix_GetError());
		success = false;
	}
	//Load background texture
	try
	{
		Background.loadFromFile("desert.png", m_Renderer);
		Background.getHeight();
	}
	catch (string e)
	{
		std::cout << e << std::endl;
		success = false;
	}
	//Load sprite sheet texture
	if (!gSpriteSheetTexture.loadFromFile("sprite1.png", m_Renderer))
	{
		printf("Failed to load sprite sheet texture!\n");
		success = false;
	}
	else
	{
		//Set top left sprite
		gSpriteClips[0].x = 0;
		gSpriteClips[0].y = 0;
		gSpriteClips[0].w = 75;
		gSpriteClips[0].h = 75;

		//Set top right sprite
		gSpriteClips[1].x = 75;
		gSpriteClips[1].y = 0;
		gSpriteClips[1].w = 75;
		gSpriteClips[1].h = 75;

		//Set bottom left sprite
		gSpriteClips[2].x = 0;
		gSpriteClips[2].y = 75;
		gSpriteClips[2].w = 75;
		gSpriteClips[2].h = 75;

		//Set bottom right sprite
		gSpriteClips[3].x = 75;
		gSpriteClips[3].y = 75;
		gSpriteClips[3].w = 75;
		gSpriteClips[3].h = 75;
	}
	if (!vehicle.loadFromFile("lambo1.png", m_Renderer))
	{
		printf("Failed to load sprite sheet texture!\n");
		success = false;
	}
	return success;
}

SDL_Texture * cMedia::loadTexture(std::string path,
	SDL_Renderer*& gRenderer)
{
	//The final texture 
	SDL_Texture* newTexture = nullptr;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == nullptr)
	{
		printf("Unable to load image %s! SDL Error: %s\n",
			path.c_str(), SDL_GetError());
	}
	else
	{
		//Create texture from surface pixels 
		newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
		if (newTexture == nullptr)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n",
				path.c_str(), SDL_GetError());
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	return newTexture;
}
