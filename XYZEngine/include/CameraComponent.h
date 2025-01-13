#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include "TransformComponent.h"

#ifdef XYZENGINE_EXPORTS
#define XYZENGINE_API __declspec(dllexport)
#else
#define XYZENGINE_API __declspec(dllimport)
#endif

namespace Engine
{
	class XYZENGINE_API CameraComponent : public Component
	{
	public:
		CameraComponent(GameObject* gameObject);
		~CameraComponent();

		void Update(float deltaTime) override;
		void Render() override;

		void SetWindow(sf::RenderWindow* newWindow);
		void ZoomBy(float newZoom);

		void SetBaseResolution(int width, int height);
	private:
		TransformComponent* transform;
		sf::RenderWindow* window;
		sf::View* view;
	};
}