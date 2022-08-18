#pragma once
#include "Math/Transform.h"
#include "Serialization/Serializable.h"

#define REGISTER_CLASS(class) Factory::Instance().Register<class>(#class)

namespace Skyers
{
	class GameObject
	{
	public:
		GameObject() = default;
		

		virtual void Update() = 0;

	};
}
