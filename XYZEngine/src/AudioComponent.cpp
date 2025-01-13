#include "AudioComponent.h"

namespace Engine
{
	AudioComponent::AudioComponent(GameObject* gameObject) : Component(gameObject) 
	{
		sound = new sf::Sound();
	}
	AudioComponent::~AudioComponent()
	{
		sound->stop();
		delete sound;
	}

	void AudioComponent::Update(float deltaTime)
	{

	}
	void AudioComponent::Render()
	{

	}

	void AudioComponent::SetLoop(bool loop)
	{
		sound->setLoop(loop);
	}
	void AudioComponent::SetAudio(const sf::SoundBuffer& audio)
	{
		sound->setBuffer(audio);
	}

	void AudioComponent::SetVolume(float volume)
	{
		sound->setVolume(volume);
	}
	void AudioComponent::Play()
	{
		if (sound->getStatus() != sf::SoundSource::Playing)
		{
			sound->play();
		}
	}
	void AudioComponent::Stop()
	{
		sound->stop();
	}
	void AudioComponent::Pause()
	{
		sound->pause();
	}
	void AudioComponent::Resume()
	{
		if (sound->getStatus() != sf::SoundSource::Playing)
		{
			sound->play();
		}
	}
}