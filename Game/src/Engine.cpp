#include "Engine.h"


namespace Engine {
	void Engine::Start()
	{
		m_Window = Window("SDL", 960, 540);
		m_Window.Init();

		obj1 = new Object;
		obj1->CreateObject(Shapes::CreateSquare());

		obj2 = new Object;
		obj2->CreateObject(Shapes::CreateSquare());

		m_Shader = Shader("Shaders/shader.vert", "Shaders/shader.frag");
		m_Renderer.setShader(m_Shader);
		m_Renderer.AddObject(obj1);
		m_Renderer.AddObject(obj2);;

		obj1->TranslateX(-0.7f);
		obj2->TranslateX(0.7f);

		obj1->TranslateY(-0.5f);
		obj2->TranslateY(-0.5f);

		obj1->Scale(0.4f);
		obj2->Scale(0.4f);

		obj1->TranslateZ(-2.0f);
		obj2->TranslateZ(-2.0f);

		obj1->SetColor(0.7f, 0.1f, 0.2f);
		obj2->SetColor(0.2f, 0.7f, 0.22f);

		MainLoop();

		m_Window.Destroy();
	}


	void Engine::MainLoop()
	{
		
		uint32_t fT = 0;
		float timeStep = 0;
		GLfloat position = 0.0f;
		float rot = 0.0f;
		float nrot = 0.0f;
		while (!m_Window.IsClosed()) {
			Uint32 sT = SDL_GetTicks();
			
			glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			rot += 1.f;
			obj1->RotateZ(rot);
			nrot = -rot;
			obj2->RotateZ(nrot);
			//std::cout << rot << "\n";

			m_Renderer.Draw(m_Window.GetWidth(), m_Window.GetHeight(), timeStep);
			SDL_GL_SwapWindow(m_Window.GetWindow());

			timeStep = (float)sT - (float)fT;
			fT = sT;
			//std::cout << "FPS: " << (int)(1 / (timeStep / 1000)) << "\n";
		}
	}
}
