/***********************************************************
* Author:					Arthur Clark
* Date Created:				11/15/15
* Last Modification Date:	11/18/15
* Lab Number:				Lab 6
* Filename:					cWindow.cpp
************************************************************/
#include "cWindow.h"

//Screen dimension constants
const int SCREEN_WIDTH = 1350;
const int SCREEN_HEIGHT = 680;

cWindow::cWindow()
{
}

cWindow::~cWindow()
{
}

cWindow::cWindow(const cWindow & rhs)
{
}

cWindow & cWindow::operator=(const cWindow & rhs)
{
	return *this;
}

//Initializes SDL_Window
bool cWindow::InitializeSDLWindow(SDL_Window*& window, string gameName,
					 SDL_Renderer*& gRenderer)
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Create window
		window = SDL_CreateWindow(gameName.c_str(), SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
			SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == nullptr)
		{
			printf("Window could not be created! SDL_Error: %s\n",
				SDL_GetError());
			success = false;
		}
		else
		{
			//Create renderer for window 
			gRenderer = SDL_CreateRenderer( window, -1, 
												SDL_RENDERER_ACCELERATED ); 
			if( gRenderer == NULL ) 
			{ 
				printf( "Renderer could not be created! SDL Error: %s\n", 
										SDL_GetError() ); success = false;
			} 
			else 
			{ 
				//Initialize renderer color 
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
				//Initialize PNG loading 
				int imgFlags = IMG_INIT_PNG; 
				if( !( IMG_Init( imgFlags ) & imgFlags ) ) 
				{ 
					printf( "SDL_image could not initialize! "
						"SDL_image Error: %s\n", IMG_GetError() ); 
					success = false; 
				} 
			}
			//Initialize SDL_mixer 
			if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
			{
				printf("SDLmixer couldn't initialize! SDL_mixer Error: %s\n",
					Mix_GetError()); success = false;
			}
			else
			{
				//Get window surface 
				//screenSurface = SDL_GetWindowSurface(window);
			}
		}
	}

	return success;
}
