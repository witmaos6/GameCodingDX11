#pragma once

struct VertexColorData
{
	Vec3 position = { 0,0,0 };
	Color color = { 0,0,0,0 };

	static vector<D3D11_INPUT_ELEMENT_DESC> descs;
};

struct VertexTextureData
{
	Vec3 position = { 0,0,0 };
	Vec2 uv = { 0,0 }; // min : 0.f, max : 1.0f

	static vector<D3D11_INPUT_ELEMENT_DESC> descs;
};
