#include "Player.h"

void Player::Render()
{

}

void Player::HandleMovement(float ts)
{

	m_Direction = glm::vec2(0.0f);

	if (KeyboardHandler::isPressed(SDL_SCANCODE_W) == 1) {
		m_Direction.y = 1.f;
		std::cout << "up\n";
	}
    if (KeyboardHandler::isPressed(SDL_SCANCODE_S) == 1) {
		m_Direction.y = -1.f;
		std::cout << "down\n";
	}
	if (KeyboardHandler::isPressed(SDL_SCANCODE_D) == 1) {
		m_Direction.x = 1.f;
		std::cout << "right\n";
	}
	if (KeyboardHandler::isPressed(SDL_SCANCODE_A) == 1) {
		m_Direction.x = -1.f;
		std::cout << "left\n";
	}


	if (glm::length(m_Direction) > 0) {
		const float speed = 0.034f;
		m_Direction = glm::normalize(m_Direction);
		m_Velocity = m_Direction * speed;
	}

	m_Velocity = glm::mix(m_Velocity, glm::vec2(0.0f), 0.3f);
	m_Position += m_Velocity;
	m_Position.x = glm::clamp(m_Position.x, -1.0f, 1.0f);
	m_Position.y = glm::clamp(m_Position.y, -1.0f, 1.0f);
}
