#pragma once

#ifdef XYZENGINE_EXPORTS
#define XYZENGINE_API __declspec(dllexport)
#else
#define XYZENGINE_API __declspec(dllimport)
#endif

namespace Engine
{
	class XYZENGINE_API Scene
	{
	public:
		virtual void Start() = 0;
		virtual void Restart() = 0;
		virtual void Stop() = 0;
	};
}