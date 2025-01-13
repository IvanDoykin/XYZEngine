#include "ColliderComponent.h"

namespace Engine
{
	ColliderComponent::ColliderComponent(GameObject* gameObject) : Component(gameObject) {}

	void ColliderComponent::SetTrigger(bool newIsTrigger)
	{
		isTrigger = newIsTrigger;
	}
}