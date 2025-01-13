#pragma once

#ifdef XYZENGINE_EXPORTS
#define XYZENGINE_API __declspec(dllexport)
#else
#define XYZENGINE_API __declspec(dllimport)
#endif

namespace Engine
{
	class GameObject;

	class XYZENGINE_API Component
	{
	public:
		Component(GameObject* gameObject);
		virtual ~Component();

		virtual void Update(float deltaTime) = 0;
		virtual void Render() = 0;

		GameObject* GetGameObject();
	protected:
		GameObject* gameObject;
	};
}