/***********************************************************
* Author:					Arthur Clark
* Date Created:				11/15/15
* Last Modification Date:	11/23/15
* Lab Number:				Lab 6
* Filename:					cGame.h
************************************************************/
#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <SDL.h> 
#include <SDL_thread.h> 
#include <SDL_image.h> 
#include <stdio.h>
#include <string>
#include <vector>

#include "cMedia.h"
#include "cWindow.h"
#include "cEventHandler.h"
#include "cMusic.h"
#include "cTexture.h"
#include "cSprite.h"
#include "cPlayer.h"
//Number of sprites
const int SPRITES = 4;
//Using Stl String Library
using std::string;
using std::vector;
/****************************************************************
* Class: cGame
*	Description: This class holds all core components of the game
*				 and holds the game loop.
*
* Constructors:
*		cGame();
*		cGame(string gameName);
*		cGame(const  cGame& rhs);
* Destructors:
*		~cGame();
* Methods:
*		//Overload Assignment Operator Method
*		cGame & operator=(const cGame & rhs);
*		//Set Game Name
*		void SetGameName(string newName);
*		//Executes Game
*		void RunGame();
*		//Enter Game Loop
*		void RunGameLoop();
*		//Falling Rects
*		void decendSprites();
*		//Tests to see if vehicle has hit an object
*		void TestCrash(bool & testResult);
*****************************************************************/
class cGame
{
public:
	//Default Constructor
	cGame();
	//Constructor(String will Change Game Name)
	cGame(string gameName);
	//Destructor
	~cGame();
	//Copy Constructor
	cGame(const  cGame& rhs);
	//Overload Assignment Operator Method
	cGame & operator=(const cGame & rhs);
	//Set Game Name
	void SetGameName(string newName);
	//Executes Game
	void RunGame();
	//Runs Game Loop
	void RunGameLoop();
	//Falling Rects
	void decendSprites();
	//Tests to see if vehicle has hit an object
	void TestCrash(bool & testResult);
private:
	//The Name of the Game
	string m_gameName;
	//The window we'll be rendering to
	SDL_Window* m_Window;
	//cWindow Object
	cWindow m_gameWindow;
	//cMedia Object
	cMedia m_gameMedia;
	//Event Handler Object
	cEventHandler m_gameEventHandler;
	//Music Object
	cMusic m_music;
	//Current displayed texture 
	SDL_Texture* m_Texture;
	//The window renderer 
	SDL_Renderer* m_Renderer;
	//Background Texture
	cTexture m_Background;
	//Scene sprites
	SDL_Rect m_SpriteClips[SPRITES];
	cSprite m_SpriteSheetTexture;
	//Integer Array for Sprite X positions
	int m_sprite_x[SPRITES];
	//Integer Array for Sprite Y positions
	int m_sprite_y[SPRITES];
	//Vehicle Object (Yellow Car)
	cSprite m_vehicle;	
	//Vehicle X & Y Positions
	int m_vehicleX;
	int m_vehicleY;
	//Crash Detector
	bool m_crash = false;
	//Top Players Tracker (Not Fully Implemented)
	//Displays in console window & does not save.
	vector<cPlayer> m_TopTen;
	//Current Player
	cPlayer m_CurrentPlayer;

};

#endif // !GAME_H

