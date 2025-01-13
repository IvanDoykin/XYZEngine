#pragma once

#include <Component.h>
#include <SFML/Window.hpp> 

#ifdef XYZENGINE_EXPORTS
#define XYZENGINE_API __declspec(dllexport)
#else
#define XYZENGINE_API __declspec(dllimport)
#endif

namespace Engine
{
	class XYZENGINE_API InputComponent : public Component
	{
	public:
		InputComponent(GameObject* gameObject);

		void Update(float deltaTime) override;
		void Render() override;

		float GetHorizontalAxis() const;
		float GetVerticalAxis() const;
	private:
		float horizontalAxis = 0.f;
		float verticalAxis = 0.f;
	};
}
