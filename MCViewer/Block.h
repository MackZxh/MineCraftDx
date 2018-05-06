#pragma once
#include <d3d11_4.h>
#include <DirectXMath.h>
#include <wrl.h>
#include "SimpleMath.h"
#include "Geometry.h"
#include <Effects.h>
#include <DirectXHelpers.h>

namespace
{
	using FaceVertexType = DirectX::VertexPositionNormalTexture;

	// Helper for creating a D3D vertex or index buffer.
	template<typename T>
	void CreateBuffer(_In_ ID3D11Device* device, T const& data, D3D11_BIND_FLAG bindFlags, _Outptr_ ID3D11Buffer** pBuffer)
	{
		assert(pBuffer != 0);

		D3D11_BUFFER_DESC bufferDesc = {};

		bufferDesc.ByteWidth = (UINT)data.size() * sizeof(typename T::value_type);
		bufferDesc.BindFlags = bindFlags;
		bufferDesc.Usage = D3D11_USAGE_DEFAULT;

		D3D11_SUBRESOURCE_DATA dataDesc = {};

		dataDesc.pSysMem = data.data();

		ThrowIfFailed(
			device->CreateBuffer(&bufferDesc, &dataDesc, pBuffer)
		);

		_Analysis_assume_(*pBuffer != 0);

		SetDebugObjectName(*pBuffer, "DirectXTK:GeometricPrimitive");
	}


	// Helper for creating a D3D input layout.
	void CreateInputLayout(_In_ ID3D11Device* device, DirectX::IEffect* effect, _Outptr_ ID3D11InputLayout** pInputLayout)
	{
		assert(pInputLayout != 0);

		void const* shaderByteCode;
		size_t byteCodeLength;

		effect->GetVertexShaderBytecode(&shaderByteCode, &byteCodeLength);

		HRESULT hr = device->CreateInputLayout(
			FaceVertexType::InputElements,
			FaceVertexType::InputElementCount,
			shaderByteCode, byteCodeLength,
			pInputLayout);
		if (FAILED(hr)) {
			throw "Failed to create input layout.";
		};

		_Analysis_assume_(*pInputLayout != 0);

		DirectX::SetDebugObjectName(*pInputLayout, "DirectXTK:GeometricPrimitive");
	}
}

namespace MC {

using namespace DirectX;

