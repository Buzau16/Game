#include "Camera.h"

Camera::Camera(glm::vec2 position, float zoom) : m_Position(position), m_Zoom(zoom)
{
	m_View = glm::mat4(1.0f);
}

void Camera::SetPosition(const glm::vec2& pos)
{
	m_Position = pos;
}

void Camera::AdjustZoom(float value)
{
	m_Zoom += value;

	if (m_Zoom > 5.f) m_Zoom = 5.f;
	if (m_Zoom < 0.5f) m_Zoom = 0.5f;
}
void Camera::Move(glm::vec2& value)
{
	m_Position += value;
}
void Camera::Follow(const Object& obj)
{

	m_Position = glm::mix(m_Position, obj.GetPosition(), 0.2);
}


void Camera::UpdateMatricies(GLfloat Width, GLfloat Height)
{

	m_View = glm::translate(glm::mat4(1.f), glm::vec3(-m_Position.x, -m_Position.y, 0.0f));

	glm::mat4 zoomMatrix = glm::scale(glm::mat4(1.f), glm::vec3(m_Zoom, m_Zoom, 1.0f));

	glm::mat4 recenterMatrix = glm::translate(glm::mat4(1.f), glm::vec3(Width / 2, Height / 2, 0.0f));

	m_View = recenterMatrix * zoomMatrix * m_View;

}
