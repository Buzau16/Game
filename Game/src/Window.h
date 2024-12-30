#pragma once
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <iostream>

class Window
{
public:
	Window() = default;
	Window(const std::string& name, int w, int h) : name(name), width(w), height(h), window(nullptr) {};
	~Window() = default;


	void Init();
	void Destroy();
	bool IsClosed();

private:
	SDL_Window* window;
	std::string name;
	int width, height;
};

