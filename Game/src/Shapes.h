#pragma once

#include <GL/glew.h>
#include <vector>

struct Shape {
	std::vector<GLfloat> vertices;
	std::vector<GLuint> indices;

	Shape(const std::vector<GLfloat>& v, const std::vector<GLuint>& i) : vertices(v), indices(i) {}
};

namespace Shapes {
	inline Shape CreateSquare(float l) {
		return Shape(
			{ -1.0f * l, -1.0f * l, 0.0f,
			   1.0f * l, -1.0f * l, 0.0f,
			   1.0f * l,  1.0f * l, 0.0f,
			  -1.0f * l,  1.0f * l, 0.0f},
			{ 0, 1, 2,
			 2, 3, 0 });
	}

	inline Shape CreateSquare() {
		float l = 0.5f;
		return Shape(
			{ -1.0f * l, -1.0f * l, 0.0f,
			   1.0f * l, -1.0f * l, 0.0f,
			   1.0f * l,  1.0f * l, 0.0f,
			  -1.0f * l,  1.0f * l, 0.0f },
			{ 0, 1, 2,
			 2, 3, 0 });
	}

	inline Shape CreateRectangle(float w, float h) {
		return Shape(
			{ -1.0f * w/2, -1.0f * h/2, 0.0f,
			   1.0f * w/2, -1.0f * h/2, 0.0f,
			   1.0f * w/2,  1.0f * h/2, 0.0f,
			  -1.0f * w/2,  1.0f * h/2, 0.0f },
			{ 0, 1, 2,
			 2, 3, 0 });
	}
}