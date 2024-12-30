#include "Renderer.h"

void Renderer::Draw()
{
	for (auto& obj : m_Objects) {
		//glm::mat4 model(1.0f);
		m_Shader.SetUniformMatrix("model", obj->HandleModelMatrix());
		obj->DrawObject(m_Shader);
	}
}

void Renderer::setShader(const Shader& shader)
{
	m_Shader = shader;
}