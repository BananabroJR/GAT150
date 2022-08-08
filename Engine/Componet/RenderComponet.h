#pragma once
#include "Framework/Componet.h"

namespace Skyers
{
	class Renderer;

	class RenderComponet : public Componet
	{
	public:
		virtual void Draw(Renderer& renderer) = 0;
	};
}