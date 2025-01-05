#pragma once
#include <SDL2/SDL.h>
#include <iostream>

namespace KeyboardHandler
{
	void HandleKeyboardEvent(const SDL_Event& event);
	bool isPressed(SDL_Scancode code);
	bool isReleased(SDL_Scancode code);
};

