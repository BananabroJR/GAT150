#pragma once
#include "RenderComponet.h"
#include "Math/Rect.h"

namespace Skyers
{
	class Texture;

	class SpriteComponent : public RenderComponent
	{
	public:
		CLASS_DECLARATION(SpriteComponent)

		// Inherited via RenderComponent
		virtual void Update() override;

		virtual void Draw(Renderer& renderer) override;
	


		// Inherited via RenderComponent
		virtual bool Write(const rapidjson::Value& value) const override;

		virtual bool Read(const rapidjson::Value& value) override;

	public:
		std::shared_ptr<Texture> m_texture;

	};

}
