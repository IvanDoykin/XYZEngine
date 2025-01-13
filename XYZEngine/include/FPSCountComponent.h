#pragma once

#include "Component.h"

#ifdef XYZENGINE_EXPORTS
#define XYZENGINE_API __declspec(dllexport)
#else
#define XYZENGINE_API __declspec(dllimport)
#endif

namespace Engine
{
	class XYZENGINE_API FPSCountComponent : public Component
	{
	public:
		FPSCountComponent(GameObject* gameObject);

		void Update(float deltaTime) override;
		void Render() override;
	private:
		int frames = 0;
		float seconds = 0.f;
	};
}