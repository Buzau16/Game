#pragma once

#include <SDL2/SDL.h>

#include "Object.h"
#include "Window.h"

class Player : public Object
{
public:

	Player() = default;
	~Player() = default;

	void Render();
	float GetPlayerSpeed() { return m_Speed; };
	void SetPlayerSpeed(float speed) { m_Speed = speed; };

	void HandleMovement(float deltaTime);

private:
	glm::vec2 m_Direction = glm::vec2(0.0f);
	glm::vec2 m_Velocity = glm::vec2(0.0f);
	float m_Speed = 1.f;
};

