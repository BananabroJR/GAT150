#include "Engine.h"

namespace Skyers
{
	Renderer g_renderer;
	InputSystem g_inputSystem;
	Time g_time;
	AudioSystem g_audio;
	ResourceManager g_resource;
	PhysicsSystem g_physics;
	EventManager g_event;

	void Engine::Register()
	{
		REGISTER_CLASS(Actor);
		REGISTER_CLASS(AudioComponent);
		REGISTER_CLASS(ModelComponent);
		REGISTER_CLASS(PhysicsComponent);
		REGISTER_CLASS(CollisionComponent);
		REGISTER_CLASS(RBPhysicsComponent);
		REGISTER_CLASS(PlayerComponent);
		REGISTER_CLASS(SpriteComponent);
		REGISTER_CLASS(SpriteAnimComponent);
		REGISTER_CLASS(TextComponent);
		REGISTER_CLASS(TilemapComponent);
		REGISTER_CLASS(CameraComponent);
		Factory::Instance().Register<Actor>("Actor");
	}
}
