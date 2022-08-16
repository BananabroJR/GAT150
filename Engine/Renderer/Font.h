#pragma once
#include "Engine.h"
#include "Recource/Resource.h"
// !! add necessary includes 

// !! forward declare the _TTF_Font struct 
struct _TTF_Font;

namespace Skyers
{
	class Font : public Resource
	{
	public:
		Font() = default;
		Font(const std::string& filename, int fontSize);
		~Font();

		bool Create(const std::string& filename, void* data = nullptr) override;

		void Load(const std::string& filename, int fontSize);

	private:
		_TTF_Font* m_ttfFont = nullptr;
		friend class Text;
	};
}