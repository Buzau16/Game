#pragma once
#include "Window.h"
#include "Renderer.h"
#include "Shader.h"


namespace Engine {
	class Engine
	{
	public:
		Engine() = default;
		~Engine() = default;

		void Start();

	private:
		void MainLoop();

		Object* obj1;
		Window m_Window;
		Renderer m_Renderer;
		Shader m_Shader;
	};

}

