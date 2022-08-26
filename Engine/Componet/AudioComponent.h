#pragma once
#include "Framework/Component.h"
#include "Audio/AudioChannel.h"

namespace Skyers
{
	class AudioComponent : public Component
	{
	public:
		AudioComponent() = default;
		~AudioComponent();

		CLASS_DECLARATION(AudioComponent)

		void Initialize() override;	
		void Update() override;

		void Play();

		void Stop();


		AudioChannel m_channel;

		std::string soundName;
		bool playOnAwake = false;
		float volume = 1;
		float pitch = 1;
		bool loop = false;
				

		// Inherited via Component
		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;
	};
}