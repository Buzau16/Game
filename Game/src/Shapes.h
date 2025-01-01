#pragma once

#include <GL/glew.h>
#include <vector>

struct Shape {
	std::vector<GLfloat> vertices;
	std::vector<GLuint> indices;

	Shape(const std::vector<GLfloat>& v, const std::vector<GLuint>& i) : vertices(v), indices(i) {}
};

namespace Shapes {
	inline Shape CreateSquare() {
		return Shape(
			{ -1.0f, -1.0f, 0.0f,
			   1.0f, -1.0f, 0.0f,
			   1.0f,  1.0f, 0.0f,
			  -1.0f,  1.0f, 0.0f },
			{ 0, 1, 2,
			 2, 3, 0 });
	}
}