#include "TextComponent.h"
#include "Engine.h"

namespace Skyers
{
    void TextComponent::Update()
    {

    }

    void TextComponent::Draw(Renderer& renderer)
    {
        g_renderer.Draw(m_texture, m_owner->m_transform, registration);
    }

    void TextComponent::SetText(const std::string& text)
    {
        SDL_Surface* surface = m_font->CreateSurface(text, color);
        m_texture->CreateFromSurface(surface, g_renderer);
    }

    bool TextComponent::Write(const rapidjson::Value& value) const
    {
        return true;
    }

    bool TextComponent::Read(const rapidjson::Value& value)
    {
        READ_DATA(value, text);
        READ_DATA(value, fontName);
        READ_DATA(value, fontSize);
        READ_DATA(value, registration);
        READ_DATA(value, color);
        READ_DATA(value, active);
        
        m_font = g_resource.Get<Font>(fontName, fontSize);
        m_texture = std::make_unique<Texture>();

        return true;
    }



}

