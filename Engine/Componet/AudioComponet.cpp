#include "AudioComponent.h"
#include "Engine.h"

namespace Skyers
{

	void AudioComponent::Update()
	{
	}

	void AudioComponent::play()
	{
		Skyers::g_audio.PlayAudio(m_soundName, m_loop);
	}

	void AudioComponent::stop()
	{
	}

	bool AudioComponent::Write(const rapidjson::Value& value) const
	{
		return false;
	}

	bool AudioComponent::Read(const rapidjson::Value& value)
	{
		return false;
	}

}
