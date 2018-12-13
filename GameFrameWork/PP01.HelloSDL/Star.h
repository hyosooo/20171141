#pragma once
#include <SDL_image.h>
#include <iostream>
#include"SDLGameObject.h"

class Star : public SDLGameObject
{
public:

	Star(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();

};