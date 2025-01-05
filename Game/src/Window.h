#pragma once
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <iostream>
#include "KeyboardHandler.h"


class Window
{
public:
	Window() = default;
	Window(const std::string& name, int w, int h) : m_Name(name), m_Width(w), m_Height(h), m_Window(nullptr), m_Context(nullptr) {};
	~Window() = default;

	SDL_Window* GetWindow() { return m_Window; };
	int GetWidth() { return m_Width; }
	int GetHeight() { return m_Height; }

	void Init();
	void Destroy();
	bool IsClosed();
	void HandleResizing();
	void PollEvents();

private:

	SDL_Window* m_Window;
	SDL_GLContext m_Context;
	std::string m_Name;
	int m_Width, m_Height;

	bool m_IsResized = false;
	bool m_IsClosed = false;

	
};

