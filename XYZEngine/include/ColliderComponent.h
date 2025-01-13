#pragma once

#include "Component.h"
#include "Collision.h"
#include "Trigger.h"

#ifdef XYZENGINE_EXPORTS
#define XYZENGINE_API __declspec(dllexport)
#else
#define XYZENGINE_API __declspec(dllimport)
#endif

namespace Engine
{
	class PhysicsSystem;
	class XYZENGINE_API ColliderComponent : public Component
	{
	public:
		ColliderComponent(GameObject* gameObject);

		virtual void Update(float deltaTime) = 0;
		virtual void Render() = 0;

		void SetTrigger(bool newIsTrigger);

		friend PhysicsSystem;
	protected:
		sf::FloatRect bounds;
		bool isTrigger = false;

		virtual void OnCollision(Collision collision) = 0;
		virtual void OnTriggerEnter(Trigger trigger) = 0;
		virtual void OnTriggerExit(Trigger trigger) = 0;
	};
}