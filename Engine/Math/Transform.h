#pragma once
#include "Vector2.h"

namespace Skyers
{
	struct Transform
	{
		Vector2 position;
		float rotation{ 0 };
		float scale{ 1 };
	};
}
