#include "AudioComponent.h"
#include "Engine.h"

namespace Skyers
{
	AudioComponent::~AudioComponent()
	{
		Stop();
	}

	void AudioComponent::Initialize()
	{
		if (playOnAwake)
		{
			Play();
		}
	}

	void AudioComponent::Update()
	{
	}

	void AudioComponent::Play()
	{
		m_channel.Stop();
		m_channel = g_audio.PlayAudio(soundName, volume, pitch, loop);
	}

	void AudioComponent::Stop()
	{
		m_channel.Stop();
	}

	bool AudioComponent::Write(const rapidjson::Value& value) const
	{
		return true;
	}

	bool AudioComponent::Read(const rapidjson::Value& value)
	{
		READ_DATA(value, soundName);
		READ_DATA(value, volume);
		READ_DATA(value, pitch);
		READ_DATA(value, loop);

		g_audio.AddAudio(soundName, soundName);

		return true;
	}

}
