#include "Object.h"

void Object::TranslateX(const float pos)
{
	m_Position.x = pos;
}

void Object::TranslateY(const float pos)
{
	m_Position.y = pos;
}

void Object::Rotate(float& angle)
{
	m_Rotation = angle;
}

void Object::SetGravity(bool value)
{
	m_Gravity = value;
}

void Object::ModifyMass(float mass)
{
	m_Mass = mass;
}

void Object::SetColor(float r, float g, float b)
{
	m_Color = glm::vec3(r, g, b);
}

void Object::Scale(const float scale)
{
	m_Scale = glm::vec2(scale);
}

void Object::CreateObject(const Shape& shape)
{
	CreateGLMesh(shape.vertices.data(), shape.indices.data(), shape.vertices.size(), shape.indices.size());
}

void Object::CreateObject(const Shape& shape, Texture& texture)
{
	m_Texture = &texture;
	m_HasTexture = true;
	CreateGLMesh(shape.vertices.data(), shape.indices.data(), shape.vertices.size(), shape.indices.size());
}

void Object::DrawObject(const Shader& shader)
{
	shader.UseShader();
	if (m_HasTexture) {
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, m_Texture->GetTextureID());
		shader.SetUniformInt("hasTexture", 1);
	}
	else {
		shader.SetUniformInt("hasTexture", 0);
	}

	glBindVertexArray(m_VAO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
	glDrawElements(GL_TRIANGLES, m_IC, GL_UNSIGNED_INT, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void Object::Update(float ts)
{
	HandleGravity(ts);
}

glm::mat4 Object::HandleModelMatrix() const
{
	glm::mat4 model(1.0f);
	model = glm::translate(model, glm::vec3(m_Position, -1.0f));
	model = glm::rotate(model, glm::radians(m_Rotation), glm::vec3(0.0f, 0.0f, 1.0f));
	model = glm::scale(model, glm::vec3(m_Scale, 1.0f));

	return model;
}

void Object::CreateGLMesh(const GLfloat* vertices, const GLuint* indices, GLuint nV, GLuint nI)
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

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 5, (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 5, (void*)(sizeof(GLfloat) * 3));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	glBindVertexArray(0);
}

void Object::HandleGravity(float ts)
{
	float velocity = 0.0f;
	float acceleration = (m_gAcc * m_Mass) * 0.005f;
	velocity += acceleration * ts;

	std::cout << m_Position.y;

	m_Position.y -= velocity * ts;

	std::cout << m_Position.y << "\n";

	if (m_Position.y <= -1.0f)
		m_Position.y = -1.0f;
}
