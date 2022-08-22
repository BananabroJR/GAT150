#include "PhysicsComponet.h"
#include "Framework/Actor.h"
#include "Engine.h"
namespace Skyers
{
	void PhysicsComponent::Update()
	{
		velocity += acceloration * g_time.deltaTime;
		m_owner->m_transform.position += velocity * g_time.deltaTime;
		velocity *= damping;

		acceloration = Vector2::zero;
	}

	bool PhysicsComponent::Write(const rapidjson::Value& value) const
	{
		return false;
	}

	bool PhysicsComponent::Read(const rapidjson::Value& value)
	{
		READ_DATA(value, damping);
		READ_DATA(value, velocity);
		READ_DATA(value, acceloration);

		return true;
	}



}

