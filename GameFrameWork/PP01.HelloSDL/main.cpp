#include "Game.h"

Game* g_game = 0;

int main(int argc, char* garv[])
{
	g_game = new Game();
	g_game->init("Chapter 5", 100, 100, 640, 480, false);

	while (g_game->running())
	{
		g_game->handleEvents();
		g_game->update();
		g_game->render();
	}
	SDL_Delay(10000);

	g_game->clean();
	return 0;
}
