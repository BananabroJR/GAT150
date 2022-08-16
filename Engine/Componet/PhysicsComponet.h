#pragma once
#include "Framework/Componet.h"
#include "Math/Vector2.h"

namespace Skyers
{
	class PhysiscsComponet : public Componet
	{
	public:
		PhysiscsComponet() = default;

		void Update() override;
		void ApplyForce(Vector2& force) { m_acceloration += force; }

		Vector2 m_velocity;
		Vector2 m_acceloration;

		float m_damping = 1;
	};

}