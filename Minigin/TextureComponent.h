#pragma once
#include "Transform.h"
#include "Component.h"

namespace dae
{
	class Texture2D;
	class TextureComponent : public Component
	{
	public:
		void Update() override;
		void Render() const override;

		void SetTexture(const std::string& filename);
		void SetPosition(float x, float y);

		TextureComponent() = default;
		virtual ~TextureComponent();
		TextureComponent(const TextureComponent& other) = delete;
		TextureComponent(TextureComponent&& other) = delete;
		TextureComponent& operator=(const TextureComponent& other) = delete;
		TextureComponent& operator=(TextureComponent&& other) = delete;

	private:
		Transform m_Transform;
		std::shared_ptr<Texture2D> m_Texture{};
	};
}