	class Block
	{
		//FaceVertexType m_Faces[6][4];
	public:
		enum Faces {
			down = 0, up = 1, north = 2, south = 3, west = 4, east = 5
		};
		Block() {
			//m_Faces[down][0] = { XMFLOAT3{-0.5f, -0.5f, -0.5f},XMFLOAT2{0.0f, 0.0f} };
			//m_Faces[down][1] = { XMFLOAT3{0.5f, -0.5f, -0.5f},XMFLOAT2{1.0f, 0.0f} };
			//m_Faces[down][2] = { XMFLOAT3{0.5f, -0.5f, 0.5f},XMFLOAT2{1.0f, 1.0f} };
			//m_Faces[down][3] = { XMFLOAT3{-0.5f, -0.5f, 0.5f},XMFLOAT2{0.0f, 1.0f} };
			//m_Faces[up][0] = { XMFLOAT3{-0.5f, 0.5f, 0.5f},XMFLOAT2{0.0f, 0.0f} };
			//m_Faces[up][1] = { XMFLOAT3{0.5f, 0.5f, 0.5f},XMFLOAT2{1.0f, 0.0f} };
			//m_Faces[up][2] = { XMFLOAT3{0.5f, 0.5f, -0.5f},XMFLOAT2{1.0f, 1.0f} };
			//m_Faces[up][3] = { XMFLOAT3{-0.5f, 0.5f, -0.5f},XMFLOAT2{0.0f, 1.0f} };
			//m_Faces[north][0] = { XMFLOAT3{0.5f, 0.5f, 0.5f},XMFLOAT2{0.0f, 0.0f} };
			//m_Faces[north][1] = { XMFLOAT3{-0.5f, 0.5f, 0.5f},XMFLOAT2{1.0f, 0.0f} };
			//m_Faces[north][2] = { XMFLOAT3{-0.5f, -0.5f, 0.5f},XMFLOAT2{1.0f, 1.0f} };
			//m_Faces[north][3] = { XMFLOAT3{0.5f, -0.5f, 0.5f},XMFLOAT2{0.0f, 1.0f} };
			//m_Faces[south][0] = { XMFLOAT3{-0.5f, 0.5f, -0.5f},XMFLOAT2{0.0f, 0.0f} };
			//m_Faces[south][1] = { XMFLOAT3{0.5f, 0.5f, -0.5f},XMFLOAT2{1.0f, 0.0f} };
			//m_Faces[south][2] = { XMFLOAT3{0.5f, -0.5f, -0.5f},XMFLOAT2{1.0f, 1.0f} };
			//m_Faces[south][3] = { XMFLOAT3{-0.5f, -0.5f, -0.5f},XMFLOAT2{0.0f, 1.0f} };
			//m_Faces[west][0] = { XMFLOAT3{-0.5f, 0.5f, 0.5f},XMFLOAT2{0.0f, 0.0f} };
			//m_Faces[west][1] = { XMFLOAT3{-0.5f, 0.5f, -0.5f},XMFLOAT2{1.0f, 0.0f} };
			//m_Faces[west][2] = { XMFLOAT3{-0.5f, -0.5f, -0.5f},XMFLOAT2{1.0f, 1.0f} };
			//m_Faces[west][3] = { XMFLOAT3{-0.5f, -0.5f, 0.5f},XMFLOAT2{0.0f, 1.0f} };
			//m_Faces[east][0] = { XMFLOAT3{0.5f, 0.5f, -0.5f},XMFLOAT2{0.0f, 0.0f} };
			//m_Faces[east][1] = { XMFLOAT3{0.5f, 0.5f, 0.5f},XMFLOAT2{1.0f, 0.0f} };
			//m_Faces[east][2] = { XMFLOAT3{0.5f, -0.5f, 0.5f},XMFLOAT2{1.0f, 1.0f} };
			//m_Faces[east][3] = { XMFLOAT3{0.5f, -0.5f, -0.5f},XMFLOAT2{0.0f, 1.0f} };
		};

		Block(Block const&) = delete;
		Block& operator=(Block const&) = delete;
		//Block(ID3D11Device* device, ID3D11DeviceContext* deviceContext, int x, int y, int z) {
		//	m_gpBox = DirectX::GeometricPrimitive::CreateBox(deviceContext, DirectX::XMFLOAT3(1.0f, 1.0f, 1.0f));
		//	m_world = DirectX::SimpleMath::Matrix::CreateWorld(DirectX::SimpleMath::Vector3::Vector3((float)x, (float)y, (float)z),
		//		DirectX::SimpleMath::Vector3::Backward,
		//		DirectX::SimpleMath::Vector3::Up);
		//};
		void XM_CALLCONV Draw(ID3D11DeviceContext* deviceContext,
			DirectX::BasicEffect* effect,
			DirectX::CXMMATRIX view,
			DirectX::CXMMATRIX projection) const
		{
			effect->SetMatrices(DirectX::XMMatrixIdentity(), view, projection);

			effect->SetColorAndAlpha(Colors::Yellow);
			effect->EnableDefaultLighting();
			effect->SetTextureEnabled(false);
			deviceContext->IASetInputLayout(this->m_inputlayout.Get());
			effect->Apply(deviceContext);

			deviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
			deviceContext->IASetIndexBuffer(this->m_IndexBuffer.Get(), DXGI_FORMAT_R16_UINT, 0);
			UINT stride = sizeof(FaceVertexType);
			UINT offset = 0;
			deviceContext->IASetVertexBuffers(0, 1, m_VertexBuffer.GetAddressOf(), &stride, &offset);
			for (int i = 0; i < 6; i++) {
				//effect->SetTexture(m_Textures[i].Get());
				//effect->Apply(deviceContext);

				deviceContext->DrawIndexed(6, i * 6, 0);
			}
		};

		void Reset() {
			//m_gpBox.reset();
			m_IndexBuffer.Reset();
			m_VertexBuffer.Reset();
			m_inputlayout.Reset();
			for (int i = 0; i < 6; i++) {
				m_Textures[i].Reset();
			}
		}

