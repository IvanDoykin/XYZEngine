#pragma once

#include "Component.h"

#ifdef XYZENGINE_EXPORTS
#define XYZENGINE_API __declspec(dllexport)
#else
#define XYZENGINE_API __declspec(dllimport)
#endif

namespace Engine
{
	class XYZENGINE_API DummyComponent : public Component
	{
	public:
		DummyComponent(GameObject* gameObject);

		void Update(float deltaTime) override;
		void Render() override;
	};
}