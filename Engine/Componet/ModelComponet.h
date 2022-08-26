#pragma once
#include "RenderComponet.h"


namespace Skyers
{
	class Model;
	class ModelComponent : public RenderComponent
	{
	public:

		CLASS_DECLARATION(ModelComponent)


		// Inherited via RenderComponent
		virtual void Update() override;

		virtual void Draw(Renderer& renderer) override;

		std::shared_ptr<Model> m_model;


		// Inherited via RenderComponent
		virtual bool Write(const rapidjson::Value& value) const override;

		virtual bool Read(const rapidjson::Value& value) override;

	};
}
