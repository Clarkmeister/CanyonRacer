/***********************************************************
* Author:					Arthur Clark
* Date Created:				11/15/15
* Last Modification Date:	11/18/15
* Lab Number:				Lab 6
* Filename:					cTexture.h
************************************************************/
#ifndef TEXTURE_H
#define TEXTURE_H

#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
using std::string;
/****************************************************************
* Class: cTexture
*	Description:
*		Texture Wrapper Class for Easy Texture Creation
* Constructors:
*		cTexture();
*		cTexture(const cTexture& rhs);
* Destructors:
*		~cTexture();
* Methods:
*		//Overload Assignment Operator Method
*		cTexture & operator=(const cTexture & rhs);
*		//Loads image at specified path 
*		bool loadFromFile( std::string path, SDL_Renderer*& gRenderer);
*		//Deallocates texture 
*		void free(); 
*		//Renders texture at given point 
*		void render( int x, int y, SDL_Renderer*& gRenderer);
*		//Gets image dimensions 
*		int getWidth(); 
*		int getHeight();
*****************************************************************/
class cTexture
{
public:
	//Constructor
	cTexture();
	//Destructor
	~cTexture();
	//Copy Constructor
	cTexture(const cTexture& rhs);
	//Overload Assignment Operator Method
	cTexture & operator=(const cTexture & rhs);
	//Loads image at specified path 
	bool loadFromFile( std::string path, SDL_Renderer*& gRenderer);
	//Deallocates texture 
	void free(); 
	//Renders texture at given point 
	void render( int x, int y, SDL_Renderer*& gRenderer);
	//Gets image dimensions 
	int getWidth(); 
	int getHeight();
	
private:
	//The actual hardware texture 
	SDL_Texture* mTexture; 
	SDL_Texture* mBackground;

	//Image dimensions 
	int mWidth; 
	int mHeight;
};

#endif // !WINDOW_H
