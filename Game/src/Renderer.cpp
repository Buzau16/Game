#include "Renderer.h"

void Renderer::Init()
{
	m_Camera = Camera(glm::vec2(0.0f, 0.0f), 1.f);
}
// AABB

void Renderer::Draw(int Width, int Height){

	// Projection Matrix is "recalculated" every draw call. Could be a performance improvement later on...
	glm::mat4 Proj = glm::ortho(0.f, (float)Width, (float)Height, 0.0f, -1.f, 1.f);
	m_Camera.UpdateMatricies(Width, Height);

	for (auto& obj : m_Objects) {

		if (!obj->IsVisible()) {
			continue;
		}

		
		m_MVP = m_Camera.GetViewMatrix() * Proj * obj->HandleModelMatrix();
		m_Shader.SetUnifromVec3("vCol", obj->GetColor());
		m_Shader.SetUniformMatrix("MVP", m_MVP);
		obj->DrawObject(m_Shader);
	}
}

void Renderer::setShader(const Shader& shader)
{
	m_Shader = shader;
}
