#pragma once

#include <GL/glew.h>
#include <vector>

struct Shape {
	std::vector<GLfloat> vertices;
	std::vector<GLuint> indices;

	Shape(const std::vector<GLfloat>& v, const std::vector<GLuint>& i) : vertices(v), indices(i) {}
};

namespace Shapes {

	Shape CreateSquare(float l);
	Shape CreateSquare();
	Shape CreateRectangle(float w, float h);
}