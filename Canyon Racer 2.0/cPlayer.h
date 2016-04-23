/***********************************************************
* Author:					Arthur Clark
* Date Created:				11/23/15
* Last Modification Date:	11/23/15
* Lab Number:				Lab 6
* Filename:					cPlayer.h
************************************************************/
#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_image.h>
using std::string;
/****************************************************************
* Class: cPlayer
*	  Description: cPlayer is a class that will Keep Track of a 
*		players name, abrieviation, and score.
*	Constructor:
*		cPlayer();
*	Destructor:
*		~cPlayer();
*	Methods:
*		//Copy Constructor
*		cPlayer(const  cPlayer& rhs);
*		//Overload Assignment Operator Method
*		cPlayer & operator=(const cPlayer & rhs);
*		//Set Player Name
*		void setName(string newName);
*		//Set First Initial
*		void setFi(char F);
*		//Set Middle Initial
*		void setMi(char M);
*		//Set Last Initial
*		void setLi(char L);
*		//Return First Initial
*		char getFi() const;
*		//Return Middle Initial
*		char getMi() const;
*		//Return Last Initial
*		char getLi() const;
*		//Set Score
*		void setScore(int newScore);
*		//Increment Score + 1
*		void scoreIncrement();
*		//Return Score
*		int GetScore() const;
*		//Reset Score to Zero
*		void ResetScore();

*****************************************************************/
class cPlayer
{
public:
	//Constructors
	cPlayer();
	//Destructor
	~cPlayer();
	//Copy Constructor
	cPlayer(const  cPlayer& rhs);
	//Overload Assignment Operator Method
	cPlayer & operator=(const cPlayer & rhs);
	//Set Player Name
	void setName(string newName);
	//Set First Initial
	void setFi(char F);
	//Set Middle Initial
	void setMi(char M);
	//Set Last Initial
	void setLi(char L);
	//Return First Initial
	char getFi() const;
	//Return Middle Initial
	char getMi() const;
	//Return Last Initial
	char getLi() const;
	//Set Score
	void setScore(int newScore);
	//Increment Score + 1
	void scoreIncrement();
	//Return Score
	int GetScore() const;
	//Reset Score to Zero
	void ResetScore();
private:
	//Player Name
	string m_playerName;
	//First Initial
	char m_FirstInitial;
	//Middle Initial
	char m_MiddleInitial;
	//Last Initial
	char m_LastInitial;
	//Player Score
	int m_score;
};
#endif // !PLAYER_H