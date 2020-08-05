#include "MiniginPCH.h"
#include "TimeManager.h"

void dae::TimeManager::Update(float elapsedTime)
{
    deltaTime = elapsedTime;
}

float dae::TimeManager::getDeltaTime() const
{
    return deltaTime;
}
