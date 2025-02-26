﻿#pragma once
#include <GL/glew.h>
#include <vector>

#include "Object.h"
#include "Player.h"
#include "Window.h"
#include "Camera.h"


class Renderer {
public:

	static Renderer& GetInstance() {
		static Renderer instance;
		return instance;
	};

	void Init();
	void AddObject(Object* object) { m_Objects.push_back(object); };

	void Draw(int Width, int Height);
	Camera GetCamera() { return m_Camera; };

	void setShader(const Shader& shader);
	
	

private:

	Renderer() = default;
	Renderer(const Renderer&) = delete;
	Renderer& operator=(const Renderer&) = delete;

	std::vector<Object*> m_Objects;
	glm::mat4 m_View = glm::mat4(1.0f);
	glm::mat4 m_MVP = glm::mat4(1.0f);
	Shader m_Shader;
	Camera m_Camera;
	
};