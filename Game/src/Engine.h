#pragma once
#include "Window.h"
#include "Renderer.h"
#include "Shader.h"
#include "TextureManager.h"
#include "Scene.h"
#include <vector>

class Engine
{
public:
	Engine() = default;
	~Engine() = default;

	void Start();

private:
	void MainLoop();


	/*std::vector<Object*> m_Objects;*/
	Player player;
	Window m_Window;
	Shader m_Shader;
	Scene m_Scene;

	float ts = 0;
};


