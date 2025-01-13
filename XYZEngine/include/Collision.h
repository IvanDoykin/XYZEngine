#pragma once

#include <SFML/Graphics.hpp>

#ifdef XYZENGINE_EXPORTS
#define XYZENGINE_API __declspec(dllexport)
#else
#define XYZENGINE_API __declspec(dllimport)
#endif

namespace Engine
{
	class ColliderComponent;
	struct XYZENGINE_API Collision
	{
	public:
		Collision(ColliderComponent* newFirst, ColliderComponent* newSecond, sf::FloatRect newCollisionRect) :
			first(newFirst), second(newSecond), collisionRect(newCollisionRect) {};
	private:
		ColliderComponent* first;
		ColliderComponent* second;
		sf::FloatRect collisionRect;
	};
}