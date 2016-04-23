/***********************************************************
* Author:					Arthur Clark
* Date Created:				11/15/15
* Last Modification Date:	11/18/15
* Lab Number:				Lab 6
* Filename:					cMedia.h
************************************************************/
#ifndef MEDIA_H
#define MEDIA_H

#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include "cMusic.h"
#include "cTexture.h"
#include "cSprite.h"
using std::string;
/****************************************************************
* Class: cMedia
*	Description:
*		This Class is used for Handling ALL media loaded in to the 
*		game.
* Constructors:
*		cMedia();
*		cMedia(const  cMedia& rhs);
* Destructors:
*		~cMedia();
* Methods:
*		//Overload Assignment Operator Method
*		cMedia & operator=(const cMedia & rhs);
*		//Load All Media
*		bool cMedia::loadMedia(SDL_Renderer*& m_Renderer, 
*					SDL_Texture*& gTexture,	cMusic & Music, 
*					cTexture & Background, SDL_Rect * gSpriteClips, 
*					cSprite &gSpriteSheetTexture, cSprite &vehicle);
*		//Load media to surface.
*		SDL_Texture * cMedia::loadTexture(std::string path,
*											SDL_Renderer*& m_Renderer);
*****************************************************************/
class cMedia
{
public:
	//Constructor
	cMedia();
	//Destructor
	~cMedia();
	//Copy Constructor
	cMedia(const  cMedia& rhs);
	//Overload Assignment Operator Method
	cMedia & operator=(const cMedia & rhs);
	//Load Media
	bool cMedia::loadMedia(SDL_Renderer*& m_Renderer, SDL_Texture*& gTexture,
					cMusic & Music, cTexture & Background,
					SDL_Rect * gSpriteClips, cSprite &gSpriteSheetTexture,
					cSprite &vehicle);
	//Load media to surface.
	SDL_Texture * cMedia::loadTexture(std::string path,
											SDL_Renderer*& m_Renderer);
private:
};

#endif // !WINDOW_H
