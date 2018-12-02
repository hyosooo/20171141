#pragma once
#include "SDL.h"
#include "Vector2D.h"
#include <vector>
#include <map>

enum mouse_buttons
{
	LEFT = 0,
	MIDDLE = 1,
	RIGHT = 2
};

class InputHandler
{
public:
	~InputHandler() {}

	static InputHandler* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new InputHandler();
		}
		return s_pInstance;
	}

	void reset();
	void update();
	void clean();

	void onKeyUp();
	void onKeyDown();
	void onMouseMove(SDL_Event& event);
	void onMouseButtonDown(SDL_Event& event);
	void onMouseButtonUp(SDL_Event& event);

	bool isKeyDown(SDL_Scancode key);
	bool getMouseButtonState(int buttonNumber);


	Vector2D* m_mousePosition;
	Vector2D* getMousePosition();

private:
	InputHandler();

	static InputHandler* s_pInstance;
	const Uint8* m_keystates;

	std::vector<bool> m_mouseButtonStates;


};
typedef InputHandler TheInputHandler;