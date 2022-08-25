#include "TextComponent.h"
#include "Engine.h"

namespace Skyers
{
    void TextrueComponent::Update()
    {

    }

    void TextrueComponent::Draw(Renderer& renderer)
    {
        g_renderer.Draw(m_texture, m_owner->m_transform, registration);
    }

    void TextrueComponent::SetText(const std::string& text)
    {
        SDL_Surface* surface = m_font->CreateSurface(text, color);
        m_texture->CreateFromSurface(surface, g_renderer);
    }

    bool TextrueComponent::Write(const rapidjson::Value& value) const
    {
        return true;
    }

    bool TextrueComponent::Read(const rapidjson::Value& value)
    {
        READ_DATA(value, text);
        READ_DATA(value, fontName);
        READ_DATA(value, fontSize);
        READ_DATA(value, registration);
        READ_DATA(value, color);
        
        m_font = g_resource.Get<Font>(fontName, fontSize);
        m_texture = std::make_unique<Texture>();

        return true;
    }



}

