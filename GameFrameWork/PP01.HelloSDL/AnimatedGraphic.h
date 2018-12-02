#pragma once
#include "SDLGameObject.h"

class AnimatedGraphic : public SDLGameObject
{
	int m_animSpeed;
public:

	void update();
	void draw();
	void clean();
	
	AnimatedGraphic(const LoaderParams* pParams, int animSpeed);
};
