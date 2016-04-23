/***********************************************************
* Author:					Arthur Clark
* Date Created:				11/15/15
* Last Modification Date:	11/18/15
* Lab Number:				Lab 6
* Filename:					cSprite.h
************************************************************/
#ifndef SPRITE_H
#define SPRITE_H

#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
using std::string;
/****************************************************************
* Class: cSprite
*	Description:
*		Sprite Wrapper Class For Easy Sprite Sheet Creation
* Constructors:
*		cSprite();
*		cSprite(const  cSprite& rhs);
* Destructors:
*		~cSprite();
* Methods:
*		//Overload Assignment Operator Method
*		cSprite & operator=(const cSprite & rhs);
*		//Loads image at specified path
*		bool loadFromFile(std::string path, SDL_Renderer * gRenderer);
*		//Deallocates texture
*		void free();
*		//Renders texture at given point
*		void render(int x, int y, SDL_Renderer * gRenderer,
*										SDL_Rect* clip = nullptr);
*****************************************************************/
class cSprite
{
public:
	//Initializes variables
	cSprite();
	//Deallocates memory
	~cSprite();
	//Copy Constructor
	cSprite(const  cSprite& rhs);
	//Overload Assignment Operator Method
	cSprite & operator=(const cSprite & rhs);
	//Loads image at specified path
	bool loadFromFile(std::string path, SDL_Renderer * gRenderer);
	//Deallocates texture
	void free();
	//Renders texture at given point
	void render(int x, int y, SDL_Renderer * gRenderer, 
									SDL_Rect* clip = nullptr);

	//Gets image dimensions
	int getWidth();
	int getHeight();
private:
	//The actual hardware texture
	SDL_Texture* mTexture;
	//Image dimensions
	int mWidth;
	int mHeight;
};

#endif // !SPRITES_H
