#pragma once

#include "Component.h"
#include "GameWorld.h"

#ifdef XYZENGINE_EXPORTS
#define XYZENGINE_API __declspec(dllexport)
#else
#define XYZENGINE_API __declspec(dllimport)
#endif

namespace Engine
{
	class XYZENGINE_API DestroySelfComponent : public Component
	{
	public:
		DestroySelfComponent(GameObject* gameObject);

		void Update(float deltaTime) override;
		void Render() override;
	};
}