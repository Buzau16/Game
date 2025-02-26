#pragma once
#include "Window.h"
#include "Renderer.h"
#include "Shader.h"
#include "TextureManager.h"
#include <vector>

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
	Shader m_Shader;


	float ts = 0;
};


