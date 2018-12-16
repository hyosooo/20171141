#pragma once

#include "SDLGameObject.h"



class MovingBg : public SDLGameObject
{

private:

	//int bgX = 0, bgY = 0;

	int m_numFrames = 1;



public:

	MovingBg(const LoaderParams* pParams);

	virtual void draw();

	virtual void update();

	virtual void clean();

};