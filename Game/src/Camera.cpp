#include "Camera.h"

Camera::Camera(glm::vec2 position, float zoom) : m_Position(position), m_Zoom(zoom)
{
}

void Camera::SetPosition(const glm::vec2& pos)
{
	m_Position = pos;
}

void Camera::AdjustZoom(float value)
{
	m_Zoom = value;

	if (m_Zoom > 10.f) m_Zoom = 10.f;
	if (m_Zoom < 0.1f) m_Zoom = 0.1f;

}
void Camera::Move(glm::vec2& value)
{
	m_Position += value;
}
void Camera::Follow(const Object& obj)
{
	m_Position = glm::mix(m_Position, obj.GetPosition(), 0.016);
}


void Camera::UpdateMatricies(GLfloat Width, GLfloat Height)
{
	float left = m_Position.x - (Width / 2) / m_Zoom;
	float right = m_Position.x + (Width / 2) / m_Zoom;
	float up = m_Position.y + (Height / 2) / m_Zoom;
	float down = m_Position.y - (Height / 2) / m_Zoom;

	m_Proj = glm::ortho(left, right, down, up, -1.0f, 1.0f);
	m_View = glm::translate(m_View, glm::vec3(-m_Position, 0.0f));

	m_VP = m_Proj * m_View;
}
