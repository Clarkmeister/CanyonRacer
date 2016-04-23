/***********************************************************
* Author:					Arthur Clark
* Date Created:				11/23/15
* Last Modification Date:	11/23/15
* Lab Number:				Lab 6
* Filename:					cPlayer.cpp
************************************************************/
#include "cPlayer.h"

const int ZERO = 0;
const int TEST_SCORE = 1000;
//Constructor
cPlayer::cPlayer() : m_FirstInitial('A'), m_LastInitial('A'), 
					m_MiddleInitial('A'), m_playerName("NewPlayer"), 
					m_score(TEST_SCORE)
{
}
//Destructor
cPlayer::~cPlayer()
{
	m_FirstInitial = 'A';
	m_MiddleInitial = 'A';
	m_LastInitial = 'A';
	m_playerName = "New Player";
	m_score = ZERO;
}
//Copy Constructor
cPlayer::cPlayer(const cPlayer & rhs)
{
	m_FirstInitial = rhs.m_FirstInitial;
	m_MiddleInitial = rhs.m_MiddleInitial;
	m_LastInitial = rhs.m_LastInitial;
	m_playerName = rhs.m_playerName;
	m_score = rhs.m_score;
}
//Operator = Overload Function
cPlayer & cPlayer::operator=(const cPlayer & rhs)
{
	m_FirstInitial = rhs.m_FirstInitial;
	m_MiddleInitial = rhs.m_MiddleInitial;
	m_LastInitial = rhs.m_LastInitial;
	m_playerName = rhs.m_playerName;
	m_score = rhs.m_score;
	return *this;
}
//Set Player Name
void cPlayer::setName(string newName)
{
	m_playerName = newName;
}
//Set First Initial
void cPlayer::setFi(char F)
{
	m_FirstInitial = F;
}
//Set Middle Initial
void cPlayer::setMi(char M)
{
	m_MiddleInitial = M;
}
//Set Last Initial
void cPlayer::setLi(char L)
{
	m_LastInitial = L;
}
//Return First Initial
char cPlayer::getFi() const
{
	return m_FirstInitial;
}
//Return Middle Initial
char cPlayer::getMi() const
{
	return m_MiddleInitial;
}
//Return Last Initial
char cPlayer::getLi() const
{
	return m_LastInitial;
}
//Set Score
void cPlayer::setScore(int newScore)
{
	m_score = newScore;
}
//Increment Score
void cPlayer::scoreIncrement()
{
	m_score++;
}
//Return Score
int cPlayer::GetScore() const
{
	return m_score;
}
//Reset Score
void cPlayer::ResetScore()
{
	m_score = ZERO;
}
