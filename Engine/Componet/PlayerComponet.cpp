#include "PlayerComponet.h"
#include "Framework/Actor.h"
#include "Engine.h"
#include <iostream>

namespace Skyers
{
	void PlayerComponent::Initialize()
	{
		auto componenet = m_owner->GetComponent<CollisionComponent>();

		if (componenet)
		{
			componenet->SetCollisionEnter(std::bind(&PlayerComponent::OnCollisionEnter, this, std::placeholders::_1));
			componenet->SetCollisionEnter(std::bind(&PlayerComponent::OnCollisionExit, this, std::placeholders::_1));
		}

	}
	void PlayerComponent::Update()
	{
		  Vector2 direction = Vector2::zero;
		//update transform with input
		if (g_inputSystem.GetKeyState(key_left) == InputSystem::KeyState::Held)
		{
			direction = Vector2::left;
			//direction = Vector2::left;
		}
		if (g_inputSystem.GetKeyState(key_right) == InputSystem::KeyState::Held)
		{
			direction = Vector2::right;
			//direction = Vector2::right;
		}
	
		auto component = m_owner->GetComponent<PhysicsComponent>();
		if (component)
		{
		
			component->ApplyForce(direction * speed);

		
		}
	
		if (g_inputSystem.GetKeyState(key_space) == InputSystem::KeyState::Pressed)
		{
			auto component = m_owner->GetComponent<PhysicsComponent>();
			if (component)
			{

				component->ApplyForce(Vector2::up * 30);


			}
		}
	}

	bool PlayerComponent::Write(const rapidjson::Value& value) const
	{
		return true;
	}

	bool PlayerComponent::Read(const rapidjson::Value& value)
	{
		READ_DATA(value, speed);
	

		return true;
	}

	void PlayerComponent::OnCollisionEnter(Actor* other)
	{
		std::cout << "player enter\n";
	}

	void PlayerComponent::OnCollisionExit(Actor* other)
	{
		std::cout << "player exit\n";
	}

}

