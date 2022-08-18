#include "PhysicsComponet.h"
#include "Engine.h"
namespace Skyers
{
	void PhysiscsComponent::Update()
	{
		m_velocity += m_acceloration * g_time.deltaTime;
		m_owner->m_transform.position += m_velocity * g_time.deltaTime;
		m_velocity *= m_damping;

		m_acceloration = Vector2::zero;
	}

	bool PhysiscsComponent::Write(const rapidjson::Value& value) const
	{
		return false;
	}

	bool PhysiscsComponent::Read(const rapidjson::Value& value)
	{
		return false;
	}



}

