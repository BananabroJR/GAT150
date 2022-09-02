#include "PlayerComponet.h"
#include "Framework/Actor.h"
#include "Engine.h"
#include "Framework/Scene.h"
#include <iostream>

namespace Skyers
{
	void PlayerComponent::Initialize()
	{
		CharacterComponent::Initialize();

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
	
		auto camera = m_owner->GetScene()->GetActorFromName("Camera");
		if (camera)
		{
			//camera->m_transform.position = m_owner->m_transform.position;
			camera->m_transform.position = math::Lerp(camera->m_transform.position, m_owner->m_transform.position, 2 * g_time.deltaTime); 
		}

		Vector2 veloctiy;
		auto component = m_owner->GetComponent<PhysicsComponent>();
		if (component)
		{
			component->ApplyForce(direction * speed);
			veloctiy = component->velocity;
		
		}
	
		if (m_groundCount > 0 && g_inputSystem.GetKeyState(key_space) == InputSystem::KeyState::Pressed)
		{
			auto component = m_owner->GetComponent<PhysicsComponent>();
			if (component)
			{

				component->ApplyForce(Vector2::up * jump);


			}
		}

 		

		auto animComponent = m_owner->GetComponent<SpriteAnimComponent>();
		if (animComponent)
		{
			if (veloctiy.x != 0) animComponent->SetFlipHorizontal(veloctiy.x < 0);
			if (std::fabs(veloctiy.x) > 0)
			{
				animComponent->SetSequence("run");
			}
			else
			{
				animComponent->SetSequence("idle");
			}
		}
	}

	bool PlayerComponent::Write(const rapidjson::Value& value) const
	{
		return true;
	}

	bool PlayerComponent::Read(const rapidjson::Value& value)
	{

		CharacterComponent::Read(value);
		READ_DATA(value, jump);
	

		return true;
	}

	void PlayerComponent::OnNotify(const Event& event)
	{
		if (event.name == "EVENT_DAMAGE")
		{
			health -= std::get<float>(event.data);
			std::cout << "Health" << health << std::endl;
			std::cout << "Damage" << damage << std::endl;
			if (health <= 0)
			{
				m_owner->SetDestroy();

				Event event;
				event.name = "EVENT_PLAYER_DEAD";

				g_event.Notify(event);
			}
		}
	}

	void PlayerComponent::OnCollisionEnter(Actor* other)
	{
		if (other->GetTag() == "Ground")
		{
			m_groundCount++;
		}

		if (other->GetName() == "Coin")
		{
			Event event;
			event.name = "EVENT_ADD_POINTS";
			event.data = 100;
			auto component = m_owner->GetComponent<PhysicsComponent>();
			if (component)
			{

				component->ApplyForce(Vector2::up * jump);


			}

			health += 1;

			g_event.Notify(event);
			Skyers::g_audio.PlayAudio("coin");

			other->SetDestroy();
		}

		if (other->GetTag() == "Enemy")
		{
			Event event;
			event.name = "EVENT_DAMAGE";
			event.data = damage;
			event.receiver = other;

			g_event.Notify(event);

			other->SetDestroy();
		}


		
	}

	void PlayerComponent::OnCollisionExit(Actor* other)
	{
		if (other->GetTag() == "Ground")
		{
			m_groundCount--;
		}
	}

}

