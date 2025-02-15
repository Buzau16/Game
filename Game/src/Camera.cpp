#include "Camera.h"

Camera::Camera(glm::vec2 position, float zoom) : m_Position(position), m_Zoom(zoom)
{
	m_VP = glm::mat4(1.0f);
	m_View = glm::mat4(1.0f);
	m_Proj = glm::mat4(1.0f);
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
	std::cout << "Updating camera matrices with: " << Width << "x" << Height << " Zoom: " << m_Zoom << std::endl;
	std::cout << "Position: " << m_Position.x << ", " << m_Position.y << std::endl;

	m_View = glm::translate(glm::mat4(1.f), glm::vec3(-m_Position, 0.0f));

	m_VP = m_View;

	std::cout << "VP Matrix: " << glm::to_string(m_VP) << std::endl;
}
