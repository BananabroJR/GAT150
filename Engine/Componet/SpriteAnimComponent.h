#pragma once
#include "RenderComponet.h"
#include "Math/Rect.h"

namespace Skyers
{
	class Texture;

	class SpriteAnimComponent : public RenderComponent
	{
	public:
		CLASS_DECLARATION(SpriteAnimComponent)

		// Inherited via RenderComponent
		virtual void Update() override;

		virtual void Draw(Renderer& renderer) override;



		// Inherited via RenderComponent
		virtual bool Write(const rapidjson::Value& value) const override;

		virtual bool Read(const rapidjson::Value& value) override;


		float fps = 0;
		int num_culumns = 0;
		int num_rows = 0;

		int start_frame = 0;
		int end_frame = 0;

		int frame = 0;
		float frameTimer = 0;

		Rect source;
		std::shared_ptr<Texture> m_texture;

	};

}
