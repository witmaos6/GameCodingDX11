#pragma once

#include "Types.h"

struct Vertex
{
	Vec3 position;
	//Color color;
	Vec2 uv; // min : 0.f, max : 1.0f
};

struct TransformData
{
	Matrix matWorld = Matrix::Identity;
	Matrix matView = Matrix::Identity;
	Matrix matProjection = Matrix::Identity;
};
