#include "DestroySelfComponent.h"

namespace Engine
{
	DestroySelfComponent::DestroySelfComponent(GameObject* gameObject) : Component(gameObject) {}

	void DestroySelfComponent::Update(float deltaTime)
	{
		std::cout << "Try destroy " << gameObject << std::endl;
		GameWorld::Instance()->DestroyGameObject(gameObject);
	};

	void DestroySelfComponent::Render()
	{

	};
}