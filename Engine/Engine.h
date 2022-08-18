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

#include "Recource/ResourceManager.h"

#include "Audio/AudioSystem.h"

#include "Input/InputSystem.h"

#include "Renderer/Renderer.h"
#include "Renderer/Font.h"
#include "Renderer/Text.h"
#include "Renderer/Model.h"
#include "Renderer/Texture.h"


#include "Componet/AudioComponent.h"
#include "Componet/ModelComponet.h"
#include "Componet/PlayerComponet.h"
#include "Componet/SpriteComponet.h"
#include "Componet/PhysicsComponet.h"


#include <memory>


namespace Skyers
{
	extern Renderer g_renderer;
	extern AudioSystem g_audio;
	extern InputSystem g_inputSystem;
	extern Time g_time;
	extern ResourceManager g_resource;

	class Engine : public Singleton<Engine>
	{
	public:
		void Register();
	};
}