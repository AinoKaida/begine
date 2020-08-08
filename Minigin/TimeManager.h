#pragma once
#include "Singleton.h"
#include "Minigin.h"

namespace dae
{
	// Use to access game elapsed time
	class TimeManager : public Singleton<TimeManager>
	{
	public:
		float getDeltaTime() const;
		float getLag() const;

	private:
		friend class Singleton<TimeManager>;
		friend void Minigin::Run();
		TimeManager() = default;
		float deltaTime;
		float lag;
	};
}