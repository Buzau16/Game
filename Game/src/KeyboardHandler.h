#pragma once
#include <SDL2/SDL.h>

namespace KeyboardHandler
{
	static bool keys[SDL_NUM_SCANCODES] = { 0 };

	inline void HandleKeyboardEvent(const SDL_Event& event) {
		if (event.key.state == SDL_PRESSED) {
			keys[event.key.keysym.scancode] = SDL_PRESSED;
			std::cout << "down\n";
		}
		else if (event.key.state == SDL_RELEASED) {
			keys[event.key.keysym.scancode] = SDL_RELEASED;
			std::cout << "up\n";
		}
	}
	inline bool isPressed(SDL_Scancode code) {
		return keys[code] == SDL_PRESSED;
	}
	inline bool isReleased(SDL_Scancode code) {
		return keys[code] == SDL_RELEASED;
	}
};

