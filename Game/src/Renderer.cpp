#include "Renderer.h"

void Renderer::Init()
{
	
}

void Renderer::Draw(int Width, int Height, float ts)
{
	for (auto& obj : m_Objects) {

		glm::mat4 m_Proj = glm::perspective(glm::radians(45.0f), (GLfloat)Width / (GLfloat)Height, 0.1f, 100.0f);
		m_MVP = m_Proj * m_View * obj->HandleModelMatrix();

		m_Shader.SetUnifromVec3("vCol", obj->GetColor());
		m_Shader.SetUniformMatrix("MVP", m_MVP);
		obj->DrawObject(m_Shader);
	}
}

void Renderer::setShader(const Shader& shader)
{
	m_Shader = shader;
}