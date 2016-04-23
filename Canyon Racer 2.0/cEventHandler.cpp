/***********************************************************
* Author:					Arthur Clark
* Date Created:				11/15/15
* Last Modification Date:	11/18/15
* Lab Number:				Lab 6
* Filename:					cEventHandler.cpp
************************************************************/
#include "cEventHandler.h"

const int MOVE_UP = -2;
const int MOVE_DOWN = 2;
const int MOVE_RIGHT = 2;
const int MOVE_LEFT = -2;
const int WALL_POSITION_RIGHT = 1110;
const int WALL_POSITION_LEFT = 100;
const int BOTTOM_SCREEN = 575;
const int ZERO = 0;

cEventHandler::cEventHandler()
{
}

cEventHandler::~cEventHandler()
{
	//Unsure how or if m_event needs to be reset/deleted. 
	//Nullptr & 0 do not work.
}

cEventHandler::cEventHandler(const cEventHandler & rhs)
{
	m_event = rhs.m_event;
}

cEventHandler & cEventHandler::operator=(const cEventHandler & rhs)
{
	m_event = rhs.m_event;
	return *this;
}

void cEventHandler::GameEventHandler(bool & quit, cMusic & Music,
	int & vX, int & vY)
{
	//Handle events on queue 
	//while (SDL_PollEvent(&m_event) != 0)
	//{
	SDL_PollEvent(&m_event);
	//User requests quit 
	if (m_event.type == SDL_QUIT)
	{
		quit = true;
	}
	//User presses a key 
	else if (m_event.type == SDL_KEYDOWN)
	{
		//Select surfaces based on key press 
		switch (m_event.key.keysym.sym)
		{
		case SDLK_UP:
			vY = (vY + MOVE_UP);
			if (vY < ZERO)
			{
				vY = ZERO;
			}
			break;
		case SDLK_DOWN:
			vY = (vY + MOVE_DOWN);
			if (vY > BOTTOM_SCREEN)
			{
				vY = BOTTOM_SCREEN;
			}
			//Mix_VolumeChunk(Music.GetCruising(), 0);
			break;
		case SDLK_LEFT:
			vX = (vX + MOVE_LEFT);
			if (vX < WALL_POSITION_LEFT)
			{
				vX = (WALL_POSITION_LEFT);
			}
			break;
		case SDLK_RIGHT:
			vX = (vX + MOVE_RIGHT);
			if (vX > WALL_POSITION_RIGHT)
			{
				vX = WALL_POSITION_RIGHT;
			}
			break;
		case SDLK_ESCAPE:
			quit = true;
			break;
			//Play scratch sound effect 
		case SDLK_SPACE:
			Mix_VolumeChunk(Music.GetCruising(), 2);
			Mix_PlayChannel(-1, Music.GetCruising(), -1);
			break;
		case SDLK_p:
			//If there is no music playing 
			if (Mix_PlayingMusic() == 0)
			{
				//Play the music 
				Mix_PlayMusic(Music.GetMusic(), -1);
			}
			//If music is being played else 
			{
				//If the music is paused 
				if (Mix_PausedMusic() == 1)
				{
					//Resume the music 
					Mix_ResumeMusic();
				}
				//If the music is playing 
				else
				{
					//Pause the music 
					Mix_PauseMusic();
				}
			}
			break;
		case SDLK_0:
			//Stop the music
			Mix_HaltMusic();
			break;
		default:

			break;
		}
	}
	//}
}
