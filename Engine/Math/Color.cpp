#include "Color.h"

namespace Skyers
{
	 std::istream& operator >> (std::istream& stream, Color& color)
	{
		std::string line;
		std::getline(stream, line);

		color.r = 255;
		color.g = 255;
		color.b = 255;
		color.a = 255;

		return stream;
	}
}