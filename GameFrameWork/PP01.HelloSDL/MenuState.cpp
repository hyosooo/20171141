#include "MenuState.h"
#include "MenuButton.h"
#include "TextureManager.h"
#include "PlayState.h"
#include "AnimatedGraphic.h"
#include "Game.h"
#include <iostream>
using namespace std;

const std::string MenuState::s_menuID = "MENU";

void MenuState::update()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}

void MenuState::render()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}

bool MenuState::onEnter()
{
	if (!TheTextureManager::Instance()->load("assets/button3.png",
		"playbutton", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/exit3.png",
		"exitbutton", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load("assets/background3.png",
		"background", TheGame::Instance()->getRenderer())) {
		return false;
	}

	if (!TheTextureManager::Instance()->load("assets/text.png",
		"text", TheGame::Instance()->getRenderer())) {
		return false;
	}

	GameObject* button1 = new MenuButton(
		new LoaderParams(85, 400, 280, 70,3, "playbutton"),s_menuToPlay);

	GameObject* button2 = new MenuButton(
		new LoaderParams(85, 520, 280, 70,3, "exitbutton"),s_exitFromMenu);

	GameObject* gameOverText = new AnimatedGraphic(
		new LoaderParams(7, 200, 450, 168, 2, "text"), 2);

	GameObject* sdlgameobject = new SDLGameObject(
		new LoaderParams(0, 0, 450, 800, 0, "background"));

	m_gameObjects.push_back(sdlgameobject);
	m_gameObjects.push_back(gameOverText);
	m_gameObjects.push_back(button1);
	m_gameObjects.push_back(button2);

	std::cout << "entering MenuState\n";
	return true;
}

bool MenuState::onExit()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();
	TheTextureManager::Instance()
		->clearFromTextureMap("playbutton");
	TheTextureManager::Instance()
		->clearFromTextureMap("exitbutton");
	std::cout << "exiting MenuState\n";
	return true;

}

void MenuState::s_menuToPlay()
{
	TheGame::Instance()->getStateMachine()->changeState(
		new PlayState());
}

void MenuState::s_exitFromMenu()
{
	TheGame::Instance()->quit();
}