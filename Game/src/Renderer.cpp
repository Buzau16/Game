#include "Renderer.h"

void Renderer::Init(int Width, int Height)
{
	m_Width = Width;
	m_Height = Height;
	m_Camera = Camera(glm::vec2(0.0f, 0.0f), 1.f);
}
// AABB

void Renderer::Draw(){

	// Projection Matrix is "recalculated" every draw call. Could be a performance improvement later on...
	glm::mat4 Proj = glm::ortho(0.f, (float)m_Width, (float)m_Height, 0.0f, -1.f, 1.f);
	m_Camera.UpdateMatricies(m_Width, m_Height);

	for (auto& obj : m_Scene.GetObjects()) {

		if (!obj->IsVisible()) {
			continue;
		}

		m_MVP = Proj * m_Camera.GetViewMatrix() * obj->HandleModelMatrix();
		m_Shader.SetUnifromVec3("vCol", obj->GetColor());
		m_Shader.SetUniformMatrix("MVP", m_MVP);
		obj->DrawObject(m_Shader);
	}
}

void Renderer::SetScene(const Scene& scene)
{
	m_Scene = scene;
}

void Renderer::SetShader(const Shader& shader)
{
	m_Shader = shader;
}
