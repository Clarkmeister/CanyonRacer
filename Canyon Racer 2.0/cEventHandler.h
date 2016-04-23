/***********************************************************
* Author:					Arthur Clark
* Date Created:				11/15/15
* Last Modification Date:	11/18/15
* Lab Number:				Lab 6
* Filename:					cEventHandler.h
************************************************************/
#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include "cMusic.h"

using std::string;
/****************************************************************
* Class: cEventHandler
*	Description:
*		This class waits for a Keyboard input or an SDL_Event to happen and
*		does an action depending on which key is pressed.
* Constructors:
*		cEventHandler();
*		cEventHandler(const  cEventHandler& rhs);
* Destructors:
*		~cEventHandler();
* Methods:
*		//Overload Assignment Operator Method
*		cEventHandler & operator=(const cEventHandler & rhs);
*	//Handles Any Keyboard Inputs
*	void GameEventHandler(bool & quit, cMusic & Music, int & vX, int & vY);
*****************************************************************/
class cEventHandler
{
public:
	//Constructor
	cEventHandler();
	//Destructor
	~cEventHandler();
	//Copy Constructor
	cEventHandler(const  cEventHandler& rhs);
	//Overload Assignment Operator Method
	cEventHandler & operator=(const cEventHandler & rhs);
	//Handles Keyboard Inputs
	void GameEventHandler(bool & quit, cMusic & Music, int & vX, int & vY);
private:
	//Event Handler
	SDL_Event m_event;
};

#endif // !EVENTHANDLER_H