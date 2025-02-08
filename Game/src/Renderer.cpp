#include "Renderer.h"

void Renderer::Init()
{
	//m_Camera = Camera(glm::vec2(0.0f, 0.0f), 5.f);
}
// AABB

void Renderer::Draw(int Width, int Height){

	glm::mat4 Proj = glm::ortho(0.f, (float)Width, 0.0f, (float)Height);

	for (auto& obj : m_Objects) {

		if (!obj->IsVisible()) {
			continue;
		}

		
		m_MVP = obj->HandleModelMatrix() * Proj;
		m_Shader.SetUnifromVec3("vCol", obj->GetColor());
		m_Shader.SetUniformMatrix("MVP", m_MVP);
		obj->DrawObject(m_Shader);
	}
}

void Renderer::setShader(const Shader& shader)
{
	m_Shader = shader;
}
