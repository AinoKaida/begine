#pragma once

namespace dae
{
	class Scene;
	class NotGameObjectAnymore
	{
	public:

		NotGameObjectAnymore() = default;
		NotGameObjectAnymore(unsigned int objectID, std::shared_ptr<Scene> scene);
		NotGameObjectAnymore(NotGameObjectAnymore&) = delete;
		NotGameObjectAnymore(NotGameObjectAnymore&&) = delete;
		NotGameObjectAnymore& operator=(NotGameObjectAnymore&) = delete;
		NotGameObjectAnymore& operator=(NotGameObjectAnymore&&) = delete;
		~NotGameObjectAnymore() = default;

	private:
		unsigned int m_ObjectID;
		std::shared_ptr<Scene> m_pScene;
	};
}
