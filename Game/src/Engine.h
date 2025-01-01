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
		Object* obj2;
		Object* obj3;
		Window m_Window;
		Renderer m_Renderer;
		Shader m_Shader;

		float ts = 0;
	};

}

