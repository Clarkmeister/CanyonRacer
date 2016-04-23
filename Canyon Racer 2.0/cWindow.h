/***********************************************************
* Author:					Arthur Clark
* Date Created:				11/15/15
* Last Modification Date:	11/18/15
* Lab Number:				Lab 6
* Filename:					cWindow.h
************************************************************/
#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
using std::string;
/****************************************************************
* Class: cWindow	
*	Description:
*			This Class Initializes an SDL_Window
* Constructors:
*			cWindow(); - Class has no data members
*			cWindow(const cWindow& rhs); 
* Destructors:
*			~cWindow(); - Class has no data members
* Methods:
*				//Overload Assignment Operator Method
*				cWindow & operator=(const cWindow & rhs);
*				//Starts up SDL and creates window
*				bool InitializeSDLWindow(SDL_Window*& window, string gameName,
*											 SDL_Renderer*& gRenderer);
*****************************************************************/
class cWindow
{
public:
	//Constructor
	cWindow();
	//Destructor
	~cWindow();
	//Copy Constructor
	cWindow(const  cWindow& rhs);
	//Overload Assignment Operator Method
	cWindow & operator=(const cWindow & rhs);
	//Starts up SDL and creates window
	bool InitializeSDLWindow(SDL_Window*& window, string gameName,
						 SDL_Renderer*& gRenderer);
private:

};

#endif // !WINDOW_H
