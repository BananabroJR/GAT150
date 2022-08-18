#pragma once
#include "Framework/Component.h"

namespace Skyers
{
	class Renderer;

	class RenderComponent : public Component
	{
	public:
		virtual void Draw(Renderer& renderer) = 0;
	};
}