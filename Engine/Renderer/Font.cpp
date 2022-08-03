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
			TTF_CloseFont;
		}
	}

	void Font::Load(const std::string& filename, int fontSize)
	{

		filename.c_str();
		
	 	auto fontName = TTF_OpenFont("../Assets/Fonts/Cat.ttf", 23);
		m_ttfFont = fontName;
		
		
		// !! call TTF_OpenFont  
		// !! use filename.c_str() to get the c-style string 
		// !! assign the return value of TTF_OpenFont to m_ttfFont 
	}
}