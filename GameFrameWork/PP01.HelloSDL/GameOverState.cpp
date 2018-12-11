#include"GameOverState.h"
#include "Game.h"
#include"TextureManager.h"
#include"MenuState.h"
#include "AnimatedGraphic.h"
#include "PlayState.h"
#include <iostream>
#include "MenuButton.h"

const std::string GameOverState::s_gameOverID = "GAMEOVER";
GameOverState* GameOverState::s_pInstance = nullptr;

GameOverState::GameOverState()
{
}

void GameOverState::s_gameOverToMain()
{
	TheGame::Instance()->getStateMachine()->changeState(
		MenuState::Instance());
}
void GameOverState::s_restartPlay()
{
	TheGame::Instance()->getStateMachine()->changeState(
		PlayState::Instance());
}

void GameOverState::update()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}

void GameOverState::render()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}

bool GameOverState::onEnter()
{
	if (!TheTextureManager::Instance()->load("assets/gameover2.png",
		"gameovertext", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/main2.png",
		"mainbutton", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/restart2.png",
		"restartbutton", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("assets/background3.png",
		"background", TheGame::Instance()->getRenderer())) {
		return false;
	}

	GameObject* gameOverText = new AnimatedGraphic(
		new  LoaderParams(101, 200, 247, 39, 2,"gameovertext"), 2);

	GameObject* button1 = new MenuButton(
		new LoaderParams(125, 300, 200, 80, 3,"mainbutton"),
		s_gameOverToMain);

	GameObject* button2 = new MenuButton(
		new LoaderParams(125, 400, 200, 80, 3,"restartbutton"),
		s_restartPlay);

	GameObject* sdlgameobject = new SDLGameObject(
		new LoaderParams(0, 0, 450, 800, 0, "background"));

	m_gameObjects.push_back(sdlgameobject);
	m_gameObjects.push_back(gameOverText);
	m_gameObjects.push_back(button1);
	m_gameObjects.push_back(button2);
	std::cout << "entering PauseState\n";
	return true;
}

bool GameOverState::onExit()
{
	for (int i = 0; i < (int)m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();
	TheTextureManager::Instance()->clearFromTextureMap("resumebutton");
	TheTextureManager::Instance()->clearFromTextureMap("mainbutton");
	std::cout << "exiting GameOverState" << std::endl;
	return true;
}