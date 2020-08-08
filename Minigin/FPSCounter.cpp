#include "MiniginPCH.h"
#include "FPSCounter.h"
#include "TimeManager.h"

dae::FPSCounter::FPSCounter(const std::shared_ptr<TextComponent>& pTextComponent)
	: m_FPS{ 0 }
	, m_Accumulator{ 100 }
	, m_Alpha{ 0.005f }
{
	pTextComponent->SetText(std::to_string(m_FPS));
	AddComponent(std::static_pointer_cast<Component>(pTextComponent)); // Derived->Base, no dynamic cast needed
}

void dae::FPSCounter::Update()
{
	m_FPS = unsigned int(1000.f / dae::TimeManager::GetInstance().getDeltaTime());

	std::shared_ptr<TextComponent> textComponent = std::static_pointer_cast<TextComponent>(m_ComponentPointers.at(0));

	// super cool math 
	m_Accumulator = (m_Alpha * m_FPS) + (1.0f - m_Alpha) * m_Accumulator;

	textComponent->SetText(std::to_string(int(m_Accumulator)) + " FPS");
	textComponent->Update();
}

void dae::FPSCounter::Render() const
{
	std::static_pointer_cast<TextComponent>(m_ComponentPointers.at(0))->Render();
}

void dae::FPSCounter::SetPosition(float x, float y)
{
	std::static_pointer_cast<TextComponent>(m_ComponentPointers.at(0))->SetPosition(x, y);
}
