#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <RenderSystem.h>
#include <PhysicsSystem.h>
#include <ResourceSystem.h>
#include <GameWorld.h>

#ifdef XYZENGINE_EXPORTS
#define XYZENGINE_API __declspec(dllexport)
#else
#define XYZENGINE_API __declspec(dllimport)
#endif

namespace Engine
{
	class XYZENGINE_API Game
	{
	public:
		void Run();
	};
}