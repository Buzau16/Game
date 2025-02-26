#include "Engine.h"

void Engine::Start()
{
	m_Window = Window("SDL", 960, 540);
	Renderer::GetInstance().Init();
	m_Window.Init();

	//m_Renderer.GetCamera().SetPosition(glm::vec2(0.0f, 0.0f));
	//m_Renderer.GetCamera().SetZoom(0.5f);

	TextureManager& m_TextureManager = TextureManager::GetInstance();
	m_TextureManager.LoadTexture("player", "Textures/Player.png");
	m_TextureManager.LoadTexture("box", "Textures/Box.png");



	player.CreateObject(Shapes::CreateSquare(50.f), *m_TextureManager.GetTexture("player"));

	Object* obj1 = new Object();
	obj1->CreateObject(Shapes::CreateRectangle(1.f, 1.f), *m_TextureManager.GetTexture("box"));

	m_Objects.push_back(obj1);

	m_Shader = Shader("Shaders/shader.vert", "Shaders/shader.frag");
	Renderer::GetInstance().setShader(m_Shader);

	Renderer::GetInstance().AddObject(&player);


	for (auto& obj : m_Objects) {
		Renderer::GetInstance().AddObject(obj);
	}

	//player.SetColor(0.8f, 0.2f, 0.3f);
	player.Translate(400, 400);

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

		//glOrtho(0.0f, m_Window.GetWidth(), m_Window.GetHeight(), 0.0f, 0.f, 1.0f);

		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		player.HandleMovement();

		Renderer::GetInstance().GetCamera().Follow(player);
		Renderer::GetInstance().GetCamera().SetPosition(glm::vec2(1.f));

		Renderer::GetInstance().Draw(m_Window.GetWidth(), m_Window.GetHeight());

		SDL_GL_SwapWindow(m_Window.GetWindow());

		timeStep = (float)sT - (float)fT;
		fT = sT;
	}
}
