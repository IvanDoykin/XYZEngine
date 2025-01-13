#include "SpriteColliderComponent.h"

namespace Engine
{
	SpriteColliderComponent::SpriteColliderComponent(GameObject* gameObject) : ColliderComponent(gameObject)
	{
		auto spriteRenderer = gameObject->GetComponent<SpriteRendererComponent>();
		if (spriteRenderer == nullptr)
		{
			std::cout << "SpriteRenderer required to SpriteCollider." << std::endl;
			gameObject->RemoveComponent(this);
			return;
		}

		sprite = gameObject->GetComponent<SpriteRendererComponent>()->GetSprite();
		PhysicsSystem::Instance()->Subscribe(this);
	}
	SpriteColliderComponent::~SpriteColliderComponent()
	{
		if (&bounds != nullptr)
		{
			std::destroy_at(&bounds);
		}
		PhysicsSystem::Instance()->Unsubscribe(this);
	}

	void SpriteColliderComponent::Update(float deltaTime)
	{
		bounds = sprite->getGlobalBounds();
	}
	void SpriteColliderComponent::Render()
	{
		/*sf::RectangleShape rectangle(sf::Vector2f(bounds.width, bounds.height));
		rectangle.setPosition(bounds.left, bounds.top);
		rectangle.setFillColor(sf::Color::Transparent);
		rectangle.setOutlineColor(sf::Color::White);
		rectangle.setOutlineThickness(4);

		RenderSystem::Instance()->Render(rectangle);*/
	}

	void SpriteColliderComponent::SubscribeCollision(std::function<void(Collision)> onCollisionAction)
	{
		onCollisionActions.push_back(onCollisionAction);
	}
	void SpriteColliderComponent::UnsubscribeCollision(std::function<void(Collision)> onCollisionAction)
	{
		onCollisionActions.erase(std::remove_if
		(
			onCollisionActions.begin(),
			onCollisionActions.end(),
			[&onCollisionAction](const std::function<void(Collision)>& action)
			{
				return action.target<void(Collision)>() == onCollisionAction.target<void(Collision)>();
			}
		), onCollisionActions.end());
	}

	void SpriteColliderComponent::SubscribeTriggerEnter(std::function<void(Trigger)> onTriggerEnterAction)
	{
		onTriggerEnterActions.push_back(onTriggerEnterAction);
	}
	void SpriteColliderComponent::UnsubscribeTriggerEnter(std::function<void(Trigger)> onTriggerEnterAction)
	{
		onTriggerEnterActions.erase(std::remove_if
		(
			onTriggerEnterActions.begin(),
			onTriggerEnterActions.end(),
			[&onTriggerEnterAction](const std::function<void(Trigger)>& action)
			{
				return action.target<void(Trigger)>() == onTriggerEnterAction.target<void(Trigger)>();
			}
		), onTriggerEnterActions.end());
	}

	void SpriteColliderComponent::SubscribeTriggerExit(std::function<void(Trigger)> onTriggerExitAction)
	{
		onTriggerExitActions.push_back(onTriggerExitAction);
	}
	void SpriteColliderComponent::UnsubscribeTriggerExit(std::function<void(Trigger)> onTriggerExitAction)
	{
		onTriggerExitActions.erase(std::remove_if
		(
			onTriggerExitActions.begin(),
			onTriggerExitActions.end(),
			[&onTriggerExitAction](const std::function<void(Trigger)>& action)
			{
				return action.target<void(Trigger)>() == onTriggerExitAction.target<void(Trigger)>();
			}
		), onTriggerExitActions.end());
	}

	void SpriteColliderComponent::OnCollision(Collision collision)
	{
		for (int i = 0; i < onCollisionActions.size(); i++)
		{
			onCollisionActions[i](collision);
		}
	}
	void SpriteColliderComponent::OnTriggerEnter(Trigger trigger)
	{
		for (int i = 0; i < onTriggerEnterActions.size(); i++)
		{
			onTriggerEnterActions[i](trigger);
		}
	}
	void SpriteColliderComponent::OnTriggerExit(Trigger trigger)
	{
		for (int i = 0; i < onTriggerExitActions.size(); i++)
		{
			onTriggerExitActions[i](trigger);
		}
	}
}