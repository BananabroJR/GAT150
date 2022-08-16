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

		for (auto& child : m_children)
		{
			child->Update();
		}

		if (m_parent) m_transform.Update(m_parent->m_transform.matrix);
		else
		m_transform.Update();
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

		for (auto& child : m_children)
		{
			child->Draw(renderer);
		}
	}

	void Actor::AddChild(std::unique_ptr<Actor> child)
	{
		child->m_parent = this;
		child->m_scene = this->m_scene;

		m_children.push_back(child);
		
	}

	void Actor::AddComponet(std::unique_ptr<Componet> componet)
	{
		componet->m_owner = this;
		m_components.push_back(std::move(componet));
	}

}
