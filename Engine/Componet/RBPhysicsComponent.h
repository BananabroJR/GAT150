#pragma once
#include "PhysicsComponet.h"
#include "Physics/PhysicsSystem.h"

namespace Skyers
{
	class RBPhysicsComponent : public PhysicsComponent
	{
	public:
		RBPhysicsComponent() = default;
		~RBPhysicsComponent();

		void Initialize() override;
		void Update() override;
		virtual void ApplyForce(Vector2& force);

		// Inherited via Component
		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

		friend class CollisionComponent;
	private:
		PhysicsSystem::RigidBodyData data;
		b2Body* m_body = nullptr;

	};
}
