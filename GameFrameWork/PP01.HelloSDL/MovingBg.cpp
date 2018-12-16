#include "MovingBg.h"



MovingBg::MovingBg(const LoaderParams* pParams) : SDLGameObject(pParams)

{

	m_velocity.setY(5);

}

void MovingBg::draw()

{

	SDLGameObject::draw();
}

void MovingBg::update()

{

	m_currentFrame = int(((SDL_GetTicks() / 100) % m_numFrames));

	if (m_position.getY() >= -2400)
	{
		m_velocity.setY(5);
	}
	if (m_position.getY() > 0)
	{
		m_position.setY(-1600);
	}

	SDLGameObject::update();

}



void MovingBg::clean()

{



}