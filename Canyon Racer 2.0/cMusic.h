/***********************************************************
* Author:					Arthur Clark
* Date Created:				11/15/15
* Last Modification Date:	11/18/15
* Lab Number:				Lab 6
* Filename:					cMusic.h
************************************************************/
#ifndef MUSIC_H
#define MUSIC_H

#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_image.h>
using std::string;
/****************************************************************
* Class: cMusic
*	Description:
*		Music Wrapper Class For Easy Music and Sound Effect Implementation.
* Constructors:
*		cMusic();
*		cMusic(const  cMusic& rhs);
* Destructors:
*		~cMusic();
* Methods:
*		//Overload Assignment Operator Method
*		cMusic & operator=(const cMusic & rhs);
*		//Returns m_Music
*		Mix_Music *& GetMusic();
*		//Returns m_Crash
*		Mix_Chunk *& GetCrash();
*		//Returns m_Cruising
*		Mix_Chunk *& GetCruising();
*****************************************************************/
class cMusic
{
public:
	//Constructor
	cMusic();
	//Destructor
	~cMusic();
	//Copy Constructor
	cMusic(const  cMusic& rhs);
	//Overload Assignment Operator Method
	cMusic & operator=(const cMusic & rhs);
	//Returns m_Music
	Mix_Music *& GetMusic();
	//Returns m_Crash
	Mix_Chunk *& GetCrash();
	//Returns m_Cruising
	Mix_Chunk *& GetCruising();
protected:
	//The music that will be played 
	Mix_Music * m_Music; 
	//The sound effects that will be used 
	Mix_Chunk * m_Crash;
	Mix_Chunk * m_Cruising;
};

#endif // !MUSIC_H
