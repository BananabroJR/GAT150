#pragma once
#include "Framework/Componet.h"

namespace Skyers
{
	class PlayerComponet : public Componet
	{
	public:
		PlayerComponet() = default;

		void Update() override;
	};
}
