#pragma once
#include "Core/Memory.h"
#include "Core/File.h"
#include "Core/Time.h"

#include "Math/MathUtils.h"
#include "Math/Random.h"

#include "Framework/Scene.h"
#include "Framework/Game.h"
#include "Framework/Actor.h"

#include "Audio/AudioSystem.h"

#include "Input/InputSystem.h"

#include "Renderer/Renderer.h"
#include "Renderer/Font.h"
#include "Renderer/Text.h"
#include "Renderer/Model.h"
#include "Renderer/Text.h"


#include <memory>
#include <vector>
#include <list>

namespace Skyers
{
	extern Renderer g_renderer;
	extern AudioSystem g_audio;
	extern InputSystem g_inputSystem;
	extern Time g_time;
}