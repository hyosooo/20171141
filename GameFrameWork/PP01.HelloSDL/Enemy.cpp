#include"Enemy.h"
#include <SDL_image.h>
#include <iostream>
#include"AnimatedGraphic.h"

Enemy::Enemy(const LoaderParams* pParams) : SDLGameObject(pParams)
{
	m_velocity.setY(2);
	//m_velocity.setX(0.001f);
}

void Enemy::draw()
{
	SDLGameObject::draw();
}

void Enemy::update()
{
	m_currentFrame = int(((SDL_GetTicks() / 100) % m_numFrames));

	//if (m_position.getY() > 700)
	//{
	//	m_velocity.setY(-2);
	//}
	//else if (m_position.getX() > 320)
	//{
	//	m_velocity.setX(-2);
	//}
	SDLGameObject::update();
}

void Enemy::clean()
{
	//if (m_position.getY() > 300)
	//{
	//	~Enemy();
	//}
}
