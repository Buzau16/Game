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

void Object::RotateX(float& angle)
{
	if (angle >= 360.f)
		angle = 0.0f;
	m_Rotation.x = angle;
}

void Object::RotateY(float& angle)
{
	if (angle >= 360.f)
		angle = 0.0f;
	m_Rotation.y = angle;
}

void Object::RotateZ(float& angle)
{
	if (angle >= 360.f)
		angle = 0.0f;
	m_Rotation.z = angle;
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
	m_Scale = glm::vec3(scale);
}

void Object::CreateObject(const Shape& shape)
{
	CreateGLMesh(shape.vertices.data(), shape.indices.data(), shape.vertices.size(), shape.indices.size());
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

void Object::Update(float ts)
{
	HandleGravity(ts);
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

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 3, (void*)0);
	glEnableVertexAttribArray(0);

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
