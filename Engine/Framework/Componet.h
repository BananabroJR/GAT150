#pragma once
#include "GameObject.h"

namespace Skyers
{
	class Actor;

	class Componet : public GameObject
	{
	public:
		Componet() = default;

		virtual void Update() = 0;

		friend Actor;
	protected:
		Actor* m_owner = nullptr;
	};
}
