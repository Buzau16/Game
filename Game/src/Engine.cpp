#include "Engine.h"


namespace Engine {
	void Engine::Start()
	{
		window = new Window("SDL", 800, 600);
		window->Init();
		MainLoop();
		window->Destroy();
	}
	void Engine::MainLoop()
	{
		while (!window->IsClosed()) {
			
		}
	}
}
