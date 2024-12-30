#pragma once
#include "Window.h"


namespace Engine {
	class Engine
	{
	public:
		Engine() = default;
		~Engine() = default;

		void Start();

	private:
		Window* window;
		void MainLoop();
	};

}

