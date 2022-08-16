#include "Engine.h"

namespace Skyers
{
	Renderer g_renderer;
	InputSystem g_inputSystem;
	Time g_time;
	AudioSystem g_audio;
	ResourceManager g_resource;

	void Engine::Register()
	{
		REGISTER_CLASS(Actor);
		REGISTER_CLASS(AudioComponet);
		REGISTER_CLASS(ModelComponet);
		REGISTER_CLASS(PhysiscsComponet);
		REGISTER_CLASS(PlayerComponet);
		REGISTER_CLASS(SpriteComponet);
		Factory::Instance().Register<Actor>("Actor");
	}
}
