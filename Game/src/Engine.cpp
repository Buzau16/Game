#include "Engine.h"

void Engine::Start()
{
	m_Window = Window("SDL", 960, 540);
	Renderer::GetInstance().Init(m_Window.GetWidth(), m_Window.GetHeight());
	m_Window.Init();

	TextureManager& m_TextureManager = TextureManager::GetInstance();
	m_TextureManager.LoadTexture("player", "Textures/Player.png");
	m_TextureManager.LoadTexture("box", "Textures/Box.png");

	player.CreateObject(Shapes::CreateSquare(50.f), *m_TextureManager.GetTexture("player"));

	Object* obj1 = new Object();
	obj1->CreateObject(Shapes::CreateRectangle(50.f, 50.f), *m_TextureManager.GetTexture("box"));

	Object* obj2 = new Object();
	obj2->CreateObject(Shapes::CreateRectangle(50.f, 50.f), *m_TextureManager.GetTexture("box"));

	m_Shader = Shader("Shaders/shader.vert", "Shaders/shader.frag");
	Renderer::GetInstance().SetShader(m_Shader);

	m_Scene.AddObject(&player);
	m_Scene.AddObject(obj1);
	m_Scene.AddObject(obj2);

	obj2->Translate(100.f, 100.f);

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

		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		player.HandleMovement(timeStep);

		Renderer::GetInstance().GetCamera().Follow(player);

		Renderer::GetInstance().Draw();

		SDL_GL_SwapWindow(m_Window.GetWindow());
		
		std::cout << "TimeStep: " << timeStep << std::endl;

		fT = sT;
	}
	m_Window.Destroy();
}
