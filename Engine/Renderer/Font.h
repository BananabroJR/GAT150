#pragma once
#include "..\Engine.h"
// !! add necessary includes 

// !! forward declare the _TTF_Font struct 
struct _TTF_Font;

namespace Skyers
{
	class Font
	{
	public:
		Font() = default;
		Font(const std::string& filename, int fontSize);
		~Font();

		void Load(const std::string& filename, int fontSize);

	private:
		_TTF_Font* m_ttfFont = nullptr;
		friend class Text;
	};
}