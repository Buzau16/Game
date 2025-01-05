#include "KeyboardHandler.h"

namespace KeyboardHandler {

	bool keys[SDL_NUM_SCANCODES] = { 0 };

	void HandleKeyboardEvent(const SDL_Event& event) {
		if (event.key.state == SDL_PRESSED) {
			keys[event.key.keysym.scancode] = SDL_PRESSED;
		}
		else if (event.key.state == SDL_RELEASED) {
			keys[event.key.keysym.scancode] = SDL_RELEASED;
		}
	}
	bool isPressed(SDL_Scancode code) {
		return keys[code] == SDL_PRESSED;
	}
	bool isReleased(SDL_Scancode code) {
		return keys[code] == SDL_RELEASED;
	}
}