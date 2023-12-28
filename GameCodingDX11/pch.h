#pragma once

#define _XM_NO_INTRINSICS_

#include "Types.h"
#include "Values.h"
#include "Struct.h"

#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <string>
#include <iostream>
using namespace std;

#include <windows.h>
#include <assert.h>

#include <d3d11.h>
#include <d3dcompiler.h>
#include <wrl.h>
#include <DirectXMath.h>
#include <DirectXTex/DirectXTex.h>
#include <DirectXTex/DirectXTex.inl>
using namespace DirectX;
using namespace Microsoft::WRL;

#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "d3dcompiler.lib")

#ifdef _DEBUG
#pragma comment(lib, "DirectXTex\\DirectXTex_debug.lib")
#else
#pragma comment(lib, "DirectXTex\\DirectXTex.lib")
#endif

#define CHECK(p)	assert(SUCCEEDED(p))

// Engine
#include "Graphics.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "InputLayout.h"
#include "Geometry.h"
#include "VertexData.h"
#include "GeometryHelper.h"
#include "Shader.h"
#include "ConstantBuffer.h"
#include "Texture.h"
#include "RasterizerState.h"
#include "SamplerState.h"
#include "BlendState.h"
#include "Pipeline.h"
