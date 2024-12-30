#include "Window.h"

void Window::Init()
{
	// SDL + Window initialization
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		std::cerr << "Error initalizing SDL: " << SDL_GetError();
		return;
	}

	m_Window = SDL_CreateWindow(m_Name.c_str(), 200, 200, m_Width, m_Height, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);

	if (!m_Window) {
		std::cerr << "Error initializing window: " << SDL_GetError();
		SDL_Quit();
		return;
	}

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	

	m_Context = SDL_GL_CreateContext(m_Window);
	if (!m_Context) {
		std::cerr << "Error creating OpenGL context: " << SDL_GetError() << std::endl;
		SDL_DestroyWindow(m_Window);
		SDL_Quit();
		return;
	}

	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK) {
		std::cerr << "Failed to initalize GLEW!\n";
		SDL_GL_DeleteContext(m_Context);
		SDL_DestroyWindow(m_Window);
		SDL_Quit();
	}

	glViewport(0, 0, m_Width, m_Height);
	
}

void Window::Destroy()
{
	SDL_DestroyWindow(m_Window);
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
