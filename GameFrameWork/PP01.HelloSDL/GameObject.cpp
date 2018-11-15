#include "GameObject.h"
#include"TextureManager.h"
#include <SDL_image.h>
#include <iostream>
using namespace std;

void GameObject::draw()
{

}

void GameObject::update()
{
	m_x += 1;
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
}
void GameObject::clean()
{
}

