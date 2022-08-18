#pragma once
#include "RenderComponet.h"
#include "Renderer/Model.h"

namespace Skyers
{
	class Texture;
	class ModelComponent : public RenderComponent
	{
	public:

		// Inherited via RenderComponent
		virtual void Update() override;

		virtual void Draw(Renderer& renderer) override;

		std::shared_ptr<Model> m_model;


		// Inherited via RenderComponent
		virtual bool Write(const rapidjson::Value& value) const override;

		virtual bool Read(const rapidjson::Value& value) override;

	};
}
