#pragma once
#include "Framework/Component.h"
#include "Math/Vector2.h"

namespace Skyers
{
	class PhysicsComponent : public Component
	{
	public:
		PhysicsComponent() = default;
		CLASS_DECLARATION(PhysicsComponent)

		Vector2 velocity;
		Vector2 acceloration;

		float damping = 1;
		void Update() override;
		void ApplyForce(const Vector2& force) {acceloration += force; }

		// Inherited via Component
		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;
	};

}