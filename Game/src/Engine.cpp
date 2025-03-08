#include "Engine.h"

void Engine::Start()
{
	m_Window = Window("SDL", 960, 540);
	Renderer::GetInstance().Init(m_Window.GetWidth(), m_Window.GetHeight());
	m_Window.Init();

	TextureManager& m_TextureManager = TextureManager::GetInstance();
	m_TextureManager.LoadTexture("player", "Textures/Player.png");
	m_TextureManager.LoadTexture("box", "Textures/Box.png");
	m_TextureManager.LoadTexture("tile", "Textures/Tile.png");

	player.CreateObject(Shapes::CreateSquare(50.f), *m_TextureManager.GetTexture("player"));

	m_Shader = Shader("Shaders/shader.vert", "Shaders/shader.frag");
	Renderer::GetInstance().SetShader(m_Shader);

	m_Scene.AddObject(&player);

	for (int y = 0; y < 10; y++)
	{
		for (int x = 0; x < 10; x++)
		{
			Object* obj = new Object();
			obj->CreateObject(Shapes::CreateRectangle(50.f, 50.f), *m_TextureManager.GetTexture("tile"));
			obj->Translate(x * 50, y * 50);
			m_Scene.AddObject(obj);
		}
	}

	Renderer::GetInstance().SetScene(m_Scene);

	MainLoop();

	m_Window.Destroy();
}


void Engine::MainLoop()
{
	uint32_t fT = 0;
	float timeStep = 0;
	while (!m_Window.IsClosed()) {

		Uint32 sT = SDL_GetTicks();
		timeStep = (float)sT - (float)fT;

		m_Window.PollEvents();
		m_Window.HandleResizing();

		glClearColor(0.0f, 0.3f, 0.7f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		player.HandleMovement(timeStep);

		Renderer::GetInstance().GetCamera().Follow(player);

		Renderer::GetInstance().Draw();

		SDL_GL_SwapWindow(m_Window.GetWindow());
		
		std::cout << " " << timeStep << std::endl;

		fT = sT;
	}
	m_Window.Destroy();
}
