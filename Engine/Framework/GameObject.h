#pragma once
#include "Math/Transform.h"
#include "Serialization/Serializable.h"

#define CLASS_DECLARATION(class) \
std::unique_ptr<GameObject> Clone() { return std::make_unique<class>(*this); } //this is part of CLASS_DECLARATION

#define REGISTER_CLASS(class) Skyers::Factory::Instance().Register<class>(#class)

namespace Skyers
{
	class GameObject
	{
	public:
		GameObject() = default;
		
		virtual std::unique_ptr<GameObject> Clone() = 0;
		virtual void Initialize() = 0;
		virtual void Update() = 0;

	};
}
