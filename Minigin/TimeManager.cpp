#include "MiniginPCH.h"
#include "TimeManager.h"

float dae::TimeManager::getDeltaTime() const
{
    return deltaTime;
}

float dae::TimeManager::getLag() const
{
    return lag;
}
