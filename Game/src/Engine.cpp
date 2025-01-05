#include "Engine.h"


namespace Engine {
	void Engine::Start()
	{
		m_Window = Window("SDL", 960, 540);
		m_Window.Init();

		player.CreateObject(Shapes::CreateSquare(0.2f));

		Object* obj1 = new Object;
		obj1->CreateObject(Shapes::CreateSquare(.01f));

		Object* obj2 = new Object;
		obj2->CreateObject(Shapes::CreateSquare(.3f));

		Object* obj3 = new Object;
		obj3->CreateObject(Shapes::CreateRectangle(.5f, 1.0f));

		m_Objects.push_back(obj1);
		m_Objects.push_back(obj2);
		m_Objects.push_back(obj3);

		m_Shader = Shader("Shaders/shader.vert", "Shaders/shader.frag");
		m_Renderer.setShader(m_Shader);

		m_Renderer.AddObject(&player);

		for (auto& obj : m_Objects) {
			m_Renderer.AddObject(obj);
		}

		
		
		obj1->TranslateX(-0.5f);
		obj2->TranslateX(0.5f);

		obj1->SetColor(0.7f, 0.1f, 0.2f);
		obj2->SetColor(0.2f, 0.7f, 0.22f);

		player.SetColor(0.8f, 0.2f, 0.3f);

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

			m_Window.PollEvents();
			m_Window.HandleResizing();

			Uint32 sT = SDL_GetTicks();
			
			
			glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			rot += 1.f;
			//m_Objects[0]->RotateZ(rot);
			m_Objects[1]->Rotate(rot);

			player.HandleMovement(timeStep);

			m_Renderer.Draw(m_Window.GetWidth(), m_Window.GetHeight());
			SDL_GL_SwapWindow(m_Window.GetWindow());

			timeStep = (float)sT - (float)fT;
			fT = sT;
		}
	}
}
