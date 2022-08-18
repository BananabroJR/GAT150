#pragma once
#include "GameObject.h"
#include "Framework/Actor.h"

namespace Skyers
{
	class Actor;

	class Component : public GameObject, public ISerializable
	{
	public:
		Component() = default;

		virtual void Update() = 0;

		friend Actor;
	protected:
		Actor* m_owner = nullptr;
	};
}
