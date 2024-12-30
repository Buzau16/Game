#pragma once
#include <GL/glew.h>
#include <vector>

#include "Object.h"


class Renderer {
public:
	Renderer() = default;
	~Renderer() = default;

	void AddObject(Object* object) { m_Objects.push_back(object); };
	void Draw();

	void setShader(const Shader& shader);

private:
	std::vector<Object*> m_Objects;
	Shader m_Shader;
	
};