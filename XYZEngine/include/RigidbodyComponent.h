#pragma once

#include "Component.h"
#include <SFML/System/Vector2.hpp>
#include "TransformComponent.h"

#ifdef XYZENGINE_EXPORTS
#define XYZENGINE_API __declspec(dllexport)
#else
#define XYZENGINE_API __declspec(dllimport)
#endif

namespace Engine
{
	class XYZENGINE_API RigidbodyComponent : public Component
	{
	public:
		RigidbodyComponent(GameObject* gameObject);

		void Update(float deltaTime) override;
		void Render() override;

		void SetLinearVelocity(sf::Vector2f newLinearVelocity);
		void AddLinearVelocity(sf::Vector2f linearOffset);
		sf::Vector2f GetLinearVelocity() const;

		void SetAngleVelocity(float newAngleVelocity);
		void AddAngleVelocity(float angleOffset);
		float GetAngleVelocity() const;

		void SetLinearDamping(float newLinearDamping);
		float GetLinearDamping() const;

		void SetAngleDamping(float newAngleDamping);
		float GetAngleDamping() const;

		void SetKinematic(bool newIsKinematic);
		bool GetKinematic() const;
	private:
		TransformComponent* transform;

		sf::Vector2f linearVelocity = { 0.f, 0.f };
		float angleVelocity = 0.f;

		float linearDamping = 0.f;
		float angleDamping = 0.f;

		bool isKinematic = false;
	};
}