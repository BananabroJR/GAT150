#pragma once
#include "RenderComponet.h"

namespace Skyers
{
	class Texture;
	class SpriteComponet : public RenderComponet
	{
	public:

		// Inherited via RenderComponet
		virtual void Update() override;

		virtual void Draw(Renderer& renderer) override;
	
		std::shared_ptr<Texture> m_texture;

	};

}
