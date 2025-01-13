#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <SFML/Graphics/Transform.hpp>
#include "Component.h"
#include "GameObject.h"

#ifdef XYZENGINE_EXPORTS
#define XYZENGINE_API __declspec(dllexport)
#else
#define XYZENGINE_API __declspec(dllimport)
#endif

namespace Engine
{
	class XYZENGINE_API TransformComponent : public Component
	{
	public:
		TransformComponent(GameObject* gameObject);

		void Update(float deltaTime) override;
		void Render() override;

		void MoveBy(const sf::Vector2f& offset);
		void MoveBy(float offsetX, float offsetY);
		void SetWorldPosition(const sf::Vector2f& position);
		void SetWorldPosition(float positionX, float positionY);
		void SetLocalPosition(const sf::Vector2f& position);
		void SetLocalPosition(float positionX, float positionY);

		void RotateBy(float offset);
		void SetWorldRotation(float angle);
		void SetLocalRotation(float angle);

		void ScaleBy(const sf::Vector2f& scale);
		void ScaleBy(float scaleX, float scaleY);
		void SetWorldScale(const sf::Vector2f& scale);
		void SetWorldScale(float scaleX, float scaleY);
		void SetLocalScale(const sf::Vector2f& scale);
		void SetLocalScale(float scaleX, float scaleY);

		const sf::Vector2f& GetWorldPosition() const;
		const sf::Vector2f& GetLocalPosition() const;

		const float GetWorldRotation() const;
		const float GetLocalRotation() const;

		const sf::Vector2f& GetWorldScale() const;
		const sf::Vector2f& GetLocalScale() const;

		void SetParent(TransformComponent* newParent);
		TransformComponent* GetParent() const;

		const sf::Transform GetWorldTransform() const;

	private:
		TransformComponent* parent = nullptr;

		mutable sf::Transform localTransform = sf::Transform::Identity;
		mutable bool isUpdated = false;

		mutable sf::Vector2f localPosition = { 0, 0 };
		mutable float localRotation = 0.f;
		mutable sf::Vector2f localScale = { 1, 1 };

		mutable sf::Vector2f position = { 0, 0 };
		mutable float rotation = 0.f;
		mutable sf::Vector2f scale = { 1, 1 };

		void setWorldInfoFrom(const sf::Transform& transform) const;
		void setLocalInfoFrom(const sf::Transform& transform) const;
		void updateLocalTransform() const;
		void updateLocalTransform(const sf::Vector2f& position, float rotation, const sf::Vector2f& scale) const;
		sf::Transform createTransform(const sf::Vector2f& position, float rotation, const sf::Vector2f& scale) const;
	};
}