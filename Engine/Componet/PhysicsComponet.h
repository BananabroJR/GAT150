#pragma once
#include "Framework/Component.h"
#include "Math/Vector2.h"

namespace Skyers
{
	class PhysiscsComponent : public Component
	{
	public:
		PhysiscsComponent() = default;

		void Update() override;
		void ApplyForce(Vector2& force) { m_acceloration += force; }

		Vector2 m_velocity;
		Vector2 m_acceloration;

		float m_damping = 1;

		// Inherited via Component
		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;
	};

}