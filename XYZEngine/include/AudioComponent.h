#pragma once

#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include "Component.h"

#ifdef XYZENGINE_EXPORTS
#define XYZENGINE_API __declspec(dllexport)
#else
#define XYZENGINE_API __declspec(dllimport)
#endif

namespace Engine
{
	class XYZENGINE_API AudioComponent : public Component
	{
	public:
		AudioComponent(GameObject* gameObject);
		~AudioComponent();

		void Update(float deltaTime) override;
		void Render() override;

		void SetAudio(const sf::SoundBuffer& audio);
		void SetLoop(bool loop);

		void SetVolume(float volume);
		void Play();
		void Stop();
		void Pause();
		void Resume();
	private:
		sf::Sound* sound;
	};
}