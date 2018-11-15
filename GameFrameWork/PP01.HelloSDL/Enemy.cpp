#include "Game.h"
#include <SDL_image.h>
#include <iostream>
#include"TextureManager.h"
#include "Enemy.h"
#include "GameObject.h"

using namespace std;

void Enemy::update()
{
	m_y += 1;
	m_x += 1;
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
}