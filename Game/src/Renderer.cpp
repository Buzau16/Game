#include "Renderer.h"

void Renderer::Init()
{
	m_Camera = Camera(glm::vec2(0.0f, 0.0f), 1.f);
}

void Renderer::Draw(int Width, int Height)
{
	for (auto& obj : m_Objects) {

		if (!obj->IsVisible()) {
			continue;
		}

		//m_Camera.UpdateMatricies(Width, Height);
		m_MVP = m_Camera.GetVPMatricies() * obj->HandleModelMatrix();
		m_Shader.SetUnifromVec3("vCol", obj->GetColor());
		m_Shader.SetUniformMatrix("MVP", m_MVP);
		obj->DrawObject(m_Shader);
	}
}

void Renderer::setShader(const Shader& shader)
{
	m_Shader = shader;
}
