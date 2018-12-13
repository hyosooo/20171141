#pragma once
#include <SDL_events.h>

class MovingBg
{
public:

	static const int DOT_WIDTH = 20;
	static const int DOT_HEIGHT = 20;


	static const int DOT_VEL = 10;


	MovingBg();

	void handleEvent(SDL_Event& e);


	void move();

	void render();

private:

	int mPosX, mPosY;

	int mVelX, mVelY;
};