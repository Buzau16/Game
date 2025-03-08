#include "Shapes.h"

// Format: {x, y, z, u, v }
// Indices: { TL, TR, BR, 
//			 BR, BL, TL}

namespace Shapes {
	Shape CreateSquare(float l) {
		return Shape(
			{ -1.0f * l, -1.0f * l, 0.0f, 0.0f, 0.0f,
			   1.0f * l, -1.0f * l, 0.0f, 1.0f, 0.0f,
			   1.0f * l,  1.0f * l, 0.0f, 1.0f, 1.0f,
			  -1.0f * l,  1.0f * l, 0.0f, 0.0f, 1.0f, },
			{ 0, 1, 2,
			 2, 3, 0 });
	}

	Shape CreateSquare() {
		float l = 0.5f;
		return Shape(
			{ -1.0f * l, -1.0f * l, 0.0f, 0.0f, 0.0f,
			   1.0f * l, -1.0f * l, 0.0f, 1.0f, 0.0f,
			   1.0f * l,  1.0f * l, 0.0f, 1.0f, 1.0f,
			  -1.0f * l,  1.0f * l, 0.0f, 0.0f, 1.0f, },
			{ 0, 1, 2,
			 2, 3, 0 });
	}

	Shape CreateRectangle(float w, float h) {
		return Shape(
			{ -1.0f * w, -1.0f * h, 0.0f, 0.0f, 0.0f,
			   1.0f * w, -1.0f * h, 0.0f, 1.0f, 0.0f,
			   1.0f * w,  1.0f * h, 0.0f, 1.0f, 1.0f,
			  -1.0f * w,  1.0f * h, 0.0f, 0.0f, 1.0f, },
			{ 0, 1, 2,
			 2, 3, 0 });
	}
}