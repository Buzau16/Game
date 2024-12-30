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
		GLfloat position = 0.0f;
		bool dir = false;
		while (!m_Window.IsClosed()) {
			if (abs(position) >= 1) 
				dir = !dir;

			if (dir)
				position += 0.01f;
			else
				position -= 0.01f;

			obj1->TranslateX(position);

			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			m_Renderer.Draw();
			SDL_GL_SwapWindow(m_Window.GetWindow());
		}
	}
}
