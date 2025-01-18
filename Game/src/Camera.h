#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "Object.h"
#include <GL/glew.h>


// TODO: Add Camera!!!!!!

class Camera
{
public:
	Camera() = default;
	Camera(glm::vec2 position, float zoom);
	~Camera() = default;

	void SetPosition(const glm::vec2& pos);
	void SetZoom(const float value) { m_Zoom = value; };
	glm::vec2 GetPosition() const { return m_Position; };
	glm::mat4 GetVPMatricies() const { return m_VP; };
	void AdjustZoom(float value);
	void Move(glm::vec2& value);
	void Follow(const Object& obj);

	void UpdateMatricies(GLfloat Width, GLfloat Height);


private:

	glm::vec2 m_Position = glm::vec2(0.0f, 0.0f);
	float m_Zoom;
	glm::mat4 m_Proj = glm::mat4(1.0f);
	glm::mat4 m_View = glm::mat4(1.0f);
	glm::mat4 m_VP = glm::mat4(1.0f);
};

