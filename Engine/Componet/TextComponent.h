#pragma once
#include "RenderComponet.h"
#include "Math/Color.h"
#include "Math/Vector2.h"
#include <memory>

namespace Skyers
{
	class Font;
	class Texture;

	class TextrueComponent : public RenderComponent
	{
	public:
		CLASS_DECLARATION(TextrueComponent)

		virtual void Update() override;
		virtual void Draw(Renderer& renderer) override;

		void SetText(const std::string& text);

	

		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

		std::string text;
		std::string fontName;
		int fontSize;
		Vector2 registration;
		Color color;


		std::shared_ptr<Font> m_font;
		std::shared_ptr<Texture> m_texture;

	};
}