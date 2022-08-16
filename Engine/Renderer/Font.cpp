#include "Font.h" 
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

	bool Font::Create(const std::string& filename, void* data)
	{
		return false;
	}

	void Font::Load(const std::string& filename, int fontSize)
	{

		;
		
		m_ttfFont = TTF_OpenFont(filename.c_str(), 23);
		
		// !! call TTF_OpenFont  
		// !! use filename.c_str() to get the c-style string 
		// !! assign the return value of TTF_OpenFont to m_ttfFont 
	}
}