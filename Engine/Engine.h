#pragma once

#include "Serialization/Json.h"

#include "Core/Memory.h"
#include "Core/File.h"
#include "Core/Time.h"

#include "Math/MathUtils.h"
#include "Math/Random.h"

#include "Framework/Scene.h"
#include "Framework/Game.h"
#include "Framework/Singleton.h"
#include "Framework/Factory.h"
#include "Framework/Actor.h"

#include "Recource/ResourceManager.h"

#include "Audio/AudioSystem.h"

#include "Input/InputSystem.h"

#include "Renderer/Renderer.h"
#include "Renderer/Font.h"
#include "Renderer/Text.h"
#include "Renderer/Model.h"
#include "Renderer/Texture.h"

#include "Physics/PhysicsSystem.h"

#include "Componet/AudioComponent.h"
#include "Componet/ModelComponet.h"
#include "Componet/PlayerComponet.h"
#include "Componet/SpriteComponet.h"
#include "Componet/SpriteAnimComponent.h"
#include "Componet/PhysicsComponet.h"
#include "Componet/RBPhysicsComponent.h"
#include "Componet/CollisionComponenet.h"
#include "Componet/TextComponent.h"


#include <memory>


namespace Skyers
{
	extern Renderer g_renderer;
	extern AudioSystem g_audio;
	extern InputSystem g_inputSystem;
	extern Time g_time;
	extern ResourceManager g_resource;
	extern PhysicsSystem g_physics;

	class Engine : public Singleton<Engine>
	{
	public:
		void Register();
	};
}