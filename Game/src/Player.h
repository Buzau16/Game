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

	void HandleMovement(float ts);

private:
	glm::vec2 m_Direction = glm::vec2(0.0f);
	glm::vec2 m_Velocity = glm::vec2(0.0f);

};

