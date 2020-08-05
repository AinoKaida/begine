#include "MiniginPCH.h"
#include "NotGameObjectAnymore.h"
#include "Scene.h"

dae::NotGameObjectAnymore::NotGameObjectAnymore(unsigned int objectID, std::shared_ptr<dae::Scene> scene)
	: m_ObjectID{ objectID }
	, m_pScene{ scene }
{
}
