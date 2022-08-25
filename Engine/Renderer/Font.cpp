#include "Font.h" 
#include "Core/Logger.h"
#include <SDL_ttf.h> 

namespace Skyers
{
	Font::Font(const std::string& filename, int fontSize)
	{
		// !! call Load() function below passing filename and fontSize 
		Load(filename, fontSize);

	}

	Font::~Font()
	{
		// !! if m_ttfFont not null, close font (TTF_CloseFont)
		if (m_ttfFont)
		{
			TTF_CloseFont(m_ttfFont);
			m_ttfFont = nullptr;
		}
	}

	bool Font::Create(const std::string filename, ...)
	{
		va_list args;
		va_start(args, filename);
		int fontSize = va_arg(args, int);

		va_end(args);

		return Load(filename,fontSize);
	}

	SDL_Surface* Font::CreateSurface(const std::string& text, const Color& color)
	{
		SDL_Color c = *((SDL_Color*)(&color));
		SDL_Surface* surface = TTF_RenderText_Solid(m_ttfFont, text.c_str(), c);
		
		if (surface == nullptr)
		{
			LOG(SDL_GetError());
		}

		return surface;
	}

	bool Font::Load(const std::string& filename, int fontSize)
	{

		m_ttfFont = TTF_OpenFont(filename.c_str(), fontSize);
		if (m_ttfFont == nullptr)
		{
			LOG("Could not open font %s", filename.c_str());
			return false;
		}
		return true;

		// !! call TTF_OpenFont  
		// !! use filename.c_str() to get the c-style string 
		// !! assign the return value of TTF_OpenFont to m_ttfFont 
	}
}