#include "FPSCountComponent.h"
#include <iostream>

namespace Engine
{
	FPSCountComponent::FPSCountComponent(GameObject* gameObject) : Component(gameObject) {}

	void FPSCountComponent::Update(float deltaTime)
	{
		frames += 1;
		seconds += deltaTime;

		if (seconds > 1.0f)
		{
			seconds -= 1.0f;
			std::cout << frames << std::endl;
			frames = 0;
		}
	}

	void FPSCountComponent::Render()
	{

	}
}