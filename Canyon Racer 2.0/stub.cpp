/***********************************************************
* Author:					Arthur Clark
* Date Created:				11/15/15
* Last Modification Date:	11/18/15
* Lab Number:				CST136 LAB 6
* Filename:					stub.cpp
*
*
* Overview:
*	This is Lab 6 completed. Using an SDL Window this program
*	will render a car, 4 objects, and a Background to the screen.
*	The user will be able to move the vehicle, attempting to dodge
*	the objects. If an object makes contact with the vehicle. Control
*	of the vehicle is lost and it drifts off the screen, eventually
*	closing the program.
*
* Input:
*	P(x2) = Play/Pause Music
*	Spacebar = Play Car Noise
*	Left, Right, Up, Down Arrow Keys = Vehicle Movement
*
* Output:
*	The output of this program will Simulate a Desert floor
*	 with a vehicle and 4 objects. (Yellow Car, 3 Rocks, 1 Bush)
*
************************************************************/
#define _CRTBG_MAP_ALLOC
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include "cGame.h"
#include <crtdbg.h>

int main(int argc, char* args[])
{
	//Checks For Memory Leaks
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//Initialize cGame Object with name Canyon Racer
	cGame canyonRacer("Canyon Racer");
	//Run Canyon Racer Game
	canyonRacer.RunGame();


	return 0;
}