#pragma once
namespace dae
{
	class Component;
	class SceneObject
	{
	public:
		virtual void Update() = 0;
		virtual void Render() const = 0;

		SceneObject() = default;
		virtual ~SceneObject() = default;
		SceneObject(const SceneObject& other) = delete;
		SceneObject(SceneObject&& other) = delete;
		SceneObject& operator=(const SceneObject& other) = delete;
		SceneObject& operator=(SceneObject&& other) = delete;

		void AddComponent(const std::shared_ptr<Component> pComponent);
		void RemoveComponent(const std::shared_ptr<Component> pComponent);

	protected:
		std::vector<std::shared_ptr<Component>> m_ComponentPointers;
	};
}
