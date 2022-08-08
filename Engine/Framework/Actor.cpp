#include "Actor.h"
#include "Componet/RenderComponet.h"


namespace Skyers
{
	void Actor::Update()
	{
		for (auto& componet : m_components)
		{
			componet->Update();
		}
	}
	void Actor::Draw(Renderer& renderer)
	{
		for (auto& componet : m_components)
		{
			auto renderComponet = dynamic_cast<RenderComponet*>(componet.get());
			if (renderComponet)
			{
				renderComponet->Draw(renderer);
			}
			//componet->Update();

		}
	}

	void Actor::AddComponet(std::unique_ptr<Componet> componet)
	{
		componet->m_owner = this;
		m_components.push_back(std::move(componet));
	}

}
