#pragma once
#include"SDLGameObject.h"

class Projectile : public SDLGameObject
{
public:
	Projectile(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();

private:
	bool drawbullet = false;
	void handleInput();
};
