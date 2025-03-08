#pragma once
#include <GL/glew.h>
#include <vector>

#include "Object.h"
#include "Player.h"
#include "Window.h"
#include "Camera.h"
#include "Scene.h"


class Renderer {
public:

	static Renderer& GetInstance() {
		static Renderer instance;
		return instance;
	};

	void Init(int Width, int Height);

	void Draw();
	Camera& GetCamera() { return m_Camera; };

	void SetScene(const Scene& scene);
	void SetShader(const Shader& shader);
	
	

private:

	Renderer() = default;
	Renderer(const Renderer&) = delete;
	Renderer& operator=(const Renderer&) = delete;


	int m_Width, m_Height;
	Scene m_Scene;

	glm::mat4 m_View = glm::mat4(1.0f);
	glm::mat4 m_MVP = glm::mat4(1.0f);

	Shader m_Shader;
	Camera m_Camera;
	
};