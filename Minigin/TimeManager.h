#pragma once
#include "Singleton.h"

namespace dae
{
	// Use to access game elapsed time
	class TimeManager : public Singleton<TimeManager>
	{
	public:
		void Update(float elapsedTime);
		float getDeltaTime() const;

	private:
		friend class Singleton<TimeManager>;
		TimeManager() = default;
		float deltaTime;
	};
}