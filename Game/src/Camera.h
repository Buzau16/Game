#pragma once
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/string_cast.hpp>
#include "Object.h"
#include "KeyboardHandler.h"
#include <GL/glew.h>


// TODO: Add Camera!!!!!!
// Kinda added? need to fix some things

class Camera
{
public:
	Camera() = default;
	Camera(glm::vec2 position, float zoom);
	~Camera() = default;

	void SetPosition(const glm::vec2& pos);
	void SetZoom(const float value) { m_Zoom = value; };
	glm::vec2 GetPosition() const { return m_Position; };
	glm::mat4 GetViewMatrix() const { return m_View; };
	void AdjustZoom(float value);
	void Move(glm::vec2& value);
	void Follow(const Object& obj);

	void UpdateMatricies(GLfloat Width, GLfloat Height);


private:

	glm::vec2 m_Position = glm::vec2(0.0f, 0.0f);
	float m_Zoom;
	glm::mat4 m_View;
};

