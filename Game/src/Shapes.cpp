#include "Shapes.h"

namespace Shapes {
	Shape CreateSquare(float l) {
		return Shape(
			{ -1.0f * l, -1.0f * l, 0.0f,
			   1.0f * l, -1.0f * l, 0.0f,
			   1.0f * l,  1.0f * l, 0.0f,
			  -1.0f * l,  1.0f * l, 0.0f },
			{ 0, 1, 2,
			 2, 3, 0 });
	}

	Shape CreateSquare() {
		float l = 0.5f;
		return Shape(
			{ -1.0f * l, -1.0f * l, 0.0f,
			   1.0f * l, -1.0f * l, 0.0f,
			   1.0f * l,  1.0f * l, 0.0f,
			  -1.0f * l,  1.0f * l, 0.0f },
			{ 0, 1, 2,
			 2, 3, 0 });
	}

	Shape CreateRectangle(float w, float h) {
		return Shape(
			{ -1.0f * w / 2, -1.0f * h / 2, 0.0f,
			   1.0f * w / 2, -1.0f * h / 2, 0.0f,
			   1.0f * w / 2,  1.0f * h / 2, 0.0f,
			  -1.0f * w / 2,  1.0f * h / 2, 0.0f },
			{ 0, 1, 2,
			 2, 3, 0 });
	}
}