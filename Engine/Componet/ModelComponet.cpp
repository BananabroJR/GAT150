#include "ModelComponet.h"
#include "Renderer/Renderer.h"
#include "Framework/Actor.h"

namespace Skyers
{

	void ModelComponet::Update()
	{
	}

	void ModelComponet::Draw(Renderer& renderer)
	{
		m_model->Draw(renderer, m_owner->m_transform);
	}
}
