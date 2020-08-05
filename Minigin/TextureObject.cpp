#include "MiniginPCH.h"
#include "TextureObject.h"
#include "ResourceManager.h"
#include "Renderer.h"

dae::TextureObject::~TextureObject() = default;

void dae::TextureObject::Update(){}

void dae::TextureObject::Render() const
{
	const auto pos = m_Transform.GetPosition();
	Renderer::GetInstance().RenderTexture(*m_Texture, pos.x, pos.y);
}

void dae::TextureObject::SetTexture(const std::string& filename)
{
	m_Texture = ResourceManager::GetInstance().LoadTexture(filename);
}

void dae::TextureObject::SetPosition(float x, float y)
{
	m_Transform.SetPosition(x, y, 0.0f);
}
