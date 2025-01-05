#pragma once
#include <glm/glm.hpp>


// TODO: Add Camera!!!!!!

class Camera
{
public:
	Camera() = default;
	~Camera() = default;

private:
	glm::vec3 m_Position;
	glm::vec3 m_WorldUp = glm::vec3(0.0f, 1.0f, 0.0f);

};

