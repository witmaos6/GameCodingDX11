#pragma once

#include "Types.h"

struct Vertex
{
	Vec3 position;
	//Color color;
	Vec2 uv; // min : 0.f, max : 1.0f
};

struct TransformData // struct alignas(32) TransformData
{
	Vec3 offset;
	float dummy; // Possible replace padding
};
