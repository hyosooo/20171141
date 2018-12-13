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
using namespace std;

const std::string PlayState::s_playID = "PLAY";

void PlayState::update()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}

	if (checkCollision(dynamic_cast<SDLGameObject*>(m_gameObjects[1]), dynamic_cast<SDLGameObject*>(m_gameObjects[2])))
	{
		TheGame::Instance()->getStateMachine()->changeState(GameOverState::Instance());
	}

	else if (checkCollision(dynamic_cast<SDLGameObject*>(m_gameObjects[3]), dynamic_cast<SDLGameObject*>(m_gameObjects[4])))
	{
		TheGame::Instance()->getStateMachine()->changeState(GameOverState::Instance());
	}

	//else if (checkCollision(dynamic_cast<SDLGameObject*>(m_gameObjects[2]), dynamic_cast<SDLGameObject*>(m_gameObjects[3])))
	//{
	//	m_gameObjects.erase(m_gameObjects.begin() + 2);
	//}

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

	if (!TheTextureManager::Instance()->load("assets/helicopter2.png",
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

	if (!TheTextureManager::Instance()->load("assets/background3.png",
		"background", TheGame::Instance()->getRenderer())) 
	{
		return false;
	}

	GameObject* star = new AnimatedGraphic(
		new LoaderParams(302, 500, 51, 51, 2, "starr"), 2);

	GameObject* player = new Player(
		new LoaderParams(300, 100, 131, 87, 5,"helicopter"));

	GameObject* enemy = new Enemy(
		new LoaderParams(100, 100, 128, 55, 5,"helicopter2"));

	GameObject* bullet = new Projectile(
		new LoaderParams(100, 600, 12, 12, 0, "bullet"));

	GameObject* background = new SDLGameObject(
		new LoaderParams(0, 0, 450, 800, 0, "background"));
	

	m_gameObjects.push_back(background);
	m_gameObjects.push_back(player);
	m_gameObjects.push_back(enemy);
	m_gameObjects.push_back(bullet);
	m_gameObjects.push_back(star);

	this->player = (Player*)player;
	this->projectile = (Projectile*)bullet;

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


//bool PlayState::checkCollision2(SDLGameObject* p2, SDLGameObject* p3)
//{
//	float leftC, leftD;
//	float rightC, rightD;
//	float topC, topD;
//	float bottomC, bottomD;
//
//	leftC = p2->getPosition().getX();
//	rightC = p2->getPosition().getX() + p2->getWidth();
//	topC = p2->getPosition().getY();
//	bottomC = p2->getPosition().getY() + p2->getHeight();
//
//	leftD = p3->getPosition().getX();
//	rightD = p3->getPosition().getX() + p3->getWidth();
//	topD = p3->getPosition().getY();
//	bottomD = p3->getPosition().getY() + p3->getHeight();
//
//
//	if (bottomC <= topD) { return false; }
//	if (topC >= bottomD) { return false; }
//	if (rightC <= leftD) { return false; }
//	if (leftC >= rightD) { return false; }
//
//
//	return true;
//}