#include "Window.h"

void Window::Init()
{
	// SDL + Window initialization
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		std::cerr << "Error initalizing SDL: " << SDL_GetError();
		return;
	}

	window = SDL_CreateWindow(name.c_str(), 200, 200, width, height, SDL_WINDOW_SHOWN);

	if (!window) {
		std::cerr << "Error initializing window: " << SDL_GetError();
		SDL_Quit();
		return;
	}
}

void Window::Destroy()
{
	SDL_DestroyWindow(window);
	SDL_Quit();
}

bool Window::IsClosed()
{
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) {
			return true;
		}
	}
	return false;
}
