#include"Enemy.h"
#include <SDL_image.h>
#include <iostream>
#include"AnimatedGraphic.h"

Enemy::Enemy(const LoaderParams* pParams) : SDLGameObject(pParams)
{
}

void Enemy::draw()
{
	if (alive)
	{
		SDLGameObject::draw();
	}
}

void Enemy::update()
{
	if (alive)
	{
		m_velocity.setY(m_velocity.getY() +3);
		m_currentFrame = int(((SDL_GetTicks() / 100) % m_numFrames));

		if (m_position.getY() < 800)
		{
			m_velocity.setY(3);
		}

		if (m_position.getY() > 800)
		{
			m_position.setX(rand() % 400);
			m_position.setY(-5);
		}
	}

	SDLGameObject::update();
}

void Enemy::clean()
{
	alive = false;
	
}
