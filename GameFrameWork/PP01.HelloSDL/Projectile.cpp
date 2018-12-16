#include "Projectile.h"
#include "InputHandler.h"

Projectile::Projectile(const LoaderParams* pParams) : SDLGameObject(pParams)
{
}

void Projectile::draw()
{
	if (drawbullet)
	{
		SDLGameObject::draw();
	}
}

void Projectile::update()
{
	if (drawbullet)
	{
		m_position.setY(m_position.getY() -5);

		m_currentFrame = int(((SDL_GetTicks() / 100) % 1));

		if (m_position.getY() <= 0)
		{
			drawbullet = false;
		}
	}

	handleInput();

	SDLGameObject::update();
}

void Projectile::Shoot(float x, float y)
{
	if (drawbullet)
		return;
	m_position.setX(x);
	m_position.setY(y);
	drawbullet = true;
}

void Projectile::handleInput()
{
}

void Projectile::clean()
{
	drawbullet = false;
}
