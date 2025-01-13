#include "DelayActionComponent.h"
#include <iostream>

namespace Engine
{
	DelayActionComponent::DelayActionComponent(GameObject* gameObject) : Component(gameObject) {}

	void DelayActionComponent::Update(float deltaTime)
	{
		if (isActive)
		{
			time -= deltaTime;
			if (time <= 0)
			{
				action();
				isActive = false;

				if (callback)
				{
					callback();
				}
			}
		}
	}

	void DelayActionComponent::Render() 
	{

	}

	void DelayActionComponent::SetAction(std::function<void()> newAction, std::function<void()> newCallback)
	{
		action = newAction;
		callback = newCallback;
	}
	void DelayActionComponent::Invoke(float newTime)
	{
		time = newTime;
		isActive = true;
	}
}