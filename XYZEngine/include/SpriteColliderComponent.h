#pragma once

#include <SFML/Graphics.hpp>
#include <functional>
#include <vector>
#include "ColliderComponent.h"
#include "Component.h"
#include "Collision.h"
#include "Trigger.h"
#include "SpriteRendererComponent.h"
#include "RenderSystem.h"
#include "PhysicsSystem.h"

#ifdef XYZENGINE_EXPORTS
#define XYZENGINE_API __declspec(dllexport)
#else
#define XYZENGINE_API __declspec(dllimport)
#endif

namespace Engine
{
	class XYZENGINE_API SpriteColliderComponent : public ColliderComponent
	{
	public:
		SpriteColliderComponent(GameObject* gameObject);
		~SpriteColliderComponent();

		void Update(float deltaTime) override;
		void Render() override;

		void SubscribeCollision(std::function<void(Collision)> onCollisionAction);
		void UnsubscribeCollision(std::function<void(Collision)> onCollisionAction);

		void SubscribeTriggerEnter(std::function<void(Trigger)> onTriggerEnterAction);
		void UnsubscribeTriggerEnter(std::function<void(Trigger)> onTriggerEnterAction);

		void SubscribeTriggerExit(std::function<void(Trigger)> onTriggerExitAction);
		void UnsubscribeTriggerExit(std::function<void(Trigger)> onTriggerExitAction);
	protected:
		void OnCollision(Collision collision) override;
		void OnTriggerEnter(Trigger trigger) override;
		void OnTriggerExit(Trigger trigger) override;
	private:
		const sf::Sprite* sprite;

		std::vector<std::function<void(Collision)>> onCollisionActions;
		std::vector<std::function<void(Trigger)>> onTriggerEnterActions;
		std::vector<std::function<void(Trigger)>> onTriggerExitActions;
	};
}