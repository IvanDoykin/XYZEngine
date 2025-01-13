#include "RigidbodyComponent.h"
#include <stdlib.h>

namespace Engine
{
	RigidbodyComponent::RigidbodyComponent(GameObject* gameObject) : Component(gameObject) 
	{
		transform = gameObject->GetComponent<TransformComponent>();
	}

	void RigidbodyComponent::Update(float deltaTime)
	{
		transform->MoveBy(linearVelocity);
		transform->RotateBy(angleVelocity);

		linearVelocity = (1.f - linearDamping * deltaTime) * linearVelocity;
		angleVelocity = (1.f - angleDamping * deltaTime) * angleVelocity;

		if (linearVelocity.x < 0.001f)
		{
			linearVelocity = { 0.f, linearVelocity.y };
		}
		if (linearVelocity.y < 0.001f)
		{
			linearVelocity = { linearVelocity.x, 0.f };
		}

		if (angleVelocity < 0.001f)
		{
			angleVelocity = 0.f;
		}
	}
	void RigidbodyComponent::Render()
	{

	}

	void RigidbodyComponent::SetLinearVelocity(sf::Vector2f newLinearVelocity)
	{
		linearVelocity = newLinearVelocity;
	}
	void RigidbodyComponent::AddLinearVelocity(sf::Vector2f linearOffset)
	{
		linearVelocity += linearOffset;
	}
	sf::Vector2f RigidbodyComponent::GetLinearVelocity() const
	{
		return linearVelocity;
	}

	void RigidbodyComponent::SetAngleVelocity(float newAngleVelocity)
	{
		angleVelocity = newAngleVelocity;
	}
	void RigidbodyComponent::AddAngleVelocity(float angleOffset)
	{
		angleVelocity += angleOffset;
	}
	float RigidbodyComponent::GetAngleVelocity() const
	{
		return angleVelocity;
	}

	void RigidbodyComponent::SetLinearDamping(float newLinearDamping)
	{
		linearDamping = newLinearDamping;
	}
	float RigidbodyComponent::GetLinearDamping() const
	{
		return linearDamping;
	}

	void RigidbodyComponent::SetAngleDamping(float newAngleDamping)
	{
		angleDamping = newAngleDamping;
	}
	float RigidbodyComponent::GetAngleDamping() const
	{
		return angleDamping;
	}

	void RigidbodyComponent::SetKinematic(bool newIsKinematic)
	{
		isKinematic = newIsKinematic;
	}
	bool RigidbodyComponent::GetKinematic() const
	{
		return isKinematic;
	}
}