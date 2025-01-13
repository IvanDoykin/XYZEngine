#pragma once

#include "Component.h"
#include <functional>

#ifdef XYZENGINE_EXPORTS
#define XYZENGINE_API __declspec(dllexport)
#else
#define XYZENGINE_API __declspec(dllimport)
#endif

namespace Engine
{
	class XYZENGINE_API DelayActionComponent : public Component
	{
	public:
		DelayActionComponent(GameObject* gameObject);

		void Update(float deltaTime) override;
		void Render() override;

		void SetAction(std::function<void()> action, std::function<void()> callback = nullptr);
		void Invoke(float newTime);
	private:
		bool isActive = false;
		std::function<void()> action;
		std::function<void()> callback;
		float time = 0.f;
	};
}