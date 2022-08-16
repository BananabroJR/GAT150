#include "Texture.h" 
#include "Renderer.h" 
#include "Core\Logger.h"
#include <SDL.h> 
#include <SDL_image.h> 

namespace Skyers
{
    Texture::~Texture()
    {

        if (m_texture != nullptr)
        {
            SDL_DestroyTexture(m_texture);
        }
    }

    bool Texture::Create(const std::string& filename, void* data)
    {

        //check data != null

         Renderer* renderer = static_cast<Renderer*>(data);

        return Create(*renderer, filename);
    }

    bool Texture::Create(Renderer& renderer, const std::string& filename)
    {
        // load surface 
        SDL_Surface* surface = IMG_Load(filename.c_str());
        if (surface == nullptr)
        {
            LOG(SDL_GetError());
        }

        // create texture 

        m_texture = SDL_CreateTextureFromSurface(renderer.m_renderer, surface);
        if (m_texture == nullptr)
        {
            LOG(SDL_GetError());
            SDL_FreeSurface(surface);

            return false;
        }

        SDL_FreeSurface(surface);
        return true;
    }

    Skyers::Vector2 Texture::GetSize() const
    {
        SDL_Point point;
        SDL_QueryTexture(m_texture, nullptr, nullptr, &point.x, &point.y);


        return Skyers::Vector2(point.x, point.y);
    }
}