#pragma once
#include "RenderComponet.h"

namespace Skyers
{
	class Texture;
	class SpriteComponent : public RenderComponent
	{
	public:

		// Inherited via RenderComponent
		virtual void Update() override;

		virtual void Draw(Renderer& renderer) override;
	
		std::shared_ptr<Texture> m_texture;


		// Inherited via RenderComponent
		virtual bool Write(const rapidjson::Value& value) const override;

		virtual bool Read(const rapidjson::Value& value) override;

	};

}
