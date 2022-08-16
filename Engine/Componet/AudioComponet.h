#pragma once
#include "Framework/Componet.h"

namespace Skyers
{
	class AudioComponet : public Componet
	{
	public:
		AudioComponet() = default;

		void Update() override;

		void play();

		void stop();

		std::string m_soundName;
		bool m_playOnAwake = false;
		float m_volume = 1;
		float m_pitch = 1;
		bool m_loop = false;
	};
}