		HRESULT Initialize(ID3D11Device* device, DirectX::BasicEffect* effect) {

			//DirectX::VertexPositionColorTexture vertices[] = {
			//	{ XMFLOAT3{ -0.5f, -0.5f, -0.5f },XMFLOAT4{ 0.0f, 1.0f, 0.0f, 1.0f }, XMFLOAT2{ 0.0f, 1.0f } },
			//{ XMFLOAT3{ -0.5f, 0.5f, -0.5f },XMFLOAT4{ 0.0f, 1.0f, 0.0f, 1.0f },  XMFLOAT2{ 0.0f, 0.0f } },
			//{ XMFLOAT3{ 0.5f, 0.5f, -0.5f }, XMFLOAT4{ 0.0f, 1.0f, 0.0f, 1.0f }, XMFLOAT2{ 1.0f, 0.0f } },
			//{ XMFLOAT3{ 0.5f, -0.5f, -0.5f }, XMFLOAT4{ 0.0f, 1.0f, 0.0f, 1.0f }, XMFLOAT2{ 1.0f, 0.0f } },
			//{ XMFLOAT3{ -0.5f, -0.5f, 0.5f }, XMFLOAT4{ 0.0f, 1.0f, 0.0f, 1.0f }, XMFLOAT2{ 1.0f, 1.0f } },
			//{ XMFLOAT3{ -0.5f, 0.5f, 0.5f },XMFLOAT4{ 0.0f, 1.0f, 0.0f, 1.0f },  XMFLOAT2{ 1.0f, 0.0f } },
			//{ XMFLOAT3{ 0.5f, 0.5f, 0.5f },XMFLOAT4{ 0.0f, 1.0f, 0.0f, 1.0f },  XMFLOAT2{ 1.0f, 1.0f } },
			//{ XMFLOAT3{ 0.5f, -0.5f, 0.5f },XMFLOAT4{ 0.0f, 1.0f, 0.0f, 1.0f },  XMFLOAT2{ 0.0f, 1.0f } },
			//};

			//FaceVertexType vertices[] = {
			//{ XMFLOAT3{ -0.5f, -0.5f, -0.5f },XMFLOAT3{ -0.5f, -0.5f, -0.5f },XMFLOAT2{ 0.0f, 0.0f } },
			//{ XMFLOAT3{ 0.5f, -0.5f, -0.5f },XMFLOAT2{ 1.0f, 0.0f } },
			//{ XMFLOAT3{ 0.5f, -0.5f, 0.5f },XMFLOAT2{ 1.0f, 1.0f } },
			//{ XMFLOAT3{ -0.5f, -0.5f, 0.5f },XMFLOAT2{ 0.0f, 1.0f } },
			//{   XMFLOAT3{ -0.5f, 0.5f, 0.5f },XMFLOAT2{ 0.0f, 0.0f } },
			//{   XMFLOAT3{ 0.5f, 0.5f, 0.5f },XMFLOAT2{ 1.0f, 0.0f } },
			//{   XMFLOAT3{ 0.5f, 0.5f, -0.5f },XMFLOAT2{ 1.0f, 1.0f } },
			//{ XMFLOAT3{ -0.5f, 0.5f, -0.5f },XMFLOAT2{ 0.0f, 1.0f } },
			// { XMFLOAT3{ 0.5f, 0.5f, 0.5f },XMFLOAT2{ 0.0f, 0.0f } },
			// { XMFLOAT3{ -0.5f, 0.5f, 0.5f },XMFLOAT2{ 1.0f, 0.0f } },
			// { XMFLOAT3{ -0.5f, -0.5f, 0.5f },XMFLOAT2{ 1.0f, 1.0f } },
			// { XMFLOAT3{ 0.5f, -0.5f, 0.5f },XMFLOAT2{ 0.0f, 1.0f } },
			// { XMFLOAT3{ -0.5f, 0.5f, -0.5f },XMFLOAT2{ 0.0f, 0.0f } },
			// { XMFLOAT3{ 0.5f, 0.5f, -0.5f },XMFLOAT2{ 1.0f, 0.0f } },
			// { XMFLOAT3{ 0.5f, -0.5f, -0.5f },XMFLOAT2{ 1.0f, 1.0f } },
			// { XMFLOAT3{ -0.5f, -0.5f, -0.5f },XMFLOAT2{ 0.0f, 1.0f } },
			//{ XMFLOAT3{ -0.5f, 0.5f, 0.5f },XMFLOAT2{ 0.0f, 0.0f } },
			//{ XMFLOAT3{ -0.5f, 0.5f, -0.5f },XMFLOAT2{ 1.0f, 0.0f } },
			//{ XMFLOAT3{ -0.5f, -0.5f, -0.5f },XMFLOAT2{ 1.0f, 1.0f } },
			//{ XMFLOAT3{ -0.5f, -0.5f, 0.5f },XMFLOAT2{ 0.0f, 1.0f } },
			//{ XMFLOAT3{ 0.5f, 0.5f, -0.5f },XMFLOAT2{ 0.0f, 0.0f } },
			//{ XMFLOAT3{ 0.5f, 0.5f, 0.5f },XMFLOAT2{ 1.0f, 0.0f } },
			//{ XMFLOAT3{ 0.5f, -0.5f, 0.5f },XMFLOAT2{ 1.0f, 1.0f } },
			//{ XMFLOAT3{ 0.5f, -0.5f, -0.5f },XMFLOAT2{ 0.0f, 1.0f } }
			//};
			//short indices[] = { 0, 1, 3, 2, 1, 3,
			//4, 5, 7, 6, 5, 7,
			//8, 9, 11, 10, 9, 11,
			//12, 13, 15, 14, 13, 15,
			//16, 17, 19, 18, 17, 19,
			//20, 21, 23, 22, 21, 23 };

			VertexCollection vertices;
			IndexCollection indices;
			ComputeBox(vertices, indices, XMFLOAT3(1.0f, 1.0f, 1.0f), false, false);

			CreateBuffer(device, vertices, D3D11_BIND_VERTEX_BUFFER, m_VertexBuffer.ReleaseAndGetAddressOf());
			CreateBuffer(device, indices, D3D11_BIND_INDEX_BUFFER, m_IndexBuffer.ReleaseAndGetAddressOf());

			effect->SetTextureEnabled(true);
			CreateInputLayout(device, effect, this->m_inputlayout.ReleaseAndGetAddressOf());

			//D3D11_BUFFER_DESC bfdesc{ 0 };
			//bfdesc.Usage = D3D11_USAGE_DEFAULT;
			//bfdesc.ByteWidth = sizeof(uint16_t) * indices.size();
			//bfdesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
			//D3D11_SUBRESOURCE_DATA initData = { 0 };
			//initData.pSysMem = indices.data();
			//HRESULT hr = device->CreateBuffer(&bfdesc, &initData, &m_IndexBuffer);

			//bfdesc.ByteWidth = sizeof(FaceVertexType) * vertices.size();
			//bfdesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
			//initData.pSysMem = vertices.data();
			//hr = device->CreateBuffer(&bfdesc, &initData, &m_VertexBuffer);

			//void const* shaderByteCode;
			//size_t byteCodeLength;
			//effect->GetVertexShaderBytecode(&shaderByteCode, &byteCodeLength);

			//hr = device->CreateInputLayout(FaceVertexType::InputElements, FaceVertexType::InputElementCount,
			//	shaderByteCode, byteCodeLength,
			//	this->m_inputlayout.ReleaseAndGetAddressOf());

			return S_OK;
		}

		void AddTexture(enum Faces face, ID3D11ShaderResourceView* texture) {
			m_Textures[face] = texture;
		};
	private:
		//std::unique_ptr<DirectX::GeometricPrimitive> m_gpBox;
		DirectX::SimpleMath::Matrix m_world;
		//DirectX::XMMATRIX
		Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> m_Textures[6];
		Microsoft::WRL::ComPtr<ID3D11Buffer> m_VertexBuffer;
		Microsoft::WRL::ComPtr<ID3D11Buffer> m_IndexBuffer;
		Microsoft::WRL::ComPtr<ID3D11InputLayout> m_inputlayout;
	};

}