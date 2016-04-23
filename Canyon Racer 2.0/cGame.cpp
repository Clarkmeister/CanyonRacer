/***********************************************************
* Author:					Arthur Clark
* Date Created:				11/15/15
* Last Modification Date:	11/23/15
* Lab Number:				Lab 6
* Filename:					cGame.cpp
************************************************************/
#include "cGame.h"
#include <random>
#include <exception>
#include <fstream>

using std::ifstream;
using std::ofstream;

//Screen dimension constants
const int SCREEN_WIDTH = 1350;
const int WALL_POSITION_RIGHT = 1250;
const int RANDOM_X = 1000;
const int WALL_POSITION_LEFT = 100;
const int SCREEN_HEIGHT = 680;
const int QUARTERSCREEN_X = 336;
const int QUARTERSCREEN_Y = 170;
const int ZERO = 0;
const int SPRITE_SPEED = 1;
const int CAR_HEIGHT = 100;
const int CAR_WIDTH = 65;
const int SPRITE_WIDTH = 65;
const int HALF_SPRITE = 37;
const int HALFCAR_H = 72;
const int HALFCAR_W = 37;
const int CAR_START_X = 675;
const int CAR_START_Y = 525;
const int PLAYER_COUNT = 10;

cGame::cGame() : m_gameName("No Name"), m_Window(nullptr), m_Texture(nullptr),
m_Renderer(nullptr), m_vehicleX(0), m_vehicleY(0),
m_crash(true)
{
	for (int i = 0; i < SPRITES; i++)
	{
		m_sprite_x[i] = 0;
		m_sprite_y[i] = 0;
	}
	cPlayer newPlayer;
	for (int i = 0; i < PLAYER_COUNT; i++)
	{
		m_TopTen.push_back(newPlayer);
	}
}

cGame::cGame(string gameName) : m_crash(false), m_vehicleX(CAR_START_X),
m_vehicleY(CAR_START_Y)
{
	m_gameName = gameName;
	int xRange = WALL_POSITION_LEFT;
	int yRange = ZERO;
	for (int i = 0; i < SPRITES; i++)
	{
		m_sprite_x[i] = xRange;
		m_sprite_y[i] = yRange;
		xRange += QUARTERSCREEN_X;
		yRange += QUARTERSCREEN_Y;
	}
	for (int i = 0; i < PLAYER_COUNT; i++)
	{

		cPlayer newPlayer;
		m_TopTen.push_back(newPlayer);

	}

}

cGame::~cGame()
{
	for (int i = 0; i < SPRITES; i++)
	{
		m_sprite_x[i] = 0;
		m_sprite_y[i] = 0;
	}
	m_gameName = "No Name";
	//Destroy window
	SDL_DestroyWindow(m_Window);
	m_Window = nullptr;
	SDL_DestroyRenderer(m_Renderer);
	m_Renderer = nullptr;
	SDL_DestroyTexture(m_Texture);
	m_Texture = nullptr;
	//Quit SDL subsystems
	SDL_Quit();
}

cGame::cGame(const cGame & rhs)
{
	m_Background = rhs.m_Background;
	m_crash = rhs.m_crash;
	m_gameEventHandler = rhs.m_gameEventHandler;
	m_gameMedia = rhs.m_gameMedia;
	m_gameName = rhs.m_gameName;
	m_gameWindow = rhs.m_gameWindow;
	m_music = rhs.m_music;
	m_Renderer = rhs.m_Renderer;
	m_SpriteSheetTexture = rhs.m_SpriteSheetTexture;
	m_vehicle = rhs.m_vehicle;
	m_vehicleX = rhs.m_vehicleX;
	m_vehicleY = rhs.m_vehicleY;
	m_Texture = rhs.m_Texture;
	m_Window = rhs.m_Window;
}

cGame & cGame::operator=(const cGame & rhs)
{
	m_Background = rhs.m_Background;
	m_crash = rhs.m_crash;
	m_gameEventHandler = rhs.m_gameEventHandler;
	m_gameMedia = rhs.m_gameMedia;
	m_gameName = rhs.m_gameName;
	m_gameWindow = rhs.m_gameWindow;
	m_music = rhs.m_music;
	m_Renderer = rhs.m_Renderer;
	m_SpriteSheetTexture = rhs.m_SpriteSheetTexture;
	m_vehicle = rhs.m_vehicle;
	m_vehicleX = rhs.m_vehicleX;
	m_vehicleY = rhs.m_vehicleY;
	m_Texture = rhs.m_Texture;
	m_Window = rhs.m_Window;
	return *this;
}

void cGame::SetGameName(string newName)
{
	m_gameName = newName;
}

void cGame::RunGame()
{
	ifstream HighScores("HighScores.txt");
	if (HighScores.is_open())
	{
		//Start up SDL and create window
		if (!m_gameWindow.InitializeSDLWindow(m_Window, m_gameName, m_Renderer))
		{
			printf("Failed to initialize!\n");
		}
		else
		{

			//Load media
			if (!m_gameMedia.loadMedia(m_Renderer, m_Texture, m_music,
				m_Background, m_SpriteClips, m_SpriteSheetTexture,
				m_vehicle))
			{
				printf("Failed to load media!\n");
			}
			else
			{
				RunGameLoop();
			}
		}
		HighScores.close();
	}
	else
	{
		std::cout << "Error File Not open!" << std::endl;
	}
	ofstream saveData("HighScores.txt");
	for (int i = 0; i < PLAYER_COUNT; i++)
	{
		saveData << m_TopTen[i].getFi() << m_TopTen[i].getMi() << m_TopTen[i].getLi() << m_TopTen[i].GetScore() << "\n";
		//m_TopTen.pop_back();
	}
}

