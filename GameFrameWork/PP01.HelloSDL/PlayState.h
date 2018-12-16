#pragma once
#include "GameState.h"
#include "SDLGameObject.h"


class GameObject;

class PlayState : public GameState
{
public:
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	

	virtual std::string getStateID() const { return s_playID; }

	static PlayState* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new PlayState();
		}
		return s_pInstance;
	}

	bool checkCollision(SDLGameObject* p1, SDLGameObject* p2);

	std::vector<GameObject*> m_gameObjects;

private:
	

	static const std::string s_playID;
	static PlayState* s_pInstance;

	class Projectile* projectile;
	class Player* player;
	class Enemy* enemy;
};
