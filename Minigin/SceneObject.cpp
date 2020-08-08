#include "MiniginPCH.h"
#include "SceneObject.h"

void dae::SceneObject::AddComponent(const std::shared_ptr<Component> pComponent)
{
	m_ComponentPointers.push_back(pComponent);
}

void dae::SceneObject::RemoveComponent(const std::shared_ptr<Component> pComponent)
{
	m_ComponentPointers.erase(std::find(m_ComponentPointers.cbegin(), m_ComponentPointers.cend(), pComponent));
}
