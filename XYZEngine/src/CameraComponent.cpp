#include "CameraComponent.h"
#include "TransformComponent.h"

namespace Engine
{
	CameraComponent::CameraComponent(GameObject* gameObject) : Component(gameObject)
	{
		view = new sf::View(sf::FloatRect(0, 0, 800, -600));
		transform = gameObject->GetComponent<TransformComponent>();
	}
	CameraComponent::~CameraComponent()
	{
		delete view;
	}

	void CameraComponent::Update(float deltaTime)
	{
		auto position = transform->GetWorldPosition();
		auto rotation = transform->GetWorldRotation();

		view->setCenter(position);
		view->setRotation(rotation);

		window->setView(*view);
	}
	void CameraComponent::Render()
	{

	}

	void CameraComponent::SetBaseResolution(int width, int height)
	{
		view->reset(sf::FloatRect(0, 0, width, -height));
	}
	void CameraComponent::SetWindow(sf::RenderWindow* newWindow)
	{
		window = newWindow;
	}
	void CameraComponent::ZoomBy(float newZoom)
	{
		if (newZoom <= 0)
		{
			std::cout << "Not allowed zoom lesser or equal than zero." << std::endl;
			return;
		}
		view->zoom(newZoom);
	}
}