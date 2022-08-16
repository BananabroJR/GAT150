#pragma once
#include "RenderComponet.h"
#include "Renderer/Model.h"

namespace Skyers
{
	class Texture;
	class ModelComponet : public RenderComponet
	{
	public:

		// Inherited via RenderComponet
		virtual void Update() override;

		virtual void Draw(Renderer& renderer) override;

		std::shared_ptr<Model> m_model;

	};
}
