#include "pch.h"
#include "Pipeline.h"

Pipeline::Pipeline(ComPtr<ID3D11DeviceContext> deviceContext)
	:_deviceContext(deviceContext)
{
}

Pipeline::~Pipeline()
{
}

void Pipeline::UpdatePipeline(PipelineInfo info)
{
	_deviceContext->IASetInputLayout(info.inputLayout->GetInputLayout().Get());
	_deviceContext->IASetPrimitiveTopology(info.topology);

	if (info.vertexShader)
	{
		_deviceContext->VSSetShader(info.vertexShader->GetShader().Get(), nullptr, 0);
	}

	if (info.rasterizerState)
	{
		_deviceContext->RSSetState(info.rasterizerState->GetRasterizerState().Get());
	}

	if (info.pixelShader)
	{
		_deviceContext->PSSetShader(info.pixelShader->GetShader().Get(), nullptr, 0);
	}

	if (info.blendState)
	{
		_deviceContext->OMSetBlendState(info.blendState->GetBlendState().Get(), info.blendState->GetBlendFactor(), info.blendState->GetSampleMask());
	}
}

void Pipeline::SetVertexBuffer(shared_ptr<VertexBuffer> buffer)
{
	uint32 stride = buffer->GetStride();
	uint32 offset = buffer->GetOffset();
	_deviceContext->IASetVertexBuffers(0, 1, buffer->GetBuffer().GetAddressOf(), &stride, &offset);
}

void Pipeline::SetIndexBuffer(shared_ptr<IndexBuffer> buffer)
{
	_deviceContext->IASetIndexBuffer(buffer->GetBuffer().Get(), DXGI_FORMAT_R32_UINT, 0);
}

void Pipeline::SetTexture(uint32 slot, uint32 scope, shared_ptr<Texture> texture)
{
	if (scope & SS_VertexShader)
	{
		_deviceContext->VSSetShaderResources(slot, 1, texture->GetSRV().GetAddressOf());
	}
	else if (scope & SS_PixelShader)
	{
		_deviceContext->PSSetShaderResources(slot, 1, texture->GetSRV().GetAddressOf());
	}
}

void Pipeline::SetSamplerState(uint32 slot, uint32 scope, shared_ptr<SamplerState> samplerState)
{
	if (scope & SS_VertexShader)
	{
		_deviceContext->VSSetSamplers(0, 1, samplerState->GetSamplerState().GetAddressOf());
	}
	else if (scope & SS_PixelShader)
	{
		_deviceContext->PSSetSamplers(0, 1, samplerState->GetSamplerState().GetAddressOf());
	}
}

void Pipeline::Draw(uint32 vertexCount, uint32 startVertexLocation)
{
	_deviceContext->Draw(vertexCount, startVertexLocation);
}

void Pipeline::DrawIndexed(uint32 indexCount, uint32 startIndexLocation, uint32 baseVertexLocation)
{
	_deviceContext->DrawIndexed(indexCount, startIndexLocation, baseVertexLocation);
}
