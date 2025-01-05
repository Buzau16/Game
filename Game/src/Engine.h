#pragma once
#include "Window.h"
#include "Renderer.h"
#include "Shader.h"
#include <vector>

namespace Engine {
	class Engine
	{
	public:
		Engine() = default;
		~Engine() = default;

		void Start();

	private:
		void MainLoop();


		std::vector<Object*> m_Objects;
		Player player;
		Window m_Window;
		Renderer m_Renderer;
		Shader m_Shader;

		float ts = 0;
	};

}

