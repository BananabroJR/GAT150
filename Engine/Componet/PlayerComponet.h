#pragma once
#include "Framework/Component.h"

namespace Skyers
{
	class PlayerComponent : public Component
	{
	public:
		PlayerComponent() = default;
		void Update() override;

		// Inherited via Component
		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

		float speed = 0;
	};
}