void cGame::RunGameLoop()
{
	//Main loop flag
	bool quit = false;
	m_CurrentPlayer.ResetScore();
	//While application is running 
	while (!quit)
	{
		SDL_SetRenderDrawColor(m_Renderer, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(m_Renderer);
		m_Background.render(0, 0, m_Renderer);
		if (!m_crash)
		{
			m_gameEventHandler.GameEventHandler(quit, m_music, m_vehicleX,
				m_vehicleY);
		}
		m_vehicle.render(m_vehicleX, m_vehicleY, m_Renderer);
		if (m_crash)
		{
			m_vehicleY++;
			if (m_vehicleY > SCREEN_HEIGHT)
			{
				quit = true;
				SDL_Delay(100);
			}
		}
		for (int i = 0; i < SPRITES; i++)
		{
			//Render sprite
			m_SpriteSheetTexture.render(m_sprite_x[i], m_sprite_y[i],
				m_Renderer, &m_SpriteClips[i]);
		}
		//Update screen 
		SDL_RenderPresent(m_Renderer);
		decendSprites();
		TestCrash(quit);
		m_CurrentPlayer.scoreIncrement();

	}
	//Insert Your Score To High Score List If Applicable
	for (int i = 0; i < PLAYER_COUNT; i++)
	{
		if (m_CurrentPlayer.GetScore() > m_TopTen[i].GetScore())
		{
			m_CurrentPlayer.setFi('A');
			m_CurrentPlayer.setMi('J');
			m_CurrentPlayer.setLi('C');
			m_TopTen.insert(m_TopTen.begin() + i, m_CurrentPlayer);
			i = PLAYER_COUNT;
		}
	}
	//Output Top 10 Scores
	std::cout << "Top Ten Scores" << std::endl;
	for (int i = 0; i < PLAYER_COUNT; i++)
	{
		std::cout << (i + 1) << ". " << m_TopTen[i].getFi() <<
			m_TopTen[i].getMi() << m_TopTen[i].getLi()
			<< "  " << m_TopTen[i].GetScore() << std::endl;
	}
	//Output Your Score
	std::cout << std::endl << "Your Score: " << m_CurrentPlayer.GetScore()
		<< std::endl;
}

void cGame::decendSprites()
{
	//RANDOM NUMBER GENERATOR!!!!
	std::random_device rd;   // non-deterministic generator
	std::mt19937 gen(rd());  // to seed mersenne twister.

	//Drop Sprites 1 on Y axis
	for (int i = 0; i < SPRITES; i++)
	{
		m_sprite_y[i] += SPRITE_SPEED;
	}
	SDL_Delay(3);
	//If A Sprite Reaches the Bottom of the screen, Reposition to the top.
	//(Random X coordinate given)
	for (int i = 0; i < SPRITES; i++)
	{
		if (m_sprite_y[i] >= SCREEN_HEIGHT)
		{
			m_sprite_x[i] = ((gen() % RANDOM_X) + WALL_POSITION_LEFT);
			m_sprite_y[i] = -50;
		}
	}
}
void cGame::TestCrash(bool & testResult)
{
	for (int i = 0; i < SPRITES; i++)
		/**************COLLISION DETECTOR*******************************/
	{		/**************TOP LEFT CORNER CHECK****************************/
		if (m_vehicleX > m_sprite_x[i] &&
			m_vehicleX < (m_sprite_x[i] + SPRITE_WIDTH) &&
			m_vehicleY > m_sprite_y[i] &&
			(m_sprite_y[i] + SPRITE_WIDTH) > m_vehicleY
			/***************************BOTTOM RIGHT CHECK******************/
			|| (m_vehicleX + CAR_WIDTH) > m_sprite_x[i] &&
			(m_vehicleX + CAR_WIDTH) < (m_sprite_x[i] + SPRITE_WIDTH)
			&& (m_vehicleY + CAR_HEIGHT) > m_sprite_y[i] &&
			(m_sprite_y[i] + SPRITE_WIDTH) > (m_vehicleY + CAR_HEIGHT)
			/*********************TOP RIGHT CHECK***************************/
			|| (m_vehicleX + CAR_WIDTH) > m_sprite_x[i] &&
			(m_vehicleX + CAR_WIDTH) < (m_sprite_x[i] + SPRITE_WIDTH) &&
			(m_vehicleY) > m_sprite_y[i] &&
			(m_sprite_y[i] + SPRITE_WIDTH) > (m_vehicleY)
			/*********************BOTTOM LEFT CHECK*************************/
			|| (m_vehicleX) > m_sprite_x[i] &&
			(m_vehicleX) < (m_sprite_x[i] + SPRITE_WIDTH) &&
			(m_vehicleY + CAR_HEIGHT) > m_sprite_y[i] &&
			(m_sprite_y[i] + SPRITE_WIDTH) > (m_vehicleY + CAR_HEIGHT))
		{
			if (m_crash == false)
			{
				Mix_PlayChannel(0, m_music.GetCrash(), 0);
				Mix_PauseMusic();
				m_crash = true;
			}
		}

	}
}


