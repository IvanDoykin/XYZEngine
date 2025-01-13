#include "TransformComponent.h"
#include <cmath>
#include <iostream>

namespace Engine
{
	TransformComponent::TransformComponent(GameObject* gameObject) : Component(gameObject) {}

	void TransformComponent::Update(float deltaTime) 
	{

	}
	void TransformComponent::Render() 
	{

	}

	void TransformComponent::MoveBy(const sf::Vector2f& offset)
	{
		MoveBy(offset.x, offset.y);
		isUpdated = false;
	}
	void TransformComponent::MoveBy(float offsetX, float offsetY)
	{
		localPosition.x += offsetX;
		localPosition.y += offsetY;
		isUpdated = false;
	}
	void TransformComponent::SetWorldPosition(const sf::Vector2f& position)
	{
		SetWorldPosition(position.x, position.y);
		isUpdated = false;
	}
	void TransformComponent::SetWorldPosition(float positionX, float positionY)
	{
		sf::Vector2f newPosition = { positionX, positionY };
		if (parent == nullptr)
		{
			localPosition = newPosition;
		}
		else
		{
			sf::Transform newWorldTransform = createTransform(newPosition, GetWorldRotation(), GetWorldScale());
			localTransform = parent->GetWorldTransform().getInverse() * newWorldTransform;

			setLocalInfoFrom(localTransform);

			isUpdated = false;
			updateLocalTransform();
		}
	}
	void TransformComponent::SetLocalPosition(const sf::Vector2f& position)
	{
		SetLocalPosition(position.x, position.y);
		isUpdated = false;
	}
	void TransformComponent::SetLocalPosition(float positionX, float positionY)
	{
		localPosition.x = positionX;
		localPosition.y = positionY;
		isUpdated = false;
	}

	void TransformComponent::RotateBy(float offset)
	{
		localRotation = localRotation + offset;
		while (localRotation >= 360)
		{
			localRotation -= 360;
		}
		while (localRotation < 0)
		{
			localRotation += 360;
		}
		isUpdated = false;
	}
	void TransformComponent::SetWorldRotation(float angle)
	{
		if (parent == nullptr)
		{
			localRotation = angle;
		}
		else
		{
			sf::Transform newWorldTransform = createTransform(GetWorldPosition(), angle, GetWorldScale());
			localTransform = parent->GetWorldTransform().getInverse() * newWorldTransform;

			setLocalInfoFrom(localTransform);

			isUpdated = false;
			updateLocalTransform();
		}
	}
	void TransformComponent::SetLocalRotation(float angle)
	{
		localRotation = angle;
		while (localRotation >= 360)
		{
			localRotation -= 360;
		}
		while (localRotation < 0)
		{
			localRotation += 360;
		}
		isUpdated = false;
	}

	void TransformComponent::ScaleBy(const sf::Vector2f& scale)
	{
		ScaleBy(scale.x, scale.y);
		isUpdated = false;
	}
	void TransformComponent::ScaleBy(float scaleX, float scaleY)
	{
		localScale.x *= scaleX;
		localScale.y *= scaleY;
		isUpdated = false;
	}
	void TransformComponent::SetWorldScale(const sf::Vector2f& scale)
	{
		SetWorldScale(scale.x, scale.y);
		isUpdated = false;
	}
	void TransformComponent::SetWorldScale(float scaleX, float scaleY)
	{
		sf::Vector2f newScale = { scaleX, scaleY };
		if (parent == nullptr)
		{
			localScale = newScale;
		}
		else
		{
			sf::Transform newWorldTransform = createTransform(GetWorldPosition(), GetWorldRotation(), newScale);
			localTransform = parent->GetWorldTransform().getInverse() * newWorldTransform;

			setLocalInfoFrom(localTransform);

			isUpdated = false;
			updateLocalTransform();
		}
	}
	void TransformComponent::SetLocalScale(const sf::Vector2f& scale)
	{
		SetLocalScale(scale.x, scale.y);
		isUpdated = false;
	}
	void TransformComponent::SetLocalScale(float scaleX, float scaleY)
	{
		localScale.x = scaleX;
		localScale.y = scaleY;
		isUpdated = false;
	}

	const sf::Vector2f& TransformComponent::GetWorldPosition() const
	{
		updateLocalTransform();
		if (parent == nullptr)
		{
			return GetLocalPosition();
		}

		setWorldInfoFrom(parent->GetWorldTransform() * localTransform);
		return position;
	}
	const sf::Vector2f& TransformComponent::GetLocalPosition() const
	{
		updateLocalTransform();
		return localPosition;
	}

