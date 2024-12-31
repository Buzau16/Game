#include "Engine.h"


namespace Engine {
	void Engine::Start()
	{
		m_Window = Window("SDL", 960, 540);
		m_Window.Init();
		GLfloat vertices[] = {
			-1.0f, -1.0f, 0.0f,
			 1.0f, -1.0f, 0.0f,
			 0.0f,  1.0f, 0.0f
		};

		GLuint indices[] = {
			0, 1, 2
		};

		obj1 = new Object();
		obj1->CreateObject(vertices, indices, 9, 3);
		m_Shader = Shader("Shaders/shader.vert", "Shaders/shader.frag");
		m_Renderer.setShader(m_Shader);
		m_Renderer.AddObject(obj1);

		obj1->Scale(0.4f);
		

		MainLoop();

		m_Window.Destroy();
	}


	void Engine::MainLoop()
	{
		
		uint32_t fT = 0;
		float timeStep = 0;
		GLfloat position = 0.0f;
		bool dir = false;
		while (!m_Window.IsClosed()) {
			uint32_t sT = SDL_GetPerformanceCounter();
			if (abs(position) >= 1) 
				dir = !dir;

			if (dir)
				position += 0.01f;
			else
				position -= 0.01f;

			obj1->TranslateX(position);

			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			m_Renderer.Draw(timeStep);
			SDL_GL_SwapWindow(m_Window.GetWindow());
			fT = SDL_GetPerformanceCounter();
			timeStep = sT - fT;
		}
	}
}
