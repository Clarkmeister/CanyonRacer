/***********************************************************
* Author:					Arthur Clark
* Date Created:				11/15/15
* Last Modification Date:	11/18/15
* Lab Number:				Lab 6
* Filename:					cMusic.cpp
************************************************************/
#include "cMusic.h"

cMusic::cMusic() : m_Music(nullptr), m_Crash(nullptr), m_Cruising(nullptr)
{
}

cMusic::~cMusic()
{
	Mix_FreeChunk(m_Cruising);
	m_Cruising = nullptr;
	//Free the sound effects 
	Mix_FreeChunk( m_Crash );
	m_Crash = nullptr;
	//Free the music 
	Mix_FreeMusic( m_Music ); 
	m_Music = nullptr;
	//Quit SDL subsystems 
	Mix_Quit();
}

cMusic::cMusic(const cMusic & rhs)
{
	m_Crash = rhs.m_Crash;
	m_Cruising = rhs.m_Cruising;
	m_Music = rhs.m_Music;
}

cMusic & cMusic::operator=(const cMusic & rhs)
{   
	m_Crash = rhs.m_Crash;
	m_Cruising = rhs.m_Cruising;
	m_Music = rhs.m_Music;
	return *this;
}

Mix_Music *& cMusic::GetMusic()
{
	return m_Music;
}

Mix_Chunk *& cMusic::GetCrash()
{
	return m_Crash;
}

Mix_Chunk *& cMusic::GetCruising()
{
	return m_Cruising;
}
