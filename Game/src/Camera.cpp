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

	if (m_Zoom > 10.f) m_Zoom = 10.f;
	if (m_Zoom < 0.1f) m_Zoom = 0.1f;

}
void Camera::Move(glm::vec2& value)
{
	m_Position += value;
}
void Camera::Follow(const Object& obj)
{
	m_Position = obj.GetPosition();
}


void Camera::UpdateMatricies(GLfloat Width, GLfloat Height)
{
	std::cout << "Updating camera matrices with: " << Width << "x" << Height << " Zoom: " << m_Zoom << std::endl;
	std::cout << "Position: " << m_Position.x << ", " << m_Position.y << std::endl;

	if (KeyboardHandler::isPressed(SDL_SCANCODE_I)) {
		m_Zoom -= 0.1f;
	}
	if (KeyboardHandler::isPressed(SDL_SCANCODE_O)) {
		m_Zoom += 0.1f;
	}

	m_View = glm::translate(glm::mat4(1.f), glm::vec3(-m_Position, 0.0f));

	glm::mat4 zoomMatrix = glm::scale(glm::mat4(1.f), glm::vec3(m_Zoom, m_Zoom, 1.0f));

	m_View = zoomMatrix * m_View;

	std::cout << "VP Matrix: " << glm::to_string(m_View) << std::endl;
}
