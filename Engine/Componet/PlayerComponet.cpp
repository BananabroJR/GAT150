#include "PlayerComponet.h"
#include "Engine.h"
#include <iostream>

namespace Skyers
{
	void PlayerComponet::Update()
	{
		//add in schmovement
		Vector2 direction = Vector2::zero;
		if (g_inputSystem.GetKeyState(key_left) == InputSystem::KeyState::Held)
		{
			m_owner->m_transform.rotation -= 180 * g_time.deltaTime;
		}
		if (g_inputSystem.GetKeyState(key_right) == InputSystem::KeyState::Held)
		{
			m_owner->m_transform.rotation += 180 * g_time.deltaTime;
		}

		float thrust = 0;
		if (g_inputSystem.GetKeyState(key_up) == InputSystem::KeyState::Held)
		{
			thrust = 100;
		}

		auto component = m_owner->GetComponet<PhysiscsComponet>();
		if (component)
		{
			
			Vector2 force = Vector2::Rotate({1,0}, math::DegToRad(m_owner->m_transform.rotation)) * thrust;
			component->ApplyForce(force);

			force = (Vector2{ 200,100 } - m_owner->m_transform.position).Normalized() * 100.0f;
			component->ApplyForce(force);
		}

		if (g_inputSystem.GetKeyState(key_space) == InputSystem::KeyState::Held)
		{
			auto componet = m_owner->GetComponet<AudioComponet>();
			if (componet)
			{
				componet->play();
			}
		}
	}

}