	const float TransformComponent::GetWorldRotation() const
	{
		updateLocalTransform();
		if (parent == nullptr)
		{
			return GetLocalRotation();
		}

		setWorldInfoFrom(parent->GetWorldTransform() * localTransform);
		return rotation;
	}

	const float TransformComponent::GetLocalRotation() const
	{
		updateLocalTransform();
		return localRotation;
	}

	const sf::Vector2f& TransformComponent::GetWorldScale() const
	{
		updateLocalTransform();
		if (parent == nullptr)
		{
			return GetLocalScale();
		}

		setWorldInfoFrom(parent->GetWorldTransform() * localTransform);
		return scale;
	}
	const sf::Vector2f& TransformComponent::GetLocalScale() const
	{
		updateLocalTransform();
		return localScale;
	}

	void TransformComponent::SetParent(TransformComponent* newParent)
	{
		if (parent == nullptr && newParent != nullptr)
		{
			newParent->gameObject->AddChild(gameObject);
			localTransform = newParent->GetWorldTransform().getInverse() * localTransform;
		}
		else if (parent != nullptr && newParent == nullptr)
		{
			parent->gameObject->RemoveChild(gameObject);
			localTransform = parent->GetWorldTransform() * localTransform;
		}
		else if (parent != nullptr && newParent != nullptr)
		{
			parent->gameObject->RemoveChild(gameObject);
			newParent->gameObject->AddChild(gameObject);
			localTransform = newParent->GetWorldTransform().getInverse() * (parent->GetWorldTransform() * localTransform);
		}

		setLocalInfoFrom(localTransform);

		parent = newParent;
		isUpdated = false;
	}
	TransformComponent* TransformComponent::GetParent() const
	{
		return parent;
	}

	const sf::Transform TransformComponent::GetWorldTransform() const
	{
		updateLocalTransform();

		if (parent == nullptr)
		{
			return localTransform;
		}

		return parent->GetWorldTransform() * localTransform;
	}

	void TransformComponent::setWorldInfoFrom(const sf::Transform& transform) const
	{
		position.x = transform.getMatrix()[12];
		position.y = transform.getMatrix()[13];

		scale.x = std::sqrt(transform.getMatrix()[0] * transform.getMatrix()[0] + transform.getMatrix()[1] * transform.getMatrix()[1]);
		scale.y = std::sqrt(transform.getMatrix()[4] * transform.getMatrix()[4] + transform.getMatrix()[5] * transform.getMatrix()[5]);

		rotation = std::atan2(transform.getMatrix()[1], transform.getMatrix()[0]) * 180 / 3.14159265;
	}
	void TransformComponent::setLocalInfoFrom(const sf::Transform& transform) const
	{
		localPosition.x = transform.getMatrix()[12];
		localPosition.y = transform.getMatrix()[13];

		localScale.x = std::sqrt(transform.getMatrix()[0] * transform.getMatrix()[0] + transform.getMatrix()[1] * transform.getMatrix()[1]);
		localScale.y = std::sqrt(transform.getMatrix()[4] * transform.getMatrix()[4] + transform.getMatrix()[5] * transform.getMatrix()[5]);

		localRotation = std::atan2(transform.getMatrix()[1], transform.getMatrix()[0]) * 180 / 3.14159265;
	}
	void TransformComponent::updateLocalTransform() const
	{
		if (!isUpdated)
		{
			localTransform = createTransform(localPosition, localRotation, localScale);
			isUpdated = true;
		}
	}
	void TransformComponent::updateLocalTransform(const sf::Vector2f& position, float rotation, const sf::Vector2f& scale) const
	{
		if (!isUpdated)
		{
			localTransform = createTransform(position, rotation, scale);
			isUpdated = true;
		}
	}
	sf::Transform TransformComponent::createTransform(const sf::Vector2f& position, float rotation, const sf::Vector2f& scale) const
	{
		const float angle = rotation * (3.14159265f / 180.f);
		const float cosine = std::cos(angle);
		const float sine = std::sin(angle);
		const float sxc = scale.x * cosine;
		const float syc = scale.y * cosine;
		const float sxs = scale.x * sine;
		const float sys = scale.y * sine;
		const float tx = position.x;
		const float ty = position.y;

		return sf::Transform(sxc, sys, tx,
			-sxs, syc, ty,
			0.f, 0.f, 1.f);
	}
}