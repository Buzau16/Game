#pragma once
#include <GL/glew.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Shader.h"

class Object {
public:
	Object() = default;
	~Object() = default;

	void TranslateX(const float pos);
	void TranslateY(const float pos);
	void TranslateZ(const float pos);

	void RotateX(const float angle);
	void RotateY(const float angle);
	void RotateZ(const float angle);
	void SetGravity(bool value);
	void ModifyMass(float mass);

	void Scale(const float scale);

	void CreateObject(const GLfloat* vertices, const GLuint* indices, GLuint nV, GLuint nI);
	void DrawObject(const Shader& shader);

	
	void Update(float ts);
	glm::mat4 HandleModelMatrix() const;

private:

	void HandleGravity(float ts);
	bool m_Gravity = 0;
	float m_gAcc = 9.8f;
	float m_Mass = 1.0f;
	
	glm::vec3 m_Position = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 m_Scale = glm::vec3(1.0f, 1.0f, 1.0f);
	glm::vec3 m_Rotation;
	GLuint m_VAO, m_VBO, m_EBO, m_IC;
	

};