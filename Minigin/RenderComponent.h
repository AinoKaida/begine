#pragma once
#include "Component.h"
#include "Transform.h"

namespace dae
{
	class RenderComponent : public Component
	{
	public:
		explicit RenderComponent();
		virtual void Update() override;
		virtual void Render() const override;
		virtual ~RenderComponent();

	private:
		Transform m_Transform;
	};
}

