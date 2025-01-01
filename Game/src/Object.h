#pragma once
#include <GL/glew.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Shader.h"
#include "Shapes.h"

class Object {
public:
	Object() = default;
	~Object() = default;

	void TranslateX(const float pos);
	void TranslateY(const float pos);
	void TranslateZ(const float pos);

	void RotateX(float& angle);
	void RotateY(float& angle);
	void RotateZ(float& angle);
	void SetGravity(bool value);
	void ModifyMass(float mass);
	void SetColor(float r, float g, float b);
	glm::vec3 GetColor() { return m_Color; };

	void Scale(const float scale);

	void CreateObject(const Shape& shape);
	void DrawObject(const Shader& shader);

	
	void Update(float ts);
	glm::mat4 HandleModelMatrix() const;

private:

	void CreateGLMesh(const GLfloat* vertices, const GLuint* indices, GLuint nV, GLuint nI);
	void HandleGravity(float ts);
	bool m_Gravity = 0;
	float m_gAcc = 9.0f;
	float m_Mass = 1.0f;

	glm::vec3 m_Color = glm::vec3(1.0f, 1.0f, 1.0f);
	glm::vec3 m_Position = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 m_Scale = glm::vec3(1.0f, 1.0f, 1.0f);
	glm::vec3 m_Rotation = glm::vec3(0.0f);
	GLuint m_VAO = 0, m_VBO = 0, m_EBO = 0, m_IC = 0;
	

};