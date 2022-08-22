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
		if (m_ttfFont != nullptr)
		{
			TTF_CloseFont(m_ttfFont);
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