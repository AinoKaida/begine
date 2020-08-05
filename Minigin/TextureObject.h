#pragma once
#include "Transform.h"
#include "SceneObject.h"

namespace dae
{
	class Texture2D;
	class TextureObject : public SceneObject
	{
	public:
		void Update() override;
		void Render() const override;

		void SetTexture(const std::string& filename);
		void SetPosition(float x, float y);

		TextureObject() = default;
		virtual ~TextureObject();
		TextureObject(const TextureObject& other) = delete;
		TextureObject(TextureObject&& other) = delete;
		TextureObject& operator=(const TextureObject& other) = delete;
		TextureObject& operator=(TextureObject&& other) = delete;

	private:
		Transform m_Transform;
		std::shared_ptr<Texture2D> m_Texture{};
	};
}
