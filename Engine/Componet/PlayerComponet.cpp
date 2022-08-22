#include "PlayerComponet.h"
#include "Framework/Actor.h"
#include "Engine.h"
#include <iostream>

void Skyers::PlayerComponent::Update()
{
	Vector2 direction = Vector2::zero;
	//update transform with input
	if (g_inputSystem.GetKeyState(key_left) == InputSystem::KeyState::Held)
	{
		m_owner->m_transform.rotation -= 180 * g_time.deltaTime;
		//direction = Vector2::left;
	}
	if (g_inputSystem.GetKeyState(key_down) == InputSystem::KeyState::Held)
	{
		m_owner->m_transform.rotation += 180 * g_time.deltaTime;
		//direction = Vector2::right;
	}
	float  thrust = 0;
	if (g_inputSystem.GetKeyState(key_up) == InputSystem::KeyState::Held)
	{
		thrust = speed;
	}
	auto component = m_owner->GetComponent<PhysicsComponent>();
	if (component)
	{
		Vector2 force = Vector2::Rotate({ 1, 0 }, math::DegToRad(m_owner->m_transform.rotation)) * thrust;
		component->ApplyForce(force);

		//gravitational force
		//force = (Vector2{ 400, 300 } - m_owner->m_transform.position).Normalized() * 60.0f;
		//component->ApplyForce(force);
	}

	

	m_owner->m_transform.position += direction * 300 * g_time.deltaTime;

	if (g_inputSystem.GetKeyState(key_space) == InputSystem::KeyState::Pressed)
	{
		auto component = m_owner->GetComponent<AudioComponent>();
		if (component)
		{
			component->play();
		}
	}
}

bool Skyers::PlayerComponent::Write(const rapidjson::Value& value) const
{
	return true;
}

bool Skyers::PlayerComponent::Read(const rapidjson::Value& value)
{
	READ_DATA(value, speed);
	

	return true;
}
