#include "AudioComponet.h"
#include "Engine.h"

namespace Skyers
{

	void AudioComponet::Update()
	{
	}

	void AudioComponet::play()
	{
		Skyers::g_audio.PlayAudio(m_soundName, m_loop);
	}

	void AudioComponet::stop()
	{
	}

}
