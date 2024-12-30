#include "Object.h"

void Object::TranslateX(const float pos)
{
	m_Position.x = pos;
}

void Object::TranslateY(const float pos)
{
	m_Position.y = pos;
}

void Object::TranslateZ(const float pos)
{
	m_Position.z = pos;
}

void Object::RotateX(const float angle)
{
	m_Rotation.x = angle;
}

void Object::RotateY(const float angle)
{
	m_Rotation.y = angle;
}

void Object::RotateZ(const float angle)
{
	m_Rotation.z = angle;
}

void Object::Scale(const float scale)
{
	m_Scale = glm::vec3(scale);
}

void Object::CreateObject(const GLfloat* vertices, const GLuint* indices, GLuint nV, GLuint nI)
{
	m_IC = nI;
	glGenVertexArrays(1, &m_VAO);
	glBindVertexArray(m_VAO);

	glGenBuffers(1, &m_EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * nI, indices, GL_STATIC_DRAW);

	glGenBuffers(1, &m_VBO);
	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * nV, vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 3, (void*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	glBindVertexArray(0);
}

void Object::DrawObject(const Shader& shader)
{
	shader.UseShader();
	glBindVertexArray(m_VAO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
	glDrawElements(GL_TRIANGLES, m_IC, GL_UNSIGNED_INT, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

glm::mat4 Object::HandleModelMatrix() const
{
	glm::mat4 model(1.0f);
	
	model = glm::translate(model, m_Position);
	model = glm::rotate(model, glm::radians(m_Rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
	model = glm::rotate(model, glm::radians(m_Rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
	model = glm::rotate(model, glm::radians(m_Rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
	model = glm::scale(model, m_Scale);

	return model;
}
