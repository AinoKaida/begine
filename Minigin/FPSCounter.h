#pragma once
#include "SceneObject.h"
#include "TextComponent.h"

namespace dae
{
	class FPSCounter final : public SceneObject
	{
	public:
		explicit FPSCounter(const std::shared_ptr<TextComponent>& pTextComponent);
		virtual void Update() override;
		virtual void Render() const override;
		void SetPosition(float x, float y);

	private:
		unsigned int m_FPS;
		float m_Accumulator;
		const float m_Alpha;
	};
}

