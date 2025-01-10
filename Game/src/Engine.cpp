#include "Engine.h"


namespace Engine {
	void Engine::Start()
	{
		m_Window = Window("SDL", 960, 540);
		m_Window.Init();


		TextureManager& m_TextureManager = TextureManager::GetInstance();
		m_TextureManager.LoadTexture("wood", "Textures/PaintedWood007C_1K-JPG_Color.jpg");
		m_TextureManager.LoadTexture("woode", "Textures/PaintedWood007B_1K-JPG_Color.jpg");


		
		player.CreateObject(Shapes::CreateSquare(0.1f), *m_TextureManager.GetTexture("wood"));
		
		Object* obj1 = new Object();
		obj1->CreateObject(Shapes::CreateRectangle(1.f, 1.f), *m_TextureManager.GetTexture("woode"));

		m_Objects.push_back(obj1);

		m_Shader = Shader("Shaders/shader.vert", "Shaders/shader.frag");
		m_Renderer.setShader(m_Shader);

		m_Renderer.AddObject(&player);

		for (auto& obj : m_Objects) {
			m_Renderer.AddObject(obj);
		}

		//player.SetColor(0.8f, 0.2f, 0.3f);

		MainLoop();

		m_Window.Destroy();
	}


	void Engine::MainLoop()
	{
		uint32_t fT = 0;
		float timeStep = 0;
		while (!m_Window.IsClosed()) {

			Uint32 sT = SDL_GetTicks();

			m_Window.PollEvents();
			m_Window.HandleResizing();

			

			glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			player.HandleMovement();

			m_Renderer.Draw(m_Window.GetWidth(), m_Window.GetHeight());

			SDL_GL_SwapWindow(m_Window.GetWindow());

			timeStep = (float)sT - (float)fT;
			fT = sT;
		}
	}
}
