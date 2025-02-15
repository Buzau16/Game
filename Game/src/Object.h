#pragma once
#include <GL/glew.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Shader.h"
#include "Shapes.h"
#include "Texture.h"

class Object {
public:
	Object() = default;
	~Object() = default;

	void TranslateX(const float pos);
	void TranslateY(const float pos);
	
	void Translate(const float x, const float y);

	void Rotate(float& angle);

	void SetGravity(bool value);
	void ModifyMass(float mass);
	void SetColor(float r, float g, float b);
	inline glm::vec3 GetColor() const { return m_Color; };
	bool IsVisible() const { return m_IsVisible; };
	void SetObjectVisible(bool value) { m_IsVisible = value; };

	void Scale(const float scale);

	void CreateObject(const Shape& shape);
	void CreateObject(const Shape& shape, Texture& texture);
	void DrawObject(const Shader& shader);

	
	void Update(float ts);
	glm::mat4 HandleModelMatrix() const;
	glm::vec2 GetPosition() const { return m_Position; };

protected:

	void CreateGLMesh(const GLfloat* vertices, const GLuint* indices, GLuint nV, GLuint nI);

	void HandleGravity(float ts);
	bool m_Gravity = 0;
	float m_gAcc = 9.0f;
	float m_Mass = 1.0f;

	glm::vec3 m_Color = glm::vec3(1.0f, 1.0f, 1.0f);
	glm::vec2 m_Position = glm::vec2(0.0f, 0.0f);
	glm::vec2 m_Scale = glm::vec2(1.0f, 1.0f);
	GLfloat m_Rotation = 0.0f;
	GLuint m_VAO = 0, m_VBO = 0, m_EBO = 0, m_IC = 0;
	bool m_IsVisible = true;

	Texture* m_Texture;
	bool m_HasTexture = false;
};