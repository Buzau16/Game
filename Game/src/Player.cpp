#include "Player.h"

void Player::HandleMovement(float deltaTime)
{
	m_Direction = glm::vec2(0.0f);

	if (KeyboardHandler::isPressed(SDL_SCANCODE_W)) {
		m_Direction.y = -1.f;
	}
    if (KeyboardHandler::isPressed(SDL_SCANCODE_S)) {
		m_Direction.y = 1.f;
	}
	if (KeyboardHandler::isPressed(SDL_SCANCODE_D)) {
		m_Direction.x = 1.f;
	}
	if (KeyboardHandler::isPressed(SDL_SCANCODE_A)) {
		m_Direction.x = -1.f;
	}


	if (glm::length(m_Direction) > 0) {
		m_Direction = glm::normalize(m_Direction);
		m_Velocity = m_Direction * m_Speed * deltaTime;
	}

	m_Velocity = glm::mix(m_Velocity, glm::vec2(0.0f), 0.23f);
	m_Position += m_Velocity;
}
