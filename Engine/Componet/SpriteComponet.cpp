#include "SpriteComponet.h"
#include "Renderer/Renderer.h"
#include "Framework/Actor.h"

namespace Skyers
{

	void SpriteComponet::Update()
	{
	}

	void SpriteComponet::Draw(Renderer& renderer)
	{
		renderer.Draw(m_texture, m_owner->m_transform);
	}
}
