#include "PlayState.h"
#include "TextureManager.h"
#include "InputHandler.h"
#include "PauseState.h"
#include "Game.h"
#include "Player.h"
#include "Enemy.h"

#include "GameOverState.h"
#include "SDLGameObject.h"
#include "Projectile.h"
#include <iostream>
#include "AnimatedGraphic.h"
#include "MovingBg.h"
using namespace std;

const std::string PlayState::s_playID = "PLAY";

void PlayState::update()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}

	
	if (checkCollision(dynamic_cast<SDLGameObject*>(m_gameObjects[3]), dynamic_cast<SDLGameObject*>(m_gameObjects[1])))
		{
			TheGame::Instance()->getStateMachine()->changeState(GameOverState::Instance());
		}

		else if (checkCollision(dynamic_cast<SDLGameObject*>(m_gameObjects[4]), dynamic_cast<SDLGameObject*>(m_gameObjects[1])))
		{
			TheGame::Instance()->getStateMachine()->changeState(GameOverState::Instance());
		}

		else if (checkCollision(dynamic_cast<SDLGameObject*>(m_gameObjects[5]), dynamic_cast<SDLGameObject*>(m_gameObjects[1])))
		{
			TheGame::Instance()->getStateMachine()->changeState(GameOverState::Instance());
		}

		else if (checkCollision(dynamic_cast<SDLGameObject*>(m_gameObjects[6]), dynamic_cast<SDLGameObject*>(m_gameObjects[1])))
		{
			TheGame::Instance()->getStateMachine()->changeState(GameOverState::Instance());
		}

	
		else if (checkCollision(dynamic_cast<SDLGameObject*>(m_gameObjects[3]), dynamic_cast<SDLGameObject*>(m_gameObjects[2])))
		{
			enemy->clean();
			projectile->clean();
		}

		else if (checkCollision(dynamic_cast<SDLGameObject*>(m_gameObjects[4]), dynamic_cast<SDLGameObject*>(m_gameObjects[2])))
		{
			enemy->clean();
			projectile->clean();
		}

		else if (checkCollision(dynamic_cast<SDLGameObject*>(m_gameObjects[5]), dynamic_cast<SDLGameObject*>(m_gameObjects[2])))
		{
			enemy->clean();
			projectile->clean();
		}

		else if (checkCollision(dynamic_cast<SDLGameObject*>(m_gameObjects[6]), dynamic_cast<SDLGameObject*>(m_gameObjects[2])))
		{
			enemy->clean();
			projectile->clean();
		}


	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		TheGame::Instance()->getStateMachine()->changeState(PauseState::Instance());
	}

	if (TheInputHandler::Instance()->getMouseButtonState(0))
	{
		float x = player->getPosition().getX()+55;
		float y = player->getPosition().getY();
		projectile->Shoot(x, y);
	}
}

void PlayState::render()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}

}
bool PlayState::onEnter()
{

	if (!TheTextureManager::Instance()->load("assets/airplane.png",
		"helicopter", TheGame::Instance()->getRenderer())) 
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("assets/airplane2.png",
		"helicopter2", TheGame::Instance()->getRenderer())) 
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("assets/bullet.png", 
		"bullet",TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("assets/star.png",
		"starr", TheGame::Instance()->getRenderer())) {
		return false;
	}

	if (!TheTextureManager::Instance()->load("assets/background4.png",
		"background", TheGame::Instance()->getRenderer())) 
	{
		return false;
	}

	GameObject* player = new Player(
		new LoaderParams(200, 600, 131, 87, 5,"helicopter"));

	GameObject* enemy = new Enemy(
		new LoaderParams( rand() % 400 ,-100, 78, 65, 3,"helicopter2"));

	GameObject* enemy1 = new Enemy(
		new LoaderParams(rand() % 400, -300, 78, 65, 3, "helicopter2"));

	GameObject* enemy2 = new Enemy(
		new LoaderParams(rand() % 400, -500, 78, 65, 3, "helicopter2"));

	GameObject* enemy3 = new Enemy(
		new LoaderParams(rand() % 400, -800, 78, 65, 3, "helicopter2"));

	GameObject* bullet = new Projectile(
		new LoaderParams(100, 600, 12, 12, 0, "bullet"));

	GameObject* background = new MovingBg(
		new LoaderParams(0, -2400, 450, 3200, 1, "background"));
	

	m_gameObjects.push_back(background);
	m_gameObjects.push_back(player);
	m_gameObjects.push_back(bullet);
	m_gameObjects.push_back(enemy);
	m_gameObjects.push_back(enemy1);
	m_gameObjects.push_back(enemy2);
	m_gameObjects.push_back(enemy3);

	this->player = (Player*)player;
	this->projectile = (Projectile*)bullet;
	this->enemy = (Enemy*)enemy;


	std::cout << "entering PlayState\n";
	return true;
}

bool PlayState::onExit()
{
	for (int i = 0; i < m_gameObjects.size(); ++i)
	{
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();
	TheTextureManager::Instance()->clearFromTextureMap("helicopter");

	std::cout << "exiting PlayState\n";
	return true;
}

bool PlayState::checkCollision(SDLGameObject* p1, SDLGameObject* p2)
{
	float leftA, leftB;
	float rightA, rightB;
	float topA, topB;
	float bottomA, bottomB;

	leftA = p1->getPosition().getX();
	rightA = p1->getPosition().getX() + p1->getWidth();
	topA = p1->getPosition().getY();
	bottomA = p1->getPosition().getY() + p1->getHeight();

	leftB = p2->getPosition().getX();
	rightB = p2->getPosition().getX() + p2->getWidth();
	topB = p2->getPosition().getY();
	bottomB = p2->getPosition().getY() + p2->getHeight();


	if (bottomA <= topB) { return false; }
	if (topA >= bottomB) { return false; }
	if (rightA <= leftB) { return false; }
	if (leftA >= rightB) { return false; }


	return true;
}
